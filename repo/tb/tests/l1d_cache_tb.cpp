#include "testbench.h"
#include <cstdlib>

#define CYCLES 1000

unsigned int ticks = 0;

class DcacheTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
    }
};


TEST_F(DcacheTestbench, DcacheTest0)
{
    top->clk          = 0;
    top->fetch        = 0;
    top->MemWrite_m   = 0;
    top->LoadSize     = 0;
    top->LoadUnsigned = 1;
    top->SizeWrite_m  = 0;
    top->wd           = 0;
    top->addr         = 0x00000000;
    
    for (int i = 0; i < 4; ++i) { // Adjust '4' to match your (CacheLineSize / 32)
        top->line_from_mem[i] = 0;
    }

    top->fetch = 1;
    top->eval();
    EXPECT_EQ(top->stall, 1)
        << "Cache should assert stall on first access to a cold line (miss)." << top->stall;

    runSimulation(1);

    EXPECT_EQ(top->stall, 0)
        << "Cache should deassert stall on subsequent access to the same line (hit).";
        
    top->fetch = 0;
    runSimulation(1);

    EXPECT_EQ(top->stall, 0)
        << "Cache should not stall when fetch is deasserted.";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}