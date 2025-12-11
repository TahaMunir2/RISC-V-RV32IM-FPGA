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

TEST_F(CpuTestbench, Zba)
{
    setupTest("shadd");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(7);
    EXPECT_EQ(top_->a0, 135); // does sh1add
    runSimulation(1);
    EXPECT_EQ(top_->a0, 263); // does sh2add
    runSimulation(1);
    EXPECT_EQ(top_->a0, 519); // does sh3add
}

TEST_F(CpuTestbench, TestCSR)
{
    setupTest("csr");     
    initSimulation();
    runSimulation(CYCLES);         
    EXPECT_EQ(top_->a0, 305463040); // Expect 0x1234FF00
}



TEST_F(CpuTestbench, TestInterrupt)
{
    setupTest("interrupt_test"); 
    initSimulation();
    runSimulation(100);
    top_->trigger = 1;
    runSimulation(5); 
    top_->trigger = 0; 
    runSimulation(MAX_SIM_CYCLES);
    EXPECT_EQ(top_->a0, 3405691582); // 0xCAFEBABE
}


TEST_F(CpuTestbench, Timer)
{
    setupTest("timer");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(100);
    EXPECT_EQ(top_->leds, 1); 
    runSimulation(450);
    EXPECT_EQ(top_->leds, 255); 
    runSimulation(550);
    
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
