#include "base_testbench.h"
#include <cstdlib>

#define CYCLES 1000

unsigned int ticks = 0;

class CpuTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 1;
        top->rst = 0;
    }
};


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
    EXPECT_EQ(top_->a0, 4080);
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
    EXPECT_EQ(top_->a0, 4097);
}

TEST_F(CpuTestbench, TestShift)
{
    setupTest("10_unsigned_immediate_shift");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 2);
}

TEST_F(CpuTestbench, TestPdf2)
{
    setupTest("a0test");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 155);
}

// Note this is how we are going to test your CPU. Do not worry about this for
// now, as it requires a lot more instructions to function
// TEST_F(CpuTestbench, Return5Test)
// {
//     system("./compile.sh c/return_5.c");
//     runSimulation(100);
//     EXPECT_EQ(top->a0, 5);
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
