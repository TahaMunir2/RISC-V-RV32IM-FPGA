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
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [3U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.top__DOT__EQ));
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__RegWrite));
        bufp->chgCData(oldp+2,(vlSelfRef.top__DOT__ALUCtrl),3);
        bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__ALUSrc));
        bufp->chgCData(oldp+4,(vlSelfRef.top__DOT__ImmSrc),2);
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__PCSrc));
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__ImmOp),32);
        bufp->chgBit(oldp+7,(vlSelfRef.top__DOT__reg_entry));
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem),32);
        bufp->chgIData(oldp+11,(((IData)(vlSelfRef.top__DOT__reg_entry)
                                  ? vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem
                                  : vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU)),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__instr),32);
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__pc_block__DOT__internal_pc),32);
        bufp->chgCData(oldp+14,((0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_h7cd686f0_0_0) 
                                          >> 7U))),5);
        bufp->chgCData(oldp+15,((0x1fU & (vlSelfRef.top__DOT__instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+16,((0x1fU & (vlSelfRef.__VdfgRegularize_h7cd686f0_0_1 
                                          >> 0xfU))),5);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                                [(0x1fU & (vlSelfRef.top__DOT__instr 
                                           >> 0x14U))]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[1]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[2]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[3]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[4]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[5]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[6]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[7]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[8]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[9]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[10]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[11]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[12]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[13]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[14]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[15]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[16]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[17]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[18]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[19]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[20]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[21]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[22]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[23]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[24]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[25]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[26]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[27]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[28]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[29]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[30]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[31]),32);
        bufp->chgCData(oldp+51,(vlSelfRef.top__DOT__control__DOT__op),7);
        bufp->chgCData(oldp+52,(vlSelfRef.top__DOT__control__DOT__funct3),3);
        bufp->chgCData(oldp+53,((0x7fU & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                          [(0xffU & 
                                            ((IData)(3U) 
                                             + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                          >> 1U))),7);
        bufp->chgIData(oldp+54,(((IData)(4U) + vlSelfRef.top__DOT__pc_block__DOT__internal_pc)),32);
    }
    bufp->chgBit(oldp+55,(vlSelfRef.clk));
    bufp->chgBit(oldp+56,(vlSelfRef.rst));
    bufp->chgIData(oldp+57,(vlSelfRef.a0),32);
    bufp->chgIData(oldp+58,((vlSelfRef.top__DOT__ImmOp 
                             + vlSelfRef.top__DOT__pc_block__DOT__internal_pc)),32);
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
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
