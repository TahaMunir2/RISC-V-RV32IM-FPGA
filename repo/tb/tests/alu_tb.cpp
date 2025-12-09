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

TEST_F(ALUTestbench, ALUTest9) // MULHSU: high 32 bits of signed * unsigned
{
    top->ALUCtrl = 14;              // MULHSU
    top->ALUop1  = 0xFFFFFFFF;      // -1 (signed)
    top->ALUop2  = 0x00000002;      // 2 (unsigned)

    top->eval();

    // (-1 * 2) = -2 = 0xFFFFFFFFFFFFFFFE -> high 32 bits = 0xFFFFFFFF
    EXPECT_EQ(top->ALUout, 0xFFFFFFFF);
}

TEST_F(ALUTestbench, ALUTest10) // MULHU: high 32 bits of unsigned * unsigned
{
    top->ALUCtrl = 15;              // MULHU
    top->ALUop1  = 0x80000000;      // 2^31
    top->ALUop2  = 0x00000002;      // 2

    top->eval();

    // 2^31 * 2 = 2^32 = 0x0000000100000000 -> high 32 bits = 0x00000001
    EXPECT_EQ(top->ALUout, 0x00000001);
}

TEST_F(ALUTestbench, ALUTest11) // DIV: negative / positive
{
    top->ALUCtrl = 16;              // DIV
    top->ALUop1  = 0xFFFFFFF9;      // -7 (signed)
    top->ALUop2  = 0x00000002;      // 2

    top->eval();

    // -7 / 2 = -3 (trunc toward zero) = 0xFFFFFFFD
    EXPECT_EQ(top->ALUout, 0xFFFFFFFD);
}

TEST_F(ALUTestbench, ALUTest12) // DIV: overflow case -2^31 / -1
{
    top->ALUCtrl = 16;              // DIV
    top->ALUop1  = 0x80000000;      // -2^31
    top->ALUop2  = 0xFFFFFFFF;      // -1

    top->eval();

    // Special case: result should be -2^31 again
    EXPECT_EQ(top->ALUout, 0x80000000);
}

TEST_F(ALUTestbench, ALUTest13) // DIV: divide by zero
{
    top->ALUCtrl = 16;              // DIV
    top->ALUop1  = 0x12345678;
    top->ALUop2  = 0x00000000;      // divisor = 0

    top->eval();

    // RISC-V / your ALU spec: DIV by zero -> -1
    EXPECT_EQ(top->ALUout, 0xFFFFFFFF);
}

TEST_F(ALUTestbench, ALUTest14) // DIVU: simple unsigned division
{
    top->ALUCtrl = 17;              // DIVU
    top->ALUop1  = 10;              // 0x0000000A
    top->ALUop2  = 3;               // 0x00000003

    top->eval();

    // 10 / 3 = 3 (unsigned)
    EXPECT_EQ(top->ALUout, 0x00000003);
}

TEST_F(ALUTestbench, ALUTest15) // DIVU: divide by zero
{
    top->ALUCtrl = 17;              // DIVU
    top->ALUop1  = 0x87654321;
    top->ALUop2  = 0x00000000;      // divisor = 0

    top->eval();

    // DIVU by zero -> -1 (all ones)
    EXPECT_EQ(top->ALUout, 0xFFFFFFFF);
}

TEST_F(ALUTestbench, ALUTest16) // REM: positive % negative
{
    top->ALUCtrl = 18;              // REM
    top->ALUop1  = 7;               // dividend
    top->ALUop2  = 0xFFFFFFFE;      // -2

    top->eval();

    // - RISC-V signed semantics: quotient trunc toward 0
    //   7 / -2 = -3, remainder = 7 - (-3 * -2) = 1
    EXPECT_EQ(top->ALUout, 0x00000001);
}

TEST_F(ALUTestbench, ALUTest17) // REM: remainder when divisor is zero
{
    top->ALUCtrl = 18;              // REM
    top->ALUop1  = 0x12345678;      // dividend
    top->ALUop2  = 0x00000000;      // divisor = 0

    top->eval();

    // REM by zero -> returns dividend
    EXPECT_EQ(top->ALUout, 0x12345678);
}

TEST_F(ALUTestbench, ALUTest18) // REMU: simple unsigned remainder
{
    top->ALUCtrl = 19;              // REMU
    top->ALUop1  = 10;              // 0x0000000A
    top->ALUop2  = 3;               // 0x00000003

    top->eval();

    // 10 % 3 = 1 (unsigned)
    EXPECT_EQ(top->ALUout, 0x00000001);
}

TEST_F(ALUTestbench, ALUTest19) // REMU: remainder when divisor is zero
{
    top->ALUCtrl = 19;              // REMU
    top->ALUop1  = 0xCAFEBABE;      // dividend
    top->ALUop2  = 0x00000000;      // divisor = 0

    top->eval();

    // REMU by zero -> returns dividend
    EXPECT_EQ(top->ALUout, 0xCAFEBABE);
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
