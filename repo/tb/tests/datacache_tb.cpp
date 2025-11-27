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
    bool success = false;
    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(1);
        if (top->RD1 == 100 && top->RD2 == 100 && top->A0 == 100)
        {
            SUCCEED();
            success = true;
            break;
        }
    }
    if (!success)
    {
        FAIL() << "Cache did not stall";
    }
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}