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
        top->ALUCtrl = 0;
        top->ALUop1 = 0;
        top->ALUop2 = 0;
    }
};

TEST_F(ALUTestbench, ALUTest0) // test addition
{
    top->ALUCtrl = 0;
    top->ALUop1 = 5;
    top->ALUop2 = 5;

    top->eval();

    EXPECT_EQ(top->ALUout, 10);
}

TEST_F(ALUTestbench, ALUTest1) // eq flag raised
{
    top->ALUCtrl = 1;
    top->ALUop1 = 5;
    top->ALUop2 = 5;

    top->eval();

    EXPECT_EQ(top->EQ, 1);
}

TEST_F(ALUTestbench, ALUTest2) // eq flag reset
{
    top->ALUCtrl = 1;
    top->ALUop1 = 5;
    top->ALUop2 = 4;

    top->eval();

    EXPECT_EQ(top->EQ, 0);
}

TEST_F(ALUTestbench, ALUTest3) // MUL
{
    top->ALUCtrl = 12;
    top->ALUop1 = 5;
    top->ALUop2 = 4;

    top->eval();

    EXPECT_EQ(top->ALUout, 20);
}


TEST_F(ALUTestbench, ALUTest4) // MULH
{
    top->ALUCtrl = 13;
    top->ALUop1 = 0x0FFF0000;
    top->ALUop2 = 256;

    top->eval();

    EXPECT_EQ(top->ALUout, 0xF);
}

TEST_F(ALUTestbench, ALUTest5) // MULH
{
    top->ALUCtrl = 13;
    top->ALUop1 = 0xFFFFFFF0;
    top->ALUop2 = 0xFFFFFFF0;

    top->eval();

    EXPECT_EQ(top->ALUout, 0);
}

TEST_F(ALUTestbench, ALUTest6) // DIV
{
    top->ALUCtrl = 16;
    top->ALUop1 = 0xFFFFFFF0;
    top->ALUop2 = 0xFFFFFFF0;

    top->eval();

    EXPECT_EQ(top->ALUout, 1);
}

TEST_F(ALUTestbench, ALUTest7) // REM
{
    top->ALUCtrl = 18;
    top->ALUop1 = 0xFFFFFFFD;
    top->ALUop2 = 0xFFFFFFFE;

    top->eval();

    EXPECT_EQ(top->ALUout, 0xFFFFFFFF);
}

TEST_F(ALUTestbench, ALUTest8) // REMU
{
    top->ALUCtrl = 19;
    top->ALUop1 = 0xFFFFFFFD;
    top->ALUop2 = 0xFFFFFFFE;

    top->eval();

    EXPECT_EQ(top->ALUout, 0xFFFFFFFD);
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
