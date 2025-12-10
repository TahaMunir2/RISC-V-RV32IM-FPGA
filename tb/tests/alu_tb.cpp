/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class ALUTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->ALUctrl = 0;
        top->ALUop1 = 0;
        top->ALUop2 = 0;
    }
};

TEST_F(ALUTestbench, ALUTest0) // test addition
{
    top->ALUctrl = 0;
    top->ALUop1 = 5;
    top->ALUop2 = 5;

    top->eval();

    EXPECT_EQ(top->ALUout, 10);
}

TEST_F(ALUTestbench, ALUTest1) // eq flag raised
{
    top->ALUctrl = 1;
    top->ALUop1 = 5;
    top->ALUop2 = 5;

    top->eval();

    EXPECT_EQ(top->EQ, 1);
}

TEST_F(ALUTestbench, ALUTest2) // eq flag reset
{
    top->ALUctrl = 1;
    top->ALUop1 = 5;
    top->ALUop2 = 4;

    top->eval();

    EXPECT_EQ(top->EQ, 0);
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
