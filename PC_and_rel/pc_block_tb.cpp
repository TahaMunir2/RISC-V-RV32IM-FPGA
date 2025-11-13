#include "Vpc_block.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include "vbuddy.cpp"     // include vbuddy code
#define WIDTH 32
#define MAX_SIM_CYC 1000


int main (int argc, char **argv, char **env) {
    int tick;
    int clk;



    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vpc_block* top = new Vpc_block;
    //init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("pc_block.vcd");

    // init Vbuddy
    if (vbdOpen()!=1) return(-1);
    vbdHeader("L2T1: PC_block");
    //vbdSetMode(1);        // Flag mode set to one-shot

    //initialize simulation inputs
    top->clk = 0;
    top->rst = 0;
    top->Imm_op = 10;
    top->pc_src = 0;

    //run simulation for many clock cycles
    for(clk=0; clk<MAX_SIM_CYC; clk++){

        //dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*clk+tick);
            top->clk = !top->clk;
            top->eval ();
        }

        //send count value to Vbuddy
        vbdPlot(int(top->pc), 0, 10000000000000000000000000000000000000000000000000);
        

        top->pc_src = vbdFlag();
        vbdCycle(clk);


        if (Verilated::gotFinish()||(vbdGetkey()=='q')) exit(0);
    }
    vbdClose();
    tfp->close();
    exit(0);
}

