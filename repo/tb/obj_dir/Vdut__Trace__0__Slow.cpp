// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+19,"clk", false,-1);
    tracep->declBit(c+20,"fetch", false,-1);
    tracep->declBus(c+21,"addr", false,-1, 31,0);
    tracep->declBus(c+22,"wd", false,-1, 31,0);
    tracep->declArray(c+23,"line_from_mem", false,-1, 127,0);
    tracep->declBus(c+27,"SizeWrite_m", false,-1, 1,0);
    tracep->declBit(c+28,"MemWrite_m", false,-1);
    tracep->declBus(c+29,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+30,"LoadUnsigned", false,-1);
    tracep->declBus(c+31,"data_out", false,-1, 31,0);
    tracep->declArray(c+32,"write_back", false,-1, 127,0);
    tracep->declBit(c+36,"write_back_en", false,-1);
    tracep->declBit(c+37,"stall", false,-1);
    tracep->pushNamePrefix("l1d_cache ");
    tracep->declBus(c+42,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+42,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+43,"BLOCK_SIZE", false,-1, 31,0);
    tracep->declBit(c+19,"clk", false,-1);
    tracep->declBit(c+20,"fetch", false,-1);
    tracep->declBus(c+21,"addr", false,-1, 31,0);
    tracep->declBus(c+22,"wd", false,-1, 31,0);
    tracep->declArray(c+23,"line_from_mem", false,-1, 127,0);
    tracep->declBus(c+27,"SizeWrite_m", false,-1, 1,0);
    tracep->declBit(c+28,"MemWrite_m", false,-1);
    tracep->declBus(c+29,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+30,"LoadUnsigned", false,-1);
    tracep->declBus(c+31,"data_out", false,-1, 31,0);
    tracep->declArray(c+32,"write_back", false,-1, 127,0);
    tracep->declBit(c+36,"write_back_en", false,-1);
    tracep->declBit(c+37,"stall", false,-1);
    tracep->declBit(c+2,"wr_en", false,-1);
    tracep->declBit(c+3,"rd_en", false,-1);
    tracep->declArray(c+4,"write_data", false,-1, 127,0);
    tracep->declBit(c+8,"way", false,-1);
    tracep->declBus(c+38,"tag_bits", false,-1, 31,11);
    tracep->declBus(c+39,"set", false,-1, 6,0);
    tracep->declBus(c+40,"block_offset", false,-1, 1,0);
    tracep->declBus(c+41,"byte_offset", false,-1, 1,0);
    tracep->declArray(c+9,"wmask", false,-1, 127,0);
    tracep->declBit(c+13,"hit0", false,-1);
    tracep->declBit(c+14,"hit1", false,-1);
    tracep->declBit(c+15,"valid0", false,-1);
    tracep->declBit(c+16,"valid1", false,-1);
    tracep->declBit(c+17,"miss", false,-1);
    tracep->declBus(c+18,"bottom_bit", false,-1, 6,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdut___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->l1d_cache__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+2,(vlSelf->l1d_cache__DOT__wr_en));
    bufp->fullBit(oldp+3,(vlSelf->l1d_cache__DOT__rd_en));
    bufp->fullWData(oldp+4,(vlSelf->l1d_cache__DOT__write_data),128);
    bufp->fullBit(oldp+8,(vlSelf->l1d_cache__DOT__way));
    bufp->fullWData(oldp+9,(vlSelf->l1d_cache__DOT__wmask),128);
    bufp->fullBit(oldp+13,(vlSelf->l1d_cache__DOT__hit0));
    bufp->fullBit(oldp+14,(vlSelf->l1d_cache__DOT__hit1));
    bufp->fullBit(oldp+15,(vlSelf->l1d_cache__DOT__valid0));
    bufp->fullBit(oldp+16,(vlSelf->l1d_cache__DOT__valid1));
    bufp->fullBit(oldp+17,(vlSelf->l1d_cache__DOT__miss));
    bufp->fullCData(oldp+18,(vlSelf->l1d_cache__DOT__bottom_bit),7);
    bufp->fullBit(oldp+19,(vlSelf->clk));
    bufp->fullBit(oldp+20,(vlSelf->fetch));
    bufp->fullIData(oldp+21,(vlSelf->addr),32);
    bufp->fullIData(oldp+22,(vlSelf->wd),32);
    bufp->fullWData(oldp+23,(vlSelf->line_from_mem),128);
    bufp->fullCData(oldp+27,(vlSelf->SizeWrite_m),2);
    bufp->fullBit(oldp+28,(vlSelf->MemWrite_m));
    bufp->fullCData(oldp+29,(vlSelf->LoadSize),2);
    bufp->fullBit(oldp+30,(vlSelf->LoadUnsigned));
    bufp->fullIData(oldp+31,(vlSelf->data_out),32);
    bufp->fullWData(oldp+32,(vlSelf->write_back),128);
    bufp->fullBit(oldp+36,(vlSelf->write_back_en));
    bufp->fullBit(oldp+37,(vlSelf->stall));
    bufp->fullIData(oldp+38,((vlSelf->addr >> 0xbU)),21);
    bufp->fullCData(oldp+39,((0x7fU & (vlSelf->addr 
                                       >> 4U))),7);
    bufp->fullCData(oldp+40,((3U & (vlSelf->addr >> 2U))),2);
    bufp->fullCData(oldp+41,((3U & vlSelf->addr)),2);
    bufp->fullIData(oldp+42,(0x20U),32);
    bufp->fullIData(oldp+43,(4U),32);
}
