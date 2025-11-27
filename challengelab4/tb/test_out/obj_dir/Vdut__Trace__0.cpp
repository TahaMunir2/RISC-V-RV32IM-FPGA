// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(((((0x20000U >= (0x3ffffU 
                                                & ((IData)(3U) 
                                                   + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                   ? vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                  [(0x3ffffU & ((IData)(3U) 
                                                + vlSelf->top__DOT__pc_block__DOT__internal_pc))]
                                   : 0U) << 0x18U) 
                                | ((((0x20000U >= (0x3ffffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                      ? vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                     [(0x3ffffU & ((IData)(2U) 
                                                   + vlSelf->top__DOT__pc_block__DOT__internal_pc))]
                                      : 0U) << 0x10U) 
                                   | ((((0x20000U >= 
                                         (0x3ffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                         ? vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                        [(0x3ffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->top__DOT__pc_block__DOT__internal_pc))]
                                         : 0U) << 8U) 
                                      | ((0x20000U 
                                          >= (0x3ffffU 
                                              & vlSelf->top__DOT__pc_block__DOT__internal_pc))
                                          ? vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                         [(0x3ffffU 
                                           & vlSelf->top__DOT__pc_block__DOT__internal_pc)]
                                          : 0U))))),32);
        bufp->chgCData(oldp+1,((3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc))),2);
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__pc_block__DOT__internal_pc),32);
        bufp->chgIData(oldp+3,(((IData)(4U) + vlSelf->top__DOT__pc_block__DOT__internal_pc)),32);
        bufp->chgIData(oldp+4,(vlSelf->top__DOT__instr_d),32);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__regOp2),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__output_DataMem),32);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__ResultSrc),2);
        bufp->chgBit(oldp+8,(vlSelf->top__DOT__MemWrite));
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__SizeWrite),2);
        bufp->chgBit(oldp+10,(vlSelf->top__DOT__ALUsrc2));
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__LoadSize),2);
        bufp->chgBit(oldp+12,(vlSelf->top__DOT__LoadUnsigned));
        bufp->chgBit(oldp+13,(vlSelf->top__DOT__F_Write));
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__PCWrite));
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__PCD),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__PCD_save),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__ImmExt_d),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__PCPlus4dE),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__RD1_e),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__RD2_e),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__pc_e),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__RdE),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__ImmExt_e),32);
        bufp->chgBit(oldp+24,(vlSelf->top__DOT__RegWrite_d));
        bufp->chgBit(oldp+25,(vlSelf->top__DOT__Branch_d));
        bufp->chgCData(oldp+26,(vlSelf->top__DOT__ALUCtrl_d),4);
        bufp->chgBit(oldp+27,(vlSelf->top__DOT__ALUSrc_d));
        bufp->chgBit(oldp+28,(vlSelf->top__DOT__RegWriteE));
        bufp->chgCData(oldp+29,(vlSelf->top__DOT__ResultSrcE),2);
        bufp->chgBit(oldp+30,(vlSelf->top__DOT__MemWriteE));
        bufp->chgBit(oldp+31,(vlSelf->top__DOT__Jump_e));
        bufp->chgBit(oldp+32,(vlSelf->top__DOT__Branch_e));
        bufp->chgCData(oldp+33,(vlSelf->top__DOT__ALUCtrl_e),4);
        bufp->chgBit(oldp+34,(vlSelf->top__DOT__ALUSrc_e));
        bufp->chgCData(oldp+35,(vlSelf->top__DOT__SizeWriteE),2);
        bufp->chgCData(oldp+36,(vlSelf->top__DOT__LoadSizeE),2);
        bufp->chgBit(oldp+37,(vlSelf->top__DOT__LoadUnsignedE));
        bufp->chgBit(oldp+38,(vlSelf->top__DOT__ALUSrc2_e));
        bufp->chgCData(oldp+39,((7U & (vlSelf->top__DOT__instr_d 
                                       >> 0xcU))),3);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__PCPlus4M),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__RdM),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__ALUResultM),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__WriteDataM),32);
        bufp->chgBit(oldp+44,(vlSelf->top__DOT__RegWriteM));
        bufp->chgBit(oldp+45,(vlSelf->top__DOT__MemWriteM));
        bufp->chgCData(oldp+46,(vlSelf->top__DOT__SizeWriteM),2);
        bufp->chgCData(oldp+47,(vlSelf->top__DOT__LoadSizeM),2);
        bufp->chgBit(oldp+48,(vlSelf->top__DOT__LoadUnsignedm));
        bufp->chgBit(oldp+49,(vlSelf->top__DOT__RegWriteW));
        bufp->chgCData(oldp+50,(vlSelf->top__DOT__ResultSrcW),2);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__ALUResultW),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__ReadDataW),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__RdW),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__ResultW),32);
        bufp->chgBit(oldp+56,((1U & (IData)(vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m))));
        bufp->chgCData(oldp+57,(vlSelf->top__DOT__ForwardAE),2);
        bufp->chgCData(oldp+58,(vlSelf->top__DOT__ForwardBE),2);
        bufp->chgCData(oldp+59,(vlSelf->top__DOT____Vcellout__control__ImmSrc),3);
        bufp->chgCData(oldp+60,((0x7fU & vlSelf->top__DOT__instr_d)),7);
        bufp->chgCData(oldp+61,((vlSelf->top__DOT__instr_d 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data),32);
        bufp->chgIData(oldp+63,((0x1fU & (vlSelf->top__DOT__instr_d 
                                          >> 0xfU))),32);
        bufp->chgIData(oldp+64,((0x1fU & (vlSelf->top__DOT__instr_d 
                                          >> 0x14U))),32);
        bufp->chgIData(oldp+65,((0x1fU & (vlSelf->top__DOT__instr_d 
                                          >> 7U))),32);
        bufp->chgCData(oldp+66,(vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m),2);
        bufp->chgBit(oldp+67,((1U & (IData)(vlSelf->top__DOT__ForwardAE))));
        bufp->chgBit(oldp+68,((1U & ((IData)(vlSelf->top__DOT__ForwardAE) 
                                     >> 1U))));
        bufp->chgBit(oldp+69,((1U & (IData)(vlSelf->top__DOT__ForwardBE))));
        bufp->chgBit(oldp+70,((1U & ((IData)(vlSelf->top__DOT__ForwardBE) 
                                     >> 1U))));
        bufp->chgCData(oldp+71,((0x1fU & vlSelf->top__DOT__RD1_e)),5);
        bufp->chgCData(oldp+72,((0x1fU & vlSelf->top__DOT__RD2_e)),5);
        bufp->chgCData(oldp+73,((0x1fU & vlSelf->top__DOT__RdM)),5);
        bufp->chgCData(oldp+74,((0x1fU & vlSelf->top__DOT__RdE)),5);
        bufp->chgCData(oldp+75,((0x1fU & vlSelf->top__DOT__RdW)),5);
        bufp->chgCData(oldp+76,((1U & (IData)(vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m))),2);
        bufp->chgBit(oldp+77,(vlSelf->top__DOT__hazard_unit__DOT__wStall));
        bufp->chgIData(oldp+78,((vlSelf->top__DOT__pc_block__DOT__internal_pc 
                                 + vlSelf->top__DOT__ImmOp)),32);
        bufp->chgIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__regfile_array[0]),32);
        bufp->chgIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__regfile_array[1]),32);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__regfile_array[2]),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__regfile_array[3]),32);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__regfile_array[4]),32);
        bufp->chgIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__regfile_array[5]),32);
        bufp->chgIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__regfile_array[6]),32);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__regfile_array[7]),32);
        bufp->chgIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__regfile_array[8]),32);
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__regfile_array[9]),32);
        bufp->chgIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__regfile_array[10]),32);
        bufp->chgIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__regfile_array[11]),32);
        bufp->chgIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__regfile_array[12]),32);
        bufp->chgIData(oldp+92,(vlSelf->top__DOT__regfile__DOT__regfile_array[13]),32);
        bufp->chgIData(oldp+93,(vlSelf->top__DOT__regfile__DOT__regfile_array[14]),32);
        bufp->chgIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__regfile_array[15]),32);
        bufp->chgIData(oldp+95,(vlSelf->top__DOT__regfile__DOT__regfile_array[16]),32);
        bufp->chgIData(oldp+96,(vlSelf->top__DOT__regfile__DOT__regfile_array[17]),32);
        bufp->chgIData(oldp+97,(vlSelf->top__DOT__regfile__DOT__regfile_array[18]),32);
        bufp->chgIData(oldp+98,(vlSelf->top__DOT__regfile__DOT__regfile_array[19]),32);
        bufp->chgIData(oldp+99,(vlSelf->top__DOT__regfile__DOT__regfile_array[20]),32);
        bufp->chgIData(oldp+100,(vlSelf->top__DOT__regfile__DOT__regfile_array[21]),32);
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__regfile__DOT__regfile_array[22]),32);
        bufp->chgIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__regfile_array[23]),32);
        bufp->chgIData(oldp+103,(vlSelf->top__DOT__regfile__DOT__regfile_array[24]),32);
        bufp->chgIData(oldp+104,(vlSelf->top__DOT__regfile__DOT__regfile_array[25]),32);
        bufp->chgIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__regfile_array[26]),32);
        bufp->chgIData(oldp+106,(vlSelf->top__DOT__regfile__DOT__regfile_array[27]),32);
        bufp->chgIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__regfile_array[28]),32);
        bufp->chgIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__regfile_array[29]),32);
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__regfile_array[30]),32);
        bufp->chgIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__regfile_array[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+111,(vlSelf->top__DOT__EQ));
        bufp->chgBit(oldp+112,((1U & (IData)(vlSelf->top__DOT____Vcellout__control__PCSrc))));
        bufp->chgIData(oldp+113,(vlSelf->top__DOT__output_ALU),32);
        bufp->chgIData(oldp+114,(vlSelf->top__DOT__ALUop2),32);
        bufp->chgBit(oldp+115,(vlSelf->top__DOT__LT));
        bufp->chgBit(oldp+116,(vlSelf->top__DOT__LTU));
        bufp->chgBit(oldp+117,(vlSelf->top__DOT__flush_d_exec));
        bufp->chgBit(oldp+118,(vlSelf->top__DOT__flush_f_d));
        bufp->chgBit(oldp+119,(vlSelf->top__DOT__PCSrcE));
        bufp->chgIData(oldp+120,(vlSelf->top__DOT__SrcAE),32);
        bufp->chgIData(oldp+121,(vlSelf->top__DOT__SrcBE),32);
        bufp->chgCData(oldp+122,(vlSelf->top__DOT____Vcellout__control__PCSrc),2);
        bufp->chgCData(oldp+123,(vlSelf->top__DOT__PCSrcE),2);
    }
    bufp->chgBit(oldp+124,(vlSelf->clk));
    bufp->chgBit(oldp+125,(vlSelf->rst));
    bufp->chgIData(oldp+126,(vlSelf->a0),32);
    bufp->chgIData(oldp+127,(vlSelf->top__DOT__ALUop1),32);
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
