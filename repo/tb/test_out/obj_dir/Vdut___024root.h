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
    VL_IN8(l1write_back_en,0,0);
    VL_IN8(ready,0,0);
    VL_IN8(wb_ready,0,0);
    VL_OUT8(ready_i,0,0);
    VL_OUT8(ready_d,0,0);
    VL_OUT8(wb_ready_d,0,0);
    VL_OUT8(write_back_en,0,0);
    VL_OUT8(main_mem_addr,0,0);
    VL_OUT8(main_mem_fetch,0,0);
    CData/*0:0*/ l2_cache__DOT__wr_en;
    CData/*0:0*/ l2_cache__DOT__rd_en;
    CData/*0:0*/ l2_cache__DOT__wr_wb;
    CData/*1:0*/ l2_cache__DOT__way_rd;
    CData/*0:0*/ l2_cache__DOT__fetch;
    CData/*0:0*/ l2_cache__DOT__req_d;
    CData/*0:0*/ l2_cache__DOT__req_i;
    CData/*0:0*/ l2_cache__DOT__l1write;
    CData/*0:0*/ l2_cache__DOT__hit0;
    CData/*0:0*/ l2_cache__DOT__hit1;
    CData/*0:0*/ l2_cache__DOT__hit2;
    CData/*0:0*/ l2_cache__DOT__hit3;
    CData/*0:0*/ l2_cache__DOT__valid0;
    CData/*0:0*/ l2_cache__DOT__valid1;
    CData/*0:0*/ l2_cache__DOT__valid2;
    CData/*0:0*/ l2_cache__DOT__valid3;
    CData/*0:0*/ l2_cache__DOT__miss;
    CData/*0:0*/ l2_cache__DOT__evict;
    CData/*0:0*/ l2_cache__DOT__l1write_buffer;
    CData/*7:0*/ l2_cache__DOT__set_wb;
    CData/*2:0*/ l2_cache__DOT__block_offset_wb;
    CData/*0:0*/ l2_cache__DOT__hit0_wb;
    CData/*0:0*/ l2_cache__DOT__hit1_wb;
    CData/*0:0*/ l2_cache__DOT__hit2_wb;
    CData/*0:0*/ l2_cache__DOT__hit3_wb;
    CData/*0:0*/ l2_cache__DOT__miss_wb;
    CData/*1:0*/ l2_cache__DOT__way;
    CData/*7:0*/ l2_cache__DOT__set;
    CData/*2:0*/ l2_cache__DOT__block_offset;
    CData/*1:0*/ l2_cache__DOT__l2write_buffer;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(addr_i,31,0);
    VL_IN(addr_d,31,0);
    VL_INW(line_from_mem,255,0,8);
    VL_INW(l1write_back_data,127,0,4);
    VL_IN(l1write_back_addr,31,0);
    VL_OUTW(data_out,127,0,4);
    VL_OUTW(write_back_data,127,0,4);
    VL_OUT(write_back_addr,31,0);
    VlWide<8>/*255:0*/ l2_cache__DOT__write_data;
    VlWide<8>/*255:0*/ l2_cache__DOT__wmask;
    IData/*31:0*/ l2_cache__DOT__addr;
    VlWide<4>/*127:0*/ l2_cache__DOT__l1write_back_data_buffer;
    IData/*31:0*/ l2_cache__DOT__l1write_back_addr_buffer;
    IData/*18:0*/ l2_cache__DOT__tag_bits_wb;
    IData/*18:0*/ l2_cache__DOT__tag_bits;
    VlWide<8>/*255:0*/ l2_cache__DOT__l2write_back_data_buffer;
    IData/*31:0*/ l2_cache__DOT__l2write_back_addr_buffer;
    IData/*31:0*/ l2_cache__DOT__unnamedblk1__DOT__i;
    VlUnpacked<VlWide<35>/*1113:0*/, 256> l2_cache__DOT__cache;
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
