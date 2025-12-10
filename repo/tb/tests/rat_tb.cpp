#include "base_testbench.h"

unsigned int ticks = 0;

class RatTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 0;
        top->inst1_rd = 0;
        top->inst2_rd = 0;
        top->rs1 = 0;
        top->rs2 = 0;
        top->rs3 = 0;
        top->rs4 = 0;
    }

    void reset()
    {
        top->rst = 1;
        top->clk = 1;
        top->eval();
        top->clk = 0;
        top->eval();
        top->rst = 0;
    }

    void tick()
    {
        top->clk = 1;
        top->eval();
        top->clk = 0;
        top->eval();
    }

    void issueInstructions(uint32_t rd1, uint32_t rd2)
    {
        top->inst1_rd = rd1;
        top->inst2_rd = rd2;
        tick();
    }

    uint32_t lookupSource(uint32_t rs)
    {
        top->rs1 = rs;
        top->eval();
        return top->rs1_prod_id;
    }
};

// Test initial state: all RAT entries should be 0 after reset
TEST_F(RatTestbench, InitialState)
{
    reset();
    for (int i = 0; i < 32; i++) {
        EXPECT_EQ(lookupSource(i), 0);
    }
    EXPECT_EQ(top->latest_tag, 0);
}

// Test tag assignment: inst1 gets counter-1, inst2 gets counter
TEST_F(RatTestbench, TagAssignment)
{
    reset();
    top->inst1_rd = 1;
    top->inst2_rd = 2;
    top->eval();
    // Before tick: counter is 0, so inst1_prod_id = -1 (wraps to 63), inst2_prod_id = 0
    EXPECT_EQ(top->inst1_prod_id, 63);  // 6-bit wrap: 0 - 1 = 63
    EXPECT_EQ(top->inst2_prod_id, 0);
}

// Test counter increment by 2 each cycle
TEST_F(RatTestbench, CounterIncrement)
{
    reset();
    EXPECT_EQ(top->latest_tag, 0);
    issueInstructions(1, 2);
    EXPECT_EQ(top->latest_tag, 2);
    issueInstructions(3, 4);
    EXPECT_EQ(top->latest_tag, 4);
}

// Test RAT update: destination registers are mapped to their producer tags
TEST_F(RatTestbench, RatUpdate)
{
    reset();
    issueInstructions(5, 10);  // x5 -> tag 63, x10 -> tag 0
    EXPECT_EQ(lookupSource(5), 63);
    EXPECT_EQ(lookupSource(10), 0);
}

// Test x0 handling: writes to x0 should be ignored
TEST_F(RatTestbench, X0NeverRenamed)
{
    reset();
    issueInstructions(0, 0);  // Both write to x0
    EXPECT_EQ(lookupSource(0), 0);  // x0 should remain 0
}


// Test WAW hazard: same register written by both instructions in same cycle
TEST_F(RatTestbench, WAWHazardSameCycle)
{
    reset();
    issueInstructions(7, 7);  // Both instructions write to x7
    // inst2 (younger) should win, so x7 maps to inst2's tag
    EXPECT_EQ(lookupSource(7), 0);  // inst2_prod_id = 0
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}