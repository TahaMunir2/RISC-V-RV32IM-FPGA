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
    tracep->declBit(c+87,"clk", false,-1);
    tracep->declBit(c+88,"fetch_i", false,-1);
    tracep->declBit(c+89,"fetch_d", false,-1);
    tracep->declBus(c+90,"addr_i", false,-1, 31,0);
    tracep->declBus(c+91,"addr_d", false,-1, 31,0);
    tracep->declArray(c+92,"line_from_mem", false,-1, 255,0);
    tracep->declArray(c+100,"l1write_back_data", false,-1, 127,0);
    tracep->declBit(c+104,"l1write_back_en", false,-1);
    tracep->declBus(c+105,"l1write_back_addr", false,-1, 31,0);
    tracep->declBit(c+106,"ready", false,-1);
    tracep->declBit(c+107,"wb_ready", false,-1);
    tracep->declBit(c+108,"ready_i", false,-1);
    tracep->declBit(c+109,"ready_d", false,-1);
    tracep->declBit(c+110,"wb_ready_d", false,-1);
    tracep->declArray(c+111,"data_out", false,-1, 127,0);
    tracep->declArray(c+115,"write_back_data", false,-1, 127,0);
    tracep->declBus(c+119,"write_back_addr", false,-1, 31,0);
    tracep->declBit(c+120,"write_back_en", false,-1);
    tracep->declBus(c+121,"main_mem_addr", false,-1, 31,0);
    tracep->declBit(c+122,"main_mem_fetch", false,-1);
    tracep->pushNamePrefix("l2_cache ");
    tracep->declBus(c+123,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+123,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+124,"BLOCK_SIZE", false,-1, 31,0);
    tracep->declBit(c+87,"clk", false,-1);
    tracep->declBit(c+88,"fetch_i", false,-1);
    tracep->declBit(c+89,"fetch_d", false,-1);
    tracep->declBus(c+90,"addr_i", false,-1, 31,0);
    tracep->declBus(c+91,"addr_d", false,-1, 31,0);
    tracep->declArray(c+92,"line_from_mem", false,-1, 255,0);
    tracep->declArray(c+100,"l1write_back_data", false,-1, 127,0);
    tracep->declBit(c+104,"l1write_back_en", false,-1);
    tracep->declBus(c+105,"l1write_back_addr", false,-1, 31,0);
    tracep->declBit(c+106,"ready", false,-1);
    tracep->declBit(c+107,"wb_ready", false,-1);
    tracep->declBit(c+108,"ready_i", false,-1);
    tracep->declBit(c+109,"ready_d", false,-1);
    tracep->declBit(c+110,"wb_ready_d", false,-1);
    tracep->declArray(c+111,"data_out", false,-1, 127,0);
    tracep->declArray(c+115,"write_back_data", false,-1, 127,0);
    tracep->declBus(c+119,"write_back_addr", false,-1, 31,0);
    tracep->declBit(c+120,"write_back_en", false,-1);
    tracep->declBus(c+121,"main_mem_addr", false,-1, 31,0);
    tracep->declBit(c+122,"main_mem_fetch", false,-1);
    tracep->declBit(c+2,"wr_en", false,-1);
    tracep->declBit(c+3,"rd_en", false,-1);
    tracep->declBit(c+4,"wr_wb", false,-1);
    tracep->declArray(c+5,"write_data", false,-1, 255,0);
    tracep->declBit(c+13,"clean", false,-1);
    tracep->declBus(c+14,"way_rd", false,-1, 1,0);
    tracep->declBus(c+15,"tag_bits_rd", false,-1, 31,13);
    tracep->declBus(c+16,"set_rd", false,-1, 7,0);
    tracep->declBus(c+17,"block_offset_rd", false,-1, 2,0);
    tracep->declArray(c+18,"wmask", false,-1, 255,0);
    tracep->declBit(c+26,"fetch", false,-1);
    tracep->declBit(c+27,"req_d", false,-1);
    tracep->declBit(c+28,"req_i", false,-1);
    tracep->declBus(c+29,"addr", false,-1, 31,0);
    tracep->declBit(c+30,"l1write", false,-1);
    tracep->declBit(c+31,"hit0", false,-1);
    tracep->declBit(c+32,"hit1", false,-1);
    tracep->declBit(c+33,"hit2", false,-1);
    tracep->declBit(c+34,"hit3", false,-1);
    tracep->declBit(c+35,"valid0", false,-1);
    tracep->declBit(c+36,"valid1", false,-1);
    tracep->declBit(c+37,"valid2", false,-1);
    tracep->declBit(c+38,"valid3", false,-1);
    tracep->declBit(c+39,"miss", false,-1);
    tracep->declBit(c+40,"evict", false,-1);
    tracep->declBit(c+41,"wb_ready_d_next", false,-1);
    tracep->declBit(c+42,"write_back_en_next", false,-1);
    tracep->declArray(c+68,"l1write_back_data_buffer", false,-1, 127,0);
    tracep->declArray(c+43,"l1write_back_data_buffer_next", false,-1, 127,0);
    tracep->declBit(c+72,"l1write_buffer", false,-1);
    tracep->declBit(c+47,"l1write_buffer_next", false,-1);
    tracep->declBus(c+73,"l1write_back_addr_buffer", false,-1, 31,0);
    tracep->declBus(c+48,"l1write_back_addr_buffer_next", false,-1, 31,0);
    tracep->declBus(c+74,"tag_bits_wb", false,-1, 31,13);
    tracep->declBus(c+75,"set_wb", false,-1, 7,0);
    tracep->declBus(c+76,"block_offset_wb", false,-1, 2,0);
    tracep->declBit(c+49,"hit0_wb", false,-1);
    tracep->declBit(c+50,"hit1_wb", false,-1);
    tracep->declBit(c+51,"hit2_wb", false,-1);
    tracep->declBit(c+52,"hit3_wb", false,-1);
    tracep->declBit(c+53,"miss_wb", false,-1);
    tracep->declBus(c+54,"way", false,-1, 1,0);
    tracep->declBus(c+55,"tag_bits", false,-1, 31,13);
    tracep->declBus(c+56,"set", false,-1, 7,0);
    tracep->declBus(c+57,"block_offset", false,-1, 2,0);
    tracep->declArray(c+77,"l2write_back_data_buffer", false,-1, 255,0);
    tracep->declArray(c+58,"l2write_back_data_buffer_next", false,-1, 255,0);
    tracep->declBus(c+85,"l2write_buffer", false,-1, 1,0);
    tracep->declBus(c+66,"l2write_buffer_next", false,-1, 1,0);
    tracep->declBus(c+86,"l2write_back_addr_buffer", false,-1, 31,0);
    tracep->declBus(c+67,"l2write_back_addr_buffer_next", false,-1, 31,0);
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
    bufp->fullIData(oldp+1,(vlSelf->l2_cache__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+2,(vlSelf->l2_cache__DOT__wr_en));
    bufp->fullBit(oldp+3,(vlSelf->l2_cache__DOT__rd_en));
    bufp->fullBit(oldp+4,(vlSelf->l2_cache__DOT__wr_wb));
    bufp->fullWData(oldp+5,(vlSelf->l2_cache__DOT__write_data),256);
    bufp->fullBit(oldp+13,(vlSelf->l2_cache__DOT__clean));
    bufp->fullCData(oldp+14,(vlSelf->l2_cache__DOT__way_rd),2);
    bufp->fullIData(oldp+15,((vlSelf->l2_cache__DOT__addr 
                              >> 0xdU)),19);
    bufp->fullCData(oldp+16,((0xffU & (vlSelf->l2_cache__DOT__addr 
                                       >> 5U))),8);
    bufp->fullCData(oldp+17,((7U & (vlSelf->l2_cache__DOT__addr 
                                    >> 2U))),3);
    bufp->fullWData(oldp+18,(vlSelf->l2_cache__DOT__wmask),256);
    bufp->fullBit(oldp+26,(vlSelf->l2_cache__DOT__fetch));
    bufp->fullBit(oldp+27,(vlSelf->l2_cache__DOT__req_d));
    bufp->fullBit(oldp+28,(vlSelf->l2_cache__DOT__req_i));
    bufp->fullIData(oldp+29,(vlSelf->l2_cache__DOT__addr),32);
    bufp->fullBit(oldp+30,(vlSelf->l2_cache__DOT__l1write));
    bufp->fullBit(oldp+31,(vlSelf->l2_cache__DOT__hit0));
    bufp->fullBit(oldp+32,(vlSelf->l2_cache__DOT__hit1));
    bufp->fullBit(oldp+33,(vlSelf->l2_cache__DOT__hit2));
    bufp->fullBit(oldp+34,(vlSelf->l2_cache__DOT__hit3));
    bufp->fullBit(oldp+35,(vlSelf->l2_cache__DOT__valid0));
    bufp->fullBit(oldp+36,(vlSelf->l2_cache__DOT__valid1));
    bufp->fullBit(oldp+37,(vlSelf->l2_cache__DOT__valid2));
    bufp->fullBit(oldp+38,(vlSelf->l2_cache__DOT__valid3));
    bufp->fullBit(oldp+39,(vlSelf->l2_cache__DOT__miss));
    bufp->fullBit(oldp+40,(vlSelf->l2_cache__DOT__evict));
    bufp->fullBit(oldp+41,(vlSelf->l2_cache__DOT__wb_ready_d_next));
    bufp->fullBit(oldp+42,(vlSelf->l2_cache__DOT__write_back_en_next));
    bufp->fullWData(oldp+43,(vlSelf->l2_cache__DOT__l1write_back_data_buffer_next),128);
    bufp->fullBit(oldp+47,(vlSelf->l2_cache__DOT__l1write_buffer_next));
    bufp->fullIData(oldp+48,(vlSelf->l2_cache__DOT__l1write_back_addr_buffer_next),32);
    bufp->fullBit(oldp+49,(vlSelf->l2_cache__DOT__hit0_wb));
    bufp->fullBit(oldp+50,(vlSelf->l2_cache__DOT__hit1_wb));
    bufp->fullBit(oldp+51,(vlSelf->l2_cache__DOT__hit2_wb));
    bufp->fullBit(oldp+52,(vlSelf->l2_cache__DOT__hit3_wb));
    bufp->fullBit(oldp+53,(vlSelf->l2_cache__DOT__miss_wb));
    bufp->fullCData(oldp+54,(vlSelf->l2_cache__DOT__way),2);
    bufp->fullIData(oldp+55,(vlSelf->l2_cache__DOT__tag_bits),19);
    bufp->fullCData(oldp+56,(vlSelf->l2_cache__DOT__set),8);
    bufp->fullCData(oldp+57,(vlSelf->l2_cache__DOT__block_offset),3);
    bufp->fullWData(oldp+58,(vlSelf->l2_cache__DOT__l2write_back_data_buffer_next),256);
    bufp->fullCData(oldp+66,(vlSelf->l2_cache__DOT__l2write_buffer_next),2);
    bufp->fullIData(oldp+67,(vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next),32);
    bufp->fullWData(oldp+68,(vlSelf->l2_cache__DOT__l1write_back_data_buffer),128);
    bufp->fullBit(oldp+72,(vlSelf->l2_cache__DOT__l1write_buffer));
    bufp->fullIData(oldp+73,(vlSelf->l2_cache__DOT__l1write_back_addr_buffer),32);
    bufp->fullIData(oldp+74,((vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                              >> 0xdU)),19);
    bufp->fullCData(oldp+75,((0xffU & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                       >> 5U))),8);
    bufp->fullCData(oldp+76,((7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                    >> 2U))),3);
    bufp->fullWData(oldp+77,(vlSelf->l2_cache__DOT__l2write_back_data_buffer),256);
    bufp->fullCData(oldp+85,(vlSelf->l2_cache__DOT__l2write_buffer),2);
    bufp->fullIData(oldp+86,(vlSelf->l2_cache__DOT__l2write_back_addr_buffer),32);
    bufp->fullBit(oldp+87,(vlSelf->clk));
    bufp->fullBit(oldp+88,(vlSelf->fetch_i));
    bufp->fullBit(oldp+89,(vlSelf->fetch_d));
    bufp->fullIData(oldp+90,(vlSelf->addr_i),32);
    bufp->fullIData(oldp+91,(vlSelf->addr_d),32);
    bufp->fullWData(oldp+92,(vlSelf->line_from_mem),256);
    bufp->fullWData(oldp+100,(vlSelf->l1write_back_data),128);
    bufp->fullBit(oldp+104,(vlSelf->l1write_back_en));
    bufp->fullIData(oldp+105,(vlSelf->l1write_back_addr),32);
    bufp->fullBit(oldp+106,(vlSelf->ready));
    bufp->fullBit(oldp+107,(vlSelf->wb_ready));
    bufp->fullBit(oldp+108,(vlSelf->ready_i));
    bufp->fullBit(oldp+109,(vlSelf->ready_d));
    bufp->fullBit(oldp+110,(vlSelf->wb_ready_d));
    bufp->fullWData(oldp+111,(vlSelf->data_out),128);
    bufp->fullWData(oldp+115,(vlSelf->write_back_data),128);
    bufp->fullIData(oldp+119,(vlSelf->write_back_addr),32);
    bufp->fullBit(oldp+120,(vlSelf->write_back_en));
    bufp->fullIData(oldp+121,(vlSelf->main_mem_addr),32);
    bufp->fullBit(oldp+122,(vlSelf->main_mem_fetch));
    bufp->fullIData(oldp+123,(0x20U),32);
    bufp->fullIData(oldp+124,(8U),32);
}
