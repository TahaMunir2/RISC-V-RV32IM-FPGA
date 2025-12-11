#pragma once

#include <memory>

#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "gtest/gtest.h"

#define MAX_SIM_CYCLES 10000

extern unsigned int ticks;

class BaseTestbench : public ::testing::Test
{
public:
    void SetUp() override
    {
        top = std::make_unique<Vdut>();

        tfp = std::make_unique<VerilatedVcdC>();
        Verilated::traceEverOn(true);
        top->trace(tfp.get(), 99);
        tfp->open("waveform.vcd");

        initializeInputs();
    }

    void TearDown() override
    {
        top->final();

        tfp->close();

    }

    virtual void initializeInputs() = 0;

protected:
    std::unique_ptr<Vdut> top;

    std::unique_ptr<VerilatedVcdC> tfp;

};