// Auto-generated Top Module for flattened IO

module top (
    input  wire clk,
    input  wire rst_n,
    input  wire [139:0] in_flat,
    output wire [158:0] out_flat
);

// Per-module I/O buses
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

// External inputs to module inputs
assign const_arith_wrapper_in_flat[0] = in_flat[0];
assign const_arith_wrapper_in_flat[1] = in_flat[1];
assign const_arith_wrapper_in_flat[2] = in_flat[2];
assign const_arith_wrapper_in_flat[3] = in_flat[3];
assign const_arith_wrapper_in_flat[5] = in_flat[4];
assign const_arith_wrapper_in_flat[6] = in_flat[5];
assign const_arith_wrapper_in_flat[7] = in_flat[6];
assign const_arith_wrapper_in_flat[8] = in_flat[7];
assign const_arith_wrapper_in_flat[9] = in_flat[8];
assign const_arith_wrapper_in_flat[10] = in_flat[9];
assign const_arith_wrapper_in_flat[11] = in_flat[10];
assign const_arith_wrapper_in_flat[12] = in_flat[11];
assign const_arith_wrapper_in_flat[13] = in_flat[12];
assign const_arith_wrapper_in_flat[14] = in_flat[13];
assign const_arith_wrapper_in_flat[15] = in_flat[14];
assign const_compare_wrapper_in_flat[0] = in_flat[15];
assign const_compare_wrapper_in_flat[1] = in_flat[16];
assign const_compare_wrapper_in_flat[2] = in_flat[17];
assign const_compare_wrapper_in_flat[3] = in_flat[18];
assign const_compare_wrapper_in_flat[4] = in_flat[19];
assign const_compare_wrapper_in_flat[5] = in_flat[20];
assign const_compare_wrapper_in_flat[6] = in_flat[21];
assign const_compare_wrapper_in_flat[7] = in_flat[22];
assign const_compare_wrapper_in_flat[9] = in_flat[23];
assign const_compare_wrapper_in_flat[10] = in_flat[24];
assign const_compare_wrapper_in_flat[11] = in_flat[25];
assign const_compare_wrapper_in_flat[12] = in_flat[26];
assign const_compare_wrapper_in_flat[13] = in_flat[27];
assign const_compare_wrapper_in_flat[14] = in_flat[28];
assign const_compare_wrapper_in_flat[15] = in_flat[29];
assign const_compare_wrapper_in_flat[16] = in_flat[30];
assign const_compare_wrapper_in_flat[17] = in_flat[31];
assign const_compare_wrapper_in_flat[18] = in_flat[32];
assign const_compare_wrapper_in_flat[19] = in_flat[33];
assign const_compare_wrapper_in_flat[20] = in_flat[34];
assign const_compare_wrapper_in_flat[21] = in_flat[35];
assign const_compare_wrapper_in_flat[23] = in_flat[36];
assign const_concat_repl_wrapper_in_flat[0] = in_flat[37];
assign const_concat_repl_wrapper_in_flat[1] = in_flat[38];
assign const_concat_repl_wrapper_in_flat[2] = in_flat[39];
assign const_concat_repl_wrapper_in_flat[3] = in_flat[40];
assign const_concat_repl_wrapper_in_flat[4] = in_flat[41];
assign const_concat_repl_wrapper_in_flat[6] = in_flat[42];
assign const_concat_repl_wrapper_in_flat[8] = in_flat[43];
assign const_concat_repl_wrapper_in_flat[9] = in_flat[44];
assign const_conditional_wrapper_in_flat[0] = in_flat[45];
assign const_conditional_wrapper_in_flat[1] = in_flat[46];
assign const_conditional_wrapper_in_flat[2] = in_flat[47];
assign const_conditional_wrapper_in_flat[3] = in_flat[48];
assign const_conditional_wrapper_in_flat[4] = in_flat[49];
assign const_conditional_wrapper_in_flat[5] = in_flat[50];
assign const_conditional_wrapper_in_flat[6] = in_flat[51];
assign const_conditional_wrapper_in_flat[7] = in_flat[52];
assign const_conditional_wrapper_in_flat[8] = in_flat[53];
assign const_conditional_wrapper_in_flat[9] = in_flat[54];
assign const_conditional_wrapper_in_flat[10] = in_flat[55];
assign const_conditional_wrapper_in_flat[11] = in_flat[56];
assign const_conditional_wrapper_in_flat[12] = in_flat[57];
assign const_conditional_wrapper_in_flat[13] = in_flat[58];
assign const_conditional_wrapper_in_flat[14] = in_flat[59];
assign const_conditional_wrapper_in_flat[15] = in_flat[60];
assign const_conditional_wrapper_in_flat[16] = in_flat[61];
assign const_conditional_wrapper_in_flat[17] = in_flat[62];
assign const_conditional_wrapper_in_flat[18] = in_flat[63];
assign const_conditional_wrapper_in_flat[19] = in_flat[64];
assign const_conditional_wrapper_in_flat[20] = in_flat[65];
assign const_conditional_wrapper_in_flat[21] = in_flat[66];
assign const_conditional_wrapper_in_flat[22] = in_flat[67];
assign const_conditional_wrapper_in_flat[24] = in_flat[68];
assign const_conditional_wrapper_in_flat[25] = in_flat[69];
assign const_conditional_wrapper_in_flat[26] = in_flat[70];
assign const_conditional_wrapper_in_flat[28] = in_flat[71];
assign const_conditional_wrapper_in_flat[30] = in_flat[72];
assign const_conditional_wrapper_in_flat[31] = in_flat[73];
assign const_conditional_wrapper_in_flat[32] = in_flat[74];
assign const_conditional_wrapper_in_flat[33] = in_flat[75];
assign const_logic_wrapper_in_flat[1] = in_flat[76];
assign const_logic_wrapper_in_flat[2] = in_flat[77];
assign const_logic_wrapper_in_flat[3] = in_flat[78];
assign const_logic_wrapper_in_flat[4] = in_flat[79];
assign const_logic_wrapper_in_flat[5] = in_flat[80];
assign const_logic_wrapper_in_flat[6] = in_flat[81];
assign const_logic_wrapper_in_flat[7] = in_flat[82];
assign const_logic_wrapper_in_flat[8] = in_flat[83];
assign const_logic_wrapper_in_flat[9] = in_flat[84];
assign const_nested_wrapper_in_flat[0] = in_flat[85];
assign const_nested_wrapper_in_flat[2] = in_flat[86];
assign const_nested_wrapper_in_flat[3] = in_flat[87];
assign const_nested_wrapper_in_flat[4] = in_flat[88];
assign const_nested_wrapper_in_flat[5] = in_flat[89];
assign const_nested_wrapper_in_flat[6] = in_flat[90];
assign const_nested_wrapper_in_flat[7] = in_flat[91];
assign const_nested_wrapper_in_flat[8] = in_flat[92];
assign const_nested_wrapper_in_flat[9] = in_flat[93];
assign const_nested_wrapper_in_flat[10] = in_flat[94];
assign const_nested_wrapper_in_flat[11] = in_flat[95];
assign const_nested_wrapper_in_flat[12] = in_flat[96];
assign const_nested_wrapper_in_flat[13] = in_flat[97];
assign const_nested_wrapper_in_flat[14] = in_flat[98];
assign const_nested_wrapper_in_flat[15] = in_flat[99];
assign const_nested_wrapper_in_flat[16] = in_flat[100];
assign const_nested_wrapper_in_flat[17] = in_flat[101];
assign const_nested_wrapper_in_flat[18] = in_flat[102];
assign const_nested_wrapper_in_flat[19] = in_flat[103];
assign const_nested_wrapper_in_flat[20] = in_flat[104];
assign const_nested_wrapper_in_flat[21] = in_flat[105];
assign const_nested_wrapper_in_flat[22] = in_flat[106];
assign const_nested_wrapper_in_flat[23] = in_flat[107];
assign const_nested_wrapper_in_flat[24] = in_flat[108];
assign const_nested_wrapper_in_flat[25] = in_flat[109];
assign const_nested_wrapper_in_flat[26] = in_flat[110];
assign const_partselect_wrapper_in_flat[0] = in_flat[111];
assign const_partselect_wrapper_in_flat[2] = in_flat[112];
assign const_partselect_wrapper_in_flat[3] = in_flat[113];
assign const_partselect_wrapper_in_flat[4] = in_flat[114];
assign const_partselect_wrapper_in_flat[5] = in_flat[115];
assign const_partselect_wrapper_in_flat[6] = in_flat[116];
assign const_partselect_wrapper_in_flat[8] = in_flat[117];
assign const_partselect_wrapper_in_flat[9] = in_flat[118];
assign const_partselect_wrapper_in_flat[10] = in_flat[119];
assign const_partselect_wrapper_in_flat[11] = in_flat[120];
assign const_partselect_wrapper_in_flat[12] = in_flat[121];
assign const_partselect_wrapper_in_flat[13] = in_flat[122];
assign const_partselect_wrapper_in_flat[14] = in_flat[123];
assign const_partselect_wrapper_in_flat[15] = in_flat[124];
assign const_partselect_wrapper_in_flat[16] = in_flat[125];
assign const_partselect_wrapper_in_flat[17] = in_flat[126];
assign const_partselect_wrapper_in_flat[18] = in_flat[127];
assign const_reduce_wrapper_in_flat[1] = in_flat[128];
assign const_shift_wrapper_in_flat[0] = in_flat[129];
assign const_shift_wrapper_in_flat[1] = in_flat[130];
assign const_shift_wrapper_in_flat[2] = in_flat[131];
assign const_shift_wrapper_in_flat[3] = in_flat[132];
assign const_shift_wrapper_in_flat[4] = in_flat[133];
assign const_shift_wrapper_in_flat[5] = in_flat[134];
assign const_shift_wrapper_in_flat[6] = in_flat[135];
assign const_shift_wrapper_in_flat[7] = in_flat[136];
assign const_shift_wrapper_in_flat[8] = in_flat[137];
assign const_shift_wrapper_in_flat[9] = in_flat[138];
assign const_shift_wrapper_in_flat[10] = in_flat[139];

