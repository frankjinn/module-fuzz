`include "const_arith_wrapper.sv"
`include "const_compare_wrapper.sv"
`include "const_concat_repl_wrapper.sv"
`include "const_conditional_wrapper.sv"
`include "const_logic_wrapper.sv"
`include "const_nested_wrapper.sv"
`include "const_partselect_wrapper.sv"
`include "const_reduce_wrapper.sv"
`include "const_shift_wrapper.sv"
`include "numbers_arithmetic_reduce_wrapper.sv"
`include "numbers_bitwise_logic_wrapper.sv"
`include "numbers_bitwise_reduce_wrapper.sv"
`include "numbers_concat_repl_wrapper.sv"
`include "numbers_constant_wrapper.sv"
`include "numbers_logical_op_wrapper.sv"
`include "numbers_numbers_arithmetic_wrapper.sv"
`include "numbers_reduce_case_wrapper.sv"
`include "numbers_relational_wrapper.sv"
`include "numbers_select_wrapper.sv"
`include "numbers_shift_wrapper.sv"
`include "widths_arith_wrapper.sv"
`include "widths_array_wrapper.sv"
`include "widths_cast_wrapper.sv"
`include "widths_concat_repl_wrapper.sv"
`include "widths_conditional_wrapper.sv"
`include "widths_enum_mod_wrapper.sv"
`include "widths_logic_mod_wrapper.sv"
`include "widths_param_wrapper.sv"
`include "widths_partselect_wrapper.sv"
`include "widths_shift_wrapper.sv"
`include "widths_struct_mod_wrapper.sv"
`include "widths_union_mod_wrapper.sv"

