/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class ControlTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->EQ = 0;
    }
};

TEST_F(ControlTestbench, ControlAddTest)
{
    top->instr = 19; // 00000000000000000000000000010011

    top->eval();

    EXPECT_EQ(top->RegWrite, 1);
    EXPECT_EQ(top->ALUCtrl, 0);
    EXPECT_EQ(top->ALUSrc, 1);
    EXPECT_EQ(top->ImmSrc, 0);
    EXPECT_EQ(top->PCSrc, 0);
}

TEST_F(ControlTestbench, ControlBNETest1)
{
    top->instr = 4195; // 00000000000000000001000001100011
    top->eval();

    EXPECT_EQ(top->RegWrite, 0);
    EXPECT_EQ(top->ALUCtrl, 1);
    EXPECT_EQ(top->ALUSrc, 0);
    EXPECT_EQ(top->ImmSrc, 2);
    EXPECT_EQ(top->PCSrc, 1);
}

TEST_F(ControlTestbench, ControlBNETest2)
{
    top->instr = 4195; // 00000000000000000001000001100011
    top->EQ = 1;
    top->eval();

    EXPECT_EQ(top->RegWrite, 0);
    EXPECT_EQ(top->ALUCtrl, 1);
    EXPECT_EQ(top->ALUSrc, 0);
    EXPECT_EQ(top->ImmSrc, 2);
    EXPECT_EQ(top->PCSrc, 0);
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
