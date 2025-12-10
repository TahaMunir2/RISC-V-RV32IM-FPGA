#include "base_testbench.h"

unsigned int ticks = 0;

class RobTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 0;
        top->q1_tag = 0;
        top->q2_tag = 0;
        top->q3_tag = 0;
        top->q4_tag = 0;
        top->alloc1_en = 0;
        top->alloc1_rd = 0;
        top->alloc1_tag = 0;
        top->alloc2_en = 0;
        top->alloc2_rd = 0;
        top->alloc2_tag = 0;
        top->wb1_en = 0;
        top->wb1_tag = 0;
        top->wb1_value = 0;
        top->wb2_en = 0;
        top->wb2_tag = 0;
        top->wb2_value = 0;
        top->commit1_en = 0;
        top->commit2_en = 0;
    }

    void reset()
    {
        top->clk = 0;
        top->eval();
        top->rst = 1;
        top->eval();
        top->clk = 1;
        top->eval();
        top->clk = 0;
        top->eval();
        top->rst = 0;
        top->eval();
    }

    void tick()
    {
        top->clk = 1;
        top->eval();
        top->clk = 0;
        top->eval();
    }

    void clearInputs()
    {
        top->alloc1_en = 0;
        top->alloc2_en = 0;
        top->wb1_en = 0;
        top->wb2_en = 0;
        top->commit1_en = 0;
        top->commit2_en = 0;
    }

    void allocate(uint32_t tag, uint32_t rd, int port)
    {
        if (port == 1) {
            top->alloc1_en = 1;
            top->alloc1_tag = tag;
            top->alloc1_rd = rd;
        } else {
            top->alloc2_en = 1;
            top->alloc2_tag = tag;
            top->alloc2_rd = rd;
        }
    }

    void writeback(uint32_t tag, uint32_t value, int port)
    {
        if (port == 1) {
            top->wb1_en = 1;
            top->wb1_tag = tag;
            top->wb1_value = value;
        } else {
            top->wb2_en = 1;
            top->wb2_tag = tag;
            top->wb2_value = value;
        }
    }

    void queryTag(uint32_t tag, int port)
    {
        if (port == 1) top->q1_tag = tag;
        else if (port == 2) top->q2_tag = tag;
        else if (port == 3) top->q3_tag = tag;
        else top->q4_tag = tag;
        top->eval();
    }

    // Helper to get current head position
    uint32_t getHead()
    {
        return top->commit1_tag;
    }
};

// Test initial state: all entries not ready after reset
TEST_F(RobTestbench, InitialState)
{
    reset();
    for (int i = 0; i < 64; i++) {
        queryTag(i, 1);
        EXPECT_EQ(top->q1_ready, 0);
    }
    EXPECT_EQ(top->commit1_valid, 0);
    EXPECT_EQ(top->commit2_valid, 0);
}

// Test single allocation
TEST_F(RobTestbench, SingleAllocation)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);  // Allocate at head for register x5
    tick();
    clearInputs();
    
    queryTag(head, 1);
    EXPECT_EQ(top->q1_ready, 0);  // Not ready until writeback
}

// Test dual allocation in same cycle
TEST_F(RobTestbench, DualAllocation)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);       // inst1: dest x5
    allocate(head + 1, 10, 2);  // inst2: dest x10
    tick();
    clearInputs();
    
    queryTag(head, 1);
    queryTag(head + 1, 2);
    EXPECT_EQ(top->q1_ready, 0);
    EXPECT_EQ(top->q2_ready, 0);
}

// Test writeback marks entry as ready
TEST_F(RobTestbench, WritebackMarksReady)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    tick();
    clearInputs();
    
    writeback(head, 0xDEADBEEF, 1);
    tick();
    clearInputs();
    
    queryTag(head, 1);
    EXPECT_EQ(top->q1_ready, 1);
    EXPECT_EQ(top->q1_value, 0xDEADBEEF);
}

// Test dual writeback in same cycle
TEST_F(RobTestbench, DualWriteback)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    allocate(head + 1, 10, 2);
    tick();
    clearInputs();
    
    writeback(head, 100, 1);
    writeback(head + 1, 200, 2);
    tick();
    clearInputs();
    
    queryTag(head, 1);
    queryTag(head + 1, 2);
    EXPECT_EQ(top->q1_ready, 1);
    EXPECT_EQ(top->q1_value, 100);
    EXPECT_EQ(top->q2_ready, 1);
    EXPECT_EQ(top->q2_value, 200);
}

