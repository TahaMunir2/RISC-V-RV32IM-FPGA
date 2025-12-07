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
    tracep->declBit(c+44,"clk", false,-1);
    tracep->declBit(c+45,"fetch_i", false,-1);
    tracep->declBit(c+46,"fetch_d", false,-1);
    tracep->declBus(c+47,"addr_i", false,-1, 31,0);
    tracep->declBus(c+48,"addr_d", false,-1, 31,0);
    tracep->declArray(c+49,"line_from_mem", false,-1, 255,0);
    tracep->declBit(c+57,"ready", false,-1);
    tracep->declArray(c+58,"l1write_back_data", false,-1, 127,0);
    tracep->declBit(c+62,"l1write_back_en", false,-1);
    tracep->declBus(c+63,"l1write_back_addr", false,-1, 31,0);
    tracep->declBit(c+64,"wb_ready", false,-1);
    tracep->declBit(c+65,"ready_i", false,-1);
    tracep->declBit(c+66,"ready_d", false,-1);
    tracep->declBit(c+67,"wb_ready_d", false,-1);
    tracep->declArray(c+68,"data_out", false,-1, 127,0);
    tracep->declArray(c+72,"write_back_data", false,-1, 127,0);
    tracep->declBus(c+76,"write_back_addr", false,-1, 31,0);
    tracep->declBit(c+77,"write_back_en", false,-1);
    tracep->declBus(c+78,"main_mem_addr", false,-1, 31,0);
    tracep->declBit(c+79,"main_mem_fetch", false,-1);
    tracep->pushNamePrefix("l2_cache ");
    tracep->declBus(c+80,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+80,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+81,"BLOCK_SIZE", false,-1, 31,0);
    tracep->declBit(c+44,"clk", false,-1);
    tracep->declBit(c+45,"fetch_i", false,-1);
    tracep->declBit(c+46,"fetch_d", false,-1);
    tracep->declBus(c+47,"addr_i", false,-1, 31,0);
    tracep->declBus(c+48,"addr_d", false,-1, 31,0);
    tracep->declArray(c+49,"line_from_mem", false,-1, 255,0);
    tracep->declBit(c+57,"ready", false,-1);
    tracep->declArray(c+58,"l1write_back_data", false,-1, 127,0);
    tracep->declBit(c+62,"l1write_back_en", false,-1);
    tracep->declBus(c+63,"l1write_back_addr", false,-1, 31,0);
    tracep->declBit(c+64,"wb_ready", false,-1);
    tracep->declBit(c+65,"ready_i", false,-1);
    tracep->declBit(c+66,"ready_d", false,-1);
    tracep->declBit(c+67,"wb_ready_d", false,-1);
    tracep->declArray(c+68,"data_out", false,-1, 127,0);
    tracep->declArray(c+72,"write_back_data", false,-1, 127,0);
    tracep->declBus(c+76,"write_back_addr", false,-1, 31,0);
    tracep->declBit(c+77,"write_back_en", false,-1);
    tracep->declBus(c+78,"main_mem_addr", false,-1, 31,0);
    tracep->declBit(c+79,"main_mem_fetch", false,-1);
    tracep->declBus(c+82,"NUM_SETS", false,-1, 31,0);
    tracep->declBus(c+83,"NUM_WAYS", false,-1, 31,0);
    tracep->declBus(c+81,"LINE_WORDS", false,-1, 31,0);
    tracep->declBus(c+82,"LINE_BITS", false,-1, 31,0);
    tracep->declBus(c+84,"TAG_BITS", false,-1, 31,0);
    tracep->declBit(c+27,"req_valid", false,-1);
    tracep->declBit(c+28,"req_is_i", false,-1);
    tracep->declBus(c+29,"req_addr", false,-1, 31,0);
    tracep->declBus(c+30,"req_tag", false,-1, 18,0);
    tracep->declBus(c+31,"req_set", false,-1, 7,0);
    tracep->declBus(c+32,"req_off", false,-1, 2,0);
    tracep->declBus(c+33,"hit_vec", false,-1, 3,0);
    tracep->declBit(c+34,"req_hit", false,-1);
    tracep->declBus(c+35,"hit_way", false,-1, 1,0);
    tracep->declBit(c+3,"miss_pending", false,-1);
    tracep->declBit(c+4,"miss_is_i", false,-1);
    tracep->declBus(c+5,"miss_addr", false,-1, 31,0);
    tracep->declBus(c+6,"miss_tag", false,-1, 18,0);
    tracep->declBus(c+7,"miss_set", false,-1, 7,0);
    tracep->declBus(c+8,"miss_way", false,-1, 1,0);
    tracep->declBit(c+9,"l1_wb_pending", false,-1);
    tracep->declBus(c+10,"l1_wb_addr", false,-1, 31,0);
    tracep->declArray(c+11,"l1_wb_data", false,-1, 127,0);
    tracep->declBus(c+15,"l1_wb_tag", false,-1, 18,0);
    tracep->declBus(c+16,"l1_wb_set", false,-1, 7,0);
    tracep->declBus(c+17,"l1_wb_off", false,-1, 2,0);
    tracep->declBus(c+18,"l1_wb_hit_vec", false,-1, 3,0);
    tracep->declBit(c+19,"l1_wb_hit", false,-1);
    tracep->declBus(c+20,"l1_wb_hit_way", false,-1, 1,0);
    tracep->declBit(c+21,"evict_wb_pending", false,-1);
    tracep->declBus(c+22,"evict_wb_addr", false,-1, 31,0);
    tracep->declArray(c+23,"evict_wb_data", false,-1, 127,0);
    tracep->declArray(c+36,"hit_line", false,-1, 255,0);
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->declBus(c+2,"j", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+85,"w", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->declBus(c+85,"w", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk4 ");
    tracep->declBus(c+85,"w", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk5 ");
    tracep->declBus(c+85,"w", false,-1, 31,0);
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
    bufp->fullIData(oldp+1,(vlSelf->l2_cache__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->l2_cache__DOT__j),32);
    bufp->fullBit(oldp+3,(vlSelf->l2_cache__DOT__miss_pending));
    bufp->fullBit(oldp+4,(vlSelf->l2_cache__DOT__miss_is_i));
    bufp->fullIData(oldp+5,(vlSelf->l2_cache__DOT__miss_addr),32);
    bufp->fullIData(oldp+6,(vlSelf->l2_cache__DOT__miss_tag),19);
    bufp->fullCData(oldp+7,(vlSelf->l2_cache__DOT__miss_set),8);
    bufp->fullCData(oldp+8,(vlSelf->l2_cache__DOT__miss_way),2);
    bufp->fullBit(oldp+9,(vlSelf->l2_cache__DOT__l1_wb_pending));
    bufp->fullIData(oldp+10,(vlSelf->l2_cache__DOT__l1_wb_addr),32);
    bufp->fullWData(oldp+11,(vlSelf->l2_cache__DOT__l1_wb_data),128);
    bufp->fullIData(oldp+15,((vlSelf->l2_cache__DOT__l1_wb_addr 
                              >> 0xdU)),19);
    bufp->fullCData(oldp+16,((0xffU & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                       >> 5U))),8);
    bufp->fullCData(oldp+17,((7U & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                    >> 2U))),3);
    bufp->fullCData(oldp+18,(vlSelf->l2_cache__DOT__l1_wb_hit_vec),4);
    bufp->fullBit(oldp+19,(vlSelf->l2_cache__DOT__l1_wb_hit));
    bufp->fullCData(oldp+20,(vlSelf->l2_cache__DOT__l1_wb_hit_way),2);
    bufp->fullBit(oldp+21,(vlSelf->l2_cache__DOT__evict_wb_pending));
    bufp->fullIData(oldp+22,(vlSelf->l2_cache__DOT__evict_wb_addr),32);
    bufp->fullWData(oldp+23,(vlSelf->l2_cache__DOT__evict_wb_data),128);
    bufp->fullBit(oldp+27,(vlSelf->l2_cache__DOT__req_valid));
    bufp->fullBit(oldp+28,(vlSelf->l2_cache__DOT__req_is_i));
    bufp->fullIData(oldp+29,(vlSelf->l2_cache__DOT__req_addr),32);
    bufp->fullIData(oldp+30,((vlSelf->l2_cache__DOT__req_addr 
                              >> 0xdU)),19);
    bufp->fullCData(oldp+31,((0xffU & (vlSelf->l2_cache__DOT__req_addr 
                                       >> 5U))),8);
    bufp->fullCData(oldp+32,((7U & (vlSelf->l2_cache__DOT__req_addr 
                                    >> 2U))),3);
    bufp->fullCData(oldp+33,(vlSelf->l2_cache__DOT__hit_vec),4);
    bufp->fullBit(oldp+34,(vlSelf->l2_cache__DOT__req_hit));
    bufp->fullCData(oldp+35,(vlSelf->l2_cache__DOT__hit_way),2);
    bufp->fullWData(oldp+36,(vlSelf->l2_cache__DOT__hit_line),256);
    bufp->fullBit(oldp+44,(vlSelf->clk));
    bufp->fullBit(oldp+45,(vlSelf->fetch_i));
    bufp->fullBit(oldp+46,(vlSelf->fetch_d));
    bufp->fullIData(oldp+47,(vlSelf->addr_i),32);
    bufp->fullIData(oldp+48,(vlSelf->addr_d),32);
    bufp->fullWData(oldp+49,(vlSelf->line_from_mem),256);
    bufp->fullBit(oldp+57,(vlSelf->ready));
    bufp->fullWData(oldp+58,(vlSelf->l1write_back_data),128);
    bufp->fullBit(oldp+62,(vlSelf->l1write_back_en));
    bufp->fullIData(oldp+63,(vlSelf->l1write_back_addr),32);
    bufp->fullBit(oldp+64,(vlSelf->wb_ready));
    bufp->fullBit(oldp+65,(vlSelf->ready_i));
    bufp->fullBit(oldp+66,(vlSelf->ready_d));
    bufp->fullBit(oldp+67,(vlSelf->wb_ready_d));
    bufp->fullWData(oldp+68,(vlSelf->data_out),128);
    bufp->fullWData(oldp+72,(vlSelf->write_back_data),128);
    bufp->fullIData(oldp+76,(vlSelf->write_back_addr),32);
    bufp->fullBit(oldp+77,(vlSelf->write_back_en));
    bufp->fullIData(oldp+78,(vlSelf->main_mem_addr),32);
    bufp->fullBit(oldp+79,(vlSelf->main_mem_fetch));
    bufp->fullIData(oldp+80,(0x20U),32);
    bufp->fullIData(oldp+81,(8U),32);
    bufp->fullIData(oldp+82,(0x100U),32);
    bufp->fullIData(oldp+83,(4U),32);
    bufp->fullIData(oldp+84,(0x13U),32);
    bufp->fullIData(oldp+85,(4U),32);
}