// Internal MTM connections (module-to-module)
assign const_logic_wrapper_in_flat[0] = const_arith_wrapper_out_flat[11];
assign const_reduce_wrapper_in_flat[2] = const_compare_wrapper_out_flat[3];
assign const_compare_wrapper_in_flat[8] = const_concat_repl_wrapper_out_flat[1];
assign const_reduce_wrapper_in_flat[3] = const_concat_repl_wrapper_out_flat[6];
assign const_concat_repl_wrapper_in_flat[5] = const_conditional_wrapper_out_flat[11];
assign const_compare_wrapper_in_flat[22] = const_conditional_wrapper_out_flat[14];
assign const_partselect_wrapper_in_flat[1] = const_logic_wrapper_out_flat[10];
assign const_conditional_wrapper_in_flat[29] = const_logic_wrapper_out_flat[18];
assign const_partselect_wrapper_in_flat[7] = const_nested_wrapper_out_flat[3];
assign const_conditional_wrapper_in_flat[23] = const_nested_wrapper_out_flat[4];
assign const_reduce_wrapper_in_flat[0] = const_nested_wrapper_out_flat[7];
assign const_conditional_wrapper_in_flat[27] = const_partselect_wrapper_out_flat[7];
assign const_nested_wrapper_in_flat[1] = const_shift_wrapper_out_flat[3];
assign const_partselect_wrapper_in_flat[19] = const_shift_wrapper_out_flat[5];
assign const_concat_repl_wrapper_in_flat[7] = const_shift_wrapper_out_flat[9];
assign const_arith_wrapper_in_flat[4] = const_shift_wrapper_out_flat[17];