// Automatically generated top module
module top (
    input  wire [4:0] in_flat,
    output wire [99:0] out_flat
);

  // Per-module flattened I/O buses
  wire [15:0] const_arith_wrapper_in_flat;
  wire [39:0] const_arith_wrapper_out_flat;
  wire [23:0] const_compare_wrapper_in_flat;
  wire [7:0] const_compare_wrapper_out_flat;
  wire [9:0] const_concat_repl_wrapper_in_flat;
  wire [21:0] const_concat_repl_wrapper_out_flat;
  wire [33:0] const_conditional_wrapper_in_flat;
  wire [23:0] const_conditional_wrapper_out_flat;
  wire [9:0] const_logic_wrapper_in_flat;
  wire [18:0] const_logic_wrapper_out_flat;
  wire [26:0] const_nested_wrapper_in_flat;
  wire [7:0] const_nested_wrapper_out_flat;
  wire [19:0] const_partselect_wrapper_in_flat;
  wire [7:0] const_partselect_wrapper_out_flat;
  wire [3:0] const_reduce_wrapper_in_flat;
  wire [5:0] const_reduce_wrapper_out_flat;
  wire [10:0] const_shift_wrapper_in_flat;
  wire [23:0] const_shift_wrapper_out_flat;
  wire [15:0] numbers_arithmetic_reduce_wrapper_in_flat;
  wire [9:0] numbers_arithmetic_reduce_wrapper_out_flat;
  wire [15:0] numbers_bitwise_logic_wrapper_in_flat;
  wire [23:0] numbers_bitwise_logic_wrapper_out_flat;
  wire [7:0] numbers_bitwise_reduce_wrapper_in_flat;
  wire [2:0] numbers_bitwise_reduce_wrapper_out_flat;
  wire [5:0] numbers_concat_repl_wrapper_in_flat;
  wire [21:0] numbers_concat_repl_wrapper_out_flat;
  wire [0:0] numbers_constant_wrapper_in_flat;
  wire [79:0] numbers_constant_wrapper_out_flat;
  wire [1:0] numbers_logical_op_wrapper_in_flat;
  wire [2:0] numbers_logical_op_wrapper_out_flat;
  wire [12:0] numbers_numbers_arithmetic_wrapper_in_flat;
  wire [24:0] numbers_numbers_arithmetic_wrapper_out_flat;
  wire [7:0] numbers_reduce_case_wrapper_in_flat;
  wire [1:0] numbers_reduce_case_wrapper_out_flat;
  wire [7:0] numbers_relational_wrapper_in_flat;
  wire [7:0] numbers_relational_wrapper_out_flat;
  wire [19:0] numbers_select_wrapper_in_flat;
  wire [8:0] numbers_select_wrapper_out_flat;
  wire [10:0] numbers_shift_wrapper_in_flat;
  wire [15:0] numbers_shift_wrapper_out_flat;
  wire [0:0] widths_arith_wrapper_in_flat;
  wire [0:0] widths_arith_wrapper_out_flat;
  wire [17:0] widths_array_wrapper_in_flat;
  wire [15:0] widths_array_wrapper_out_flat;
  wire [11:0] widths_cast_wrapper_in_flat;
  wire [11:0] widths_cast_wrapper_out_flat;
  wire [5:0] widths_concat_repl_wrapper_in_flat;
  wire [17:0] widths_concat_repl_wrapper_out_flat;
  wire [8:0] widths_conditional_wrapper_in_flat;
  wire [3:0] widths_conditional_wrapper_out_flat;
  wire [3:0] widths_enum_mod_wrapper_in_flat;
  wire [4:0] widths_enum_mod_wrapper_out_flat;
  wire [7:0] widths_logic_mod_wrapper_in_flat;
  wire [5:0] widths_logic_mod_wrapper_out_flat;
  wire [0:0] widths_param_wrapper_in_flat;
  wire [0:0] widths_param_wrapper_out_flat;
  wire [18:0] widths_partselect_wrapper_in_flat;
  wire [8:0] widths_partselect_wrapper_out_flat;
  wire [10:0] widths_shift_wrapper_in_flat;
  wire [15:0] widths_shift_wrapper_out_flat;
  wire [11:0] widths_struct_mod_wrapper_in_flat;
  wire [11:0] widths_struct_mod_wrapper_out_flat;
  wire [15:0] widths_union_mod_wrapper_in_flat;
  wire [15:0] widths_union_mod_wrapper_out_flat;

  // Drive module inputs from top-level in_flat
  assign widths_struct_mod_wrapper_in_flat[4] = in_flat[2];
  assign numbers_bitwise_reduce_wrapper_in_flat[1] = in_flat[4];
  assign numbers_arithmetic_reduce_wrapper_in_flat[1] = in_flat[0];
  assign const_shift_wrapper_in_flat[6] = in_flat[3];
  assign const_reduce_wrapper_in_flat[1] = in_flat[1];

  // Internal connections: module-out → module-in
  assign widths_cast_wrapper_in_flat[4] = numbers_select_wrapper_out_flat[3];
  assign widths_shift_wrapper_in_flat[0] = widths_struct_mod_wrapper_out_flat[2];
  assign widths_struct_mod_wrapper_in_flat[1] = numbers_bitwise_logic_wrapper_out_flat[6];
  assign const_conditional_wrapper_in_flat[18] = widths_shift_wrapper_out_flat[6];
  assign numbers_concat_repl_wrapper_in_flat[5] = widths_array_wrapper_out_flat[5];
  assign numbers_reduce_case_wrapper_in_flat[0] = const_arith_wrapper_out_flat[9];
  assign const_arith_wrapper_in_flat[5] = numbers_bitwise_logic_wrapper_out_flat[1];
  assign numbers_arithmetic_reduce_wrapper_in_flat[12] = widths_shift_wrapper_out_flat[4];
  assign numbers_numbers_arithmetic_wrapper_in_flat[10] = widths_union_mod_wrapper_out_flat[10];
  assign const_partselect_wrapper_in_flat[1] = const_concat_repl_wrapper_out_flat[2];
  assign const_nested_wrapper_in_flat[19] = numbers_arithmetic_reduce_wrapper_out_flat[7];
  assign const_conditional_wrapper_in_flat[0] = widths_cast_wrapper_out_flat[8];
  assign widths_cast_wrapper_in_flat[9] = widths_shift_wrapper_out_flat[7];
  assign const_logic_wrapper_in_flat[6] = numbers_select_wrapper_out_flat[4];
  assign numbers_constant_wrapper_in_flat[0] = numbers_constant_wrapper_out_flat[40];
  assign const_conditional_wrapper_in_flat[14] = numbers_constant_wrapper_out_flat[37];
  assign const_concat_repl_wrapper_in_flat[5] = const_compare_wrapper_out_flat[5];
  assign widths_enum_mod_wrapper_in_flat[2] = const_nested_wrapper_out_flat[7];
  assign widths_partselect_wrapper_in_flat[18] = widths_concat_repl_wrapper_out_flat[15];
  assign numbers_select_wrapper_in_flat[13] = numbers_constant_wrapper_out_flat[32];
  assign widths_partselect_wrapper_in_flat[16] = numbers_bitwise_logic_wrapper_out_flat[23];
  assign const_partselect_wrapper_in_flat[10] = const_conditional_wrapper_out_flat[12];
  assign widths_enum_mod_wrapper_in_flat[0] = widths_enum_mod_wrapper_out_flat[0];
  assign widths_partselect_wrapper_in_flat[1] = numbers_arithmetic_reduce_wrapper_out_flat[3];
  assign const_concat_repl_wrapper_in_flat[8] = numbers_constant_wrapper_out_flat[71];
  assign widths_logic_mod_wrapper_in_flat[2] = const_concat_repl_wrapper_out_flat[8];
  assign const_arith_wrapper_in_flat[11] = const_arith_wrapper_out_flat[4];
  assign numbers_bitwise_reduce_wrapper_in_flat[3] = widths_struct_mod_wrapper_out_flat[11];
  assign numbers_bitwise_logic_wrapper_in_flat[11] = const_conditional_wrapper_out_flat[7];
  assign numbers_numbers_arithmetic_wrapper_in_flat[4] = const_concat_repl_wrapper_out_flat[12];
  assign const_conditional_wrapper_in_flat[12] = widths_concat_repl_wrapper_out_flat[11];
  assign widths_array_wrapper_in_flat[15] = numbers_constant_wrapper_out_flat[49];
  assign numbers_bitwise_logic_wrapper_in_flat[5] = widths_partselect_wrapper_out_flat[2];
  assign numbers_concat_repl_wrapper_in_flat[2] = widths_struct_mod_wrapper_out_flat[1];
  assign numbers_relational_wrapper_in_flat[4] = const_shift_wrapper_out_flat[8];
  assign numbers_select_wrapper_in_flat[1] = const_concat_repl_wrapper_out_flat[3];
  assign widths_array_wrapper_in_flat[5] = const_logic_wrapper_out_flat[11];
  assign widths_shift_wrapper_in_flat[7] = const_conditional_wrapper_out_flat[16];
  assign const_nested_wrapper_in_flat[14] = widths_conditional_wrapper_out_flat[1];
  assign widths_conditional_wrapper_in_flat[5] = numbers_shift_wrapper_out_flat[6];
  assign numbers_select_wrapper_in_flat[10] = const_conditional_wrapper_out_flat[21];
  assign const_compare_wrapper_in_flat[5] = const_compare_wrapper_out_flat[4];
  assign const_conditional_wrapper_in_flat[5] = const_shift_wrapper_out_flat[19];
  assign numbers_numbers_arithmetic_wrapper_in_flat[5] = numbers_shift_wrapper_out_flat[9];
  assign widths_cast_wrapper_in_flat[1] = numbers_constant_wrapper_out_flat[10];
  assign widths_partselect_wrapper_in_flat[10] = numbers_arithmetic_reduce_wrapper_out_flat[6];
  assign const_partselect_wrapper_in_flat[12] = widths_concat_repl_wrapper_out_flat[2];
  assign const_compare_wrapper_in_flat[23] = widths_enum_mod_wrapper_out_flat[1];
  assign numbers_arithmetic_reduce_wrapper_in_flat[4] = widths_shift_wrapper_out_flat[11];
  assign widths_array_wrapper_in_flat[17] = const_reduce_wrapper_out_flat[1];
  assign const_logic_wrapper_in_flat[1] = const_concat_repl_wrapper_out_flat[20];
  assign numbers_bitwise_reduce_wrapper_in_flat[4] = widths_struct_mod_wrapper_out_flat[5];
  assign widths_shift_wrapper_in_flat[2] = numbers_constant_wrapper_out_flat[76];
  assign numbers_bitwise_logic_wrapper_in_flat[13] = numbers_shift_wrapper_out_flat[0];
  assign const_partselect_wrapper_in_flat[9] = const_arith_wrapper_out_flat[39];
  assign numbers_numbers_arithmetic_wrapper_in_flat[1] = const_arith_wrapper_out_flat[2];
  assign numbers_bitwise_reduce_wrapper_in_flat[0] = numbers_concat_repl_wrapper_out_flat[16];
  assign const_nested_wrapper_in_flat[7] = const_logic_wrapper_out_flat[13];
  assign widths_cast_wrapper_in_flat[11] = const_arith_wrapper_out_flat[18];
  assign widths_cast_wrapper_in_flat[0] = numbers_constant_wrapper_out_flat[66];
  assign const_partselect_wrapper_in_flat[3] = const_conditional_wrapper_out_flat[23];
  assign widths_shift_wrapper_in_flat[10] = numbers_numbers_arithmetic_wrapper_out_flat[12];
  assign const_compare_wrapper_in_flat[11] = widths_logic_mod_wrapper_out_flat[3];
  assign numbers_arithmetic_reduce_wrapper_in_flat[9] = const_conditional_wrapper_out_flat[18];
  assign const_compare_wrapper_in_flat[10] = widths_cast_wrapper_out_flat[0];
  assign const_partselect_wrapper_in_flat[19] = numbers_constant_wrapper_out_flat[11];
  assign widths_concat_repl_wrapper_in_flat[5] = widths_partselect_wrapper_out_flat[0];
  assign const_partselect_wrapper_in_flat[7] = const_compare_wrapper_out_flat[7];
  assign const_nested_wrapper_in_flat[11] = widths_cast_wrapper_out_flat[4];
  assign widths_partselect_wrapper_in_flat[8] = const_arith_wrapper_out_flat[26];
  assign numbers_bitwise_logic_wrapper_in_flat[1] = numbers_constant_wrapper_out_flat[9];
  assign const_partselect_wrapper_in_flat[18] = widths_enum_mod_wrapper_out_flat[3];
  assign numbers_numbers_arithmetic_wrapper_in_flat[2] = const_arith_wrapper_out_flat[13];
  assign const_shift_wrapper_in_flat[0] = widths_shift_wrapper_out_flat[0];
  assign const_partselect_wrapper_in_flat[14] = widths_shift_wrapper_out_flat[2];
  assign numbers_reduce_case_wrapper_in_flat[1] = numbers_bitwise_logic_wrapper_out_flat[4];
  assign widths_array_wrapper_in_flat[8] = const_logic_wrapper_out_flat[0];
  assign numbers_arithmetic_reduce_wrapper_in_flat[3] = widths_partselect_wrapper_out_flat[6];
  assign const_compare_wrapper_in_flat[13] = widths_union_mod_wrapper_out_flat[5];
  assign numbers_select_wrapper_in_flat[8] = const_shift_wrapper_out_flat[7];
  assign widths_union_mod_wrapper_in_flat[15] = numbers_constant_wrapper_out_flat[17];
  assign widths_struct_mod_wrapper_in_flat[8] = const_shift_wrapper_out_flat[22];
  assign const_concat_repl_wrapper_in_flat[4] = const_logic_wrapper_out_flat[7];
  assign numbers_shift_wrapper_in_flat[6] = numbers_relational_wrapper_out_flat[5];
  assign numbers_concat_repl_wrapper_in_flat[3] = widths_union_mod_wrapper_out_flat[14];
  assign const_compare_wrapper_in_flat[6] = const_arith_wrapper_out_flat[23];
  assign numbers_numbers_arithmetic_wrapper_in_flat[3] = numbers_bitwise_logic_wrapper_out_flat[3];
  assign widths_logic_mod_wrapper_in_flat[6] = widths_concat_repl_wrapper_out_flat[9];
  assign numbers_relational_wrapper_in_flat[2] = widths_shift_wrapper_out_flat[8];
  assign widths_partselect_wrapper_in_flat[17] = const_conditional_wrapper_out_flat[22];
  assign const_compare_wrapper_in_flat[7] = numbers_arithmetic_reduce_wrapper_out_flat[5];
  assign const_arith_wrapper_in_flat[4] = numbers_shift_wrapper_out_flat[4];
  assign const_conditional_wrapper_in_flat[6] = numbers_bitwise_logic_wrapper_out_flat[14];
  assign numbers_concat_repl_wrapper_in_flat[0] = const_shift_wrapper_out_flat[11];
  assign const_partselect_wrapper_in_flat[6] = widths_conditional_wrapper_out_flat[3];
  assign const_nested_wrapper_in_flat[8] = widths_partselect_wrapper_out_flat[3];
  assign const_nested_wrapper_in_flat[2] = numbers_constant_wrapper_out_flat[21];
  assign const_conditional_wrapper_in_flat[25] = const_partselect_wrapper_out_flat[2];
  assign numbers_select_wrapper_in_flat[19] = const_arith_wrapper_out_flat[33];
  assign const_nested_wrapper_in_flat[5] = numbers_constant_wrapper_out_flat[45];
  assign widths_logic_mod_wrapper_in_flat[0] = const_partselect_wrapper_out_flat[1];
  assign numbers_arithmetic_reduce_wrapper_in_flat[0] = widths_array_wrapper_out_flat[0];
  assign const_nested_wrapper_in_flat[22] = numbers_numbers_arithmetic_wrapper_out_flat[2];
  assign widths_cast_wrapper_in_flat[7] = widths_logic_mod_wrapper_out_flat[2];
  assign widths_enum_mod_wrapper_in_flat[3] = numbers_constant_wrapper_out_flat[59];
  assign widths_union_mod_wrapper_in_flat[12] = widths_logic_mod_wrapper_out_flat[1];
  assign widths_union_mod_wrapper_in_flat[1] = numbers_bitwise_reduce_wrapper_out_flat[0];
  assign numbers_bitwise_reduce_wrapper_in_flat[2] = const_conditional_wrapper_out_flat[9];
  assign const_nested_wrapper_in_flat[4] = widths_array_wrapper_out_flat[13];
  assign widths_struct_mod_wrapper_in_flat[11] = widths_cast_wrapper_out_flat[7];
  assign const_shift_wrapper_in_flat[7] = const_logic_wrapper_out_flat[2];
  assign const_conditional_wrapper_in_flat[28] = numbers_numbers_arithmetic_wrapper_out_flat[8];
  assign widths_arith_wrapper_in_flat[0] = const_logic_wrapper_out_flat[18];
  assign numbers_select_wrapper_in_flat[0] = const_shift_wrapper_out_flat[0];
  assign widths_shift_wrapper_in_flat[3] = const_shift_wrapper_out_flat[13];
  assign numbers_select_wrapper_in_flat[7] = const_conditional_wrapper_out_flat[2];
  assign widths_struct_mod_wrapper_in_flat[6] = numbers_constant_wrapper_out_flat[39];
  assign widths_union_mod_wrapper_in_flat[11] = numbers_concat_repl_wrapper_out_flat[10];
  assign numbers_numbers_arithmetic_wrapper_in_flat[12] = const_shift_wrapper_out_flat[10];
  assign numbers_bitwise_logic_wrapper_in_flat[12] = const_conditional_wrapper_out_flat[14];
  assign numbers_arithmetic_reduce_wrapper_in_flat[13] = numbers_constant_wrapper_out_flat[26];
  assign const_nested_wrapper_in_flat[9] = numbers_relational_wrapper_out_flat[2];
  assign const_concat_repl_wrapper_in_flat[0] = numbers_numbers_arithmetic_wrapper_out_flat[14];
  assign const_conditional_wrapper_in_flat[21] = numbers_shift_wrapper_out_flat[14];
  assign const_partselect_wrapper_in_flat[17] = numbers_relational_wrapper_out_flat[7];
  assign widths_cast_wrapper_in_flat[8] = widths_union_mod_wrapper_out_flat[2];
  assign widths_union_mod_wrapper_in_flat[3] = numbers_concat_repl_wrapper_out_flat[12];
  assign numbers_numbers_arithmetic_wrapper_in_flat[7] = const_arith_wrapper_out_flat[1];
  assign const_arith_wrapper_in_flat[12] = numbers_constant_wrapper_out_flat[7];
  assign widths_partselect_wrapper_in_flat[0] = const_nested_wrapper_out_flat[5];
  assign numbers_bitwise_logic_wrapper_in_flat[8] = numbers_bitwise_logic_wrapper_out_flat[16];
  assign numbers_bitwise_logic_wrapper_in_flat[7] = const_arith_wrapper_out_flat[31];
  assign numbers_arithmetic_reduce_wrapper_in_flat[10] = const_nested_wrapper_out_flat[2];
  assign widths_concat_repl_wrapper_in_flat[0] = numbers_concat_repl_wrapper_out_flat[19];
  assign widths_shift_wrapper_in_flat[1] = numbers_arithmetic_reduce_wrapper_out_flat[1];
  assign widths_cast_wrapper_in_flat[3] = numbers_constant_wrapper_out_flat[20];
  assign numbers_select_wrapper_in_flat[6] = numbers_constant_wrapper_out_flat[1];
  assign const_arith_wrapper_in_flat[14] = numbers_select_wrapper_out_flat[0];
  assign widths_union_mod_wrapper_in_flat[4] = numbers_select_wrapper_out_flat[8];
  assign const_arith_wrapper_in_flat[10] = numbers_constant_wrapper_out_flat[30];
  assign numbers_bitwise_logic_wrapper_in_flat[4] = widths_struct_mod_wrapper_out_flat[0];
  assign widths_logic_mod_wrapper_in_flat[3] = numbers_constant_wrapper_out_flat[75];
  assign const_arith_wrapper_in_flat[3] = numbers_constant_wrapper_out_flat[25];
  assign widths_array_wrapper_in_flat[12] = widths_union_mod_wrapper_out_flat[6];
  assign numbers_select_wrapper_in_flat[18] = numbers_numbers_arithmetic_wrapper_out_flat[4];
  assign numbers_select_wrapper_in_flat[11] = widths_shift_wrapper_out_flat[10];
  assign const_nested_wrapper_in_flat[26] = numbers_bitwise_logic_wrapper_out_flat[20];
  assign const_nested_wrapper_in_flat[6] = widths_array_wrapper_out_flat[4];
  assign const_partselect_wrapper_in_flat[0] = numbers_numbers_arithmetic_wrapper_out_flat[1];
  assign const_conditional_wrapper_in_flat[13] = const_shift_wrapper_out_flat[15];
  assign widths_union_mod_wrapper_in_flat[13] = const_conditional_wrapper_out_flat[5];
  assign widths_partselect_wrapper_in_flat[11] = numbers_constant_wrapper_out_flat[56];
  assign const_compare_wrapper_in_flat[4] = widths_cast_wrapper_out_flat[6];
  assign const_partselect_wrapper_in_flat[2] = const_logic_wrapper_out_flat[17];
  assign widths_concat_repl_wrapper_in_flat[1] = numbers_numbers_arithmetic_wrapper_out_flat[23];
  assign numbers_select_wrapper_in_flat[14] = widths_shift_wrapper_out_flat[1];
  assign widths_array_wrapper_in_flat[3] = numbers_arithmetic_reduce_wrapper_out_flat[9];
  assign const_nested_wrapper_in_flat[16] = numbers_bitwise_logic_wrapper_out_flat[15];
  assign const_arith_wrapper_in_flat[8] = numbers_select_wrapper_out_flat[1];
  assign numbers_bitwise_logic_wrapper_in_flat[15] = const_concat_repl_wrapper_out_flat[1];
  assign widths_struct_mod_wrapper_in_flat[0] = numbers_numbers_arithmetic_wrapper_out_flat[19];
  assign numbers_shift_wrapper_in_flat[9] = numbers_numbers_arithmetic_wrapper_out_flat[20];
  assign const_nested_wrapper_in_flat[1] = const_concat_repl_wrapper_out_flat[9];
  assign widths_conditional_wrapper_in_flat[6] = const_concat_repl_wrapper_out_flat[15];
  assign const_arith_wrapper_in_flat[13] = const_partselect_wrapper_out_flat[4];
  assign numbers_numbers_arithmetic_wrapper_in_flat[9] = const_conditional_wrapper_out_flat[15];
  assign numbers_arithmetic_reduce_wrapper_in_flat[14] = numbers_concat_repl_wrapper_out_flat[20];
  assign const_arith_wrapper_in_flat[0] = numbers_constant_wrapper_out_flat[60];
  assign const_conditional_wrapper_in_flat[16] = const_concat_repl_wrapper_out_flat[21];
  assign widths_union_mod_wrapper_in_flat[8] = numbers_arithmetic_reduce_wrapper_out_flat[4];
  assign const_nested_wrapper_in_flat[21] = const_conditional_wrapper_out_flat[13];
  assign numbers_relational_wrapper_in_flat[0] = const_shift_wrapper_out_flat[14];
  assign widths_conditional_wrapper_in_flat[2] = widths_logic_mod_wrapper_out_flat[4];
  assign numbers_shift_wrapper_in_flat[5] = const_logic_wrapper_out_flat[6];
  assign const_conditional_wrapper_in_flat[9] = widths_array_wrapper_out_flat[3];
  assign const_conditional_wrapper_in_flat[29] = const_arith_wrapper_out_flat[38];
  assign const_conditional_wrapper_in_flat[24] = widths_cast_wrapper_out_flat[1];
  assign const_logic_wrapper_in_flat[9] = numbers_shift_wrapper_out_flat[5];
  assign numbers_reduce_case_wrapper_in_flat[3] = widths_conditional_wrapper_out_flat[2];
  assign const_nested_wrapper_in_flat[20] = numbers_reduce_case_wrapper_out_flat[1];
  assign const_arith_wrapper_in_flat[6] = numbers_constant_wrapper_out_flat[35];
  assign numbers_shift_wrapper_in_flat[1] = const_reduce_wrapper_out_flat[0];
  assign widths_cast_wrapper_in_flat[5] = widths_cast_wrapper_out_flat[11];
  assign widths_struct_mod_wrapper_in_flat[7] = numbers_constant_wrapper_out_flat[13];
  assign numbers_select_wrapper_in_flat[9] = numbers_bitwise_logic_wrapper_out_flat[11];
  assign numbers_reduce_case_wrapper_in_flat[2] = widths_concat_repl_wrapper_out_flat[13];
  assign widths_concat_repl_wrapper_in_flat[2] = const_concat_repl_wrapper_out_flat[13];
  assign const_partselect_wrapper_in_flat[15] = numbers_bitwise_logic_wrapper_out_flat[12];
  assign const_conditional_wrapper_in_flat[3] = const_arith_wrapper_out_flat[3];
  assign widths_array_wrapper_in_flat[6] = const_conditional_wrapper_out_flat[19];
  assign widths_concat_repl_wrapper_in_flat[4] = numbers_select_wrapper_out_flat[5];
  assign numbers_relational_wrapper_in_flat[6] = const_arith_wrapper_out_flat[17];
  assign numbers_logical_op_wrapper_in_flat[1] = numbers_relational_wrapper_out_flat[6];
  assign numbers_numbers_arithmetic_wrapper_in_flat[11] = numbers_shift_wrapper_out_flat[11];
  assign const_compare_wrapper_in_flat[15] = numbers_constant_wrapper_out_flat[69];
  assign const_arith_wrapper_in_flat[9] = const_arith_wrapper_out_flat[7];
  assign widths_array_wrapper_in_flat[7] = widths_union_mod_wrapper_out_flat[0];
  assign widths_partselect_wrapper_in_flat[14] = numbers_numbers_arithmetic_wrapper_out_flat[7];
  assign const_conditional_wrapper_in_flat[1] = widths_cast_wrapper_out_flat[3];
  assign const_conditional_wrapper_in_flat[20] = const_shift_wrapper_out_flat[17];
  assign widths_union_mod_wrapper_in_flat[2] = widths_partselect_wrapper_out_flat[5];
  assign const_shift_wrapper_in_flat[4] = numbers_constant_wrapper_out_flat[63];
  assign const_logic_wrapper_in_flat[5] = widths_union_mod_wrapper_out_flat[12];
  assign widths_array_wrapper_in_flat[0] = numbers_constant_wrapper_out_flat[41];
  assign const_logic_wrapper_in_flat[8] = widths_array_wrapper_out_flat[10];
  assign numbers_shift_wrapper_in_flat[10] = widths_partselect_wrapper_out_flat[8];
  assign widths_union_mod_wrapper_in_flat[9] = widths_cast_wrapper_out_flat[2];
  assign numbers_select_wrapper_in_flat[17] = const_arith_wrapper_out_flat[22];
  assign const_conditional_wrapper_in_flat[15] = widths_partselect_wrapper_out_flat[7];
  assign const_compare_wrapper_in_flat[19] = const_conditional_wrapper_out_flat[11];
  assign widths_array_wrapper_in_flat[10] = numbers_constant_wrapper_out_flat[4];
  assign const_compare_wrapper_in_flat[17] = const_reduce_wrapper_out_flat[5];
  assign numbers_arithmetic_reduce_wrapper_in_flat[5] = numbers_constant_wrapper_out_flat[77];
  assign const_compare_wrapper_in_flat[3] = const_logic_wrapper_out_flat[1];
  assign widths_logic_mod_wrapper_in_flat[7] = numbers_bitwise_logic_wrapper_out_flat[22];
  assign widths_struct_mod_wrapper_in_flat[10] = const_conditional_wrapper_out_flat[17];
  assign widths_shift_wrapper_in_flat[4] = widths_struct_mod_wrapper_out_flat[9];
  assign widths_partselect_wrapper_in_flat[5] = widths_shift_wrapper_out_flat[3];
  assign widths_partselect_wrapper_in_flat[13] = widths_array_wrapper_out_flat[9];
  assign numbers_arithmetic_reduce_wrapper_in_flat[2] = numbers_constant_wrapper_out_flat[70];
  assign const_conditional_wrapper_in_flat[23] = widths_concat_repl_wrapper_out_flat[14];
  assign numbers_bitwise_reduce_wrapper_in_flat[5] = widths_array_wrapper_out_flat[15];
  assign widths_array_wrapper_in_flat[16] = widths_shift_wrapper_out_flat[13];
  assign numbers_reduce_case_wrapper_in_flat[7] = const_partselect_wrapper_out_flat[5];
  assign numbers_relational_wrapper_in_flat[7] = numbers_constant_wrapper_out_flat[28];
  assign const_conditional_wrapper_in_flat[31] = const_concat_repl_wrapper_out_flat[11];
  assign widths_array_wrapper_in_flat[9] = numbers_shift_wrapper_out_flat[10];
  assign const_partselect_wrapper_in_flat[11] = widths_cast_wrapper_out_flat[10];
  assign widths_logic_mod_wrapper_in_flat[4] = numbers_arithmetic_reduce_wrapper_out_flat[8];
  assign widths_partselect_wrapper_in_flat[9] = widths_array_wrapper_out_flat[8];
  assign numbers_relational_wrapper_in_flat[1] = widths_union_mod_wrapper_out_flat[8];
  assign widths_array_wrapper_in_flat[4] = widths_struct_mod_wrapper_out_flat[4];
  assign const_nested_wrapper_in_flat[13] = numbers_bitwise_logic_wrapper_out_flat[10];
  assign const_arith_wrapper_in_flat[7] = numbers_constant_wrapper_out_flat[31];
  assign const_reduce_wrapper_in_flat[2] = const_conditional_wrapper_out_flat[4];
  assign const_conditional_wrapper_in_flat[22] = const_arith_wrapper_out_flat[11];
  assign numbers_arithmetic_reduce_wrapper_in_flat[11] = numbers_concat_repl_wrapper_out_flat[18];
  assign numbers_select_wrapper_in_flat[12] = numbers_constant_wrapper_out_flat[0];
  assign const_partselect_wrapper_in_flat[4] = const_logic_wrapper_out_flat[4];
  assign const_conditional_wrapper_in_flat[4] = const_arith_wrapper_out_flat[10];
  assign const_concat_repl_wrapper_in_flat[2] = numbers_shift_wrapper_out_flat[12];
  assign const_compare_wrapper_in_flat[8] = numbers_constant_wrapper_out_flat[8];
  assign const_conditional_wrapper_in_flat[10] = numbers_bitwise_reduce_wrapper_out_flat[1];
  assign widths_union_mod_wrapper_in_flat[5] = widths_cast_wrapper_out_flat[9];
  assign widths_struct_mod_wrapper_in_flat[2] = const_arith_wrapper_out_flat[8];
  assign widths_partselect_wrapper_in_flat[15] = numbers_bitwise_logic_wrapper_out_flat[8];
  assign numbers_reduce_case_wrapper_in_flat[5] = numbers_constant_wrapper_out_flat[43];
  assign const_shift_wrapper_in_flat[3] = widths_union_mod_wrapper_out_flat[11];
  assign const_compare_wrapper_in_flat[12] = const_nested_wrapper_out_flat[3];
  assign const_concat_repl_wrapper_in_flat[1] = numbers_numbers_arithmetic_wrapper_out_flat[5];
  assign numbers_shift_wrapper_in_flat[7] = numbers_shift_wrapper_out_flat[8];
  assign const_concat_repl_wrapper_in_flat[9] = widths_concat_repl_wrapper_out_flat[10];
  assign widths_conditional_wrapper_in_flat[3] = widths_array_wrapper_out_flat[11];
  assign const_conditional_wrapper_in_flat[32] = numbers_numbers_arithmetic_wrapper_out_flat[11];
  assign const_compare_wrapper_in_flat[1] = widths_union_mod_wrapper_out_flat[3];
  assign const_conditional_wrapper_in_flat[11] = widths_shift_wrapper_out_flat[9];
  assign const_logic_wrapper_in_flat[3] = const_shift_wrapper_out_flat[1];
  assign const_nested_wrapper_in_flat[17] = numbers_constant_wrapper_out_flat[14];
  assign const_shift_wrapper_in_flat[2] = widths_union_mod_wrapper_out_flat[15];
  assign numbers_bitwise_logic_wrapper_in_flat[9] = numbers_shift_wrapper_out_flat[2];
  assign widths_partselect_wrapper_in_flat[2] = numbers_constant_wrapper_out_flat[48];
  assign numbers_arithmetic_reduce_wrapper_in_flat[7] = numbers_constant_wrapper_out_flat[12];
  assign widths_partselect_wrapper_in_flat[3] = const_arith_wrapper_out_flat[16];
  assign widths_logic_mod_wrapper_in_flat[5] = numbers_concat_repl_wrapper_out_flat[17];
  assign widths_partselect_wrapper_in_flat[12] = const_arith_wrapper_out_flat[6];
  assign const_shift_wrapper_in_flat[10] = widths_concat_repl_wrapper_out_flat[5];
  assign widths_partselect_wrapper_in_flat[7] = numbers_concat_repl_wrapper_out_flat[4];
  assign widths_cast_wrapper_in_flat[6] = const_shift_wrapper_out_flat[2];
  assign widths_param_wrapper_in_flat[0] = numbers_concat_repl_wrapper_out_flat[8];
  assign numbers_shift_wrapper_in_flat[3] = numbers_constant_wrapper_out_flat[3];
  assign const_nested_wrapper_in_flat[18] = widths_union_mod_wrapper_out_flat[9];
  assign const_nested_wrapper_in_flat[0] = numbers_constant_wrapper_out_flat[51];
  assign const_nested_wrapper_in_flat[23] = const_shift_wrapper_out_flat[20];
  assign numbers_reduce_case_wrapper_in_flat[6] = numbers_bitwise_reduce_wrapper_out_flat[2];
  assign numbers_logical_op_wrapper_in_flat[0] = widths_logic_mod_wrapper_out_flat[0];
  assign widths_union_mod_wrapper_in_flat[6] = const_arith_wrapper_out_flat[37];
  assign numbers_bitwise_logic_wrapper_in_flat[0] = const_partselect_wrapper_out_flat[3];
  assign numbers_shift_wrapper_in_flat[2] = numbers_numbers_arithmetic_wrapper_out_flat[15];
  assign numbers_arithmetic_reduce_wrapper_in_flat[15] = numbers_bitwise_logic_wrapper_out_flat[19];
  assign const_conditional_wrapper_in_flat[7] = const_nested_wrapper_out_flat[1];
  assign const_nested_wrapper_in_flat[15] = numbers_concat_repl_wrapper_out_flat[11];
  assign widths_shift_wrapper_in_flat[9] = numbers_arithmetic_reduce_wrapper_out_flat[2];
  assign numbers_bitwise_reduce_wrapper_in_flat[6] = numbers_constant_wrapper_out_flat[29];
  assign widths_partselect_wrapper_in_flat[4] = numbers_constant_wrapper_out_flat[42];
  assign widths_concat_repl_wrapper_in_flat[3] = numbers_numbers_arithmetic_wrapper_out_flat[0];
  assign widths_conditional_wrapper_in_flat[4] = numbers_constant_wrapper_out_flat[16];
  assign const_nested_wrapper_in_flat[12] = widths_array_wrapper_out_flat[14];
  assign const_compare_wrapper_in_flat[21] = widths_array_wrapper_out_flat[2];
  assign const_logic_wrapper_in_flat[4] = const_logic_wrapper_out_flat[16];
  assign widths_array_wrapper_in_flat[13] = numbers_constant_wrapper_out_flat[64];
  assign numbers_select_wrapper_in_flat[2] = const_conditional_wrapper_out_flat[3];
  assign const_arith_wrapper_in_flat[15] = const_arith_wrapper_out_flat[15];
  assign const_concat_repl_wrapper_in_flat[6] = const_arith_wrapper_out_flat[19];
  assign widths_conditional_wrapper_in_flat[1] = numbers_logical_op_wrapper_out_flat[0];
  assign const_nested_wrapper_in_flat[10] = widths_array_wrapper_out_flat[12];
  assign const_compare_wrapper_in_flat[0] = const_logic_wrapper_out_flat[3];
  assign widths_struct_mod_wrapper_in_flat[9] = const_arith_wrapper_out_flat[32];
  assign const_logic_wrapper_in_flat[0] = numbers_arithmetic_reduce_wrapper_out_flat[0];
  assign widths_union_mod_wrapper_in_flat[7] = numbers_shift_wrapper_out_flat[15];
  assign widths_array_wrapper_in_flat[1] = const_shift_wrapper_out_flat[18];
  assign const_reduce_wrapper_in_flat[0] = widths_array_wrapper_out_flat[6];
  assign numbers_select_wrapper_in_flat[15] = numbers_concat_repl_wrapper_out_flat[1];
  assign numbers_numbers_arithmetic_wrapper_in_flat[6] = numbers_constant_wrapper_out_flat[15];
  assign widths_shift_wrapper_in_flat[8] = numbers_concat_repl_wrapper_out_flat[2];
  assign const_partselect_wrapper_in_flat[5] = widths_struct_mod_wrapper_out_flat[8];
  assign const_partselect_wrapper_in_flat[13] = numbers_logical_op_wrapper_out_flat[1];
  assign numbers_select_wrapper_in_flat[3] = numbers_concat_repl_wrapper_out_flat[15];
  assign const_shift_wrapper_in_flat[1] = const_shift_wrapper_out_flat[21];
  assign widths_union_mod_wrapper_in_flat[10] = const_compare_wrapper_out_flat[2];
  assign numbers_shift_wrapper_in_flat[0] = widths_partselect_wrapper_out_flat[1];
  assign const_partselect_wrapper_in_flat[16] = const_arith_wrapper_out_flat[28];
  assign numbers_select_wrapper_in_flat[5] = const_concat_repl_wrapper_out_flat[10];
  assign const_compare_wrapper_in_flat[9] = const_compare_wrapper_out_flat[0];
  assign const_arith_wrapper_in_flat[1] = const_arith_wrapper_out_flat[25];
  assign numbers_relational_wrapper_in_flat[3] = const_shift_wrapper_out_flat[4];
  assign const_conditional_wrapper_in_flat[26] = numbers_concat_repl_wrapper_out_flat[13];
  assign widths_union_mod_wrapper_in_flat[14] = numbers_reduce_case_wrapper_out_flat[0];
  assign widths_partselect_wrapper_in_flat[6] = numbers_constant_wrapper_out_flat[18];
  assign const_conditional_wrapper_in_flat[2] = numbers_numbers_arithmetic_wrapper_out_flat[6];
  assign widths_conditional_wrapper_in_flat[8] = widths_enum_mod_wrapper_out_flat[4];
  assign numbers_numbers_arithmetic_wrapper_in_flat[0] = const_conditional_wrapper_out_flat[6];
  assign const_reduce_wrapper_in_flat[3] = const_logic_wrapper_out_flat[9];
  assign const_nested_wrapper_in_flat[25] = numbers_constant_wrapper_out_flat[72];
  assign widths_array_wrapper_in_flat[2] = numbers_relational_wrapper_out_flat[0];
  assign const_conditional_wrapper_in_flat[27] = numbers_numbers_arithmetic_wrapper_out_flat[17];
  assign const_conditional_wrapper_in_flat[17] = widths_concat_repl_wrapper_out_flat[17];
  assign widths_shift_wrapper_in_flat[6] = numbers_numbers_arithmetic_wrapper_out_flat[24];
  assign numbers_reduce_case_wrapper_in_flat[4] = numbers_constant_wrapper_out_flat[36];
  assign numbers_arithmetic_reduce_wrapper_in_flat[6] = widths_concat_repl_wrapper_out_flat[16];
  assign const_concat_repl_wrapper_in_flat[7] = numbers_constant_wrapper_out_flat[47];
  assign const_nested_wrapper_in_flat[3] = const_logic_wrapper_out_flat[10];
  assign widths_struct_mod_wrapper_in_flat[3] = const_compare_wrapper_out_flat[3];
  assign numbers_concat_repl_wrapper_in_flat[1] = const_concat_repl_wrapper_out_flat[0];
  assign const_concat_repl_wrapper_in_flat[3] = numbers_bitwise_logic_wrapper_out_flat[5];
  assign numbers_numbers_arithmetic_wrapper_in_flat[8] = numbers_constant_wrapper_out_flat[34];
  assign const_conditional_wrapper_in_flat[19] = widths_cast_wrapper_out_flat[5];
  assign numbers_concat_repl_wrapper_in_flat[4] = const_partselect_wrapper_out_flat[6];
  assign const_partselect_wrapper_in_flat[8] = widths_union_mod_wrapper_out_flat[7];
  assign widths_logic_mod_wrapper_in_flat[1] = widths_param_wrapper_out_flat[0];
  assign widths_conditional_wrapper_in_flat[7] = numbers_constant_wrapper_out_flat[57];
  assign numbers_select_wrapper_in_flat[16] = widths_conditional_wrapper_out_flat[0];
  assign const_nested_wrapper_in_flat[24] = numbers_constant_wrapper_out_flat[52];
  assign numbers_relational_wrapper_in_flat[5] = numbers_bitwise_logic_wrapper_out_flat[18];
  assign numbers_bitwise_logic_wrapper_in_flat[14] = numbers_relational_wrapper_out_flat[3];
  assign const_logic_wrapper_in_flat[2] = widths_enum_mod_wrapper_out_flat[2];
  assign numbers_bitwise_logic_wrapper_in_flat[6] = const_logic_wrapper_out_flat[8];
  assign const_compare_wrapper_in_flat[16] = numbers_shift_wrapper_out_flat[3];
  assign const_shift_wrapper_in_flat[8] = widths_logic_mod_wrapper_out_flat[5];
  assign const_compare_wrapper_in_flat[20] = numbers_constant_wrapper_out_flat[19];
  assign numbers_bitwise_logic_wrapper_in_flat[2] = numbers_numbers_arithmetic_wrapper_out_flat[22];
  assign numbers_bitwise_logic_wrapper_in_flat[10] = const_concat_repl_wrapper_out_flat[5];
  assign numbers_shift_wrapper_in_flat[4] = numbers_numbers_arithmetic_wrapper_out_flat[16];
  assign widths_struct_mod_wrapper_in_flat[5] = numbers_constant_wrapper_out_flat[53];
  assign const_shift_wrapper_in_flat[9] = widths_concat_repl_wrapper_out_flat[12];
  assign const_shift_wrapper_in_flat[5] = const_shift_wrapper_out_flat[5];
  assign const_conditional_wrapper_in_flat[30] = numbers_constant_wrapper_out_flat[79];
  assign widths_cast_wrapper_in_flat[10] = numbers_constant_wrapper_out_flat[74];
  assign widths_conditional_wrapper_in_flat[0] = widths_union_mod_wrapper_out_flat[4];
  assign const_compare_wrapper_in_flat[14] = numbers_concat_repl_wrapper_out_flat[0];
  assign numbers_bitwise_logic_wrapper_in_flat[3] = const_shift_wrapper_out_flat[3];
  assign widths_array_wrapper_in_flat[14] = numbers_constant_wrapper_out_flat[46];
  assign const_arith_wrapper_in_flat[2] = const_arith_wrapper_out_flat[20];
  assign widths_shift_wrapper_in_flat[5] = const_arith_wrapper_out_flat[21];
  assign numbers_shift_wrapper_in_flat[8] = const_conditional_wrapper_out_flat[20];
  assign const_compare_wrapper_in_flat[22] = widths_shift_wrapper_out_flat[12];
  assign const_conditional_wrapper_in_flat[33] = const_concat_repl_wrapper_out_flat[6];
  assign const_conditional_wrapper_in_flat[8] = const_concat_repl_wrapper_out_flat[14];
  assign numbers_select_wrapper_in_flat[4] = const_conditional_wrapper_out_flat[0];
  assign widths_cast_wrapper_in_flat[2] = const_logic_wrapper_out_flat[14];
  assign const_compare_wrapper_in_flat[18] = numbers_select_wrapper_out_flat[7];
  assign numbers_arithmetic_reduce_wrapper_in_flat[8] = numbers_concat_repl_wrapper_out_flat[21];
  assign widths_union_mod_wrapper_in_flat[0] = numbers_constant_wrapper_out_flat[27];
  assign numbers_bitwise_reduce_wrapper_in_flat[7] = numbers_concat_repl_wrapper_out_flat[14];
  assign widths_array_wrapper_in_flat[11] = numbers_constant_wrapper_out_flat[38];
  assign widths_enum_mod_wrapper_in_flat[1] = numbers_bitwise_logic_wrapper_out_flat[9];
  assign const_compare_wrapper_in_flat[2] = widths_concat_repl_wrapper_out_flat[0];
  assign const_logic_wrapper_in_flat[7] = numbers_constant_wrapper_out_flat[58];

  // Drive top-level out_flat from module outputs
  assign out_flat[18] = numbers_relational_wrapper_out_flat[1];
  assign out_flat[33] = numbers_relational_wrapper_out_flat[4];
  assign out_flat[29] = numbers_concat_repl_wrapper_out_flat[3];
  assign out_flat[30] = numbers_concat_repl_wrapper_out_flat[5];
  assign out_flat[10] = numbers_concat_repl_wrapper_out_flat[6];
  assign out_flat[28] = numbers_concat_repl_wrapper_out_flat[7];
  assign out_flat[80] = numbers_concat_repl_wrapper_out_flat[9];
  assign out_flat[94] = numbers_logical_op_wrapper_out_flat[2];
  assign out_flat[8] = widths_struct_mod_wrapper_out_flat[3];
  assign out_flat[58] = widths_struct_mod_wrapper_out_flat[6];
  assign out_flat[26] = widths_struct_mod_wrapper_out_flat[7];
  assign out_flat[98] = widths_struct_mod_wrapper_out_flat[10];
  assign out_flat[63] = widths_partselect_wrapper_out_flat[4];
  assign out_flat[99] = const_arith_wrapper_out_flat[0];
  assign out_flat[87] = const_arith_wrapper_out_flat[5];
  assign out_flat[59] = const_arith_wrapper_out_flat[12];
  assign out_flat[72] = const_arith_wrapper_out_flat[14];
  assign out_flat[7] = const_arith_wrapper_out_flat[24];
  assign out_flat[36] = const_arith_wrapper_out_flat[27];
  assign out_flat[50] = const_arith_wrapper_out_flat[29];
  assign out_flat[41] = const_arith_wrapper_out_flat[30];
  assign out_flat[24] = const_arith_wrapper_out_flat[34];
  assign out_flat[48] = const_arith_wrapper_out_flat[35];
  assign out_flat[46] = const_arith_wrapper_out_flat[36];
  assign out_flat[82] = widths_union_mod_wrapper_out_flat[1];
  assign out_flat[21] = widths_union_mod_wrapper_out_flat[13];
  assign out_flat[74] = const_shift_wrapper_out_flat[6];
  assign out_flat[53] = const_shift_wrapper_out_flat[9];
  assign out_flat[62] = const_shift_wrapper_out_flat[12];
  assign out_flat[73] = const_shift_wrapper_out_flat[16];
  assign out_flat[27] = const_shift_wrapper_out_flat[23];
  assign out_flat[65] = widths_array_wrapper_out_flat[1];
  assign out_flat[47] = widths_array_wrapper_out_flat[7];
  assign out_flat[88] = numbers_select_wrapper_out_flat[2];
  assign out_flat[93] = numbers_select_wrapper_out_flat[6];
  assign out_flat[5] = widths_arith_wrapper_out_flat[0];
  assign out_flat[34] = const_nested_wrapper_out_flat[0];
  assign out_flat[13] = const_nested_wrapper_out_flat[4];
  assign out_flat[78] = const_nested_wrapper_out_flat[6];
  assign out_flat[84] = numbers_numbers_arithmetic_wrapper_out_flat[3];
  assign out_flat[85] = numbers_numbers_arithmetic_wrapper_out_flat[9];
  assign out_flat[55] = numbers_numbers_arithmetic_wrapper_out_flat[10];
  assign out_flat[37] = numbers_numbers_arithmetic_wrapper_out_flat[13];
  assign out_flat[14] = numbers_numbers_arithmetic_wrapper_out_flat[18];
  assign out_flat[43] = numbers_numbers_arithmetic_wrapper_out_flat[21];
  assign out_flat[20] = numbers_bitwise_logic_wrapper_out_flat[0];
  assign out_flat[2] = numbers_bitwise_logic_wrapper_out_flat[2];
  assign out_flat[52] = numbers_bitwise_logic_wrapper_out_flat[7];
  assign out_flat[3] = numbers_bitwise_logic_wrapper_out_flat[13];
  assign out_flat[81] = numbers_bitwise_logic_wrapper_out_flat[17];
  assign out_flat[9] = numbers_bitwise_logic_wrapper_out_flat[21];
  assign out_flat[0] = widths_concat_repl_wrapper_out_flat[1];
  assign out_flat[76] = widths_concat_repl_wrapper_out_flat[3];
  assign out_flat[68] = widths_concat_repl_wrapper_out_flat[4];
  assign out_flat[77] = widths_concat_repl_wrapper_out_flat[6];
  assign out_flat[70] = widths_concat_repl_wrapper_out_flat[7];
  assign out_flat[97] = widths_concat_repl_wrapper_out_flat[8];
  assign out_flat[40] = const_partselect_wrapper_out_flat[0];
  assign out_flat[32] = const_partselect_wrapper_out_flat[7];
  assign out_flat[89] = numbers_constant_wrapper_out_flat[2];
  assign out_flat[45] = numbers_constant_wrapper_out_flat[5];
  assign out_flat[56] = numbers_constant_wrapper_out_flat[6];
  assign out_flat[75] = numbers_constant_wrapper_out_flat[22];
  assign out_flat[79] = numbers_constant_wrapper_out_flat[23];
  assign out_flat[25] = numbers_constant_wrapper_out_flat[24];
  assign out_flat[15] = numbers_constant_wrapper_out_flat[33];
  assign out_flat[60] = numbers_constant_wrapper_out_flat[44];
  assign out_flat[57] = numbers_constant_wrapper_out_flat[50];
  assign out_flat[31] = numbers_constant_wrapper_out_flat[54];
  assign out_flat[4] = numbers_constant_wrapper_out_flat[55];
  assign out_flat[96] = numbers_constant_wrapper_out_flat[61];
  assign out_flat[86] = numbers_constant_wrapper_out_flat[62];
  assign out_flat[71] = numbers_constant_wrapper_out_flat[65];
  assign out_flat[91] = numbers_constant_wrapper_out_flat[67];
  assign out_flat[49] = numbers_constant_wrapper_out_flat[68];
  assign out_flat[35] = numbers_constant_wrapper_out_flat[73];
  assign out_flat[19] = numbers_constant_wrapper_out_flat[78];
  assign out_flat[90] = const_compare_wrapper_out_flat[1];
  assign out_flat[67] = const_compare_wrapper_out_flat[6];
  assign out_flat[22] = const_reduce_wrapper_out_flat[2];
  assign out_flat[61] = const_reduce_wrapper_out_flat[3];
  assign out_flat[38] = const_reduce_wrapper_out_flat[4];
  assign out_flat[92] = const_concat_repl_wrapper_out_flat[4];
  assign out_flat[64] = const_concat_repl_wrapper_out_flat[7];
  assign out_flat[1] = const_concat_repl_wrapper_out_flat[16];
  assign out_flat[16] = const_concat_repl_wrapper_out_flat[17];
  assign out_flat[42] = const_concat_repl_wrapper_out_flat[18];
  assign out_flat[17] = const_concat_repl_wrapper_out_flat[19];
  assign out_flat[6] = const_conditional_wrapper_out_flat[1];
  assign out_flat[23] = const_conditional_wrapper_out_flat[8];
  assign out_flat[83] = const_conditional_wrapper_out_flat[10];
  assign out_flat[12] = numbers_shift_wrapper_out_flat[1];
  assign out_flat[95] = numbers_shift_wrapper_out_flat[7];
  assign out_flat[69] = numbers_shift_wrapper_out_flat[13];
  assign out_flat[54] = const_logic_wrapper_out_flat[5];
  assign out_flat[66] = const_logic_wrapper_out_flat[12];
  assign out_flat[11] = const_logic_wrapper_out_flat[15];
  assign out_flat[39] = widths_shift_wrapper_out_flat[5];
  assign out_flat[51] = widths_shift_wrapper_out_flat[14];
  assign out_flat[44] = widths_shift_wrapper_out_flat[15];

  // Instantiate each module's wrapper
  const_arith_wrapper u_const_arith_wrapper (
    .in_flat  (const_arith_wrapper_in_flat),
    .out_flat (const_arith_wrapper_out_flat)
  );
  const_compare_wrapper u_const_compare_wrapper (
    .in_flat  (const_compare_wrapper_in_flat),
    .out_flat (const_compare_wrapper_out_flat)
  );
  const_concat_repl_wrapper u_const_concat_repl_wrapper (
    .in_flat  (const_concat_repl_wrapper_in_flat),
    .out_flat (const_concat_repl_wrapper_out_flat)
  );
  const_conditional_wrapper u_const_conditional_wrapper (
    .in_flat  (const_conditional_wrapper_in_flat),
    .out_flat (const_conditional_wrapper_out_flat)
  );
  const_logic_wrapper u_const_logic_wrapper (
    .in_flat  (const_logic_wrapper_in_flat),
    .out_flat (const_logic_wrapper_out_flat)
  );
  const_nested_wrapper u_const_nested_wrapper (
    .in_flat  (const_nested_wrapper_in_flat),
    .out_flat (const_nested_wrapper_out_flat)
  );
  const_partselect_wrapper u_const_partselect_wrapper (
    .in_flat  (const_partselect_wrapper_in_flat),
    .out_flat (const_partselect_wrapper_out_flat)
  );
  const_reduce_wrapper u_const_reduce_wrapper (
    .in_flat  (const_reduce_wrapper_in_flat),
    .out_flat (const_reduce_wrapper_out_flat)
  );
  const_shift_wrapper u_const_shift_wrapper (
    .in_flat  (const_shift_wrapper_in_flat),
    .out_flat (const_shift_wrapper_out_flat)
  );
  numbers_arithmetic_reduce_wrapper u_numbers_arithmetic_reduce_wrapper (
    .in_flat  (numbers_arithmetic_reduce_wrapper_in_flat),
    .out_flat (numbers_arithmetic_reduce_wrapper_out_flat)
  );
  numbers_bitwise_logic_wrapper u_numbers_bitwise_logic_wrapper (
    .in_flat  (numbers_bitwise_logic_wrapper_in_flat),
    .out_flat (numbers_bitwise_logic_wrapper_out_flat)
  );
  numbers_bitwise_reduce_wrapper u_numbers_bitwise_reduce_wrapper (
    .in_flat  (numbers_bitwise_reduce_wrapper_in_flat),
    .out_flat (numbers_bitwise_reduce_wrapper_out_flat)
  );
  numbers_concat_repl_wrapper u_numbers_concat_repl_wrapper (
    .in_flat  (numbers_concat_repl_wrapper_in_flat),
    .out_flat (numbers_concat_repl_wrapper_out_flat)
  );
  numbers_constant_wrapper u_numbers_constant_wrapper (
    .in_flat  (numbers_constant_wrapper_in_flat),
    .out_flat (numbers_constant_wrapper_out_flat)
  );
  numbers_logical_op_wrapper u_numbers_logical_op_wrapper (
    .in_flat  (numbers_logical_op_wrapper_in_flat),
    .out_flat (numbers_logical_op_wrapper_out_flat)
  );
  numbers_numbers_arithmetic_wrapper u_numbers_numbers_arithmetic_wrapper (
    .in_flat  (numbers_numbers_arithmetic_wrapper_in_flat),
    .out_flat (numbers_numbers_arithmetic_wrapper_out_flat)
  );
  numbers_reduce_case_wrapper u_numbers_reduce_case_wrapper (
    .in_flat  (numbers_reduce_case_wrapper_in_flat),
    .out_flat (numbers_reduce_case_wrapper_out_flat)
  );
  numbers_relational_wrapper u_numbers_relational_wrapper (
    .in_flat  (numbers_relational_wrapper_in_flat),
    .out_flat (numbers_relational_wrapper_out_flat)
  );
  numbers_select_wrapper u_numbers_select_wrapper (
    .in_flat  (numbers_select_wrapper_in_flat),
    .out_flat (numbers_select_wrapper_out_flat)
  );
  numbers_shift_wrapper u_numbers_shift_wrapper (
    .in_flat  (numbers_shift_wrapper_in_flat),
    .out_flat (numbers_shift_wrapper_out_flat)
  );
  widths_arith_wrapper u_widths_arith_wrapper (
    .in_flat  (widths_arith_wrapper_in_flat),
    .out_flat (widths_arith_wrapper_out_flat)
  );
  widths_array_wrapper u_widths_array_wrapper (
    .in_flat  (widths_array_wrapper_in_flat),
    .out_flat (widths_array_wrapper_out_flat)
  );
  widths_cast_wrapper u_widths_cast_wrapper (
    .in_flat  (widths_cast_wrapper_in_flat),
    .out_flat (widths_cast_wrapper_out_flat)
  );
  widths_concat_repl_wrapper u_widths_concat_repl_wrapper (
    .in_flat  (widths_concat_repl_wrapper_in_flat),
    .out_flat (widths_concat_repl_wrapper_out_flat)
  );
  widths_conditional_wrapper u_widths_conditional_wrapper (
    .in_flat  (widths_conditional_wrapper_in_flat),
    .out_flat (widths_conditional_wrapper_out_flat)
  );
  widths_enum_mod_wrapper u_widths_enum_mod_wrapper (
    .in_flat  (widths_enum_mod_wrapper_in_flat),
    .out_flat (widths_enum_mod_wrapper_out_flat)
  );
  widths_logic_mod_wrapper u_widths_logic_mod_wrapper (
    .in_flat  (widths_logic_mod_wrapper_in_flat),
    .out_flat (widths_logic_mod_wrapper_out_flat)
  );
  widths_param_wrapper u_widths_param_wrapper (
    .in_flat  (widths_param_wrapper_in_flat),
    .out_flat (widths_param_wrapper_out_flat)
  );
  widths_partselect_wrapper u_widths_partselect_wrapper (
    .in_flat  (widths_partselect_wrapper_in_flat),
    .out_flat (widths_partselect_wrapper_out_flat)
  );
  widths_shift_wrapper u_widths_shift_wrapper (
    .in_flat  (widths_shift_wrapper_in_flat),
    .out_flat (widths_shift_wrapper_out_flat)
  );
  widths_struct_mod_wrapper u_widths_struct_mod_wrapper (
    .in_flat  (widths_struct_mod_wrapper_in_flat),
    .out_flat (widths_struct_mod_wrapper_out_flat)
  );
  widths_union_mod_wrapper u_widths_union_mod_wrapper (
    .in_flat  (widths_union_mod_wrapper_in_flat),
    .out_flat (widths_union_mod_wrapper_out_flat)
  );

endmodule