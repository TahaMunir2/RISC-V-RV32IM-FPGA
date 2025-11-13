// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_block.h for the primary calling header

#include "verilated.h"

#include "Vpc_block__Syms.h"
#include "Vpc_block___024root.h"

void Vpc_block___024root___ctor_var_reset(Vpc_block___024root* vlSelf);

Vpc_block___024root::Vpc_block___024root(Vpc_block__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpc_block___024root___ctor_var_reset(this);
}

void Vpc_block___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpc_block___024root::~Vpc_block___024root() {
}
