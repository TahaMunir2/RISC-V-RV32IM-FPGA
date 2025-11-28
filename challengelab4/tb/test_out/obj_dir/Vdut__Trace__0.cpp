// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0_sub_0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,((0x1fU & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+1,((0x1fU & (vlSelfRef.top__DOT__InstrD 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+2,((0x1fU & (vlSelfRef.top__DOT__InstrD 
                                         >> 7U))),5);
        bufp->chgCData(oldp+3,(vlSelfRef.top__DOT__Rs1E),5);
        bufp->chgCData(oldp+4,(vlSelfRef.top__DOT__Rs2E),5);
        bufp->chgCData(oldp+5,(vlSelfRef.top__DOT__RdE),5);
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__RD1E),32);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__RD2E),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__regfile__DOT__regfile_array
                               [(0x1fU & (vlSelfRef.top__DOT__InstrD 
                                          >> 0xfU))]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__regfile__DOT__regfile_array
                               [(0x1fU & (vlSelfRef.top__DOT__InstrD 
                                          >> 0x14U))]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__ExtImmE),32);
        bufp->chgIData(oldp+11,(((0U == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                  ? (((- (IData)((vlSelfRef.top__DOT__InstrD 
                                                  >> 0x1fU))) 
                                      << 0xcU) | (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x14U))
                                  : ((1U == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                      ? (((- (IData)(
                                                     (vlSelfRef.top__DOT__InstrD 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelfRef.top__DOT__InstrD 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelfRef.top__DOT__InstrD 
                                                  >> 7U))))
                                      : ((2U == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                          ? (((- (IData)(
                                                         (vlSelfRef.top__DOT__InstrD 
                                                          >> 0x1fU))) 
                                              << 0xcU) 
                                             | ((0x800U 
                                                 & (vlSelfRef.top__DOT__InstrD 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelfRef.top__DOT__InstrD 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelfRef.top__DOT__InstrD 
                                                         >> 7U)))))
                                          : ((4U == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                              ? (0xfffff000U 
                                                 & vlSelfRef.top__DOT__InstrD)
                                              : ((3U 
                                                  == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelfRef.top__DOT__InstrD 
                                                               >> 0x1fU))) 
                                                   << 0x14U) 
                                                  | (((0xff000U 
                                                       & vlSelfRef.top__DOT__InstrD) 
                                                      | (0x800U 
                                                         & (vlSelfRef.top__DOT__InstrD 
                                                            >> 9U))) 
                                                     | (0x7feU 
                                                        & (vlSelfRef.top__DOT__InstrD 
                                                           >> 0x14U))))
                                                  : 0U)))))),32);
        bufp->chgCData(oldp+12,(vlSelfRef.top__DOT__ResultSrcD),2);
        bufp->chgCData(oldp+13,(vlSelfRef.top__DOT__ResultSrcM),2);
        bufp->chgCData(oldp+14,(vlSelfRef.top__DOT__PCSrcD),2);
        bufp->chgIData(oldp+15,((((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                   [(0x1ffffU & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                   << 0x18U) | (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                [(0x1ffffU 
                                                  & ((IData)(2U) 
                                                     + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                << 0x10U)) 
                                 | ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                     [(0x1ffffU & ((IData)(1U) 
                                                   + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                     << 8U) | vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                    [(0x1ffffU & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]))),32);
        bufp->chgBit(oldp+16,(vlSelfRef.top__DOT__RegWriteD));
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__ReadDataM),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__WriteDataE),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__InstrD),32);
        bufp->chgBit(oldp+20,(vlSelfRef.top__DOT__EQ));
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__pc_block__DOT__internal_pc),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__PCD),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__PCE),32);
        bufp->chgIData(oldp+24,(((IData)(4U) + vlSelfRef.top__DOT__pc_block__DOT__internal_pc)),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__PCPlus4D),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__PCPlus4E),32);
        bufp->chgCData(oldp+27,(vlSelfRef.top__DOT__ImmSrcD),3);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__ALUResultE),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__ALUop1),32);
        bufp->chgBit(oldp+30,(vlSelfRef.top__DOT__LT));
        bufp->chgBit(oldp+31,(vlSelfRef.top__DOT__LTU));
        bufp->chgBit(oldp+32,(vlSelfRef.top__DOT__MemWriteD));
        bufp->chgCData(oldp+33,(vlSelfRef.top__DOT__SizeWriteD),2);
        bufp->chgCData(oldp+34,(vlSelfRef.top__DOT__LoadSizeD),2);
        bufp->chgBit(oldp+35,(vlSelfRef.top__DOT__LoadUnsignedD));
        bufp->chgBit(oldp+36,(vlSelfRef.top__DOT__flush_d_exec));
        bufp->chgBit(oldp+37,(vlSelfRef.top__DOT__flush_f_d));
        bufp->chgBit(oldp+38,(vlSelfRef.top__DOT__F_Write));
        bufp->chgBit(oldp+39,(vlSelfRef.top__DOT__PCWrite));
        bufp->chgCData(oldp+40,(vlSelfRef.top__DOT__ALUCtrlD),4);
        bufp->chgBit(oldp+41,(vlSelfRef.top__DOT__ALUSrcD));
        bufp->chgBit(oldp+42,(vlSelfRef.top__DOT__ALUSrc2D));
        bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__RegWriteE));
        bufp->chgCData(oldp+44,(vlSelfRef.top__DOT__ResultSrcE),2);
        bufp->chgBit(oldp+45,(vlSelfRef.top__DOT__MemWriteE));
        bufp->chgCData(oldp+46,(vlSelfRef.top__DOT__ALUCtrlE),4);
        bufp->chgBit(oldp+47,(vlSelfRef.top__DOT__ALUSrcE));
        bufp->chgCData(oldp+48,(vlSelfRef.top__DOT__SizeWriteE),2);
        bufp->chgCData(oldp+49,(vlSelfRef.top__DOT__LoadSizeE),2);
        bufp->chgBit(oldp+50,(vlSelfRef.top__DOT__LoadUnsignedE));
        bufp->chgBit(oldp+51,(vlSelfRef.top__DOT__ALUSrc2E));
        bufp->chgCData(oldp+52,(vlSelfRef.top__DOT__PCSrcE),2);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__PCPlus4M),32);
        bufp->chgCData(oldp+54,(vlSelfRef.top__DOT__RdM),5);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__ALUResultM),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__WriteDataM),32);
        bufp->chgBit(oldp+57,(vlSelfRef.top__DOT__RegWriteM));
        bufp->chgBit(oldp+58,(vlSelfRef.top__DOT__MemWriteM));
        bufp->chgCData(oldp+59,(vlSelfRef.top__DOT__SizeWriteM),2);
        bufp->chgCData(oldp+60,(vlSelfRef.top__DOT__LoadSizeM),2);
        bufp->chgBit(oldp+61,(vlSelfRef.top__DOT__LoadUnsignedM));
        bufp->chgBit(oldp+62,(vlSelfRef.top__DOT__RegWriteW));
        bufp->chgCData(oldp+63,(vlSelfRef.top__DOT__ResultSrcW),2);
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__ALUResultW),32);
        bufp->chgIData(oldp+65,(vlSelfRef.top__DOT__ReadDataW),32);
        bufp->chgCData(oldp+66,(vlSelfRef.top__DOT__RdW),5);
        bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__ResultW),32);
        bufp->chgCData(oldp+69,(vlSelfRef.top__DOT__ForwardAE),2);
        bufp->chgCData(oldp+70,(vlSelfRef.top__DOT__ForwardBE),2);
        bufp->chgIData(oldp+71,(((1U & (IData)(vlSelfRef.top__DOT__ForwardAE))
                                  ? vlSelfRef.top__DOT__ResultW
                                  : vlSelfRef.top__DOT__RD1E)),32);
        bufp->chgIData(oldp+72,(vlSelfRef.top__DOT__SrcBE),32);
        bufp->chgCData(oldp+73,((0x7fU & vlSelfRef.top__DOT__InstrD)),7);
        bufp->chgCData(oldp+74,((7U & (vlSelfRef.top__DOT__InstrD 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+75,((vlSelfRef.top__DOT__InstrD 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+76,(vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data),32);
        bufp->chgBit(oldp+77,((1U & (IData)(vlSelfRef.top__DOT__ForwardAE))));
        bufp->chgBit(oldp+78,((1U & ((IData)(vlSelfRef.top__DOT__ForwardAE) 
                                     >> 1U))));
        bufp->chgBit(oldp+79,((1U & (IData)(vlSelfRef.top__DOT__ForwardBE))));
        bufp->chgBit(oldp+80,((1U & ((IData)(vlSelfRef.top__DOT__ForwardBE) 
                                     >> 1U))));
        bufp->chgBit(oldp+81,(vlSelfRef.top__DOT__hazard_unit__DOT__wStall));
        bufp->chgIData(oldp+82,((vlSelfRef.top__DOT__ExtImmE 
                                 + vlSelfRef.top__DOT__PCE)),32);
        bufp->chgIData(oldp+83,(((vlSelfRef.top__DOT__ExtImmE 
                                  + vlSelfRef.top__DOT__PCE) 
                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc)),32);
        bufp->chgIData(oldp+84,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[0]),32);
        bufp->chgIData(oldp+85,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[1]),32);
        bufp->chgIData(oldp+86,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[2]),32);
        bufp->chgIData(oldp+87,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[3]),32);
        bufp->chgIData(oldp+88,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[4]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[5]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[6]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[7]),32);
        bufp->chgIData(oldp+92,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[8]),32);
        bufp->chgIData(oldp+93,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[9]),32);
        bufp->chgIData(oldp+94,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[10]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[11]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[12]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[13]),32);
        bufp->chgIData(oldp+98,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[14]),32);
        bufp->chgIData(oldp+99,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[15]),32);
        bufp->chgIData(oldp+100,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[16]),32);
        bufp->chgIData(oldp+101,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[17]),32);
        bufp->chgIData(oldp+102,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[18]),32);
        bufp->chgIData(oldp+103,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[19]),32);
        bufp->chgIData(oldp+104,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[20]),32);
        bufp->chgIData(oldp+105,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[21]),32);
        bufp->chgIData(oldp+106,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[22]),32);
        bufp->chgIData(oldp+107,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[23]),32);
        bufp->chgIData(oldp+108,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[24]),32);
        bufp->chgIData(oldp+109,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[25]),32);
        bufp->chgIData(oldp+110,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[26]),32);
        bufp->chgIData(oldp+111,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[27]),32);
        bufp->chgIData(oldp+112,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[28]),32);
        bufp->chgIData(oldp+113,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[29]),32);
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[30]),32);
        bufp->chgIData(oldp+115,(vlSelfRef.top__DOT__regfile__DOT__regfile_array[31]),32);
    }
    bufp->chgBit(oldp+116,(vlSelfRef.clk));
    bufp->chgBit(oldp+117,(vlSelfRef.rst));
    bufp->chgIData(oldp+118,(vlSelfRef.a0),32);
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
}
