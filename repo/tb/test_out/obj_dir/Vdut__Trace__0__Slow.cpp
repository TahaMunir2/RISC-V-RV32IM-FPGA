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
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+16,"fetch", false,-1);
    tracep->declBus(c+17,"addr", false,-1, 31,0);
    tracep->declArray(c+18,"line_from_mem", false,-1, 127,0);
    tracep->declBus(c+22,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+23,"LoadUnsigned", false,-1);
    tracep->declBit(c+24,"wake", false,-1);
    tracep->declBus(c+25,"l2_addr", false,-1, 31,0);
    tracep->declBit(c+26,"l2_fetch", false,-1);
    tracep->declBus(c+27,"data_out", false,-1, 31,0);
    tracep->declBit(c+28,"stall", false,-1);
    tracep->pushNamePrefix("l1i_cache ");
    tracep->declBus(c+33,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+33,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+34,"BLOCK_SIZE", false,-1, 31,0);
    tracep->declBit(c+15,"clk", false,-1);
    tracep->declBit(c+16,"fetch", false,-1);
    tracep->declBus(c+17,"addr", false,-1, 31,0);
    tracep->declArray(c+18,"line_from_mem", false,-1, 127,0);
    tracep->declBus(c+22,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+23,"LoadUnsigned", false,-1);
    tracep->declBit(c+24,"wake", false,-1);
    tracep->declBus(c+25,"l2_addr", false,-1, 31,0);
    tracep->declBit(c+26,"l2_fetch", false,-1);
    tracep->declBus(c+27,"data_out", false,-1, 31,0);
    tracep->declBit(c+28,"stall", false,-1);
    tracep->declBit(c+2,"wr_en", false,-1);
    tracep->declBit(c+3,"rd_en", false,-1);
    tracep->declArray(c+4,"write_data", false,-1, 127,0);
    tracep->declBit(c+8,"way", false,-1);
    tracep->declBus(c+29,"tag_bits", false,-1, 31,11);
    tracep->declBus(c+30,"set", false,-1, 6,0);
    tracep->declBus(c+31,"block_offset", false,-1, 1,0);
    tracep->declBus(c+32,"byte_offset", false,-1, 1,0);
    tracep->declBit(c+9,"hit0", false,-1);
    tracep->declBit(c+10,"hit1", false,-1);
    tracep->declBit(c+11,"valid0", false,-1);
    tracep->declBit(c+12,"valid1", false,-1);
    tracep->declBit(c+13,"miss", false,-1);
    tracep->declBus(c+14,"bottom_bit", false,-1, 6,0);
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
    bufp->fullIData(oldp+1,(vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+2,(vlSelf->l1i_cache__DOT__wr_en));
    bufp->fullBit(oldp+3,(vlSelf->l1i_cache__DOT__rd_en));
    bufp->fullWData(oldp+4,(vlSelf->l1i_cache__DOT__write_data),128);
    bufp->fullBit(oldp+8,(vlSelf->l1i_cache__DOT__way));
    bufp->fullBit(oldp+9,(vlSelf->l1i_cache__DOT__hit0));
    bufp->fullBit(oldp+10,(vlSelf->l1i_cache__DOT__hit1));
    bufp->fullBit(oldp+11,(vlSelf->l1i_cache__DOT__valid0));
    bufp->fullBit(oldp+12,(vlSelf->l1i_cache__DOT__valid1));
    bufp->fullBit(oldp+13,(vlSelf->l1i_cache__DOT__miss));
    bufp->fullCData(oldp+14,(vlSelf->l1i_cache__DOT__bottom_bit),7);
    bufp->fullBit(oldp+15,(vlSelf->clk));
    bufp->fullBit(oldp+16,(vlSelf->fetch));
    bufp->fullIData(oldp+17,(vlSelf->addr),32);
    bufp->fullWData(oldp+18,(vlSelf->line_from_mem),128);
    bufp->fullCData(oldp+22,(vlSelf->LoadSize),2);
    bufp->fullBit(oldp+23,(vlSelf->LoadUnsigned));
    bufp->fullBit(oldp+24,(vlSelf->wake));
    bufp->fullIData(oldp+25,(vlSelf->l2_addr),32);
    bufp->fullBit(oldp+26,(vlSelf->l2_fetch));
    bufp->fullIData(oldp+27,(vlSelf->data_out),32);
    bufp->fullBit(oldp+28,(vlSelf->stall));
    bufp->fullIData(oldp+29,((vlSelf->addr >> 0xbU)),21);
    bufp->fullCData(oldp+30,((0x7fU & (vlSelf->addr 
                                       >> 4U))),7);
    bufp->fullCData(oldp+31,((3U & (vlSelf->addr >> 2U))),2);
    bufp->fullCData(oldp+32,((3U & vlSelf->addr)),2);
    bufp->fullIData(oldp+33,(0x20U),32);
    bufp->fullIData(oldp+34,(4U),32);
}
