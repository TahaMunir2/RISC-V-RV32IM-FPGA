// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"

class Vdut__Syms;

class Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(fetch,0,0);
    VL_IN8(SizeWrite_m,1,0);
    VL_IN8(MemWrite_m,0,0);
    VL_IN8(LoadSize,1,0);
    VL_IN8(LoadUnsigned,0,0);
    VL_IN8(ready,0,0);
    VL_OUT8(write_back_en,0,0);
    VL_OUT8(l2_fetch,0,0);
    VL_OUT8(stall,0,0);
    CData/*0:0*/ l1d_cache__DOT__wr_en;
    CData/*0:0*/ l1d_cache__DOT__rd_en;
    CData/*0:0*/ l1d_cache__DOT__way;
    CData/*0:0*/ l1d_cache__DOT__hit0;
    CData/*0:0*/ l1d_cache__DOT__hit1;
    CData/*0:0*/ l1d_cache__DOT__valid0;
    CData/*0:0*/ l1d_cache__DOT__valid1;
    CData/*0:0*/ l1d_cache__DOT__miss;
    CData/*6:0*/ l1d_cache__DOT__bottom_bit;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(addr,31,0);
    VL_IN(wd,31,0);
    VL_INW(line_from_mem,127,0,4);
    VL_OUT(data_out,31,0);
    VL_OUTW(write_back,127,0,4);
    VL_OUT(write_back_addr,31,0);
    VL_OUT(l2_addr,31,0);
    VlWide<4>/*127:0*/ l1d_cache__DOT__write_data;
    VlWide<4>/*127:0*/ l1d_cache__DOT__wmask;
    IData/*31:0*/ l1d_cache__DOT__unnamedblk1__DOT__i;
    VlUnpacked<VlWide<10>/*302:0*/, 128> l1d_cache__DOT__cache;
    VlUnpacked<VlWide<10>/*302:0*/, 128> __Vchglast__TOP__l1d_cache__DOT__cache;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
