/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class DataMemTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {

        // output: out
    }
};

TEST_F(DataMemTestbench, Mux0WorksTest)
{
    top->A = 0; // first address which if FE FD FD FD

    top->eval();

    EXPECT_EQ(top->dout, 4278058493); // FE FD FD FD
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
