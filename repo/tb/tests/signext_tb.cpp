/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class SignextTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->ImmSrc = 0;
        // output: out
    }
};

TEST_F(SignextTestbench, SRC0Test1)
{
    top->instr = 4063236096; // F2300000

    top->eval();

    EXPECT_EQ(top->immext, 4294967075); // FFFFFF23
}


TEST_F(SignextTestbench, SRC0Test2)
{
    top->instr = 180097588; // instr[31] is 0 so imm = 0AB

    top->eval();

    EXPECT_EQ(top->immext, 171); // 000000AB
}



TEST_F(SignextTestbench, SRC1Test1)
{
    top->ImmSrc = 1;
    top->instr = 202506240; // 0C120000

    top->eval();

    EXPECT_EQ(top->immext, 192); // 000000C0
}



TEST_F(SignextTestbench, SRC1Test2)
{
    top->ImmSrc = 1;
    top->instr = 4229038080; // FC120000

    top->eval();

    EXPECT_EQ(top->immext, 4294967232); //FFFFFFC0
}

TEST_F(SignextTestbench, SRC2Test1)
{
    top->ImmSrc = 2;
    top->instr = 2113933056; // 01111110000000000000111100000000

    top->eval();

    EXPECT_EQ(top->immext, 2046); // 00000000000000000000011111111110
}



TEST_F(SignextTestbench, SRC2Test2)
{
    top->ImmSrc = 2;
    top->instr = 4261416832; // 11111110000000000000111110000000

    top->eval();

    EXPECT_EQ(top->immext, 4294967294); // 11111111111111111111111111111110
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
