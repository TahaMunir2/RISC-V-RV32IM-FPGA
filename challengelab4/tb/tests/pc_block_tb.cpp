/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "testbench.h"
#include "base_testbench.h"
#include <cstdlib>

#define CYCLES 1
Vdut *top;
VerilatedVcdC *tfp;

unsigned int ticks = 0;

class CpuTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->pc_src = 0;
        top->rst = 0;
        top->Imm_op = 0;
        top->clk = 1;
    }
};

TEST_F(CpuTestbench, PCBTest01) // check if normal increment works
{
    bool success = false;


    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(2);
        if (top->pc == 4)
        {
            SUCCEED();
            success = true;
            break;
        }
    }
    if (!success)
    {
        FAIL() << "PC did not reach 4" << top->pc;
    }
}


TEST_F(CpuTestbench, PCBTest02) // check if pc_src and immop work
{
    top->pc_src = 1;
    top->Imm_op = 12;

    bool success = false;

    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(2);
        if (top->pc == 12)
        {
            SUCCEED();
            success = true;
            break;
        }
    }
    if (!success)
    {
        FAIL() << "PC did not reach 12" << top->pc;
    }
}

TEST_F(CpuTestbench, PCBTest03) // check if rst works
{
    top->rst = 0;

    bool success = false;

    for (int i = 0; i < CYCLES; i++)
    {
        runSimulation(1);
        if (top->pc == 0)
        {
            SUCCEED();
            success = true;
            break;
        }
    }
    if (!success)
    {
        FAIL() << "PC did not reach 0" << top->pc;
    }
}   

int main(int argc, char **argv)
{
    top = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    tfp->close();

    delete top;
    delete tfp;

    return res;
}
