#include "verilated.h"
#include "cpu_testbench.h"   // your header
#include "vbuddy.cpp"        // or the correct vbuddy include in your repo
#include <chrono>
#include <thread>

#define F1_SIGNAL a0


TEST_F(CpuTestbench, noisy)
{

    setupTest("5_pdf");
    setData("reference/noisy.mem");
    std::ignore = system("echo '=== data.hex head ===' && head -n 3 data.hex && echo '==============='");
    


    // Create Vdut, set up tracing, reset, etc.
    initSimulation();

    // Initialise VBuddy
    vbdOpen();
    vbdSetMode(1);
    vbdHeader("pdf test");


    const int MAX_FUNC_CYC = 1000650;   // give pdf.s time to build the PDF
    int  bins = 0;                          // display-cycle counter
    bool display = false;
    int  prev_a0 = top_->a0;        // value of a0 before display phase
    
    // Main simulation loop
    for (int i = 0;i <MAX_FUNC_CYC && !Verilated::gotFinish(); ++i)
    {

        // Advance one clock cycle
        runSimulation(1);



        // detect when program enters the display loop:
        // display is the first time the program mutates a0
        if (!display && top_->a0 != prev_a0) {
            prev_a0 = top_->a0;
            display = true;
        }

        if (display) {
            // pause control (rotary push button)
            // bool is_paused = vbdFlag();
            // can be driven using trigger (omitted for simplicity):
            // top_->trigger = is_paused;

            // if (!is_paused) {
                ++bins;

                // a0 only changes every 3 instructions in display loop
                // only plot every 3 simulation steps to get rid of the elongation of the shape
                 if (bins % 4 == 0) {
                    vbdCycle(i);
                    vbdPlot(int(top_->a0) & 0xFF, 0, 255);
                 }
            // }
        }
    }

    vbdClose();

    // CpuTestbench::TearDown() will be called by gtest automatically
}

// TEST_F(CpuTestbench, F1StartLights)
// {
//     setupTest("f1");

//     initSimulation();

//     // Initialise VBuddy
//     vbdOpen();
//     vbdSetMode(1);

//     // Main simulation loop
//     for (int i = 0; i < MAX_SIM_CYCLES && !Verilated::gotFinish(); ++i)
//     {
//         // delay introduced
//         std::this_thread::sleep_for(std::chrono::milliseconds(500));
//         // Advance one clock cycle
//         runSimulation(1);

//         // Drive the bargraph with the lower 8 bits of the F1 output signal
//         vbdBar(top_->F1_SIGNAL & 0xFF);
//         // & 0xFF is to truncate the result to fit the number of LEDs
//     }

//     vbdClose();

//     // CpuTestbench::TearDown() will be called by gtest automatically
// }
