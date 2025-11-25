#include "verilated.h"
#include "cpu_testbench.h"   // your header
#include "vbuddy.cpp"        // or the correct vbuddy include in your repo

// TODO: change this to your real top.sv signal name
// e.g. if top.sv has: output [7:0] io_leds;
// then use:  #define F1_SIGNAL io_leds
#define F1_SIGNAL a0   // <-- REPLACE THIS with the real name

TEST_F(CpuTestbench, F1StartLights)
{
    // Assemble asm/f1start.s -> program.hex
    setupTest("f1");

    // Create Vdut, set up tracing, reset, etc.
    initSimulation();

    // Initialise VBuddy
    vbdOpen();
    vbdSetMode(1);         // if your vbuddy lib needs this; otherwise remove

    // Main simulation loop
    for (int i = 0; i < MAX_SIM_CYCLES && !Verilated::gotFinish(); ++i)
    {
        // Advance one clock cycle
        runSimulation(1);

        // Drive the bargraph with the lower 8 bits of the F1 output signal
        vbdBar(top_->F1_SIGNAL & 0xFF);
        //            ^^^^^^^^
        //   this expands to e.g. top_->io_leds & 0xFF after you fix the #define
    }

    vbdClose();

    // CpuTestbench::TearDown() will be called by gtest automatically
}
