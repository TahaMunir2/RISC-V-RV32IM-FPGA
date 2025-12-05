#include <cstdlib>
#include <utility>

#include "cpu_testbench.h"

#define CYCLES 10000

TEST_F(CpuTestbench, TestLiAdd)
{
    setupTest("2_li_add");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 1000);
}

TEST_F(CpuTestbench, TestSubAdd)
{
    setupTest("sup_sub_add");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 4);
}

TEST_F(CpuTestbench, TestRAWChain)
{
    setupTest("straight_raw_chain");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 24);
}

TEST_F(CpuTestbench, SimpleWAW)
{
    setupTest("waw_simple");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 99);
}

TEST_F(CpuTestbench, warsimple)
{
    setupTest("war_simple");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 5);
}

TEST_F(CpuTestbench,parrallelism)
{
    setupTest("parrallelism");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 40);
}

TEST_F(CpuTestbench, ReUsingRegisters)
{
    setupTest("reg_reuse");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 100);
}

TEST_F(CpuTestbench, logicalops)
{
    setupTest("logical");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 100);
}

TEST_F(CpuTestbench, shifts)
{
    setupTest("sup_shifts");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 128);
}

TEST_F(CpuTestbench, complexshifts)
{
    setupTest("complexshifts");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 44);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
