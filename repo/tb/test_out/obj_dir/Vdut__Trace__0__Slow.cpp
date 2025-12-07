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
    tracep->declBit(c+68,"clk", false,-1);
    tracep->declBit(c+69,"fetch_i", false,-1);
    tracep->declBit(c+70,"fetch_d", false,-1);
    tracep->declBus(c+71,"addr_i", false,-1, 31,0);
    tracep->declBus(c+72,"addr_d", false,-1, 31,0);
    tracep->declArray(c+73,"line_from_mem", false,-1, 255,0);
    tracep->declArray(c+81,"l1write_back_data", false,-1, 127,0);
    tracep->declBit(c+85,"l1write_back_en", false,-1);
    tracep->declBus(c+86,"l1write_back_addr", false,-1, 31,0);
    tracep->declBit(c+87,"ready", false,-1);
    tracep->declBit(c+88,"wb_ready", false,-1);
    tracep->declBit(c+89,"ready_i", false,-1);
    tracep->declBit(c+90,"ready_d", false,-1);
    tracep->declBit(c+91,"wb_ready_d", false,-1);
    tracep->declArray(c+92,"data_out", false,-1, 127,0);
    tracep->declArray(c+96,"write_back_data", false,-1, 127,0);
    tracep->declBus(c+100,"write_back_addr", false,-1, 31,0);
    tracep->declBit(c+101,"write_back_en", false,-1);
    tracep->declBit(c+102,"main_mem_addr", false,-1);
    tracep->declBit(c+103,"main_mem_fetch", false,-1);
    tracep->pushNamePrefix("l2_cache ");
    tracep->declBus(c+104,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+104,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+105,"BLOCK_SIZE", false,-1, 31,0);
    tracep->declBit(c+68,"clk", false,-1);
    tracep->declBit(c+69,"fetch_i", false,-1);
    tracep->declBit(c+70,"fetch_d", false,-1);
    tracep->declBus(c+71,"addr_i", false,-1, 31,0);
    tracep->declBus(c+72,"addr_d", false,-1, 31,0);
    tracep->declArray(c+73,"line_from_mem", false,-1, 255,0);
    tracep->declArray(c+81,"l1write_back_data", false,-1, 127,0);
    tracep->declBit(c+85,"l1write_back_en", false,-1);
    tracep->declBus(c+86,"l1write_back_addr", false,-1, 31,0);
    tracep->declBit(c+87,"ready", false,-1);
    tracep->declBit(c+88,"wb_ready", false,-1);
    tracep->declBit(c+89,"ready_i", false,-1);
    tracep->declBit(c+90,"ready_d", false,-1);
    tracep->declBit(c+91,"wb_ready_d", false,-1);
    tracep->declArray(c+92,"data_out", false,-1, 127,0);
    tracep->declArray(c+96,"write_back_data", false,-1, 127,0);
    tracep->declBus(c+100,"write_back_addr", false,-1, 31,0);
    tracep->declBit(c+101,"write_back_en", false,-1);
    tracep->declBit(c+102,"main_mem_addr", false,-1);
    tracep->declBit(c+103,"main_mem_fetch", false,-1);
    tracep->declBit(c+2,"wr_en", false,-1);
    tracep->declBit(c+3,"rd_en", false,-1);
    tracep->declBit(c+4,"wr_wb", false,-1);
    tracep->declArray(c+5,"write_data", false,-1, 255,0);
    tracep->declBus(c+13,"way_rd", false,-1, 1,0);
    tracep->declBus(c+60,"tag_bits_rd", false,-1, 31,13);
    tracep->declBus(c+61,"set_rd", false,-1, 7,0);
    tracep->declBus(c+62,"block_offset_rd", false,-1, 2,0);
    tracep->declArray(c+14,"wmask", false,-1, 255,0);
    tracep->declBit(c+63,"fetch", false,-1);
    tracep->declBit(c+64,"req_d", false,-1);
    tracep->declBit(c+65,"req_i", false,-1);
    tracep->declBus(c+66,"addr", false,-1, 31,0);
    tracep->declBit(c+67,"l1write", false,-1);
    tracep->declBit(c+22,"hit0", false,-1);
    tracep->declBit(c+23,"hit1", false,-1);
    tracep->declBit(c+24,"hit2", false,-1);
    tracep->declBit(c+25,"hit3", false,-1);
    tracep->declBit(c+26,"valid0", false,-1);
    tracep->declBit(c+27,"valid1", false,-1);
    tracep->declBit(c+28,"valid2", false,-1);
    tracep->declBit(c+29,"valid3", false,-1);
    tracep->declBit(c+30,"miss", false,-1);
    tracep->declBit(c+31,"evict", false,-1);
    tracep->declArray(c+32,"l1write_back_data_buffer", false,-1, 127,0);
    tracep->declBit(c+36,"l1write_buffer", false,-1);
    tracep->declBus(c+37,"l1write_back_addr_buffer", false,-1, 31,0);
    tracep->declBus(c+38,"tag_bits_wb", false,-1, 31,13);
    tracep->declBus(c+39,"set_wb", false,-1, 7,0);
    tracep->declBus(c+40,"block_offset_wb", false,-1, 2,0);
    tracep->declBit(c+41,"hit0_wb", false,-1);
    tracep->declBit(c+42,"hit1_wb", false,-1);
    tracep->declBit(c+43,"hit2_wb", false,-1);
    tracep->declBit(c+44,"hit3_wb", false,-1);
    tracep->declBit(c+45,"miss_wb", false,-1);
    tracep->declBus(c+46,"way", false,-1, 1,0);
    tracep->declBus(c+47,"tag_bits", false,-1, 31,13);
    tracep->declBus(c+48,"set", false,-1, 7,0);
    tracep->declBus(c+49,"block_offset", false,-1, 2,0);
    tracep->declArray(c+50,"l2write_back_data_buffer", false,-1, 255,0);
    tracep->declBus(c+58,"l2write_buffer", false,-1, 1,0);
    tracep->declBus(c+59,"l2write_back_addr_buffer", false,-1, 31,0);
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
    bufp->fullCData(oldp+13,(vlSelf->l2_cache__DOT__way_rd),2);
    bufp->fullWData(oldp+14,(vlSelf->l2_cache__DOT__wmask),256);
    bufp->fullBit(oldp+22,(vlSelf->l2_cache__DOT__hit0));
    bufp->fullBit(oldp+23,(vlSelf->l2_cache__DOT__hit1));
    bufp->fullBit(oldp+24,(vlSelf->l2_cache__DOT__hit2));
    bufp->fullBit(oldp+25,(vlSelf->l2_cache__DOT__hit3));
    bufp->fullBit(oldp+26,(vlSelf->l2_cache__DOT__valid0));
    bufp->fullBit(oldp+27,(vlSelf->l2_cache__DOT__valid1));
    bufp->fullBit(oldp+28,(vlSelf->l2_cache__DOT__valid2));
    bufp->fullBit(oldp+29,(vlSelf->l2_cache__DOT__valid3));
    bufp->fullBit(oldp+30,(vlSelf->l2_cache__DOT__miss));
    bufp->fullBit(oldp+31,(vlSelf->l2_cache__DOT__evict));
    bufp->fullWData(oldp+32,(vlSelf->l2_cache__DOT__l1write_back_data_buffer),128);
    bufp->fullBit(oldp+36,(vlSelf->l2_cache__DOT__l1write_buffer));
    bufp->fullIData(oldp+37,(vlSelf->l2_cache__DOT__l1write_back_addr_buffer),32);
    bufp->fullIData(oldp+38,((vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                              >> 0xdU)),19);
    bufp->fullCData(oldp+39,((0xffU & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                       >> 5U))),8);
    bufp->fullCData(oldp+40,((7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                    >> 2U))),3);
    bufp->fullBit(oldp+41,(vlSelf->l2_cache__DOT__hit0_wb));
    bufp->fullBit(oldp+42,(vlSelf->l2_cache__DOT__hit1_wb));
    bufp->fullBit(oldp+43,(vlSelf->l2_cache__DOT__hit2_wb));
    bufp->fullBit(oldp+44,(vlSelf->l2_cache__DOT__hit3_wb));
    bufp->fullBit(oldp+45,(vlSelf->l2_cache__DOT__miss_wb));
    bufp->fullCData(oldp+46,(vlSelf->l2_cache__DOT__way),2);
    bufp->fullIData(oldp+47,(vlSelf->l2_cache__DOT__tag_bits),19);
    bufp->fullCData(oldp+48,(vlSelf->l2_cache__DOT__set),8);
    bufp->fullCData(oldp+49,(vlSelf->l2_cache__DOT__block_offset),3);
    bufp->fullWData(oldp+50,(vlSelf->l2_cache__DOT__l2write_back_data_buffer),256);
    bufp->fullCData(oldp+58,(vlSelf->l2_cache__DOT__l2write_buffer),2);
    bufp->fullIData(oldp+59,(vlSelf->l2_cache__DOT__l2write_back_addr_buffer),32);
    bufp->fullIData(oldp+60,((vlSelf->l2_cache__DOT__addr 
                              >> 0xdU)),19);
    bufp->fullCData(oldp+61,((0xffU & (vlSelf->l2_cache__DOT__addr 
                                       >> 5U))),8);
    bufp->fullCData(oldp+62,((7U & (vlSelf->l2_cache__DOT__addr 
                                    >> 2U))),3);
    bufp->fullBit(oldp+63,(vlSelf->l2_cache__DOT__fetch));
    bufp->fullBit(oldp+64,(vlSelf->l2_cache__DOT__req_d));
    bufp->fullBit(oldp+65,(vlSelf->l2_cache__DOT__req_i));
    bufp->fullIData(oldp+66,(vlSelf->l2_cache__DOT__addr),32);
    bufp->fullBit(oldp+67,(vlSelf->l2_cache__DOT__l1write));
    bufp->fullBit(oldp+68,(vlSelf->clk));
    bufp->fullBit(oldp+69,(vlSelf->fetch_i));
    bufp->fullBit(oldp+70,(vlSelf->fetch_d));
    bufp->fullIData(oldp+71,(vlSelf->addr_i),32);
    bufp->fullIData(oldp+72,(vlSelf->addr_d),32);
    bufp->fullWData(oldp+73,(vlSelf->line_from_mem),256);
    bufp->fullWData(oldp+81,(vlSelf->l1write_back_data),128);
    bufp->fullBit(oldp+85,(vlSelf->l1write_back_en));
    bufp->fullIData(oldp+86,(vlSelf->l1write_back_addr),32);
    bufp->fullBit(oldp+87,(vlSelf->ready));
    bufp->fullBit(oldp+88,(vlSelf->wb_ready));
    bufp->fullBit(oldp+89,(vlSelf->ready_i));
    bufp->fullBit(oldp+90,(vlSelf->ready_d));
    bufp->fullBit(oldp+91,(vlSelf->wb_ready_d));
    bufp->fullWData(oldp+92,(vlSelf->data_out),128);
    bufp->fullWData(oldp+96,(vlSelf->write_back_data),128);
    bufp->fullIData(oldp+100,(vlSelf->write_back_addr),32);
    bufp->fullBit(oldp+101,(vlSelf->write_back_en));
    bufp->fullBit(oldp+102,(vlSelf->main_mem_addr));
    bufp->fullBit(oldp+103,(vlSelf->main_mem_fetch));
    bufp->fullIData(oldp+104,(0x20U),32);
    bufp->fullIData(oldp+105,(8U),32);
}
