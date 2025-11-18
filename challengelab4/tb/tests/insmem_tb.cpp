/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class InsmemTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {

    }
};

TEST_F(InsmemTestbench, Mux0WorksTest)
{
    top->addr = 3217031168; // address of first instruction

    top->eval();

    EXPECT_EQ(top->instr, 267387667); // first instruction
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
