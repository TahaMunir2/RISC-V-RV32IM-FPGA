#include "testbench.h"
#include "verilated.h"
#include <cstdlib>
#include <cstdint>

#define CYCLES 1000

unsigned int ticks = 0;

class L2CacheTestbench : public Testbench {
protected:
    void initializeInputs() override {
        top->clk               = 0;

        top->fetch_i           = 0;
        top->fetch_d           = 0;
        top->addr_i            = 0;
        top->addr_d            = 0;

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

    void setLineFromMemUniform(uint32_t word) {
        for (int i = 0; i < 8; ++i) {
            top->line_from_mem[i] = word;
        }
    }

    void setLineFromMem4(uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3) {
        top->line_from_mem[0] = w0;
        top->line_from_mem[1] = w1;
        top->line_from_mem[2] = w2;
        top->line_from_mem[3] = w3;
        for (int i = 4; i < 8; ++i) {
            top->line_from_mem[i] = 0;
        }
    }

    void setL1WriteBackData4(uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3) {
        top->l1write_back_data[0] = w0;
        top->l1write_back_data[1] = w1;
        top->l1write_back_data[2] = w2;
        top->l1write_back_data[3] = w3;
    }
};

// Basic I-cache fetch
// First fetch_i results in a miss
// L2 cache writes in line_from_mem when ready = 1
// L2 cache should assert ready_i after writing and hitting on the subsequent cycle
// Data_out should match data written in from line_from_mem

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
    EXPECT_EQ(top->main_mem_fetch, 1)
        << "L2 should assert fetch request on main mem on a miss";
    EXPECT_EQ(top->main_mem_addr, addrI)
        << "L2 should assert fetch request using addrI";

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

    EXPECT_EQ(top->data_out[0], 0xCAFEBABE)
        << "I-fetch should return the pattern written into line_from_mem.";
}

// Basic D-cache fetch
// First fetch_d results in a miss
// L2 cache writes in line_from_mem when ready = 1
// L2 cache should assert ready_d after writing and hitting on the subsequent cycle
// Data_out should match data written in from line_from_mem

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
    EXPECT_EQ(top->main_mem_fetch, 1)
        << "L2 should assert fetch request on main mem on a miss";
    EXPECT_EQ(top->main_mem_addr, addrD)
        << "L2 should assert fetch request using addrD";

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

    EXPECT_EQ(top->data_out[0], 0x12345678)
        << "D-fetch should return the pattern written into line_from_mem.";
}

// Testing arbiter logic (both fetch_d and fetch_i asserted)
// First fetch results in a miss
// L2 should prioritise fetch_d over fetch_i
// L2 cache should assert ready_d first then process the fetch_i request
// Data_out should match data written in from line_from_mem

TEST_F(L2CacheTestbench, IandDFetchMissAndHit) {
    initializeInputs();

    uint32_t addrI = 0xF0000000;
    uint32_t addrD = 0x0F000000;

    top->fetch_i = 1;
    top->fetch_d = 1;
    top->addr_i  = addrI;
    top->addr_d  = addrD;
    top->ready   = 0;

    runSimulation(1);

    EXPECT_EQ(top->ready_i, 0)
        << "L2 should not assert ready_i on first access to a cold line (miss).";
    EXPECT_EQ(top->ready_d, 0)
        << "L2 should not assert ready_d on first access to a cold line (miss).";
    EXPECT_EQ(top->main_mem_fetch, 1)
        << "L2 should assert fetch request on main mem on a miss";
    EXPECT_EQ(top->main_mem_addr, addrD)
        << "L2 should assert fetch request using addrD";

    // Memory returns a line: fill all words with a known pattern
    setLineFromMemUniform(0xABCD0000);
    top->ready = 1;

    runSimulation(1);

    EXPECT_EQ(top->ready_i, 0)
        << "L2 should not assert ready_i on the same cycle when memory has provided the line.";
    EXPECT_EQ(top->ready_d, 0)
        << "L2 should not assert ready_d on the same cycle when memory has provided the line.";

    // Deassert ready, then hit again on same address
    top->ready = 0;
    runSimulation(1);

    EXPECT_EQ(top->ready_d, 1)
        << "L2 should hit and assert ready_d after fill.";
    EXPECT_EQ(top->ready_i, 0)
        << "L2 should not assert ready_i as only fetch_d request is being processed currently.";
    EXPECT_EQ(top->data_out[0], 0xABCD0000)
        << "D-fetch should return the pattern written into line_from_mem.";

    top->fetch_d = 0;

    // Now L2 should process the I fetch (already tested before)
}

