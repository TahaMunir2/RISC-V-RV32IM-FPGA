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
    VL_IN8(fetch_i,0,0);
    VL_IN8(fetch_d,0,0);
    VL_IN8(ready,0,0);
    VL_IN8(l1write_back_en,0,0);
    VL_IN8(wb_ready,0,0);
    VL_OUT8(ready_i,0,0);
    VL_OUT8(ready_d,0,0);
    VL_OUT8(wb_ready_d,0,0);
    VL_OUT8(write_back_en,0,0);
    VL_OUT8(main_mem_fetch,0,0);
    CData/*0:0*/ l2_cache__DOT__req_valid;
    CData/*0:0*/ l2_cache__DOT__req_is_i;
    CData/*3:0*/ l2_cache__DOT__hit_vec;
    CData/*0:0*/ l2_cache__DOT__req_hit;
    CData/*1:0*/ l2_cache__DOT__hit_way;
    CData/*0:0*/ l2_cache__DOT__miss_pending;
    CData/*0:0*/ l2_cache__DOT__miss_is_i;
    CData/*7:0*/ l2_cache__DOT__miss_set;
    CData/*1:0*/ l2_cache__DOT__miss_way;
    CData/*0:0*/ l2_cache__DOT__l1_wb_pending;
    CData/*7:0*/ l2_cache__DOT__l1_wb_set;
    CData/*2:0*/ l2_cache__DOT__l1_wb_off;
    CData/*3:0*/ l2_cache__DOT__l1_wb_hit_vec;
    CData/*0:0*/ l2_cache__DOT__l1_wb_hit;
    CData/*1:0*/ l2_cache__DOT__l1_wb_hit_way;
    CData/*0:0*/ l2_cache__DOT__evict_wb_pending;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(addr_i,31,0);
    VL_IN(addr_d,31,0);
    VL_INW(line_from_mem,255,0,8);
    VL_INW(l1write_back_data,127,0,4);
    VL_IN(l1write_back_addr,31,0);
    VL_OUTW(data_out,127,0,4);
    VL_OUTW(write_back_data,127,0,4);
    VL_OUT(write_back_addr,31,0);
    VL_OUT(main_mem_addr,31,0);
    IData/*31:0*/ l2_cache__DOT__req_addr;
    IData/*31:0*/ l2_cache__DOT__miss_addr;
    IData/*18:0*/ l2_cache__DOT__miss_tag;
    IData/*31:0*/ l2_cache__DOT__l1_wb_addr;
    VlWide<4>/*127:0*/ l2_cache__DOT__l1_wb_data;
    IData/*31:0*/ l2_cache__DOT__evict_wb_addr;
    VlWide<4>/*127:0*/ l2_cache__DOT__evict_wb_data;
    VlWide<8>/*255:0*/ l2_cache__DOT__hit_line;
    IData/*31:0*/ l2_cache__DOT__i;
    IData/*31:0*/ l2_cache__DOT__j;
    VlUnpacked<VlUnpacked<VlWide<9>/*276:0*/, 4>, 256> l2_cache__DOT__cache;
    VlUnpacked<CData/*1:0*/, 256> l2_cache__DOT__rr_ptr;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

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
