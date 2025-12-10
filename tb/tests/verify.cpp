#include <cstdlib>
#include <utility>

#include "cpu_testbench.h"

#define CYCLES 10000

TEST_F(CpuTestbench, TestAddiBne)
{
    setupTest("1_addi_bne");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 254);
}

TEST_F(CpuTestbench, TestLiAdd)
{
    setupTest("2_li_add");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 1000);
}

TEST_F(CpuTestbench, TestLbuSb)
{
    setupTest("3_lbu_sb");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 300);
}

TEST_F(CpuTestbench, TestJalRet)
{
    setupTest("4_jal_ret");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 53);
}

TEST_F(CpuTestbench, TestPdf)
{
    setupTest("5_pdf");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES * 100);
    EXPECT_EQ(top_->a0, 15363);
}

TEST_F(CpuTestbench, Testbeq)
{
    setupTest("6_beq");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 2);
}

TEST_F(CpuTestbench, TestSBandLW)
{
    setupTest("7_sb_lw");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 257);
}

TEST_F(CpuTestbench, TestBranchInequalities)
{
    setupTest("8_inequality_branching");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 2);
}

TEST_F(CpuTestbench, TestAUIPC)
{
    setupTest("9_auipc");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 3217035264);
}

TEST_F(CpuTestbench, TestShift)
{
    setupTest("10_shifts");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 8);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
