#include <cstdlib>
#include <utility>

#include "cpu_testbench.h"

#define CYCLES 10000

TEST_F(CpuTestbench, Test_verysimple_addi)
{
    setupTest("");
    initSimulation("superscalar_test1");
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 10);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