// External outputs (MTO + MTM wires)
assign out_flat[0] = const_arith_wrapper_out_flat[0];
assign out_flat[1] = const_arith_wrapper_out_flat[1];
assign out_flat[2] = const_arith_wrapper_out_flat[2];
assign out_flat[3] = const_arith_wrapper_out_flat[3];
assign out_flat[4] = const_arith_wrapper_out_flat[4];
assign out_flat[5] = const_arith_wrapper_out_flat[5];
assign out_flat[6] = const_arith_wrapper_out_flat[6];
assign out_flat[7] = const_arith_wrapper_out_flat[7];
assign out_flat[8] = const_arith_wrapper_out_flat[8];
assign out_flat[9] = const_arith_wrapper_out_flat[9];
assign out_flat[10] = const_arith_wrapper_out_flat[10];
assign out_flat[11] = const_arith_wrapper_out_flat[11];
assign out_flat[12] = const_arith_wrapper_out_flat[12];
assign out_flat[13] = const_arith_wrapper_out_flat[13];
assign out_flat[14] = const_arith_wrapper_out_flat[14];
assign out_flat[15] = const_arith_wrapper_out_flat[15];
assign out_flat[16] = const_arith_wrapper_out_flat[16];
assign out_flat[17] = const_arith_wrapper_out_flat[17];
assign out_flat[18] = const_arith_wrapper_out_flat[18];
assign out_flat[19] = const_arith_wrapper_out_flat[19];
assign out_flat[20] = const_arith_wrapper_out_flat[20];
assign out_flat[21] = const_arith_wrapper_out_flat[21];
assign out_flat[22] = const_arith_wrapper_out_flat[22];
assign out_flat[23] = const_arith_wrapper_out_flat[23];
assign out_flat[24] = const_arith_wrapper_out_flat[24];
assign out_flat[25] = const_arith_wrapper_out_flat[25];
assign out_flat[26] = const_arith_wrapper_out_flat[26];
assign out_flat[27] = const_arith_wrapper_out_flat[27];
assign out_flat[28] = const_arith_wrapper_out_flat[28];
assign out_flat[29] = const_arith_wrapper_out_flat[29];
assign out_flat[30] = const_arith_wrapper_out_flat[30];
assign out_flat[31] = const_arith_wrapper_out_flat[31];
assign out_flat[32] = const_arith_wrapper_out_flat[32];
assign out_flat[33] = const_arith_wrapper_out_flat[33];
assign out_flat[34] = const_arith_wrapper_out_flat[34];
assign out_flat[35] = const_arith_wrapper_out_flat[35];
assign out_flat[36] = const_arith_wrapper_out_flat[36];
assign out_flat[37] = const_arith_wrapper_out_flat[37];
assign out_flat[38] = const_arith_wrapper_out_flat[38];
assign out_flat[39] = const_arith_wrapper_out_flat[39];
assign out_flat[40] = const_compare_wrapper_out_flat[0];
assign out_flat[41] = const_compare_wrapper_out_flat[1];
assign out_flat[42] = const_compare_wrapper_out_flat[2];
assign out_flat[43] = const_compare_wrapper_out_flat[3];
assign out_flat[44] = const_compare_wrapper_out_flat[4];
assign out_flat[45] = const_compare_wrapper_out_flat[5];
assign out_flat[46] = const_compare_wrapper_out_flat[6];
assign out_flat[47] = const_compare_wrapper_out_flat[7];
assign out_flat[48] = const_concat_repl_wrapper_out_flat[0];
assign out_flat[49] = const_concat_repl_wrapper_out_flat[1];
assign out_flat[50] = const_concat_repl_wrapper_out_flat[2];
assign out_flat[51] = const_concat_repl_wrapper_out_flat[3];
assign out_flat[52] = const_concat_repl_wrapper_out_flat[4];
assign out_flat[53] = const_concat_repl_wrapper_out_flat[5];
assign out_flat[54] = const_concat_repl_wrapper_out_flat[6];
assign out_flat[55] = const_concat_repl_wrapper_out_flat[7];
assign out_flat[56] = const_concat_repl_wrapper_out_flat[8];
assign out_flat[57] = const_concat_repl_wrapper_out_flat[9];
assign out_flat[58] = const_concat_repl_wrapper_out_flat[10];
assign out_flat[59] = const_concat_repl_wrapper_out_flat[11];
assign out_flat[60] = const_concat_repl_wrapper_out_flat[12];
assign out_flat[61] = const_concat_repl_wrapper_out_flat[13];
assign out_flat[62] = const_concat_repl_wrapper_out_flat[14];
assign out_flat[63] = const_concat_repl_wrapper_out_flat[15];
assign out_flat[64] = const_concat_repl_wrapper_out_flat[16];
assign out_flat[65] = const_concat_repl_wrapper_out_flat[17];
assign out_flat[66] = const_concat_repl_wrapper_out_flat[18];
assign out_flat[67] = const_concat_repl_wrapper_out_flat[19];
assign out_flat[68] = const_concat_repl_wrapper_out_flat[20];
assign out_flat[69] = const_concat_repl_wrapper_out_flat[21];
assign out_flat[70] = const_conditional_wrapper_out_flat[0];
assign out_flat[71] = const_conditional_wrapper_out_flat[1];
assign out_flat[72] = const_conditional_wrapper_out_flat[2];
assign out_flat[73] = const_conditional_wrapper_out_flat[3];
assign out_flat[74] = const_conditional_wrapper_out_flat[4];
assign out_flat[75] = const_conditional_wrapper_out_flat[5];
assign out_flat[76] = const_conditional_wrapper_out_flat[6];
assign out_flat[77] = const_conditional_wrapper_out_flat[7];
assign out_flat[78] = const_conditional_wrapper_out_flat[8];
assign out_flat[79] = const_conditional_wrapper_out_flat[9];
assign out_flat[80] = const_conditional_wrapper_out_flat[10];
assign out_flat[81] = const_conditional_wrapper_out_flat[11];
assign out_flat[82] = const_conditional_wrapper_out_flat[12];
assign out_flat[83] = const_conditional_wrapper_out_flat[13];
assign out_flat[84] = const_conditional_wrapper_out_flat[14];
assign out_flat[85] = const_conditional_wrapper_out_flat[15];
assign out_flat[86] = const_conditional_wrapper_out_flat[16];
assign out_flat[87] = const_conditional_wrapper_out_flat[17];
assign out_flat[88] = const_conditional_wrapper_out_flat[18];
assign out_flat[89] = const_conditional_wrapper_out_flat[19];
assign out_flat[90] = const_conditional_wrapper_out_flat[20];
assign out_flat[91] = const_conditional_wrapper_out_flat[21];
assign out_flat[92] = const_conditional_wrapper_out_flat[22];
assign out_flat[93] = const_conditional_wrapper_out_flat[23];
assign out_flat[94] = const_logic_wrapper_out_flat[0];
assign out_flat[95] = const_logic_wrapper_out_flat[1];
assign out_flat[96] = const_logic_wrapper_out_flat[2];
assign out_flat[97] = const_logic_wrapper_out_flat[3];
assign out_flat[98] = const_logic_wrapper_out_flat[4];
assign out_flat[99] = const_logic_wrapper_out_flat[5];
assign out_flat[100] = const_logic_wrapper_out_flat[6];
assign out_flat[101] = const_logic_wrapper_out_flat[7];
assign out_flat[102] = const_logic_wrapper_out_flat[8];
assign out_flat[103] = const_logic_wrapper_out_flat[9];
assign out_flat[104] = const_logic_wrapper_out_flat[10];
assign out_flat[105] = const_logic_wrapper_out_flat[11];
assign out_flat[106] = const_logic_wrapper_out_flat[12];
assign out_flat[107] = const_logic_wrapper_out_flat[13];
assign out_flat[108] = const_logic_wrapper_out_flat[14];
assign out_flat[109] = const_logic_wrapper_out_flat[15];
assign out_flat[110] = const_logic_wrapper_out_flat[16];
assign out_flat[111] = const_logic_wrapper_out_flat[17];
assign out_flat[112] = const_logic_wrapper_out_flat[18];
assign out_flat[113] = const_nested_wrapper_out_flat[0];
assign out_flat[114] = const_nested_wrapper_out_flat[1];
assign out_flat[115] = const_nested_wrapper_out_flat[2];
assign out_flat[116] = const_nested_wrapper_out_flat[3];
assign out_flat[117] = const_nested_wrapper_out_flat[4];
assign out_flat[118] = const_nested_wrapper_out_flat[5];
assign out_flat[119] = const_nested_wrapper_out_flat[6];
assign out_flat[120] = const_nested_wrapper_out_flat[7];
assign out_flat[121] = const_partselect_wrapper_out_flat[0];
assign out_flat[122] = const_partselect_wrapper_out_flat[1];
assign out_flat[123] = const_partselect_wrapper_out_flat[2];
assign out_flat[124] = const_partselect_wrapper_out_flat[3];
assign out_flat[125] = const_partselect_wrapper_out_flat[4];
assign out_flat[126] = const_partselect_wrapper_out_flat[5];
assign out_flat[127] = const_partselect_wrapper_out_flat[6];
assign out_flat[128] = const_partselect_wrapper_out_flat[7];
assign out_flat[129] = const_reduce_wrapper_out_flat[0];
assign out_flat[130] = const_reduce_wrapper_out_flat[1];
assign out_flat[131] = const_reduce_wrapper_out_flat[2];
assign out_flat[132] = const_reduce_wrapper_out_flat[3];
assign out_flat[133] = const_reduce_wrapper_out_flat[4];
assign out_flat[134] = const_reduce_wrapper_out_flat[5];
assign out_flat[135] = const_shift_wrapper_out_flat[0];
assign out_flat[136] = const_shift_wrapper_out_flat[1];
assign out_flat[137] = const_shift_wrapper_out_flat[2];
assign out_flat[138] = const_shift_wrapper_out_flat[3];
assign out_flat[139] = const_shift_wrapper_out_flat[4];
assign out_flat[140] = const_shift_wrapper_out_flat[5];
assign out_flat[141] = const_shift_wrapper_out_flat[6];
assign out_flat[142] = const_shift_wrapper_out_flat[7];
assign out_flat[143] = const_shift_wrapper_out_flat[8];
assign out_flat[144] = const_shift_wrapper_out_flat[9];
assign out_flat[145] = const_shift_wrapper_out_flat[10];
assign out_flat[146] = const_shift_wrapper_out_flat[11];
assign out_flat[147] = const_shift_wrapper_out_flat[12];
assign out_flat[148] = const_shift_wrapper_out_flat[13];
assign out_flat[149] = const_shift_wrapper_out_flat[14];
assign out_flat[150] = const_shift_wrapper_out_flat[15];
assign out_flat[151] = const_shift_wrapper_out_flat[16];
assign out_flat[152] = const_shift_wrapper_out_flat[17];
assign out_flat[153] = const_shift_wrapper_out_flat[18];
assign out_flat[154] = const_shift_wrapper_out_flat[19];
assign out_flat[155] = const_shift_wrapper_out_flat[20];
assign out_flat[156] = const_shift_wrapper_out_flat[21];
assign out_flat[157] = const_shift_wrapper_out_flat[22];
assign out_flat[158] = const_shift_wrapper_out_flat[23];

