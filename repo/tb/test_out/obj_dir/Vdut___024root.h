// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"


class Vdut__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(fetch,0,0);
    VL_IN8(SizeWrite_m,1,0);
    VL_IN8(MemWrite_m,0,0);
    VL_IN8(LoadSize,1,0);
    VL_IN8(LoadUnsigned,0,0);
    VL_OUT8(write_back_en,0,0);
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
    CData/*6:0*/ l1d_cache__DOT____VdfgExtracted_h18ae9b83__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(addr,31,0);
    VL_IN(wd,31,0);
    VL_INW(line_from_mem,127,0,4);
    VL_OUT(data_out,31,0);
    VL_OUTW(write_back,127,0,4);
    VlWide<4>/*127:0*/ l1d_cache__DOT__write_data;
    VlWide<4>/*127:0*/ l1d_cache__DOT__wmask;
    IData/*31:0*/ l1d_cache__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<VlWide<10>/*302:0*/, 128> l1d_cache__DOT__cache;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* v__name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