// Test commit valid when head is ready
TEST_F(RobTestbench, CommitValid)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);  // Allocate at head position
    tick();
    clearInputs();
    
    writeback(head, 42, 1);
    tick();
    clearInputs();
    
    EXPECT_EQ(top->commit1_valid, 1);
    EXPECT_EQ(top->commit1_rd, 5);
    EXPECT_EQ(top->commit1_value, 42);
    EXPECT_EQ(top->commit1_tag, head);
}

// Test commit not valid when head is not ready
TEST_F(RobTestbench, CommitNotValidWhenNotReady)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    tick();
    clearInputs();
    
    // No writeback, so head not ready
    EXPECT_EQ(top->commit1_valid, 0);
}

// Test single commit advances head
TEST_F(RobTestbench, SingleCommit)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    allocate(head + 1, 10, 2);
    tick();
    clearInputs();
    
    writeback(head, 100, 1);
    tick();
    clearInputs();
    
    EXPECT_EQ(top->commit1_valid, 1);
    EXPECT_EQ(top->commit1_tag, head);
    
    top->commit1_en = 1;
    tick();
    clearInputs();
    
    // Head should have advanced, commit1_tag now points to next entry
    EXPECT_EQ(top->commit1_tag, head + 1);
}

// Test dual commit when both head and head+1 are ready
TEST_F(RobTestbench, DualCommit)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    allocate(head + 1, 10, 2);
    tick();
    clearInputs();
    
    writeback(head, 100, 1);
    writeback(head + 1, 200, 2);
    tick();
    clearInputs();
    
    EXPECT_EQ(top->commit1_valid, 1);
    EXPECT_EQ(top->commit2_valid, 1);
    EXPECT_EQ(top->commit1_rd, 5);
    EXPECT_EQ(top->commit2_rd, 10);
    
    top->commit1_en = 1;
    top->commit2_en = 1;
    tick();
    clearInputs();
    
    // Both committed, head advanced by 2
    EXPECT_EQ(top->commit1_tag, head + 2);
}

// Test commit2 not valid if commit1 not valid
TEST_F(RobTestbench, Commit2RequiresCommit1)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    allocate(head + 1, 10, 2);
    tick();
    clearInputs();
    
    // Only writeback to second entry, not first
    writeback(head + 1, 200, 2);
    tick();
    clearInputs();
    
    EXPECT_EQ(top->commit1_valid, 0);  // Head not ready
    EXPECT_EQ(top->commit2_valid, 0);  // Can't commit2 without commit1
}

// Test in-order retirement: must wait for older instruction
TEST_F(RobTestbench, InOrderRetirement)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    allocate(head + 1, 10, 2);
    tick();
    clearInputs();
    
    // Out-of-order completion: inst2 finishes first
    writeback(head + 1, 200, 2);
    tick();
    clearInputs();
    
    // Can't commit yet because head (inst1) not ready
    EXPECT_EQ(top->commit1_valid, 0);
    
    // Now inst1 completes
    writeback(head, 100, 1);
    tick();
    clearInputs();
    
    // Now both can commit in order
    EXPECT_EQ(top->commit1_valid, 1);
    EXPECT_EQ(top->commit2_valid, 1);
}

// Test all 4 query ports simultaneously
TEST_F(RobTestbench, AllQueryPorts)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    allocate(head + 1, 10, 2);
    tick();
    clearInputs();
    allocate(head + 2, 15, 1);
    allocate(head + 3, 20, 2);
    tick();
    clearInputs();
    
    writeback(head, 100, 1);
    writeback(head + 1, 200, 2);
    tick();
    clearInputs();
    writeback(head + 2, 300, 1);
    writeback(head + 3, 400, 2);
    tick();
    clearInputs();
    
    top->q1_tag = head;
    top->q2_tag = head + 1;
    top->q3_tag = head + 2;
    top->q4_tag = head + 3;
    top->eval();
    
    EXPECT_EQ(top->q1_ready, 1);
    EXPECT_EQ(top->q1_value, 100);
    EXPECT_EQ(top->q2_ready, 1);
    EXPECT_EQ(top->q2_value, 200);
    EXPECT_EQ(top->q3_ready, 1);
    EXPECT_EQ(top->q3_value, 300);
    EXPECT_EQ(top->q4_ready, 1);
    EXPECT_EQ(top->q4_value, 400);
}

// Test ready bit cleared after commit
TEST_F(RobTestbench, ReadyClearedAfterCommit)
{
    reset();
    uint32_t head = getHead();
    allocate(head, 5, 1);
    tick();
    clearInputs();
    
    writeback(head, 100, 1);
    tick();
    clearInputs();
    
    queryTag(head, 1);
    EXPECT_EQ(top->q1_ready, 1);
    
    top->commit1_en = 1;
    tick();
    clearInputs();
    
    queryTag(head, 1);
    EXPECT_EQ(top->q1_ready, 0);  // Ready cleared after commit
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

