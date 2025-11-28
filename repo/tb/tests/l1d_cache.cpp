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
    top->line_from_mem = 0;

    runSimulation(1);

    top->fetch = 1;
    runSimulation(1);

    EXPECT_EQ(top->stall, 1)
        << "Cache should assert stall on first access to a cold line (miss).";

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