#include "testbench.h"
#include <cstdlib>

#define CYCLES 1000

unsigned int ticks = 0;

class IcacheTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
    }
};


TEST_F(IcacheTestbench, IcacheTest0)
{
    top->clk          = 0;
    top->fetch        = 0;
    top->LoadSize     = 0b10;
    top->LoadUnsigned = 1;
    top->ready        = 0;
    top->addr         = 0x00000000;

    top->addr = 0x00F00000;
    top->fetch = 1;

    runSimulation(1);
    //testing stall on non valid fetch (read)
    EXPECT_EQ(top->stall, 1)
        << "Cache should assert stall on first access to a cold line (miss 1).";

    //checking that the l1 cache asserts a fetch request on the l2 cache
    EXPECT_EQ(top->l2_fetch, 1)
        << "Cache should assert l2_fetch on a miss.";    

    //checkin that the l1 cache asserts the correct l2_addr for the l2 to fetch from
    EXPECT_EQ(top->l2_addr, 0x00F00000)
        << "Cache should assert l2_fetch using the correct l2_addr";

    runSimulation(1);
    //testing stall works until ready asserted
    EXPECT_EQ(top->stall, 1)
        << "Cache should assert stall until ready is asserted (miss 1).";

    for (int i = 0; i < 4; ++i) {
        top->line_from_mem[i] = 0x00FFFFFF; //should write this into set 0 way 0 with tag = '0
    }

    top->ready = 1; //L2 cache has found the value and inputted it into line_from_mem. Hazard unit readys L1 cache

    runSimulation(1);
    //testing stall deassertion
    EXPECT_EQ(top->stall, 0)
        << "Cache should deassert stall on subsequent access to the same line after data is retrieved from L2 (hit).";

    //testing l2_fetch deassertion
    EXPECT_EQ(top->l2_fetch, 0)
        << "Cache should deassert l2_fetch on subsequent access to the same line after data is retrieved from L2 (hit).";

    top->ready = 0;
    top->addr = 0x00000010; //address goes to set 1, block 0
    top->fetch = 0;

    runSimulation(1);
    //checking stall assertion on fetch = 0
    EXPECT_EQ(top->stall, 0)
        << "Cache should not stall when fetch is deasserted.";
    
    top->fetch = 1;
    top->addr = 0x00F00000;
    
    runSimulation(1);
    //testing correct word being loaded into correct position
    EXPECT_EQ(top->data_out, 0x00FFFFFF)
        << "Wrong value read.";

    top->LoadSize = 0b01;

    runSimulation(1);
    //testing LoadSize and LoadUnsigned functionality
    EXPECT_EQ(top->data_out, 0x0000FFFF)
        << "Wrong value read.";
    
    top->LoadUnsigned = 0;

    runSimulation(1);
    //testing LoadUnsigned functionality
    EXPECT_EQ(top->data_out, 0xFFFFFFFF)
        << "Wrong data value read.";

    top->LoadSize = 0b00;
    top->LoadUnsigned = 1;

    runSimulation(1);
    //testing LoadSize functionality
    EXPECT_EQ(top->data_out, 0x000000FF)
        << "Wrong data value read.";

    top->addr = 0xF0000000;
    top->LoadSize = 0b10;

    runSimulation(1);
    //testing stall on non valid fetch (write)
    EXPECT_EQ(top->stall, 1)
        << "Cache should assert stall on first access to a cold line (miss 2).";
    
    for (int i = 0; i < 4; ++i) {
        top->line_from_mem[i] = 0x00000FFF; //should write this into set 0 way 1 with tag = addr[31:11]
    }

    top->ready = 1;

    runSimulation(1);
    //testing stall deassertion. Cache should write to set 0, way 1.
    EXPECT_EQ(top->stall, 0)
        << "Cache should deassert stall on subsequent access to the same line (hit).";

    top->ready = 0;

    runSimulation(1);
    //testing correct value being written in
    EXPECT_EQ(top->data_out, 0x00000FFF)
        << "Wrong data value read.";

    top->addr = 0xF0000004;

    runSimulation(1);
    //testing that the cache wrote in the next 4 words as well
    EXPECT_EQ(top->data_out, 0x00000FFF)
        << "Wrong data value read.";

    top->addr = 0x00F00000;

    runSimulation(1);
    //should read the value in set 0, way 0
    EXPECT_EQ(top->data_out, 0x00FFFFFF)
        << "Wrong data value read.";

    //now since way 1 was least recently used, the L1 cache should evict way 1
    //if i try to write a value from the L2 cache into set 0.

    top->addr = 0x0F000000;

    runSimulation(1);
    //should stall since no value with correct tag found in set 0.
    EXPECT_EQ(top->stall, 1)
        << "Cache should assert stall on first access to a cold line (miss 3).";
    
    for (int i = 0; i < 4; ++i) {
        top->line_from_mem[i] = 0x000000FF; //should write this into set 0 way 1
    }

    top->ready = 1;

    runSimulation(1);
    //testing stall deassertion. Cache should also write to set 0, way 1, but shouldn't read new value yet.
    EXPECT_EQ(top->stall, 0)
        << "Cache should deassert stall on subsequent access to the same line (hit).";

    top->ready = 0;

    runSimulation(1);
    //should read the new value just inputted
    EXPECT_EQ(top->data_out, 0x000000FF)
        << "Wrong data value read.";

    top->addr = 0x00F00000;

    runSimulation(1);
    //checking that the previous most recently used value is still in the cache
    //and that LRU replacement was successful
    EXPECT_EQ(top->data_out, 0x00FFFFFF)
        << "Wrong data value read.";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}