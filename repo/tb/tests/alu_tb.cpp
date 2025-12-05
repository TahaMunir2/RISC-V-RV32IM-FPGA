
//Verifies ALU correctness for all supported operations.


#include "base_testbench.h"

unsigned int ticks = 0;

class AluTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->ALUop1 = 0;
        top->ALUop2 = 0;
        top->ALUCtrl = 0;
    }

    inline void load(uint32_t a, uint32_t b, uint32_t aluCtrl)
    {
        top->ALUop1  = a;
        top->ALUop2  = b;
        top->ALUCtrl = aluCtrl;
        top->eval();
    }
};

//we will test the 13 different functionalities of the ALU:

// 1) add
TEST_F(AluTestbench, AddPositive)
{
    load(10,5, 0b0000); // 10+5 =15
    EXPECT_EQ(top->ALUout, 15);
}

//special case where we add the biggest possible 32 bit integer and 1 to test the wrap around behaviour
TEST_F(AluTestbench, AddWrap)
{
    load(0xFFFFFFFF, 1, 0b0000);
    EXPECT_EQ(top->ALUout, 0);
}

// 2)sub
TEST_F(AluTestbench, SubPositive)
{
    load(10, 3, 0b0001);
    EXPECT_EQ(top->ALUout, 7);
}
//special case where we get a negative result 
TEST_F(AluTestbench, SubNegative)
{
    load(3, 10, 0b0001);
    EXPECT_EQ(top->ALUout, uint32_t(-7));
}

//BITWISE OPERATIONS:

//3)and
TEST_F(AluTestbench,AndOp)
{
    load(0b1010, 0b0110, 0b0010);
    EXPECT_EQ(top->ALUout, 0b0010);
}

//4-or
TEST_F(AluTestbench,OrOp)
{
    load(0b1010, 0b0110, 0b0011);
    EXPECT_EQ(top->ALUout, 0b1110);
}

//5)xor
TEST_F(AluTestbench, XorOp)
{
    load(0b1010, 0b0110, 0b0100);
    EXPECT_EQ(top->ALUout, 0b1100);
}


//shift operations:
//6)sll
TEST_F(AluTestbench, ShiftLeftLogical)
{
    load(0x00000001, 3, 0b0101);
    EXPECT_EQ(top->ALUout, 0x00000008);
}


//7-srl

TEST_F(AluTestbench, ShiftRight_Logical)
{
    load(0x10, 2, 0b0110);
    EXPECT_EQ(top->ALUout, 0x4);
}

//8-sra
TEST_F(AluTestbench, ShiftRight_Arithmetic)
{
    load(0xFFFFFFFF, 1, 0b0111);
    EXPECT_EQ(top->ALUout, 0xFFFFFFFF);
}

//9)SLT (signed)
TEST_F(AluTestbench, SetLessThan_Signed)
{
    load(-5, 10, 0b1000);
    EXPECT_EQ(top->ALUout, 1);
}
//opposite case
TEST_F(AluTestbench, SetLessThan_SignedFalse)
{
    load(20, -1, 0b1000);
    EXPECT_EQ(top->ALUout, 0);
}

//10) SLTU(unsigned)
TEST_F(AluTestbench, SetLessThan_Unsigned)
{
    load(5, 10, 0b1001);
    EXPECT_EQ(top->ALUout, 1);
}

TEST_F(AluTestbench, SetLessThan_UnsignedFalse)
{
    load(10, 5, 0b1001);
    EXPECT_EQ(top->ALUout, 0);
}

//11- LUI passthrough (no actions taken on the data)
TEST_F(AluTestbench, LuiImmediate)
{
    load(0,0xABCDE000, 0b1010);
    EXPECT_EQ(top->ALUout, 0xABCDE000); //same exact data as the one passed in input as b 
}


//12)AUIPC:A +B- 4
TEST_F(AluTestbench, Auipc)
{
    load(100, 20, 0b1011);
    EXPECT_EQ(top->ALUout, 100 + 20 - 4);
}

//13)Equality using flags
TEST_F(AluTestbench, EqualTrue)
{
    load(10,10,0);
    EXPECT_EQ(top->EQ, 1);
}

TEST_F(AluTestbench, EqualFalse)
{
    load(1,2,0);
    EXPECT_EQ(top->EQ, 0);
}

TEST_F(AluTestbench, SignedLessTrue)
{
    load(-5, 3, 0);
    EXPECT_EQ(top->LT, 1);
}

TEST_F(AluTestbench, UnsignedLessTrue)
{
    load(3,10,0);
    EXPECT_EQ(top->LTU, 1);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
