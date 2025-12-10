#include "base_testbench.h"

unsigned int ticks = 0;

class RuuTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 0;
        top->dispatch1_en = 0;
        top->dispatch2_en = 0;
        top->wb1_en = 0;
        top->wb2_en = 0;
        top->free1_en = 0;
        top->free2_en = 0;
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

    void clearInputs()
    {
        top->dispatch1_en = 0;
        top->dispatch2_en = 0;
        top->wb1_en = 0;
        top->wb2_en = 0;
        top->free1_en = 0;
        top->free2_en = 0;
    }

    void dispatchReady(uint32_t dest_tag, uint32_t src1_val, uint32_t src2_val, uint32_t ctrl)
    {
        top->dispatch1_en = 1;
        top->dispatch1_dest_tag = dest_tag;
        top->dispatch1_src1_valid = 1;
        top->dispatch1_src1_value = src1_val;
        top->dispatch1_src2_valid = 1;
        top->dispatch1_src2_value = src2_val;
        top->dispatch1_ctrl = ctrl;
    }

    void dispatchWaiting(uint32_t dest_tag, uint32_t src1_tag, uint32_t src2_tag, uint32_t ctrl)
    {
        top->dispatch1_en = 1;
        top->dispatch1_dest_tag = dest_tag;
        top->dispatch1_src1_valid = 0;
        top->dispatch1_src1_tag = src1_tag;
        top->dispatch1_src2_valid = 0;
        top->dispatch1_src2_tag = src2_tag;
        top->dispatch1_ctrl = ctrl;
    }

    void primeSlots()  // Issue logic starts at index 2, fill slots 0 and 1 first
    {
        top->dispatch1_en = 1;
        top->dispatch1_dest_tag = 0;
        top->dispatch1_src1_valid = 0;
        top->dispatch2_en = 1;
        top->dispatch2_dest_tag = 1;
        top->dispatch2_src1_valid = 0;
        tick();
        clearInputs();
    }
};

TEST_F(RuuTestbench, InitialState)
{
    reset();
    EXPECT_EQ(top->exec0_dest_tag, 0);
    EXPECT_EQ(top->exec1_dest_tag, 0);
}

TEST_F(RuuTestbench, DispatchReadyIssues)
{
    reset();
    primeSlots();
    dispatchReady(10, 100, 200, 0b0001);
    tick();
    clearInputs();
    top->eval();
    EXPECT_EQ(top->exec0_dest_tag, 10);
    EXPECT_EQ(top->exec0_src1_value, 100);
    EXPECT_EQ(top->exec0_src2_value, 200);
    EXPECT_EQ(top->exec0_ctrl, 0b0001);
}

TEST_F(RuuTestbench, WaitingDoesNotIssue)
{
    reset();
    primeSlots();
    dispatchWaiting(10, 5, 6, 0b0001);
    tick();
    clearInputs();
    top->eval();
    EXPECT_EQ(top->exec0_dest_tag, 0);
}

TEST_F(RuuTestbench, WritebackWakeup)
{
    reset();
    primeSlots();
    dispatchWaiting(10, 5, 6, 0b0001);
    tick();
    clearInputs();
    top->wb1_en = 1;
    top->wb1_tag = 5;
    top->wb1_value = 100;
    top->wb2_en = 1;
    top->wb2_tag = 6;
    top->wb2_value = 200;
    tick();
    clearInputs();
    top->eval();
    EXPECT_EQ(top->exec0_dest_tag, 10);
    EXPECT_EQ(top->exec0_src1_value, 100);
    EXPECT_EQ(top->exec0_src2_value, 200);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}