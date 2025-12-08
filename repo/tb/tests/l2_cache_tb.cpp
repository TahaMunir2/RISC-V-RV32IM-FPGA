#include "testbench.h"
#include "verilated.h"
#include <cstdlib>
#include <cstdint>

#define CYCLES 1000

unsigned int ticks = 0;

// Helper: your base Testbench probably typedefs Vdut as the top.
class L2CacheTestbench : public Testbench {
protected:
    void initializeInputs() override {
        top->clk               = 0;

        top->fetch_i           = 0;
        top->fetch_d           = 0;
        top->addr_i            = 0;
        top->addr_d            = 0;

        // Wide signals: line_from_mem is VlWide<8> (256 bits)
        //               l1write_back_data is VlWide<4> (128 bits)
        for (int i = 0; i < 8; ++i) {
            top->line_from_mem[i] = 0;
        }
        for (int i = 0; i < 4; ++i) {
            top->l1write_back_data[i] = 0;
        }

        top->l1write_back_en   = 0;
        top->l1write_back_addr = 0;
        top->ready             = 0;
        top->wb_ready          = 0;
    }

    // Convenience helpers for tests:

    // Fill the entire 8-word L2 line with the same 32-bit pattern.
    void setLineFromMemUniform(uint32_t word) {
        for (int i = 0; i < 8; ++i) {
            top->line_from_mem[i] = word;
        }
    }

    // Fill the first 4 words of line_from_mem with explicit values
    // (useful if you care about word positions).
    void setLineFromMem4(uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3) {
        top->line_from_mem[0] = w0;
        top->line_from_mem[1] = w1;
        top->line_from_mem[2] = w2;
        top->line_from_mem[3] = w3;
        for (int i = 4; i < 8; ++i) {
            top->line_from_mem[i] = 0;
        }
    }

    // L1 write-back data is 4 words (128 bits)
    void setL1WriteBackData4(uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3) {
        top->l1write_back_data[0] = w0;
        top->l1write_back_data[1] = w1;
        top->l1write_back_data[2] = w2;
        top->l1write_back_data[3] = w3;
    }
};

/**
 * Basic I-cache style fetch:
 *  - cold miss: no ready_i
 *  - memory provides line_from_mem + ready
 *  - hit: ready_i asserted again on same address
 */
TEST_F(L2CacheTestbench, InstructionFetchMissAndHit) {
    initializeInputs();

    uint32_t addrI = 0x00000000;

    top->fetch_i = 1;
    top->fetch_d = 0;
    top->addr_i  = addrI;
    top->ready   = 0;

    runSimulation(1);

    EXPECT_EQ(top->ready_i, 0)
        << "L2 should not assert ready_i on first access to a cold line (miss).";
    EXPECT_EQ(top->write_back_en, 0)
        << "No write-back expected on a simple read miss.";

    // Memory returns a line: fill all words with a known pattern
    setLineFromMemUniform(0xCAFEBABE);
    top->ready = 1;

    runSimulation(1);

    EXPECT_EQ(top->ready_i, 0)
        << "L2 should not assert ready_i on the same cycle when memory has provided the line.";

    // Deassert ready, then hit again on same address
    top->ready = 0;
    runSimulation(1);

    EXPECT_EQ(top->ready_i, 1)
        << "L2 should hit on the same I address after fill.";

    // If data_out is wide (VlWide<4>), check a single word:
    //   data_out[0] is least-significant 32 bits.
    // We can’t EXPECT_EQ(top->data_out, int) because data_out is VlWide<4>.
    uint32_t word0 = top->data_out[0];
    EXPECT_EQ(word0, 0xCAFEBABE)
        << "I-fetch should return the pattern written into line_from_mem.";
}

/**
 * Basic D-cache style fetch:
 *  - cold miss -> ready_d = 0
 *  - memory provides line_from_mem + ready
 *  - hit -> ready_d = 1, data_out correct
 */
TEST_F(L2CacheTestbench, DataFetchMissAndHit) {
    initializeInputs();

    uint32_t addrD = 0x00000020; // some other set/offset

    top->fetch_i = 0;
    top->fetch_d = 1;
    top->addr_d  = addrD;
    top->ready   = 0;

    runSimulation(1);

    EXPECT_EQ(top->ready_d, 0)
        << "L2 should not assert ready_d on first access (miss).";

    // Memory returns a different pattern
    setLineFromMemUniform(0x12345678);
    top->ready = 1;

    runSimulation(1);

    EXPECT_EQ(top->ready_d, 0)
        << "L2 should not assert ready_d in the same cycle as when memory returns a line.";

    top->ready = 0;
    runSimulation(1);

    EXPECT_EQ(top->ready_d, 1)
        << "L2 should hit on the same D address after fill.";

    uint32_t word0 = top->data_out[0];
    EXPECT_EQ(word0, 0x12345678)
        << "D-fetch should return the pattern written into line_from_mem.";
}

