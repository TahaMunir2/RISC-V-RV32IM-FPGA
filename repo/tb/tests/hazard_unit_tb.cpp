#include "base_testbench.h"

unsigned int ticks = 0;

class HazardUnitTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->rs1D = 0;
        top->rs2D = 0;
        top->rs1E = 0;
        top->rs2E = 0;
        top->rdM  = 0;
        top->rdE  = 0;
        top->rdWB = 0;
        top->regWriteM         = 0;
        top->resultSrCE        = 0;
        top->WriteBack_Regfile = 0;
        top->PCSrcE            = 0;
    }

    inline void load(uint32_t rs1D,
                     uint32_t rs2D,
                     uint32_t rs1E,
                     uint32_t rs2E,
                     uint32_t rdM,
                     uint32_t rdE,
                     uint32_t rdWB,
                     uint32_t regWriteM,
                     uint32_t resultSrCE,
                     uint32_t writeBackRegfile,
                     uint32_t pcSrcE)
    {
        top->rs1D = rs1D;
        top->rs2D = rs2D;
        top->rs1E = rs1E;
        top->rs2E = rs2E;
        top->rdM  = rdM;
        top->rdE  = rdE;
        top->rdWB = rdWB;
        top->regWriteM         = regWriteM;
        top->resultSrCE        = resultSrCE;
        top->WriteBack_Regfile = writeBackRegfile;
        top->PCSrcE            = pcSrcE;
        top->eval();
    }
};

TEST_F(HazardUnitTestbench, ForwardOperand1FromMem)
{
    load(0,0,5,0,5,0,0,1,0,0,0);
    EXPECT_EQ(top->selectline1, 0b10);
    EXPECT_EQ(top->selectline2, 0b00);
}

TEST_F(HazardUnitTestbench, LoadUseStall)
{
    load(3,0,0,0,0,3,0,0,0b01,0,0);
    EXPECT_EQ(top->PCWrite, 0);
    EXPECT_EQ(top->F_Write, 0);
    EXPECT_EQ(top->flush_d_exec, 1);
    EXPECT_EQ(top->flush_f_d, 0);
}

TEST_F(HazardUnitTestbench, ForwardOperand2FromWb)
{
    load(0, 0, 0, 9, 0, 0, 9, 0, 0, 1, 0);
    EXPECT_EQ(top->selectline1, 0b00);
    EXPECT_EQ(top->selectline2, 0b01);
    EXPECT_EQ(top->PCWrite, 1);
    EXPECT_EQ(top->F_Write, 1);
    EXPECT_EQ(top->flush_d_exec, 0);
    EXPECT_EQ(top->flush_f_d, 0);
}

TEST_F(HazardUnitTestbench, BranchFlushWithoutStall)
{
    load(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b01);
    EXPECT_EQ(top->flush_f_d, 1);
    EXPECT_EQ(top->flush_d_exec, 1);
    EXPECT_EQ(top->PCWrite, 1);
    EXPECT_EQ(top->F_Write, 1);
    EXPECT_EQ(top->selectline1, 0b00);
    EXPECT_EQ(top->selectline2, 0b00);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
