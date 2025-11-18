#include "testbench.h"
#include <cstdlib>

#define CYCLES 1000

unsigned int ticks = 0;

class RegandAluTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 1;
    }
};

TEST_F(RegandAluTestbench, BaseProgramTest1)
{
    bool success = false;
    system("./compile.sh asm/program.S");

    for (int i = 0; i < CYCLES; i++)
    {
        top->WE3 = 1;
        top->AD3 = 10;
        top->AD2 = 0;
        top->AD1 = 0;
        top->ALUctrl = 0;
        top->ALUsrc = 1;
        top->ImmOp = 0;
        runSimulation(1);        
        
        std::cout << top->EQ;
        if ((top->A0 == 0) && (top->EQ == 1))
        {
            SUCCEED();
            success = true;
            break;
        }
    }
    if (!success)
    {
        FAIL() << "Counter did not reach 254" << top->EQ;
    }
}

// Note this is how we are going to test your CPU. Do not worry about this for
// now, as it requires a lot more instructions to function
// TEST_F(CpuTestbench, Return5Test)
// {
//     system("./compile.sh c/return_5.c");
//     runSimulation(100);
//     EXPECT_EQ(top->a0, 5);
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