/**
 * Simple L1 write-back into L2 and then forwarded to memory.
 *
 *  - Fill a line through D-fetch
 *  - L1 writes back modified data for that address
 *  - L2 should assert wb_ready_d when it accepts the write-back
 *  - When wb_ready (memory ready), L2 should assert write_back_en
 */
TEST_F(L2CacheTestbench, L1WriteBackForwardToMemory) {
    initializeInputs();

    uint32_t addrD  = 0x00000100;
    uint32_t addrWb = 0xF0000000;

    // Fill L2 line from memory first
    top->fetch_d = 1;
    top->addr_d  = addrD;
    setLineFromMemUniform(0x11111111);
    top->ready = 1;
    runSimulation(1);

    top->ready = 0;
    runSimulation(1); // solidify hit state

    // Now simulate L1 writing back new data for the same address
    setL1WriteBackData4(0xAAAA0001, 0xAAAA0002, 0xAAAA0003, 0xAAAA0004);
    top->l1write_back_en   = 1;
    top->l1write_back_addr = addrWb;
    top->fetch_d           = 1;

    runSimulation(1);

    EXPECT_EQ(top->wb_ready_d, 1)
        << "L2 should assert wb_ready_d to acknowledge L1 write-back.";

    // Drop the request after handshake
    top->l1write_back_en = 0;

    // Now memory is ready to accept L2 write-back
    top->wb_ready = 1;

    runSimulation(1);

    EXPECT_EQ(top->write_back_en, 1)
        << "L2 should assert write_back_en to forward data to memory.";

    // Check at least low word of write_back_data
    uint32_t wb_word0 = top->write_back_data[0];
    EXPECT_EQ(wb_word0, 0xAAAA0001u)
        << "Low word of write_back_data should match L1 write-back data.";

    // Clean up
    top->wb_ready = 0;
    top->ready    = 0;
    runSimulation(1);
}

/**
 * Very basic dirty eviction scenario:
 *  - Fill one line and mark it dirty by L1 write-back
 *  - Then request a different tag mapping to same set
 *  - Expect L2 to assert write_back_en at some point (eviction)
 *
 * This is high-level; we're not checking exact LRU victim, just that
 * a dirty line eventually gets written back.
 */
TEST_F(L2CacheTestbench, DirtyEvictionCausesWriteBack) {
    initializeInputs();

    uint32_t base = 0x00000000;
    uint32_t a0   = base | 0x00000000;
    uint32_t a1   = base | 0x10000000; // different tag, same set (assuming)
    uint32_t a2   = base | 0x20000000;
    uint32_t a3   = base | 0x30000000;
    uint32_t a4   = base | 0x40000000;

    auto fillLine = [&](uint32_t addr, uint32_t pattern) {
        top->fetch_d = 1;
        top->addr_d  = addr;
        setLineFromMemUniform(pattern);
        top->ready = 1;
        runSimulation(1);
        top->ready = 0;
        runSimulation(1);
    };

    // Fill four ways with clean lines
    fillLine(a0, 0xAAA00000);
    fillLine(a1, 0xBBB00000);
    fillLine(a2, 0xCCC00000);
    fillLine(a3, 0xDDD00000);

    // Make a1 dirty via L1 write-back
    setL1WriteBackData4(0xBBBB0001, 0xBBBB0002, 0xBBBB0003, 0xBBBB0004);
    top->l1write_back_en   = 1;
    top->l1write_back_addr = a1;
    top->fetch_d           = 1;

    runSimulation(1);

    EXPECT_EQ(top->wb_ready_d, 1)
        << "L2 should accept dirty L1 write-back before eviction.";

    top->l1write_back_en = 0;
    runSimulation(1);

    // Now force a new miss in same set -> eviction of some way
    top->fetch_d = 1;
    top->addr_d  = a4;
    setLineFromMemUniform(0xEEE00000);
    top->ready = 1;
    top->wb_ready = 1;

    bool saw_writeback = false;
    for (int i = 0; i < 8; ++i) {
        runSimulation(1);
        if (top->write_back_en) {
            saw_writeback = true;
            break;
        }
    }

    EXPECT_TRUE(saw_writeback)
        << "Dirty eviction should assert write_back_en when main mem asserts wb_ready.";

    top->ready = 0;
    runSimulation(1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
