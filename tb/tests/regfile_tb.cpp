#include "testbench.h"
#include <cstdlib>

#define CYCLES 1000

unsigned int ticks = 0;

class RegfileTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 1;
        top->WD3 = 0;
        top->WE3 = 0;
        top->AD1 = 0;
        top->AD2 = 0;
        top->AD3 = 0;
    }
};

TEST_F(RegfileTestbench, RegTest0) // test if RD1 and RD2 work as well as WE3 and WD3 and A0 work;
{
    bool success = false;
    top->WE3 = 1;
    top->WD3 = 100;
    top->AD1 = 10;
    top->AD3 = 10;
    top->AD2 = 10;
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
        FAIL() << "Reg did not updated";
    }
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
