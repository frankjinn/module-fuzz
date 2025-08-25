// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_top__Syms.h"


VL_ATTR_COLD void Vtb_top___024root__trace_init_sub__TOP__0(Vtb_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_init_sub__TOP__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+102,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1,0,"in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 154,0);
    tracep->declArray(c+90,0,"out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 158,0);
    tracep->declBus(c+103,0,"cyc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+104,0,"cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+105,0,"seed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+6,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+102,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 154,0);
    tracep->declArray(c+90,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 158,0);
    tracep->declBus(c+7,0,"const_arith_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+95,0,"const_arith_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+106,0,"const_compare_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+97,0,"const_compare_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+8,0,"const_concat_repl_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+9,0,"const_concat_repl_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declQuad(c+10,0,"const_conditional_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBus(c+98,0,"const_conditional_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+12,0,"const_logic_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+13,0,"const_logic_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+14,0,"const_nested_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+15,0,"const_nested_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+16,0,"const_partselect_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+17,0,"const_partselect_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+18,0,"const_reduce_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+19,0,"const_reduce_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+20,0,"const_shift_wrapper_in_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+21,0,"const_shift_wrapper_out_flat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("u_const_arith_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+7,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+95,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+22,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+23,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+107,0,"sum_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+24,0,"diff_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+25,0,"prod_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+26,0,"quot_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+27,0,"rem_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_const_arith", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+22,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+23,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+107,0,"sum_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+24,0,"diff_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+25,0,"prod_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+26,0,"quot_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+27,0,"rem_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_compare_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+106,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+97,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+28,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+29,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+30,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+31,0,"eq_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"neq_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"lt_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"le_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"gt_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"ge_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"case_eq_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"case_neq_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_const_compare", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+28,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+29,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+30,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+31,0,"eq_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"neq_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"lt_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"le_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"gt_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"ge_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"case_eq_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"case_neq_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_concat_repl_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+8,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+9,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+37,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+38,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+39,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+40,0,"cat_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"rep_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"rep2_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->pushPrefix("u_const_concat_repl", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+37,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+38,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+39,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+40,0,"cat_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"rep_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"rep2_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_conditional_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declQuad(c+10,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBus(c+98,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+43,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+47,0,"sel1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"sel2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"cond1_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+101,0,"cond2_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"cond3_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_const_conditional", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+43,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+47,0,"sel1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"sel2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"cond1_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+101,0,"cond2_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"cond3_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_logic_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+12,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+13,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+50,0,"x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+51,0,"y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+52,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"and_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+55,0,"or_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+56,0,"xor_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+57,0,"not_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+58,0,"land_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"lor_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"lnot_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_const_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+50,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+51,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+52,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"and_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+55,0,"or_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+56,0,"xor_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+57,0,"not_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+58,0,"land_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"lor_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"lnot_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_nested_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+14,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+15,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+61,0,"p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+62,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+63,0,"r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+64,0,"s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+15,0,"nested_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_const_nested", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+61,0,"p",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+62,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+63,0,"r",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+64,0,"s",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+15,0,"nested_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+65,0,"add_pq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+66,0,"shl_rs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+67,0,"mul_part",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"xor_qr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+69,0,"and_part",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+70,0,"denom",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+71,0,"div_part",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+72,0,"mod_part",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_partselect_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+16,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+17,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+73,0,"data1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+74,0,"data2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+75,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+76,0,"sel1_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+77,0,"sel2_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+78,0,"ovf_range",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_const_partselect", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"data1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+74,0,"data2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+75,0,"idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+76,0,"sel1_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+77,0,"sel2_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+78,0,"ovf_range",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_reduce_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+18,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+19,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+18,0,"in_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+79,0,"red_and_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"red_or_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"red_xor_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"red_nand_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"red_nor_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"red_xnor_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_const_reduce", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+18,0,"in_vec",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+79,0,"red_and_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"red_or_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"red_xor_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"red_nand_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"red_nor_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"red_xnor_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_const_shift_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+20,0,"in_flat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+21,0,"out_flat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+85,0,"data_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+86,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+87,0,"shl_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+88,0,"shr_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+89,0,"ashr_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_const_shift", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+85,0,"data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+86,0,"shift_amt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+87,0,"shl_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+88,0,"shr_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+89,0,"ashr_c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+111,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_top___024root__trace_init_top(Vtb_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_init_top\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_top___024root__trace_register(Vtb_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_register\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_const_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtb_top___024root__trace_full_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_full_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_top___024root__trace_full_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_full_0_sub_0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_2;
    // Body
    bufp->fullWData(oldp+1,(vlSelfRef.tb_top__DOT__in_flat),155);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_top__DOT__i),32);
    bufp->fullSData(oldp+7,((0xffffU & vlSelfRef.tb_top__DOT__in_flat[0U])),16);
    bufp->fullSData(oldp+8,((0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       >> 5U))),10);
    bufp->fullIData(oldp+9,(((0x3fc000U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           << 7U)) 
                             | ((0x3fc0U & ((0x3c00U 
                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                >> 1U)) 
                                            | (0x3c0U 
                                               & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  >> 5U)))) 
                                | (0x3fU & ((0x30U 
                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                >> 1U)) 
                                            | ((0xcU 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 3U)) 
                                               | (3U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                     >> 5U)))))))),22);
    bufp->fullQData(oldp+10,((0x3ffffffffULL & (((QData)((IData)(
                                                                 vlSelfRef.tb_top__DOT__in_flat[4U])) 
                                                 << 0x11U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.tb_top__DOT__in_flat[3U])) 
                                                   >> 0xfU)))),34);
    bufp->fullSData(oldp+12,((0x3ffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        >> 0x11U))),10);
    bufp->fullIData(oldp+13,((((0x78000U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                              << 0x18U) 
                                             | (0xff8000U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   >> 8U))) 
                                            & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                << 0x1cU) 
                                               | (0xfff8000U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                     >> 4U))))) 
                               | (0x7800U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                               << 0x14U) 
                                              | (0xff800U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                    >> 0xcU))) 
                                             | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                 << 0x18U) 
                                                | (0xfff800U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 8U)))))) 
                              | ((0x780U & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                              << 0x10U) 
                                             | (0xff80U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   >> 0x10U))) 
                                            ^ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                << 0x14U) 
                                               | (0xfff80U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                     >> 0xcU))))) 
                                 | ((0x78U & ((~ ((
                                                   vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   << 9U) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                     >> 0x17U))) 
                                              << 3U)) 
                                    | (((IData)((0x60000U 
                                                 == 
                                                 (0x60000U 
                                                  & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                        << 2U) | (((IData)(
                                                           (0U 
                                                            != 
                                                            (0x60000U 
                                                             & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                   << 1U) 
                                                  | (1U 
                                                     & (~ 
                                                        (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                         >> 0x12U))))))))),19);
    bufp->fullIData(oldp+14,((0x7ffffffU & ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                             << 5U) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               >> 0x1bU)))),27);
    bufp->fullCData(oldp+15,((0xffU & ((((0xffU & (
                                                   ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     << 0x12U) 
                                                    | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                       >> 0xeU)) 
                                                   + 
                                                   ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     << 0x1aU) 
                                                    | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                       >> 6U)))) 
                                         * (0xffU & 
                                            (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               << 2U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x1eU)) 
                                             << (7U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x1bU))))) 
                                        & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                             << 0x1aU) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               >> 6U)) 
                                           ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                               << 2U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x1eU)))) 
                                       | VL_MODDIV_III(8, 
                                                       ((0U 
                                                         == 
                                                         (0xffU 
                                                          & ((IData)(1U) 
                                                             + 
                                                             ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                               << 0x1aU) 
                                                              | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                 >> 6U)))))
                                                         ? 0U
                                                         : 
                                                        (0xffU 
                                                         & VL_DIV_III(8, 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                          >> 0xeU)), 
                                                                      (0xffU 
                                                                       & ((IData)(1U) 
                                                                          + 
                                                                          ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            << 0x1aU) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 6U))))))), (IData)(3U))))),8);
    bufp->fullIData(oldp+16,((0xfffffU & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                           << 0xaU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                             >> 0x16U)))),20);
    bufp->fullCData(oldp+17,(((0xf0U & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 2U)) | (
                                                   (((0xcU 
                                                      >= 
                                                      (0xfU 
                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                          >> 0x16U)))
                                                      ? 
                                                     (7U 
                                                      & (((0U 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(0x3aU) 
                                                               + 
                                                               (7U 
                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                   >> 0x16U)))))
                                                           ? 0U
                                                           : 
                                                          (vlSelfRef.tb_top__DOT__in_flat[
                                                           (((IData)(0x3cU) 
                                                             + 
                                                             (7U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                 >> 0x16U))) 
                                                            >> 5U)] 
                                                           << 
                                                           ((IData)(0x20U) 
                                                            - 
                                                            (0x1fU 
                                                             & ((IData)(0x3aU) 
                                                                + 
                                                                (7U 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                    >> 0x16U))))))) 
                                                         | (vlSelfRef.tb_top__DOT__in_flat[
                                                            (((IData)(0x3aU) 
                                                              + 
                                                              (7U 
                                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                  >> 0x16U))) 
                                                             >> 5U)] 
                                                            >> 
                                                            (0x1fU 
                                                             & ((IData)(0x3aU) 
                                                                + 
                                                                (7U 
                                                                 & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                    >> 0x16U)))))))
                                                      : 0U) 
                                                    << 1U) 
                                                   | (0xcU 
                                                      < 
                                                      (0xfU 
                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                          >> 0x16U)))))),8);
    bufp->fullCData(oldp+18,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                      >> 1U))),4);
    bufp->fullCData(oldp+19,(((((0xfU == (0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  >> 1U))) 
                                << 5U) | (((0U != (0xfU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      >> 1U))) 
                                           << 4U) | 
                                          (8U & (VL_REDXOR_32(
                                                              (0xfU 
                                                               & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                  >> 1U))) 
                                                 << 3U)))) 
                              | ((4U & ((~ (0xfU == 
                                            (0xfU & 
                                             (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                              >> 1U)))) 
                                        << 2U)) | (
                                                   (2U 
                                                    & ((~ 
                                                        (0U 
                                                         != 
                                                         (0xfU 
                                                          & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                             >> 1U)))) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (~ 
                                                         VL_REDXOR_32(
                                                                      (0xfU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                          >> 1U))))))))),6);
    bufp->fullSData(oldp+20,((0x7ffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                        >> 0x10U))),11);
    bufp->fullIData(oldp+21,(((0xff0000U & ((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                               << 0xdU) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x13U)) 
                                             << (7U 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    >> 0x10U))) 
                                            << 0x10U)) 
                              | ((0xff00U & (((0xffU 
                                               & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  >> 0x13U)) 
                                              >> (7U 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     >> 0x10U))) 
                                             << 8U)) 
                                 | (0xffU & VL_SHIFTRS_III(8,8,3, 
                                                           (0xffU 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 0x13U)), 
                                                           (7U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                               >> 0x10U))))))),24);
    bufp->fullCData(oldp+22,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 8U))),8);
    bufp->fullCData(oldp+23,((0xffU & vlSelfRef.tb_top__DOT__in_flat[0U])),8);
    bufp->fullCData(oldp+24,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                         << 0x18U) 
                                        | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                           >> 8U)) 
                                       - vlSelfRef.tb_top__DOT__in_flat[0U]))),8);
    bufp->fullCData(oldp+25,((0xffU & ((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 8U)) 
                                       * (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U])))),8);
    bufp->fullCData(oldp+26,(((0U != (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U]))
                               ? (0xffU & VL_DIV_III(8, 
                                                     (0xffU 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                         >> 8U)), 
                                                     (0xffU 
                                                      & vlSelfRef.tb_top__DOT__in_flat[0U])))
                               : 0U)),8);
    bufp->fullCData(oldp+27,(((0U != (0xffU & vlSelfRef.tb_top__DOT__in_flat[0U]))
                               ? (0xffU & VL_MODDIV_III(8, 
                                                        (0xffU 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                            >> 8U)), 
                                                        (0xffU 
                                                         & vlSelfRef.tb_top__DOT__in_flat[0U])))
                               : 0U)),8);
    bufp->fullCData(oldp+28,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                        << 7U) | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0x19U)))),8);
    bufp->fullCData(oldp+29,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                       >> 0x11U))),8);
    bufp->fullCData(oldp+30,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                      >> 0xaU))),4);
    bufp->fullBit(oldp+31,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       << 7U) | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                            == (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x11U)))));
    bufp->fullBit(oldp+32,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       << 7U) | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                            != (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x11U)))));
    bufp->fullBit(oldp+33,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       << 7U) | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                            < (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0x11U)))));
    bufp->fullBit(oldp+34,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       << 7U) | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                            <= (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x11U)))));
    bufp->fullBit(oldp+35,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       << 7U) | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                            > (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        >> 0x11U)))));
    bufp->fullBit(oldp+36,(((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       << 7U) | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                            >= (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                         >> 0x11U)))));
    bufp->fullCData(oldp+37,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                      >> 0xbU))),4);
    bufp->fullCData(oldp+38,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                      >> 7U))),4);
    bufp->fullCData(oldp+39,((3U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                    >> 5U))),2);
    bufp->fullCData(oldp+40,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       >> 7U))),8);
    bufp->fullCData(oldp+41,((0xffU & ((0xf0U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 7U)) 
                                       | (0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  >> 0xbU))))),8);
    bufp->fullCData(oldp+42,((0x3fU & ((0x30U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 1U)) 
                                       | ((0xcU & (
                                                   vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 3U)) 
                                          | (3U & (
                                                   vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   >> 5U)))))),6);
    bufp->fullCData(oldp+43,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                       >> 9U))),8);
    bufp->fullCData(oldp+44,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                       >> 1U))),8);
    bufp->fullCData(oldp+45,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        << 7U) | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  >> 0x19U)))),8);
    bufp->fullCData(oldp+46,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                       >> 0x11U))),8);
    bufp->fullBit(oldp+47,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                  >> 0x10U))));
    bufp->fullBit(oldp+48,((1U & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                  >> 0xfU))));
    bufp->fullCData(oldp+49,((0xffU & (VL_LTS_III(8, 
                                                  (0xffU 
                                                   & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                       << 7U) 
                                                      | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                         >> 0x19U))), 
                                                  (0xffU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                      >> 0x11U)))
                                        ? ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                            << 0x17U) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                              >> 9U))
                                        : ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                            << 0x1fU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                              >> 1U))))),8);
    bufp->fullCData(oldp+50,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                      >> 0x17U))),4);
    bufp->fullCData(oldp+51,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                      >> 0x13U))),4);
    bufp->fullBit(oldp+52,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                  >> 0x12U))));
    bufp->fullBit(oldp+53,((1U & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                  >> 0x11U))));
    bufp->fullCData(oldp+54,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        << 9U) | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  >> 0x17U)) 
                                      & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          << 0xdU) 
                                         | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                            >> 0x13U))))),4);
    bufp->fullCData(oldp+55,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        << 9U) | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  >> 0x17U)) 
                                      | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          << 0xdU) 
                                         | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                            >> 0x13U))))),4);
    bufp->fullCData(oldp+56,((0xfU & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                        << 9U) | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                  >> 0x17U)) 
                                      ^ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          << 0xdU) 
                                         | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                            >> 0x13U))))),4);
    bufp->fullCData(oldp+57,((0xfU & (~ ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          << 9U) | 
                                         (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                          >> 0x17U))))),4);
    bufp->fullBit(oldp+58,((IData)((0x60000U == (0x60000U 
                                                 & vlSelfRef.tb_top__DOT__in_flat[4U])))));
    bufp->fullBit(oldp+59,((IData)((0U != (0x60000U 
                                           & vlSelfRef.tb_top__DOT__in_flat[4U])))));
    bufp->fullBit(oldp+60,((1U & (~ (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                     >> 0x12U)))));
    bufp->fullCData(oldp+61,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                       >> 0xeU))),8);
    bufp->fullCData(oldp+62,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                       >> 6U))),8);
    bufp->fullCData(oldp+63,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                        << 2U) | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                  >> 0x1eU)))),8);
    bufp->fullCData(oldp+64,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                    >> 0x1bU))),3);
    bufp->fullCData(oldp+65,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                         << 0x12U) 
                                        | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           >> 0xeU)) 
                                       + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           << 0x1aU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                             >> 6U))))),8);
    bufp->fullCData(oldp+66,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                         << 2U) | (
                                                   vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                   >> 0x1eU)) 
                                       << (7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x1bU))))),8);
    bufp->fullCData(oldp+67,((0xffU & ((0xffU & (((
                                                   vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   << 0x12U) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 0xeU)) 
                                                 + 
                                                 ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   << 0x1aU) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 6U)))) 
                                       * (0xffU & (
                                                   ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     << 2U) 
                                                    | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                       >> 0x1eU)) 
                                                   << 
                                                   (7U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                       >> 0x1bU))))))),8);
    bufp->fullCData(oldp+68,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                         << 0x1aU) 
                                        | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           >> 6U)) 
                                       ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           << 2U) | 
                                          (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                           >> 0x1eU))))),8);
    bufp->fullCData(oldp+69,((0xffU & (((0xffU & ((
                                                   (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x12U) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 0xeU)) 
                                                  + 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                    << 0x1aU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 6U)))) 
                                        * (0xffU & 
                                           (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 2U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                >> 0x1eU)) 
                                            << (7U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                   >> 0x1bU))))) 
                                       & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            << 0x1aU) 
                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              >> 6U)) 
                                          ^ ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                              << 2U) 
                                             | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                >> 0x1eU)))))),8);
    bufp->fullCData(oldp+70,((0xffU & ((IData)(1U) 
                                       + ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                           << 0x1aU) 
                                          | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                             >> 6U))))),8);
    bufp->fullCData(oldp+71,(((0U == (0xffU & ((IData)(1U) 
                                               + ((
                                                   vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   << 0x1aU) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                     >> 6U)))))
                               ? 0U : (0xffU & VL_DIV_III(8, 
                                                          (0xffU 
                                                           & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                              >> 0xeU)), 
                                                          (0xffU 
                                                           & ((IData)(1U) 
                                                              + 
                                                              ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                << 0x1aU) 
                                                               | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                  >> 6U)))))))),8);
    bufp->fullCData(oldp+72,((0xffU & VL_MODDIV_III(8, 
                                                    ((0U 
                                                      == 
                                                      (0xffU 
                                                       & ((IData)(1U) 
                                                          + 
                                                          ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                            << 0x1aU) 
                                                           | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                              >> 6U)))))
                                                      ? 0U
                                                      : 
                                                     (0xffU 
                                                      & VL_DIV_III(8, 
                                                                   (0xffU 
                                                                    & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                       >> 0xeU)), 
                                                                   (0xffU 
                                                                    & ((IData)(1U) 
                                                                       + 
                                                                       ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                         << 0x1aU) 
                                                                        | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                           >> 6U))))))), (IData)(3U)))),8);
    bufp->fullCData(oldp+73,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                       >> 2U))),8);
    bufp->fullCData(oldp+74,((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[2U] 
                                        << 6U) | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                  >> 0x1aU)))),8);
    bufp->fullCData(oldp+75,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                      >> 0x16U))),4);
    bufp->fullCData(oldp+76,((0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                      >> 6U))),4);
    bufp->fullCData(oldp+77,(((0xcU >= (0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                >> 0x16U)))
                               ? (7U & (((0U == (0x1fU 
                                                 & ((IData)(0x3aU) 
                                                    + 
                                                    (7U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                        >> 0x16U)))))
                                          ? 0U : (vlSelfRef.tb_top__DOT__in_flat[
                                                  (((IData)(0x3cU) 
                                                    + 
                                                    (7U 
                                                     & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                        >> 0x16U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x3aU) 
                                                       + 
                                                       (7U 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                           >> 0x16U))))))) 
                                        | (vlSelfRef.tb_top__DOT__in_flat[
                                           (((IData)(0x3aU) 
                                             + (7U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                   >> 0x16U))) 
                                            >> 5U)] 
                                           >> (0x1fU 
                                               & ((IData)(0x3aU) 
                                                  + 
                                                  (7U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                      >> 0x16U)))))))
                               : 0U)),3);
    bufp->fullBit(oldp+78,((0xcU < (0xfU & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                            >> 0x16U)))));
    bufp->fullBit(oldp+79,((0xfU == (0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                             >> 1U)))));
    bufp->fullBit(oldp+80,((0U != (0xfU & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                           >> 1U)))));
    bufp->fullBit(oldp+81,((1U & VL_REDXOR_32((0xfU 
                                               & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                  >> 1U))))));
    bufp->fullBit(oldp+82,((1U & (~ (0xfU == (0xfU 
                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 >> 1U)))))));
    bufp->fullBit(oldp+83,((1U & (~ (0U != (0xfU & 
                                            (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                             >> 1U)))))));
    bufp->fullBit(oldp+84,((1U & (~ VL_REDXOR_32((0xfU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                     >> 1U)))))));
    bufp->fullCData(oldp+85,((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                       >> 0x13U))),8);
    bufp->fullCData(oldp+86,((7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                    >> 0x10U))),3);
    bufp->fullCData(oldp+87,((0xffU & (((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                         << 0xdU) | 
                                        (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                         >> 0x13U)) 
                                       << (7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x10U))))),8);
    bufp->fullCData(oldp+88,((0xffU & ((0xffU & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x13U)) 
                                       >> (7U & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                 >> 0x10U))))),8);
    bufp->fullCData(oldp+89,((0xffU & VL_SHIFTRS_III(8,8,3, 
                                                     (0xffU 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                         >> 0x13U)), 
                                                     (7U 
                                                      & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                         >> 0x10U))))),8);
    __Vtemp_1[0U] = (IData)((((QData)((IData)(((0x3fc0000U 
                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   << 0xbU)) 
                                               | ((0x3fc00U 
                                                   & ((0x3c000U 
                                                       & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                          << 3U)) 
                                                      | (0x3c00U 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                            >> 1U)))) 
                                                  | ((0x3f0U 
                                                      & ((0x300U 
                                                          & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                             << 3U)) 
                                                         | ((0xc0U 
                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                << 1U)) 
                                                            | (0x30U 
                                                               & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                  >> 1U))))) 
                                                     | ((((0xfU 
                                                           == 
                                                           (0xfU 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                               >> 1U))) 
                                                          << 3U) 
                                                         | ((0U 
                                                             != 
                                                             (0xfU 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                 >> 1U))) 
                                                            << 2U)) 
                                                        | ((2U 
                                                            & (VL_REDXOR_32(
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))) 
                                                               << 1U)) 
                                                           | (1U 
                                                              & (~ 
                                                                 (0xfU 
                                                                  == 
                                                                  (0xfU 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                      >> 1U)))))))))))) 
                              << 0x1aU) | (QData)((IData)(
                                                          (((((0x2000000U 
                                                               & ((~ 
                                                                   (0U 
                                                                    != 
                                                                    (0xfU 
                                                                     & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                        >> 1U)))) 
                                                                  << 0x19U)) 
                                                              | ((0x1000000U 
                                                                  & ((~ 
                                                                      VL_REDXOR_32(
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U)))) 
                                                                     << 0x18U)) 
                                                                 | (((0xffU 
                                                                      & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                          << 7U) 
                                                                         | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0x19U))) 
                                                                     == 
                                                                     (0xffU 
                                                                      & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                         >> 0x11U))) 
                                                                    << 0x17U))) 
                                                             | ((((0xffU 
                                                                   & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                       << 7U) 
                                                                      | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                         >> 0x19U))) 
                                                                  != 
                                                                  (0xffU 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                      >> 0x11U))) 
                                                                 << 0x16U) 
                                                                | (((0xffU 
                                                                     & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                         << 7U) 
                                                                        | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                           >> 0x19U))) 
                                                                    < 
                                                                    (0xffU 
                                                                     & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                        >> 0x11U))) 
                                                                   << 0x15U))) 
                                                            | (((((0xffU 
                                                                   & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                       << 7U) 
                                                                      | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                         >> 0x19U))) 
                                                                  <= 
                                                                  (0xffU 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                      >> 0x11U))) 
                                                                 << 0x14U) 
                                                                | ((((0xffU 
                                                                      & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                          << 7U) 
                                                                         | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0x19U))) 
                                                                     > 
                                                                     (0xffU 
                                                                      & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                         >> 0x11U))) 
                                                                    << 0x13U) 
                                                                   | (((0xffU 
                                                                        & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                            << 7U) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0x19U))) 
                                                                       >= 
                                                                       (0xffU 
                                                                        & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                           >> 0x11U))) 
                                                                      << 0x12U))) 
                                                               | ((((0xfU 
                                                                     & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                        >> 4U)) 
                                                                    == 
                                                                    (0xfU 
                                                                     & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                        >> 0xaU))) 
                                                                   << 0x11U) 
                                                                  | (((0xfU 
                                                                       & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                          >> 4U)) 
                                                                      != 
                                                                      (0xfU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0xaU))) 
                                                                     << 0x10U)))) 
                                                           | ((0xf000U 
                                                               & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                  << 6U)) 
                                                              | ((((0xcU 
                                                                    >= 
                                                                    (0xfU 
                                                                     & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                        >> 0x16U)))
                                                                    ? 
                                                                   (7U 
                                                                    & (((0U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & ((IData)(0x3aU) 
                                                                             + 
                                                                             (7U 
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))
                                                                         ? 0U
                                                                         : 
                                                                        (vlSelfRef.tb_top__DOT__in_flat[
                                                                         (((IData)(0x3cU) 
                                                                           + 
                                                                           (7U 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                               >> 0x16U))) 
                                                                          >> 5U)] 
                                                                         << 
                                                                         ((IData)(0x20U) 
                                                                          - 
                                                                          (0x1fU 
                                                                           & ((IData)(0x3aU) 
                                                                              + 
                                                                              (7U 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))))))) 
                                                                       | (vlSelfRef.tb_top__DOT__in_flat[
                                                                          (((IData)(0x3aU) 
                                                                            + 
                                                                            (7U 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                           >> 5U)] 
                                                                          >> 
                                                                          (0x1fU 
                                                                           & ((IData)(0x3aU) 
                                                                              + 
                                                                              (7U 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))))
                                                                    : 0U) 
                                                                  << 9U) 
                                                                 | (((0xcU 
                                                                      < 
                                                                      (0xfU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                          >> 0x16U))) 
                                                                     << 8U) 
                                                                    | (0xffU 
                                                                       & ((((0xffU 
                                                                             & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x12U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))) 
                                                                            * 
                                                                            (0xffU 
                                                                             & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1bU))))) 
                                                                           & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                               | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)) 
                                                                              ^ 
                                                                              ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                               | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)))) 
                                                                          | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U))))))), (IData)(3U))))))))))));
    __Vtemp_1[1U] = (((IData)((((QData)((IData)((((0x78000U 
                                                   & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                        << 0x18U) 
                                                       | (0xff8000U 
                                                          & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                             >> 8U))) 
                                                      & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x1cU) 
                                                         | (0xfff8000U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 4U))))) 
                                                  | (0x7800U 
                                                     & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x14U) 
                                                         | (0xff800U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 0xcU))) 
                                                        | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                            << 0x18U) 
                                                           | (0xfff800U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 8U)))))) 
                                                 | ((0x780U 
                                                     & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x10U) 
                                                         | (0xff80U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 0x10U))) 
                                                        ^ 
                                                        ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x14U) 
                                                         | (0xfff80U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 0xcU))))) 
                                                    | ((0x78U 
                                                        & ((~ 
                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 9U) 
                                                             | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                >> 0x17U))) 
                                                           << 3U)) 
                                                       | (((IData)(
                                                                   (0x60000U 
                                                                    == 
                                                                    (0x60000U 
                                                                     & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                           << 2U) 
                                                          | (((IData)(
                                                                      (0U 
                                                                       != 
                                                                       (0x60000U 
                                                                        & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                              << 1U) 
                                                             | (1U 
                                                                & (~ 
                                                                   (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x12U)))))))))) 
                                << 0x18U) | (QData)((IData)(
                                                            (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                              << 0x10U) 
                                                             | ((0xff00U 
                                                                 & (((0x8000U 
                                                                      & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                      ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                      : 
                                                                     ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                       << 7U) 
                                                                      | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                         >> 0x19U))) 
                                                                    << 8U)) 
                                                                | (0xffU 
                                                                   & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x19U))), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x11U)))
                                                                       ? 
                                                                      ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        << 0x17U) 
                                                                       | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                          >> 9U))
                                                                       : 
                                                                      ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        << 0x1fU) 
                                                                       | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                          >> 1U)))))))))) 
                      << 0x14U) | (IData)(((((QData)((IData)(
                                                             ((0x3fc0000U 
                                                               & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                  << 0xbU)) 
                                                              | ((0x3fc00U 
                                                                  & ((0x3c000U 
                                                                      & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                         << 3U)) 
                                                                     | (0x3c00U 
                                                                        & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           >> 1U)))) 
                                                                 | ((0x3f0U 
                                                                     & ((0x300U 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                            << 3U)) 
                                                                        | ((0xc0U 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                               << 1U)) 
                                                                           | (0x30U 
                                                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))))) 
                                                                    | ((((0xfU 
                                                                          == 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                              >> 1U))) 
                                                                         << 3U) 
                                                                        | ((0U 
                                                                            != 
                                                                            (0xfU 
                                                                             & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))) 
                                                                           << 2U)) 
                                                                       | ((2U 
                                                                           & (VL_REDXOR_32(
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U))) 
                                                                              << 1U)) 
                                                                          | (1U 
                                                                             & (~ 
                                                                                (0xfU 
                                                                                == 
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U)))))))))))) 
                                             << 0x1aU) 
                                            | (QData)((IData)(
                                                              (((((0x2000000U 
                                                                   & ((~ 
                                                                       (0U 
                                                                        != 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                            >> 1U)))) 
                                                                      << 0x19U)) 
                                                                  | ((0x1000000U 
                                                                      & ((~ 
                                                                          VL_REDXOR_32(
                                                                                (0xfU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 1U)))) 
                                                                         << 0x18U)) 
                                                                     | (((0xffU 
                                                                          & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                              << 7U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                         == 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x11U))) 
                                                                        << 0x17U))) 
                                                                 | ((((0xffU 
                                                                       & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 7U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x19U))) 
                                                                      != 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0x11U))) 
                                                                     << 0x16U) 
                                                                    | (((0xffU 
                                                                         & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                             << 7U) 
                                                                            | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                               >> 0x19U))) 
                                                                        < 
                                                                        (0xffU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0x11U))) 
                                                                       << 0x15U))) 
                                                                | (((((0xffU 
                                                                       & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           << 7U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x19U))) 
                                                                      <= 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                          >> 0x11U))) 
                                                                     << 0x14U) 
                                                                    | ((((0xffU 
                                                                          & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                              << 7U) 
                                                                             | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                         > 
                                                                         (0xffU 
                                                                          & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                             >> 0x11U))) 
                                                                        << 0x13U) 
                                                                       | (((0xffU 
                                                                            & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                << 7U) 
                                                                               | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                                >> 0x19U))) 
                                                                           >= 
                                                                           (0xffU 
                                                                            & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                               >> 0x11U))) 
                                                                          << 0x12U))) 
                                                                   | ((((0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                            >> 4U)) 
                                                                        == 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                            >> 0xaU))) 
                                                                       << 0x11U) 
                                                                      | (((0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                                              >> 4U)) 
                                                                          != 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                              >> 0xaU))) 
                                                                         << 0x10U)))) 
                                                               | ((0xf000U 
                                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                                      << 6U)) 
                                                                  | ((((0xcU 
                                                                        >= 
                                                                        (0xfU 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                            >> 0x16U)))
                                                                        ? 
                                                                       (7U 
                                                                        & (((0U 
                                                                             == 
                                                                             (0x1fU 
                                                                              & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))
                                                                             ? 0U
                                                                             : 
                                                                            (vlSelfRef.tb_top__DOT__in_flat[
                                                                             (((IData)(0x3cU) 
                                                                               + 
                                                                               (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                              >> 5U)] 
                                                                             << 
                                                                             ((IData)(0x20U) 
                                                                              - 
                                                                              (0x1fU 
                                                                               & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))))))) 
                                                                           | (vlSelfRef.tb_top__DOT__in_flat[
                                                                              (((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U))) 
                                                                               >> 5U)] 
                                                                              >> 
                                                                              (0x1fU 
                                                                               & ((IData)(0x3aU) 
                                                                                + 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0x16U)))))))
                                                                        : 0U) 
                                                                      << 9U) 
                                                                     | (((0xcU 
                                                                          < 
                                                                          (0xfU 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                              >> 0x16U))) 
                                                                         << 8U) 
                                                                        | (0xffU 
                                                                           & ((((0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x12U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)) 
                                                                                << 
                                                                                (7U 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1bU))))) 
                                                                               & (((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)) 
                                                                                ^ 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 2U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 0x1eU)))) 
                                                                              | VL_MODDIV_III(8, 
                                                                                ((0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U)))))
                                                                                 ? 0U
                                                                                 : 
                                                                                (0xffU 
                                                                                & VL_DIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 0xeU)), 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                ((vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                << 0x1aU) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[1U] 
                                                                                >> 6U))))))), (IData)(3U))))))))))) 
                                           >> 0x20U)));
    __Vtemp_1[2U] = (((IData)((((QData)((IData)((((0x78000U 
                                                   & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                        << 0x18U) 
                                                       | (0xff8000U 
                                                          & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                             >> 8U))) 
                                                      & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x1cU) 
                                                         | (0xfff8000U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 4U))))) 
                                                  | (0x7800U 
                                                     & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x14U) 
                                                         | (0xff800U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 0xcU))) 
                                                        | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                            << 0x18U) 
                                                           | (0xfff800U 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                 >> 8U)))))) 
                                                 | ((0x780U 
                                                     & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x10U) 
                                                         | (0xff80U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 0x10U))) 
                                                        ^ 
                                                        ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                          << 0x14U) 
                                                         | (0xfff80U 
                                                            & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                               >> 0xcU))))) 
                                                    | ((0x78U 
                                                        & ((~ 
                                                            ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                              << 9U) 
                                                             | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                >> 0x17U))) 
                                                           << 3U)) 
                                                       | (((IData)(
                                                                   (0x60000U 
                                                                    == 
                                                                    (0x60000U 
                                                                     & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                           << 2U) 
                                                          | (((IData)(
                                                                      (0U 
                                                                       != 
                                                                       (0x60000U 
                                                                        & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                              << 1U) 
                                                             | (1U 
                                                                & (~ 
                                                                   (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                    >> 0x12U)))))))))) 
                                << 0x18U) | (QData)((IData)(
                                                            (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                              << 0x10U) 
                                                             | ((0xff00U 
                                                                 & (((0x8000U 
                                                                      & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                      ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                      : 
                                                                     ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                       << 7U) 
                                                                      | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                         >> 0x19U))) 
                                                                    << 8U)) 
                                                                | (0xffU 
                                                                   & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x19U))), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x11U)))
                                                                       ? 
                                                                      ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        << 0x17U) 
                                                                       | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                          >> 9U))
                                                                       : 
                                                                      ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                        << 0x1fU) 
                                                                       | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                          >> 1U)))))))))) 
                      >> 0xcU) | ((IData)(((((QData)((IData)(
                                                             (((0x78000U 
                                                                & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                     << 0x18U) 
                                                                    | (0xff8000U 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                          >> 8U))) 
                                                                   & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                       << 0x1cU) 
                                                                      | (0xfff8000U 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            >> 4U))))) 
                                                               | (0x7800U 
                                                                  & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                       << 0x14U) 
                                                                      | (0xff800U 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            >> 0xcU))) 
                                                                     | ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                         << 0x18U) 
                                                                        | (0xfff800U 
                                                                           & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                              >> 8U)))))) 
                                                              | ((0x780U 
                                                                  & (((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                       << 0x10U) 
                                                                      | (0xff80U 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            >> 0x10U))) 
                                                                     ^ 
                                                                     ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                       << 0x14U) 
                                                                      | (0xfff80U 
                                                                         & (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            >> 0xcU))))) 
                                                                 | ((0x78U 
                                                                     & ((~ 
                                                                         ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                           << 9U) 
                                                                          | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                             >> 0x17U))) 
                                                                        << 3U)) 
                                                                    | (((IData)(
                                                                                (0x60000U 
                                                                                == 
                                                                                (0x60000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                        << 2U) 
                                                                       | (((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60000U 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[4U]))) 
                                                                           << 1U) 
                                                                          | (1U 
                                                                             & (~ 
                                                                                (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                >> 0x12U)))))))))) 
                                             << 0x18U) 
                                            | (QData)((IData)(
                                                              (((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                                                                << 0x10U) 
                                                               | ((0xff00U 
                                                                   & (((0x8000U 
                                                                        & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                                        ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                                        : 
                                                                       ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                         << 7U) 
                                                                        | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                           >> 0x19U))) 
                                                                      << 8U)) 
                                                                  | (0xffU 
                                                                     & (VL_LTS_III(8, 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                                << 7U) 
                                                                                | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x19U))), 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                                >> 0x11U)))
                                                                         ? 
                                                                        ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                          << 0x17U) 
                                                                         | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            >> 9U))
                                                                         : 
                                                                        ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                          << 0x1fU) 
                                                                         | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                            >> 1U))))))))) 
                                           >> 0x20U)) 
                                  << 0x14U));
    __Vtemp_2[0U] = (IData)((((QData)((IData)((((((
                                                   (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                    << 0xdU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                      >> 0x13U)) 
                                                  << 
                                                  (7U 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                      >> 0x10U))) 
                                                 << 0x18U) 
                                                | (0xff0000U 
                                                   & (((0xffU 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                           >> 0x13U)) 
                                                       >> 
                                                       (7U 
                                                        & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                           >> 0x10U))) 
                                                      << 0x10U))) 
                                               | ((0xff00U 
                                                   & (VL_SHIFTRS_III(8,8,3, 
                                                                     (0xffU 
                                                                      & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                         >> 0x13U)), 
                                                                     (7U 
                                                                      & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                         >> 0x10U))) 
                                                      << 8U)) 
                                                  | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c))))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                << 0x18U) 
                                                               | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                  >> 8U)) 
                                                              - 
                                                              vlSelfRef.tb_top__DOT__in_flat[0U]) 
                                                             << 0x18U) 
                                                            | (0xff0000U 
                                                               & (((0xffU 
                                                                    & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                       >> 8U)) 
                                                                   * 
                                                                   (0xffU 
                                                                    & vlSelfRef.tb_top__DOT__in_flat[0U])) 
                                                                  << 0x10U))) 
                                                           | ((((0U 
                                                                 != 
                                                                 (0xffU 
                                                                  & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                 ? 
                                                                (0xffU 
                                                                 & VL_DIV_III(8, 
                                                                              (0xffU 
                                                                               & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                              (0xffU 
                                                                               & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                 : 0U) 
                                                               << 8U) 
                                                              | ((0U 
                                                                  != 
                                                                  (0xffU 
                                                                   & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                  ? 
                                                                 (0xffU 
                                                                  & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                  : 0U)))))));
    __Vtemp_2[1U] = (IData)(((((QData)((IData)(((((
                                                   ((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                     << 0xdU) 
                                                    | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                       >> 0x13U)) 
                                                   << 
                                                   (7U 
                                                    & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                       >> 0x10U))) 
                                                  << 0x18U) 
                                                 | (0xff0000U 
                                                    & (((0xffU 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                            >> 0x13U)) 
                                                        >> 
                                                        (7U 
                                                         & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                            >> 0x10U))) 
                                                       << 0x10U))) 
                                                | ((0xff00U 
                                                    & (VL_SHIFTRS_III(8,8,3, 
                                                                      (0xffU 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                          >> 0x13U)), 
                                                                      (7U 
                                                                       & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                          >> 0x10U))) 
                                                       << 8U)) 
                                                   | (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c))))) 
                               << 0x20U) | (QData)((IData)(
                                                           ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                 << 0x18U) 
                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                   >> 8U)) 
                                                               - 
                                                               vlSelfRef.tb_top__DOT__in_flat[0U]) 
                                                              << 0x18U) 
                                                             | (0xff0000U 
                                                                & (((0xffU 
                                                                     & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                        >> 8U)) 
                                                                    * 
                                                                    (0xffU 
                                                                     & vlSelfRef.tb_top__DOT__in_flat[0U])) 
                                                                   << 0x10U))) 
                                                            | ((((0U 
                                                                  != 
                                                                  (0xffU 
                                                                   & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                  ? 
                                                                 (0xffU 
                                                                  & VL_DIV_III(8, 
                                                                               (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                               (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                  : 0U) 
                                                                << 8U) 
                                                               | ((0U 
                                                                   != 
                                                                   (0xffU 
                                                                    & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                   ? 
                                                                  (0xffU 
                                                                   & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                   : 0U)))))) 
                             >> 0x20U));
    __Vtemp_2[2U] = __Vtemp_1[0U];
    __Vtemp_2[3U] = __Vtemp_1[1U];
    __Vtemp_2[4U] = __Vtemp_1[2U];
    bufp->fullWData(oldp+90,(__Vtemp_2),159);
    bufp->fullQData(oldp+95,((((QData)((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c)) 
                               << 0x20U) | (QData)((IData)(
                                                           ((((((vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                 << 0x18U) 
                                                                | (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                   >> 8U)) 
                                                               - 
                                                               vlSelfRef.tb_top__DOT__in_flat[0U]) 
                                                              << 0x18U) 
                                                             | (0xff0000U 
                                                                & (((0xffU 
                                                                     & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                        >> 8U)) 
                                                                    * 
                                                                    (0xffU 
                                                                     & vlSelfRef.tb_top__DOT__in_flat[0U])) 
                                                                   << 0x10U))) 
                                                            | ((((0U 
                                                                  != 
                                                                  (0xffU 
                                                                   & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                  ? 
                                                                 (0xffU 
                                                                  & VL_DIV_III(8, 
                                                                               (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                               (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                  : 0U) 
                                                                << 8U) 
                                                               | ((0U 
                                                                   != 
                                                                   (0xffU 
                                                                    & vlSelfRef.tb_top__DOT__in_flat[0U]))
                                                                   ? 
                                                                  (0xffU 
                                                                   & VL_MODDIV_III(8, 
                                                                                (0xffU 
                                                                                & (vlSelfRef.tb_top__DOT__in_flat[0U] 
                                                                                >> 8U)), 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb_top__DOT__in_flat[0U])))
                                                                   : 0U))))))),40);
    bufp->fullCData(oldp+97,(((((((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                             << 7U) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                               >> 0x19U))) 
                                  == (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                               >> 0x11U))) 
                                 << 7U) | (((0xffU 
                                             & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                 << 7U) 
                                                | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                   >> 0x19U))) 
                                            != (0xffU 
                                                & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                   >> 0x11U))) 
                                           << 6U)) 
                               | ((((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                               << 7U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                                    < (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                >> 0x11U))) 
                                   << 5U) | (((0xffU 
                                               & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   << 7U) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0x19U))) 
                                              <= (0xffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0x11U))) 
                                             << 4U))) 
                              | (((((0xffU & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                               << 7U) 
                                              | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                 >> 0x19U))) 
                                    > (0xffU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                >> 0x11U))) 
                                   << 3U) | (((0xffU 
                                               & ((vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                   << 7U) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0x19U))) 
                                              >= (0xffU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0x11U))) 
                                             << 2U)) 
                                 | ((((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                               >> 4U)) 
                                      == (0xfU & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                  >> 0xaU))) 
                                     << 1U) | ((0xfU 
                                                & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                                   >> 4U)) 
                                               != (0xfU 
                                                   & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                      >> 0xaU))))))),8);
    bufp->fullIData(oldp+98,((((IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c) 
                               << 0x10U) | ((0xff00U 
                                             & (((0x8000U 
                                                  & vlSelfRef.tb_top__DOT__in_flat[3U])
                                                  ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                                  : 
                                                 ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                   << 7U) 
                                                  | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                     >> 0x19U))) 
                                                << 8U)) 
                                            | (0xffU 
                                               & (VL_LTS_III(8, 
                                                             (0xffU 
                                                              & ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                                  << 7U) 
                                                                 | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                    >> 0x19U))), 
                                                             (0xffU 
                                                              & (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                                                 >> 0x11U)))
                                                   ? 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                    << 0x17U) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 9U))
                                                   : 
                                                  ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                    << 0x1fU) 
                                                   | (vlSelfRef.tb_top__DOT__in_flat[4U] 
                                                      >> 1U))))))),24);
    bufp->fullBit(oldp+99,(((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                     >> 4U)) == (0xfU 
                                                 & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                    >> 0xaU)))));
    bufp->fullBit(oldp+100,(((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                      >> 4U)) != (0xfU 
                                                  & (vlSelfRef.tb_top__DOT__in_flat[2U] 
                                                     >> 0xaU)))));
    bufp->fullCData(oldp+101,((0xffU & ((0x8000U & 
                                         vlSelfRef.tb_top__DOT__in_flat[3U])
                                         ? (IData)(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c)
                                         : ((vlSelfRef.tb_top__DOT__in_flat[4U] 
                                             << 7U) 
                                            | (vlSelfRef.tb_top__DOT__in_flat[3U] 
                                               >> 0x19U))))),8);
    bufp->fullBit(oldp+102,(vlSelfRef.tb_top__DOT__clk));
    bufp->fullIData(oldp+103,(vlSelfRef.tb_top__DOT__cyc),32);
    bufp->fullIData(oldp+104,(vlSelfRef.tb_top__DOT__cycles),32);
    bufp->fullIData(oldp+105,(vlSelfRef.tb_top__DOT__seed),32);
    bufp->fullIData(oldp+106,(vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat),24);
    bufp->fullCData(oldp+107,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_arith_wrapper__DOT__sum_c),8);
    bufp->fullCData(oldp+108,((0xfU & (vlSelfRef.tb_top__DOT__dut__DOT__const_compare_wrapper_in_flat 
                                       >> 4U))),4);
    bufp->fullCData(oldp+109,(vlSelfRef.tb_top__DOT__dut__DOT__u_const_conditional_wrapper__DOT__cond1_c),8);
    bufp->fullIData(oldp+110,(vlSelfRef.tb_top__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+111,(vlSelfRef.tb_top__DOT__unnamedblk2__DOT__j),32);
}