// Simple L1 write-back into L2 and then forwarded to memory.
// L1 writes to L2, but misses on the writeback
// L2 should assert wb_ready_d when it succesfully accepts the write back into the buffer
// When wb_ready, L2 should write the L1 writeback directly to main mem
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

// Basic dirty eviction scenario:
// Fill one line and mark it dirty by L1 write-back
// Then request a different tag mapping to same set
// And make sure that the correct victim is chosen (using LRU logic)
TEST_F(L2CacheTestbench, DirtyEvictionCausesWriteBack) {
    initializeInputs();

    uint32_t base = 0x00000000;
    uint32_t a0   = base | 0x00000000;
    uint32_t a1   = base | 0x10000000; // different tag, same set
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
    top->l1write_back_addr = a0;
    top->fetch_d           = 1;

    runSimulation(1);

    // Testing wb_ready_d assertion
    EXPECT_EQ(top->wb_ready_d, 1)
        << "L2 should accept dirty L1 write-back.";

    runSimulation(1);

    // Testing wb_ready_d deassertion/not asserting when wb buffer full
    EXPECT_EQ(top->wb_ready_d, 0)
        << "L2 should not accept dirty L1 write-back  if L1wb_buffer full.";    

    top->l1write_back_en = 0;
    runSimulation(1);

    top->fetch_d = 0;
    runSimulation(1); // Let the l1 wb buffer empty and write the dirty value

    top->fetch_d = 1;
    top->addr_d  = a0;

    runSimulation(1);

    EXPECT_EQ(top->ready_d, 1)
        << "L2 should hit and assert ready_d";

    EXPECT_EQ(top->data_out[0], 0xBBBB0001)
        << "L2 should output correct data.";

    // Now make it so that data in a1 is least recently used
    top->addr_d = a1;
    runSimulation(1);

    top->addr_d = a2;
    runSimulation(1);

    top->addr_d = a3;
    runSimulation(1);

    // Now force a new miss in same set -> eviction of some way
    top->addr_d  = a4;
    top->wb_ready = 1;

    runSimulation(1); // Fill the L2 wb buffer

    runSimulation(1);

    // Testing to see if L2 asserts write_back_en and 
    // That the LRU block has been chosen
    // write_back_data should be the first 4 words in the dirty evicted block
    EXPECT_EQ(top->write_back_en, 1)
        << "Dirty eviction should assert write_back_en when main mem asserts wb_ready.";

    top->ready = 0;

    EXPECT_EQ(top->write_back_data[0], 0xBBBB0001)
        << "Should write back correct data to main mem.";

    setLineFromMemUniform(0xEEE00000);
    top->ready = 1;

    runSimulation(1);


    // Testing to see if L2 still asserts write_back_en and writes back the last 4 words in the dirty evicted block
    EXPECT_EQ(top->write_back_en, 1)
        << "Dirty eviction should assert write_back_en when main mem asserts wb_ready.";

    EXPECT_EQ(top->write_back_data[0], 0xAAA00000)
        << "Should write back correct data to main mem.";        
    
    top->ready = 0;

    runSimulation(1);
    // Testing to see if the L2 cache deasserts write_back_en when all dirty values
    // In the evicted block have been written back
    EXPECT_EQ(top->write_back_en, 0)
        << "L2 cache should deassert write_back_en as L2wb_buffer should be empty now";

    // Testing to see if line_from_mem has been correctly filled into the L2 cache
    EXPECT_EQ(top->ready_d, 1)
        << "L2 should hit and assert ready_d"; 
        
    EXPECT_EQ(top->data_out[0], 0xEEE00000)
        << "L2 should output correct data.";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