// Instantiate all module wrappers
const_arith_wrapper u_const_arith_wrapper (
    .in_flat(const_arith_wrapper_in_flat),
    .out_flat(const_arith_wrapper_out_flat)
);
const_compare_wrapper u_const_compare_wrapper (
    .in_flat(const_compare_wrapper_in_flat),
    .out_flat(const_compare_wrapper_out_flat)
);
const_concat_repl_wrapper u_const_concat_repl_wrapper (
    .in_flat(const_concat_repl_wrapper_in_flat),
    .out_flat(const_concat_repl_wrapper_out_flat)
);
const_conditional_wrapper u_const_conditional_wrapper (
    .in_flat(const_conditional_wrapper_in_flat),
    .out_flat(const_conditional_wrapper_out_flat)
);
const_logic_wrapper u_const_logic_wrapper (
    .in_flat(const_logic_wrapper_in_flat),
    .out_flat(const_logic_wrapper_out_flat)
);
const_nested_wrapper u_const_nested_wrapper (
    .in_flat(const_nested_wrapper_in_flat),
    .out_flat(const_nested_wrapper_out_flat)
);
const_partselect_wrapper u_const_partselect_wrapper (
    .in_flat(const_partselect_wrapper_in_flat),
    .out_flat(const_partselect_wrapper_out_flat)
);
const_reduce_wrapper u_const_reduce_wrapper (
    .in_flat(const_reduce_wrapper_in_flat),
    .out_flat(const_reduce_wrapper_out_flat)
);
const_shift_wrapper u_const_shift_wrapper (
    .in_flat(const_shift_wrapper_in_flat),
    .out_flat(const_shift_wrapper_out_flat)
);
endmodule