// Auto-generated Top Module for flattened IO

module top (
    input  wire clk,
    input  wire rst_n,
    input  wire [260:0] in_flat,
    output wire [329:0] out_flat
);

// Per-module I/O buses
wire [15:0] arithmetic_reduce_wrapper_in_flat;
wire [9:0] arithmetic_reduce_wrapper_out_flat;
wire [17:0] array_wrapper_in_flat;
wire [15:0] array_wrapper_out_flat;
wire [15:0] bitwise_logic_wrapper_in_flat;
wire [23:0] bitwise_logic_wrapper_out_flat;
wire [7:0] bitwise_reduce_wrapper_in_flat;
wire [2:0] bitwise_reduce_wrapper_out_flat;
wire [11:0] cast_wrapper_in_flat;
wire [11:0] cast_wrapper_out_flat;
wire [8:0] conditional_wrapper_in_flat;
wire [3:0] conditional_wrapper_out_flat;
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
wire [1:0] logical_op_wrapper_in_flat;
wire [2:0] logical_op_wrapper_out_flat;
wire [5:0] numbers_concat_repl_wrapper_in_flat;
wire [17:0] numbers_concat_repl_wrapper_out_flat;
wire [18:0] partselect_wrapper_in_flat;
wire [8:0] partselect_wrapper_out_flat;
wire [7:0] relational_wrapper_in_flat;
wire [7:0] relational_wrapper_out_flat;
wire [19:0] select_wrapper_in_flat;
wire [8:0] select_wrapper_out_flat;
wire [10:0] shift_wrapper_in_flat;
wire [15:0] shift_wrapper_out_flat;
wire [3:0] width_enum_wrapper_in_flat;
wire [4:0] width_enum_wrapper_out_flat;
wire [7:0] width_logic_wrapper_in_flat;
wire [5:0] width_logic_wrapper_out_flat;
wire [11:0] width_struct_wrapper_in_flat;
wire [11:0] width_struct_wrapper_out_flat;
wire [15:0] width_union_wrapper_in_flat;
wire [15:0] width_union_wrapper_out_flat;

// External inputs to module inputs
assign arithmetic_reduce_wrapper_in_flat[0] = in_flat[0];
assign arithmetic_reduce_wrapper_in_flat[1] = in_flat[1];
assign arithmetic_reduce_wrapper_in_flat[2] = in_flat[2];
assign arithmetic_reduce_wrapper_in_flat[3] = in_flat[3];
assign arithmetic_reduce_wrapper_in_flat[4] = in_flat[4];
assign arithmetic_reduce_wrapper_in_flat[5] = in_flat[5];
assign arithmetic_reduce_wrapper_in_flat[6] = in_flat[6];
assign arithmetic_reduce_wrapper_in_flat[7] = in_flat[7];
assign arithmetic_reduce_wrapper_in_flat[8] = in_flat[8];
assign arithmetic_reduce_wrapper_in_flat[10] = in_flat[9];
assign arithmetic_reduce_wrapper_in_flat[12] = in_flat[10];
assign arithmetic_reduce_wrapper_in_flat[14] = in_flat[11];
assign arithmetic_reduce_wrapper_in_flat[15] = in_flat[12];
assign array_wrapper_in_flat[0] = in_flat[13];
assign array_wrapper_in_flat[1] = in_flat[14];
assign array_wrapper_in_flat[2] = in_flat[15];
assign array_wrapper_in_flat[3] = in_flat[16];
assign array_wrapper_in_flat[6] = in_flat[17];
assign array_wrapper_in_flat[7] = in_flat[18];
assign array_wrapper_in_flat[8] = in_flat[19];
assign array_wrapper_in_flat[9] = in_flat[20];
assign array_wrapper_in_flat[11] = in_flat[21];
assign array_wrapper_in_flat[12] = in_flat[22];
assign array_wrapper_in_flat[13] = in_flat[23];
assign array_wrapper_in_flat[14] = in_flat[24];
assign array_wrapper_in_flat[15] = in_flat[25];
assign array_wrapper_in_flat[16] = in_flat[26];
assign bitwise_logic_wrapper_in_flat[0] = in_flat[27];
assign bitwise_logic_wrapper_in_flat[1] = in_flat[28];
assign bitwise_logic_wrapper_in_flat[2] = in_flat[29];
assign bitwise_logic_wrapper_in_flat[4] = in_flat[30];
assign bitwise_logic_wrapper_in_flat[5] = in_flat[31];
assign bitwise_logic_wrapper_in_flat[6] = in_flat[32];
assign bitwise_logic_wrapper_in_flat[7] = in_flat[33];
assign bitwise_logic_wrapper_in_flat[8] = in_flat[34];
assign bitwise_logic_wrapper_in_flat[9] = in_flat[35];
assign bitwise_logic_wrapper_in_flat[10] = in_flat[36];
assign bitwise_logic_wrapper_in_flat[11] = in_flat[37];
assign bitwise_logic_wrapper_in_flat[12] = in_flat[38];
assign bitwise_logic_wrapper_in_flat[13] = in_flat[39];
assign bitwise_logic_wrapper_in_flat[14] = in_flat[40];
assign bitwise_logic_wrapper_in_flat[15] = in_flat[41];
assign bitwise_reduce_wrapper_in_flat[2] = in_flat[42];
assign bitwise_reduce_wrapper_in_flat[3] = in_flat[43];
assign bitwise_reduce_wrapper_in_flat[4] = in_flat[44];
assign bitwise_reduce_wrapper_in_flat[6] = in_flat[45];
assign bitwise_reduce_wrapper_in_flat[7] = in_flat[46];
assign cast_wrapper_in_flat[0] = in_flat[47];
assign cast_wrapper_in_flat[1] = in_flat[48];
assign cast_wrapper_in_flat[2] = in_flat[49];
assign cast_wrapper_in_flat[3] = in_flat[50];
assign cast_wrapper_in_flat[4] = in_flat[51];
assign cast_wrapper_in_flat[5] = in_flat[52];
assign cast_wrapper_in_flat[6] = in_flat[53];
assign cast_wrapper_in_flat[7] = in_flat[54];
assign cast_wrapper_in_flat[8] = in_flat[55];
assign cast_wrapper_in_flat[9] = in_flat[56];
assign cast_wrapper_in_flat[10] = in_flat[57];
assign cast_wrapper_in_flat[11] = in_flat[58];
assign conditional_wrapper_in_flat[0] = in_flat[59];
assign conditional_wrapper_in_flat[3] = in_flat[60];
assign conditional_wrapper_in_flat[4] = in_flat[61];
assign conditional_wrapper_in_flat[5] = in_flat[62];
assign conditional_wrapper_in_flat[6] = in_flat[63];
assign const_arith_wrapper_in_flat[0] = in_flat[64];
assign const_arith_wrapper_in_flat[1] = in_flat[65];
assign const_arith_wrapper_in_flat[3] = in_flat[66];
assign const_arith_wrapper_in_flat[4] = in_flat[67];
assign const_arith_wrapper_in_flat[5] = in_flat[68];
assign const_arith_wrapper_in_flat[6] = in_flat[69];
assign const_arith_wrapper_in_flat[7] = in_flat[70];
assign const_arith_wrapper_in_flat[8] = in_flat[71];
assign const_arith_wrapper_in_flat[9] = in_flat[72];
assign const_arith_wrapper_in_flat[11] = in_flat[73];
assign const_arith_wrapper_in_flat[13] = in_flat[74];
assign const_arith_wrapper_in_flat[14] = in_flat[75];
assign const_arith_wrapper_in_flat[15] = in_flat[76];
assign const_compare_wrapper_in_flat[0] = in_flat[77];
assign const_compare_wrapper_in_flat[1] = in_flat[78];
assign const_compare_wrapper_in_flat[2] = in_flat[79];
assign const_compare_wrapper_in_flat[3] = in_flat[80];
assign const_compare_wrapper_in_flat[4] = in_flat[81];
assign const_compare_wrapper_in_flat[5] = in_flat[82];
assign const_compare_wrapper_in_flat[6] = in_flat[83];
assign const_compare_wrapper_in_flat[7] = in_flat[84];
assign const_compare_wrapper_in_flat[8] = in_flat[85];
assign const_compare_wrapper_in_flat[9] = in_flat[86];
assign const_compare_wrapper_in_flat[10] = in_flat[87];
assign const_compare_wrapper_in_flat[11] = in_flat[88];
assign const_compare_wrapper_in_flat[12] = in_flat[89];
assign const_compare_wrapper_in_flat[13] = in_flat[90];
assign const_compare_wrapper_in_flat[14] = in_flat[91];
assign const_compare_wrapper_in_flat[15] = in_flat[92];
assign const_compare_wrapper_in_flat[16] = in_flat[93];
assign const_compare_wrapper_in_flat[17] = in_flat[94];
assign const_compare_wrapper_in_flat[20] = in_flat[95];
assign const_compare_wrapper_in_flat[21] = in_flat[96];
assign const_compare_wrapper_in_flat[22] = in_flat[97];
assign const_concat_repl_wrapper_in_flat[0] = in_flat[98];
assign const_concat_repl_wrapper_in_flat[1] = in_flat[99];
assign const_concat_repl_wrapper_in_flat[3] = in_flat[100];
assign const_concat_repl_wrapper_in_flat[4] = in_flat[101];
assign const_concat_repl_wrapper_in_flat[5] = in_flat[102];
assign const_concat_repl_wrapper_in_flat[6] = in_flat[103];
assign const_concat_repl_wrapper_in_flat[7] = in_flat[104];
assign const_concat_repl_wrapper_in_flat[8] = in_flat[105];
assign const_concat_repl_wrapper_in_flat[9] = in_flat[106];
assign const_conditional_wrapper_in_flat[0] = in_flat[107];
assign const_conditional_wrapper_in_flat[2] = in_flat[108];
assign const_conditional_wrapper_in_flat[3] = in_flat[109];
assign const_conditional_wrapper_in_flat[4] = in_flat[110];
assign const_conditional_wrapper_in_flat[5] = in_flat[111];
assign const_conditional_wrapper_in_flat[6] = in_flat[112];
assign const_conditional_wrapper_in_flat[7] = in_flat[113];
assign const_conditional_wrapper_in_flat[8] = in_flat[114];
assign const_conditional_wrapper_in_flat[9] = in_flat[115];
assign const_conditional_wrapper_in_flat[10] = in_flat[116];
assign const_conditional_wrapper_in_flat[11] = in_flat[117];
assign const_conditional_wrapper_in_flat[13] = in_flat[118];
assign const_conditional_wrapper_in_flat[14] = in_flat[119];
assign const_conditional_wrapper_in_flat[15] = in_flat[120];
assign const_conditional_wrapper_in_flat[16] = in_flat[121];
assign const_conditional_wrapper_in_flat[17] = in_flat[122];
assign const_conditional_wrapper_in_flat[18] = in_flat[123];
assign const_conditional_wrapper_in_flat[19] = in_flat[124];
assign const_conditional_wrapper_in_flat[21] = in_flat[125];
assign const_conditional_wrapper_in_flat[22] = in_flat[126];
assign const_conditional_wrapper_in_flat[23] = in_flat[127];
assign const_conditional_wrapper_in_flat[24] = in_flat[128];
assign const_conditional_wrapper_in_flat[25] = in_flat[129];
assign const_conditional_wrapper_in_flat[26] = in_flat[130];
assign const_conditional_wrapper_in_flat[28] = in_flat[131];
assign const_conditional_wrapper_in_flat[29] = in_flat[132];
assign const_conditional_wrapper_in_flat[30] = in_flat[133];
assign const_conditional_wrapper_in_flat[31] = in_flat[134];
assign const_conditional_wrapper_in_flat[32] = in_flat[135];
assign const_conditional_wrapper_in_flat[33] = in_flat[136];
assign const_logic_wrapper_in_flat[0] = in_flat[137];
assign const_logic_wrapper_in_flat[2] = in_flat[138];
assign const_logic_wrapper_in_flat[4] = in_flat[139];
assign const_logic_wrapper_in_flat[6] = in_flat[140];
assign const_logic_wrapper_in_flat[7] = in_flat[141];
assign const_logic_wrapper_in_flat[9] = in_flat[142];
assign const_nested_wrapper_in_flat[0] = in_flat[143];
assign const_nested_wrapper_in_flat[1] = in_flat[144];
assign const_nested_wrapper_in_flat[2] = in_flat[145];
assign const_nested_wrapper_in_flat[3] = in_flat[146];
assign const_nested_wrapper_in_flat[5] = in_flat[147];
assign const_nested_wrapper_in_flat[6] = in_flat[148];
assign const_nested_wrapper_in_flat[7] = in_flat[149];
assign const_nested_wrapper_in_flat[8] = in_flat[150];
assign const_nested_wrapper_in_flat[9] = in_flat[151];
assign const_nested_wrapper_in_flat[10] = in_flat[152];
assign const_nested_wrapper_in_flat[11] = in_flat[153];
assign const_nested_wrapper_in_flat[12] = in_flat[154];
assign const_nested_wrapper_in_flat[13] = in_flat[155];
assign const_nested_wrapper_in_flat[15] = in_flat[156];
assign const_nested_wrapper_in_flat[16] = in_flat[157];
assign const_nested_wrapper_in_flat[17] = in_flat[158];
assign const_nested_wrapper_in_flat[18] = in_flat[159];
assign const_nested_wrapper_in_flat[20] = in_flat[160];
assign const_nested_wrapper_in_flat[21] = in_flat[161];
assign const_nested_wrapper_in_flat[23] = in_flat[162];
assign const_nested_wrapper_in_flat[24] = in_flat[163];
assign const_nested_wrapper_in_flat[25] = in_flat[164];
assign const_nested_wrapper_in_flat[26] = in_flat[165];
assign const_partselect_wrapper_in_flat[0] = in_flat[166];
assign const_partselect_wrapper_in_flat[1] = in_flat[167];
assign const_partselect_wrapper_in_flat[2] = in_flat[168];
assign const_partselect_wrapper_in_flat[3] = in_flat[169];
assign const_partselect_wrapper_in_flat[4] = in_flat[170];
assign const_partselect_wrapper_in_flat[6] = in_flat[171];
assign const_partselect_wrapper_in_flat[7] = in_flat[172];
assign const_partselect_wrapper_in_flat[8] = in_flat[173];
assign const_partselect_wrapper_in_flat[11] = in_flat[174];
assign const_partselect_wrapper_in_flat[12] = in_flat[175];
assign const_partselect_wrapper_in_flat[13] = in_flat[176];
assign const_partselect_wrapper_in_flat[14] = in_flat[177];
assign const_partselect_wrapper_in_flat[16] = in_flat[178];
assign const_partselect_wrapper_in_flat[17] = in_flat[179];
assign const_shift_wrapper_in_flat[0] = in_flat[180];
assign const_shift_wrapper_in_flat[1] = in_flat[181];
assign const_shift_wrapper_in_flat[2] = in_flat[182];
assign const_shift_wrapper_in_flat[3] = in_flat[183];
assign const_shift_wrapper_in_flat[4] = in_flat[184];
assign const_shift_wrapper_in_flat[7] = in_flat[185];
assign const_shift_wrapper_in_flat[9] = in_flat[186];
assign const_shift_wrapper_in_flat[10] = in_flat[187];
assign numbers_concat_repl_wrapper_in_flat[1] = in_flat[188];
assign numbers_concat_repl_wrapper_in_flat[2] = in_flat[189];
assign numbers_concat_repl_wrapper_in_flat[5] = in_flat[190];
assign partselect_wrapper_in_flat[1] = in_flat[191];
assign partselect_wrapper_in_flat[2] = in_flat[192];
assign partselect_wrapper_in_flat[3] = in_flat[193];
assign partselect_wrapper_in_flat[4] = in_flat[194];
assign partselect_wrapper_in_flat[5] = in_flat[195];
assign partselect_wrapper_in_flat[8] = in_flat[196];
assign partselect_wrapper_in_flat[9] = in_flat[197];
assign partselect_wrapper_in_flat[10] = in_flat[198];
assign partselect_wrapper_in_flat[11] = in_flat[199];
assign partselect_wrapper_in_flat[12] = in_flat[200];
assign partselect_wrapper_in_flat[13] = in_flat[201];
assign partselect_wrapper_in_flat[14] = in_flat[202];
assign partselect_wrapper_in_flat[15] = in_flat[203];
assign partselect_wrapper_in_flat[16] = in_flat[204];
assign partselect_wrapper_in_flat[17] = in_flat[205];
assign relational_wrapper_in_flat[0] = in_flat[206];
assign relational_wrapper_in_flat[2] = in_flat[207];
assign relational_wrapper_in_flat[3] = in_flat[208];
assign relational_wrapper_in_flat[4] = in_flat[209];
assign relational_wrapper_in_flat[6] = in_flat[210];
assign select_wrapper_in_flat[0] = in_flat[211];
assign select_wrapper_in_flat[1] = in_flat[212];
assign select_wrapper_in_flat[2] = in_flat[213];
assign select_wrapper_in_flat[3] = in_flat[214];
assign select_wrapper_in_flat[4] = in_flat[215];
assign select_wrapper_in_flat[5] = in_flat[216];
assign select_wrapper_in_flat[6] = in_flat[217];
assign select_wrapper_in_flat[7] = in_flat[218];
assign select_wrapper_in_flat[8] = in_flat[219];
assign select_wrapper_in_flat[10] = in_flat[220];
assign select_wrapper_in_flat[11] = in_flat[221];
assign select_wrapper_in_flat[13] = in_flat[222];
assign select_wrapper_in_flat[14] = in_flat[223];
assign select_wrapper_in_flat[15] = in_flat[224];
assign select_wrapper_in_flat[16] = in_flat[225];
assign select_wrapper_in_flat[17] = in_flat[226];
assign select_wrapper_in_flat[18] = in_flat[227];
assign select_wrapper_in_flat[19] = in_flat[228];
assign shift_wrapper_in_flat[0] = in_flat[229];
assign shift_wrapper_in_flat[1] = in_flat[230];
assign shift_wrapper_in_flat[2] = in_flat[231];
assign shift_wrapper_in_flat[4] = in_flat[232];
assign shift_wrapper_in_flat[5] = in_flat[233];
assign shift_wrapper_in_flat[6] = in_flat[234];
assign shift_wrapper_in_flat[7] = in_flat[235];
assign shift_wrapper_in_flat[10] = in_flat[236];
assign width_enum_wrapper_in_flat[2] = in_flat[237];
assign width_enum_wrapper_in_flat[3] = in_flat[238];
assign width_logic_wrapper_in_flat[1] = in_flat[239];
assign width_logic_wrapper_in_flat[3] = in_flat[240];
assign width_logic_wrapper_in_flat[4] = in_flat[241];
assign width_logic_wrapper_in_flat[7] = in_flat[242];
assign width_struct_wrapper_in_flat[1] = in_flat[243];
assign width_struct_wrapper_in_flat[2] = in_flat[244];
assign width_struct_wrapper_in_flat[5] = in_flat[245];
assign width_struct_wrapper_in_flat[7] = in_flat[246];
assign width_struct_wrapper_in_flat[8] = in_flat[247];
assign width_union_wrapper_in_flat[0] = in_flat[248];
assign width_union_wrapper_in_flat[1] = in_flat[249];
assign width_union_wrapper_in_flat[2] = in_flat[250];
assign width_union_wrapper_in_flat[3] = in_flat[251];
assign width_union_wrapper_in_flat[4] = in_flat[252];
assign width_union_wrapper_in_flat[5] = in_flat[253];
assign width_union_wrapper_in_flat[6] = in_flat[254];
assign width_union_wrapper_in_flat[8] = in_flat[255];
assign width_union_wrapper_in_flat[9] = in_flat[256];
assign width_union_wrapper_in_flat[10] = in_flat[257];
assign width_union_wrapper_in_flat[12] = in_flat[258];
assign width_union_wrapper_in_flat[13] = in_flat[259];
assign width_union_wrapper_in_flat[14] = in_flat[260];

// Internal MTM connections (module-to-module)
assign width_union_wrapper_in_flat[11] = arithmetic_reduce_wrapper_out_flat[5];
assign conditional_wrapper_in_flat[1] = arithmetic_reduce_wrapper_out_flat[7];
assign array_wrapper_in_flat[4] = arithmetic_reduce_wrapper_out_flat[9];
assign bitwise_reduce_wrapper_in_flat[1] = arithmetic_reduce_wrapper_out_flat[9];
assign select_wrapper_in_flat[9] = array_wrapper_out_flat[7];
assign const_shift_wrapper_in_flat[5] = array_wrapper_out_flat[12];
assign width_enum_wrapper_in_flat[0] = array_wrapper_out_flat[12];
assign width_logic_wrapper_in_flat[0] = array_wrapper_out_flat[15];
assign const_partselect_wrapper_in_flat[5] = array_wrapper_out_flat[15];
assign const_arith_wrapper_in_flat[2] = bitwise_logic_wrapper_out_flat[4];
assign numbers_concat_repl_wrapper_in_flat[0] = bitwise_logic_wrapper_out_flat[13];
assign arithmetic_reduce_wrapper_in_flat[11] = bitwise_logic_wrapper_out_flat[13];
assign const_nested_wrapper_in_flat[19] = bitwise_logic_wrapper_out_flat[15];
assign const_compare_wrapper_in_flat[23] = bitwise_logic_wrapper_out_flat[19];
assign const_conditional_wrapper_in_flat[27] = bitwise_logic_wrapper_out_flat[21];
assign const_partselect_wrapper_in_flat[19] = bitwise_reduce_wrapper_out_flat[0];
assign const_nested_wrapper_in_flat[4] = cast_wrapper_out_flat[3];
assign const_partselect_wrapper_in_flat[18] = cast_wrapper_out_flat[9];
assign const_arith_wrapper_in_flat[10] = cast_wrapper_out_flat[9];
assign const_concat_repl_wrapper_in_flat[2] = cast_wrapper_out_flat[9];
assign const_conditional_wrapper_in_flat[12] = cast_wrapper_out_flat[10];
assign const_shift_wrapper_in_flat[8] = conditional_wrapper_out_flat[1];
assign conditional_wrapper_in_flat[8] = const_arith_wrapper_out_flat[1];
assign bitwise_reduce_wrapper_in_flat[0] = const_arith_wrapper_out_flat[5];
assign const_compare_wrapper_in_flat[18] = const_arith_wrapper_out_flat[17];
assign const_nested_wrapper_in_flat[22] = const_arith_wrapper_out_flat[26];
assign const_partselect_wrapper_in_flat[9] = const_arith_wrapper_out_flat[28];
assign const_conditional_wrapper_in_flat[20] = const_arith_wrapper_out_flat[33];
assign arithmetic_reduce_wrapper_in_flat[13] = const_arith_wrapper_out_flat[37];
assign conditional_wrapper_in_flat[7] = const_compare_wrapper_out_flat[3];
assign width_union_wrapper_in_flat[15] = const_compare_wrapper_out_flat[4];
assign array_wrapper_in_flat[10] = const_compare_wrapper_out_flat[5];
assign const_arith_wrapper_in_flat[12] = const_concat_repl_wrapper_out_flat[19];
assign bitwise_logic_wrapper_in_flat[3] = const_concat_repl_wrapper_out_flat[19];
assign const_conditional_wrapper_in_flat[1] = const_concat_repl_wrapper_out_flat[21];
assign conditional_wrapper_in_flat[2] = const_conditional_wrapper_out_flat[3];
assign width_logic_wrapper_in_flat[5] = const_conditional_wrapper_out_flat[8];
assign const_partselect_wrapper_in_flat[15] = const_conditional_wrapper_out_flat[8];
assign arithmetic_reduce_wrapper_in_flat[9] = const_conditional_wrapper_out_flat[8];
assign const_nested_wrapper_in_flat[14] = const_conditional_wrapper_out_flat[13];
assign bitwise_reduce_wrapper_in_flat[5] = const_conditional_wrapper_out_flat[18];
assign const_compare_wrapper_in_flat[19] = const_conditional_wrapper_out_flat[20];
assign partselect_wrapper_in_flat[6] = const_logic_wrapper_out_flat[9];
assign const_reduce_wrapper_in_flat[1] = const_logic_wrapper_out_flat[13];
assign width_struct_wrapper_in_flat[9] = const_logic_wrapper_out_flat[13];
assign relational_wrapper_in_flat[5] = const_logic_wrapper_out_flat[16];
assign array_wrapper_in_flat[17] = const_nested_wrapper_out_flat[2];
assign partselect_wrapper_in_flat[7] = const_nested_wrapper_out_flat[3];
assign width_union_wrapper_in_flat[7] = const_nested_wrapper_out_flat[5];
assign const_partselect_wrapper_in_flat[10] = const_nested_wrapper_out_flat[7];
assign const_logic_wrapper_in_flat[1] = const_partselect_wrapper_out_flat[0];
assign width_struct_wrapper_in_flat[10] = const_reduce_wrapper_out_flat[3];
assign shift_wrapper_in_flat[3] = const_shift_wrapper_out_flat[9];
assign const_logic_wrapper_in_flat[8] = const_shift_wrapper_out_flat[12];
assign width_enum_wrapper_in_flat[1] = const_shift_wrapper_out_flat[12];
assign partselect_wrapper_in_flat[18] = const_shift_wrapper_out_flat[16];
assign const_reduce_wrapper_in_flat[0] = logical_op_wrapper_out_flat[0];
assign shift_wrapper_in_flat[8] = numbers_concat_repl_wrapper_out_flat[0];
assign const_shift_wrapper_in_flat[6] = numbers_concat_repl_wrapper_out_flat[2];
assign partselect_wrapper_in_flat[0] = numbers_concat_repl_wrapper_out_flat[9];
assign width_struct_wrapper_in_flat[4] = numbers_concat_repl_wrapper_out_flat[16];
assign const_logic_wrapper_in_flat[3] = numbers_concat_repl_wrapper_out_flat[17];
assign width_struct_wrapper_in_flat[3] = partselect_wrapper_out_flat[1];
assign const_reduce_wrapper_in_flat[3] = partselect_wrapper_out_flat[6];
assign logical_op_wrapper_in_flat[0] = partselect_wrapper_out_flat[6];
assign relational_wrapper_in_flat[7] = partselect_wrapper_out_flat[7];
assign width_struct_wrapper_in_flat[11] = relational_wrapper_out_flat[3];
assign width_struct_wrapper_in_flat[0] = select_wrapper_out_flat[1];
assign numbers_concat_repl_wrapper_in_flat[3] = select_wrapper_out_flat[5];
assign shift_wrapper_in_flat[9] = select_wrapper_out_flat[5];
assign width_logic_wrapper_in_flat[6] = select_wrapper_out_flat[8];
assign relational_wrapper_in_flat[1] = shift_wrapper_out_flat[0];
assign const_reduce_wrapper_in_flat[2] = shift_wrapper_out_flat[5];
assign width_struct_wrapper_in_flat[6] = shift_wrapper_out_flat[6];
assign logical_op_wrapper_in_flat[1] = shift_wrapper_out_flat[13];
assign const_logic_wrapper_in_flat[5] = width_enum_wrapper_out_flat[1];
assign numbers_concat_repl_wrapper_in_flat[4] = width_logic_wrapper_out_flat[4];
assign select_wrapper_in_flat[12] = width_union_wrapper_out_flat[1];
assign array_wrapper_in_flat[5] = width_union_wrapper_out_flat[4];
assign width_logic_wrapper_in_flat[2] = width_union_wrapper_out_flat[15];

// External outputs (MTO + MTM wires)
assign out_flat[0] = arithmetic_reduce_wrapper_out_flat[0];
assign out_flat[1] = arithmetic_reduce_wrapper_out_flat[1];
assign out_flat[2] = arithmetic_reduce_wrapper_out_flat[2];
assign out_flat[3] = arithmetic_reduce_wrapper_out_flat[3];
assign out_flat[4] = arithmetic_reduce_wrapper_out_flat[4];
assign out_flat[5] = arithmetic_reduce_wrapper_out_flat[5];
assign out_flat[6] = arithmetic_reduce_wrapper_out_flat[6];
assign out_flat[7] = arithmetic_reduce_wrapper_out_flat[7];
assign out_flat[8] = arithmetic_reduce_wrapper_out_flat[8];
assign out_flat[9] = arithmetic_reduce_wrapper_out_flat[9];
assign out_flat[10] = array_wrapper_out_flat[0];
assign out_flat[11] = array_wrapper_out_flat[1];
assign out_flat[12] = array_wrapper_out_flat[2];
assign out_flat[13] = array_wrapper_out_flat[3];
assign out_flat[14] = array_wrapper_out_flat[4];
assign out_flat[15] = array_wrapper_out_flat[5];
assign out_flat[16] = array_wrapper_out_flat[6];
assign out_flat[17] = array_wrapper_out_flat[7];
assign out_flat[18] = array_wrapper_out_flat[8];
assign out_flat[19] = array_wrapper_out_flat[9];
assign out_flat[20] = array_wrapper_out_flat[10];
assign out_flat[21] = array_wrapper_out_flat[11];
assign out_flat[22] = array_wrapper_out_flat[12];
assign out_flat[23] = array_wrapper_out_flat[13];
assign out_flat[24] = array_wrapper_out_flat[14];
assign out_flat[25] = array_wrapper_out_flat[15];
assign out_flat[26] = bitwise_logic_wrapper_out_flat[0];
assign out_flat[27] = bitwise_logic_wrapper_out_flat[1];
assign out_flat[28] = bitwise_logic_wrapper_out_flat[2];
assign out_flat[29] = bitwise_logic_wrapper_out_flat[3];
assign out_flat[30] = bitwise_logic_wrapper_out_flat[4];
assign out_flat[31] = bitwise_logic_wrapper_out_flat[5];
assign out_flat[32] = bitwise_logic_wrapper_out_flat[6];
assign out_flat[33] = bitwise_logic_wrapper_out_flat[7];
assign out_flat[34] = bitwise_logic_wrapper_out_flat[8];
assign out_flat[35] = bitwise_logic_wrapper_out_flat[9];
assign out_flat[36] = bitwise_logic_wrapper_out_flat[10];
assign out_flat[37] = bitwise_logic_wrapper_out_flat[11];
assign out_flat[38] = bitwise_logic_wrapper_out_flat[12];
assign out_flat[39] = bitwise_logic_wrapper_out_flat[13];
assign out_flat[40] = bitwise_logic_wrapper_out_flat[14];
assign out_flat[41] = bitwise_logic_wrapper_out_flat[15];
assign out_flat[42] = bitwise_logic_wrapper_out_flat[16];
assign out_flat[43] = bitwise_logic_wrapper_out_flat[17];
assign out_flat[44] = bitwise_logic_wrapper_out_flat[18];
assign out_flat[45] = bitwise_logic_wrapper_out_flat[19];
assign out_flat[46] = bitwise_logic_wrapper_out_flat[20];
assign out_flat[47] = bitwise_logic_wrapper_out_flat[21];
assign out_flat[48] = bitwise_logic_wrapper_out_flat[22];
assign out_flat[49] = bitwise_logic_wrapper_out_flat[23];
assign out_flat[50] = bitwise_reduce_wrapper_out_flat[0];
assign out_flat[51] = bitwise_reduce_wrapper_out_flat[1];
assign out_flat[52] = bitwise_reduce_wrapper_out_flat[2];
assign out_flat[53] = cast_wrapper_out_flat[0];
assign out_flat[54] = cast_wrapper_out_flat[1];
assign out_flat[55] = cast_wrapper_out_flat[2];
assign out_flat[56] = cast_wrapper_out_flat[3];
assign out_flat[57] = cast_wrapper_out_flat[4];
assign out_flat[58] = cast_wrapper_out_flat[5];
assign out_flat[59] = cast_wrapper_out_flat[6];
assign out_flat[60] = cast_wrapper_out_flat[7];
assign out_flat[61] = cast_wrapper_out_flat[8];
assign out_flat[62] = cast_wrapper_out_flat[9];
assign out_flat[63] = cast_wrapper_out_flat[10];
assign out_flat[64] = cast_wrapper_out_flat[11];
assign out_flat[65] = conditional_wrapper_out_flat[0];
assign out_flat[66] = conditional_wrapper_out_flat[1];
assign out_flat[67] = conditional_wrapper_out_flat[2];
assign out_flat[68] = conditional_wrapper_out_flat[3];
assign out_flat[69] = const_arith_wrapper_out_flat[0];
assign out_flat[70] = const_arith_wrapper_out_flat[1];
assign out_flat[71] = const_arith_wrapper_out_flat[2];
assign out_flat[72] = const_arith_wrapper_out_flat[3];
assign out_flat[73] = const_arith_wrapper_out_flat[4];
assign out_flat[74] = const_arith_wrapper_out_flat[5];
assign out_flat[75] = const_arith_wrapper_out_flat[6];
assign out_flat[76] = const_arith_wrapper_out_flat[7];
assign out_flat[77] = const_arith_wrapper_out_flat[8];
assign out_flat[78] = const_arith_wrapper_out_flat[9];
assign out_flat[79] = const_arith_wrapper_out_flat[10];
assign out_flat[80] = const_arith_wrapper_out_flat[11];
assign out_flat[81] = const_arith_wrapper_out_flat[12];
assign out_flat[82] = const_arith_wrapper_out_flat[13];
assign out_flat[83] = const_arith_wrapper_out_flat[14];
assign out_flat[84] = const_arith_wrapper_out_flat[15];
assign out_flat[85] = const_arith_wrapper_out_flat[16];
assign out_flat[86] = const_arith_wrapper_out_flat[17];
assign out_flat[87] = const_arith_wrapper_out_flat[18];
assign out_flat[88] = const_arith_wrapper_out_flat[19];
assign out_flat[89] = const_arith_wrapper_out_flat[20];
assign out_flat[90] = const_arith_wrapper_out_flat[21];
assign out_flat[91] = const_arith_wrapper_out_flat[22];
assign out_flat[92] = const_arith_wrapper_out_flat[23];
assign out_flat[93] = const_arith_wrapper_out_flat[24];
assign out_flat[94] = const_arith_wrapper_out_flat[25];
assign out_flat[95] = const_arith_wrapper_out_flat[26];
assign out_flat[96] = const_arith_wrapper_out_flat[27];
assign out_flat[97] = const_arith_wrapper_out_flat[28];
assign out_flat[98] = const_arith_wrapper_out_flat[29];
assign out_flat[99] = const_arith_wrapper_out_flat[30];
assign out_flat[100] = const_arith_wrapper_out_flat[31];
assign out_flat[101] = const_arith_wrapper_out_flat[32];
assign out_flat[102] = const_arith_wrapper_out_flat[33];
assign out_flat[103] = const_arith_wrapper_out_flat[34];
assign out_flat[104] = const_arith_wrapper_out_flat[35];
assign out_flat[105] = const_arith_wrapper_out_flat[36];
assign out_flat[106] = const_arith_wrapper_out_flat[37];
assign out_flat[107] = const_arith_wrapper_out_flat[38];
assign out_flat[108] = const_arith_wrapper_out_flat[39];
assign out_flat[109] = const_compare_wrapper_out_flat[0];
assign out_flat[110] = const_compare_wrapper_out_flat[1];
assign out_flat[111] = const_compare_wrapper_out_flat[2];
assign out_flat[112] = const_compare_wrapper_out_flat[3];
assign out_flat[113] = const_compare_wrapper_out_flat[4];
assign out_flat[114] = const_compare_wrapper_out_flat[5];
assign out_flat[115] = const_compare_wrapper_out_flat[6];
assign out_flat[116] = const_compare_wrapper_out_flat[7];
assign out_flat[117] = const_concat_repl_wrapper_out_flat[0];
assign out_flat[118] = const_concat_repl_wrapper_out_flat[1];
assign out_flat[119] = const_concat_repl_wrapper_out_flat[2];
assign out_flat[120] = const_concat_repl_wrapper_out_flat[3];
assign out_flat[121] = const_concat_repl_wrapper_out_flat[4];
assign out_flat[122] = const_concat_repl_wrapper_out_flat[5];
assign out_flat[123] = const_concat_repl_wrapper_out_flat[6];
assign out_flat[124] = const_concat_repl_wrapper_out_flat[7];
assign out_flat[125] = const_concat_repl_wrapper_out_flat[8];
assign out_flat[126] = const_concat_repl_wrapper_out_flat[9];
assign out_flat[127] = const_concat_repl_wrapper_out_flat[10];
assign out_flat[128] = const_concat_repl_wrapper_out_flat[11];
assign out_flat[129] = const_concat_repl_wrapper_out_flat[12];
assign out_flat[130] = const_concat_repl_wrapper_out_flat[13];
assign out_flat[131] = const_concat_repl_wrapper_out_flat[14];
assign out_flat[132] = const_concat_repl_wrapper_out_flat[15];
assign out_flat[133] = const_concat_repl_wrapper_out_flat[16];
assign out_flat[134] = const_concat_repl_wrapper_out_flat[17];
assign out_flat[135] = const_concat_repl_wrapper_out_flat[18];
assign out_flat[136] = const_concat_repl_wrapper_out_flat[19];
assign out_flat[137] = const_concat_repl_wrapper_out_flat[20];
assign out_flat[138] = const_concat_repl_wrapper_out_flat[21];
assign out_flat[139] = const_conditional_wrapper_out_flat[0];
assign out_flat[140] = const_conditional_wrapper_out_flat[1];
assign out_flat[141] = const_conditional_wrapper_out_flat[2];
assign out_flat[142] = const_conditional_wrapper_out_flat[3];
assign out_flat[143] = const_conditional_wrapper_out_flat[4];
assign out_flat[144] = const_conditional_wrapper_out_flat[5];
assign out_flat[145] = const_conditional_wrapper_out_flat[6];
assign out_flat[146] = const_conditional_wrapper_out_flat[7];
assign out_flat[147] = const_conditional_wrapper_out_flat[8];
assign out_flat[148] = const_conditional_wrapper_out_flat[9];
assign out_flat[149] = const_conditional_wrapper_out_flat[10];
assign out_flat[150] = const_conditional_wrapper_out_flat[11];
assign out_flat[151] = const_conditional_wrapper_out_flat[12];
assign out_flat[152] = const_conditional_wrapper_out_flat[13];
assign out_flat[153] = const_conditional_wrapper_out_flat[14];
assign out_flat[154] = const_conditional_wrapper_out_flat[15];
assign out_flat[155] = const_conditional_wrapper_out_flat[16];
assign out_flat[156] = const_conditional_wrapper_out_flat[17];
assign out_flat[157] = const_conditional_wrapper_out_flat[18];
assign out_flat[158] = const_conditional_wrapper_out_flat[19];
assign out_flat[159] = const_conditional_wrapper_out_flat[20];
assign out_flat[160] = const_conditional_wrapper_out_flat[21];
assign out_flat[161] = const_conditional_wrapper_out_flat[22];
assign out_flat[162] = const_conditional_wrapper_out_flat[23];
assign out_flat[163] = const_logic_wrapper_out_flat[0];
assign out_flat[164] = const_logic_wrapper_out_flat[1];
assign out_flat[165] = const_logic_wrapper_out_flat[2];
assign out_flat[166] = const_logic_wrapper_out_flat[3];
assign out_flat[167] = const_logic_wrapper_out_flat[4];
assign out_flat[168] = const_logic_wrapper_out_flat[5];
assign out_flat[169] = const_logic_wrapper_out_flat[6];
assign out_flat[170] = const_logic_wrapper_out_flat[7];
assign out_flat[171] = const_logic_wrapper_out_flat[8];
assign out_flat[172] = const_logic_wrapper_out_flat[9];
assign out_flat[173] = const_logic_wrapper_out_flat[10];
assign out_flat[174] = const_logic_wrapper_out_flat[11];
assign out_flat[175] = const_logic_wrapper_out_flat[12];
assign out_flat[176] = const_logic_wrapper_out_flat[13];
assign out_flat[177] = const_logic_wrapper_out_flat[14];
assign out_flat[178] = const_logic_wrapper_out_flat[15];
assign out_flat[179] = const_logic_wrapper_out_flat[16];
assign out_flat[180] = const_logic_wrapper_out_flat[17];
assign out_flat[181] = const_logic_wrapper_out_flat[18];
assign out_flat[182] = const_nested_wrapper_out_flat[0];
assign out_flat[183] = const_nested_wrapper_out_flat[1];
assign out_flat[184] = const_nested_wrapper_out_flat[2];
assign out_flat[185] = const_nested_wrapper_out_flat[3];
assign out_flat[186] = const_nested_wrapper_out_flat[4];
assign out_flat[187] = const_nested_wrapper_out_flat[5];
assign out_flat[188] = const_nested_wrapper_out_flat[6];
assign out_flat[189] = const_nested_wrapper_out_flat[7];
assign out_flat[190] = const_partselect_wrapper_out_flat[0];
assign out_flat[191] = const_partselect_wrapper_out_flat[1];
assign out_flat[192] = const_partselect_wrapper_out_flat[2];
assign out_flat[193] = const_partselect_wrapper_out_flat[3];
assign out_flat[194] = const_partselect_wrapper_out_flat[4];
assign out_flat[195] = const_partselect_wrapper_out_flat[5];
assign out_flat[196] = const_partselect_wrapper_out_flat[6];
assign out_flat[197] = const_partselect_wrapper_out_flat[7];
assign out_flat[198] = const_reduce_wrapper_out_flat[0];
assign out_flat[199] = const_reduce_wrapper_out_flat[1];
assign out_flat[200] = const_reduce_wrapper_out_flat[2];
assign out_flat[201] = const_reduce_wrapper_out_flat[3];
assign out_flat[202] = const_reduce_wrapper_out_flat[4];
assign out_flat[203] = const_reduce_wrapper_out_flat[5];
assign out_flat[204] = const_shift_wrapper_out_flat[0];
assign out_flat[205] = const_shift_wrapper_out_flat[1];
assign out_flat[206] = const_shift_wrapper_out_flat[2];
assign out_flat[207] = const_shift_wrapper_out_flat[3];
assign out_flat[208] = const_shift_wrapper_out_flat[4];
assign out_flat[209] = const_shift_wrapper_out_flat[5];
assign out_flat[210] = const_shift_wrapper_out_flat[6];
assign out_flat[211] = const_shift_wrapper_out_flat[7];
assign out_flat[212] = const_shift_wrapper_out_flat[8];
assign out_flat[213] = const_shift_wrapper_out_flat[9];
assign out_flat[214] = const_shift_wrapper_out_flat[10];
assign out_flat[215] = const_shift_wrapper_out_flat[11];
assign out_flat[216] = const_shift_wrapper_out_flat[12];
assign out_flat[217] = const_shift_wrapper_out_flat[13];
assign out_flat[218] = const_shift_wrapper_out_flat[14];
assign out_flat[219] = const_shift_wrapper_out_flat[15];
assign out_flat[220] = const_shift_wrapper_out_flat[16];
assign out_flat[221] = const_shift_wrapper_out_flat[17];
assign out_flat[222] = const_shift_wrapper_out_flat[18];
assign out_flat[223] = const_shift_wrapper_out_flat[19];
assign out_flat[224] = const_shift_wrapper_out_flat[20];
assign out_flat[225] = const_shift_wrapper_out_flat[21];
assign out_flat[226] = const_shift_wrapper_out_flat[22];
assign out_flat[227] = const_shift_wrapper_out_flat[23];
assign out_flat[228] = logical_op_wrapper_out_flat[0];
assign out_flat[229] = logical_op_wrapper_out_flat[1];
assign out_flat[230] = logical_op_wrapper_out_flat[2];
assign out_flat[231] = numbers_concat_repl_wrapper_out_flat[0];
assign out_flat[232] = numbers_concat_repl_wrapper_out_flat[1];
assign out_flat[233] = numbers_concat_repl_wrapper_out_flat[2];
assign out_flat[234] = numbers_concat_repl_wrapper_out_flat[3];
assign out_flat[235] = numbers_concat_repl_wrapper_out_flat[4];
assign out_flat[236] = numbers_concat_repl_wrapper_out_flat[5];
assign out_flat[237] = numbers_concat_repl_wrapper_out_flat[6];
assign out_flat[238] = numbers_concat_repl_wrapper_out_flat[7];
assign out_flat[239] = numbers_concat_repl_wrapper_out_flat[8];
assign out_flat[240] = numbers_concat_repl_wrapper_out_flat[9];
assign out_flat[241] = numbers_concat_repl_wrapper_out_flat[10];
assign out_flat[242] = numbers_concat_repl_wrapper_out_flat[11];
assign out_flat[243] = numbers_concat_repl_wrapper_out_flat[12];
assign out_flat[244] = numbers_concat_repl_wrapper_out_flat[13];
assign out_flat[245] = numbers_concat_repl_wrapper_out_flat[14];
assign out_flat[246] = numbers_concat_repl_wrapper_out_flat[15];
assign out_flat[247] = numbers_concat_repl_wrapper_out_flat[16];
assign out_flat[248] = numbers_concat_repl_wrapper_out_flat[17];
assign out_flat[249] = partselect_wrapper_out_flat[0];
assign out_flat[250] = partselect_wrapper_out_flat[1];
assign out_flat[251] = partselect_wrapper_out_flat[2];
assign out_flat[252] = partselect_wrapper_out_flat[3];
assign out_flat[253] = partselect_wrapper_out_flat[4];
assign out_flat[254] = partselect_wrapper_out_flat[5];
assign out_flat[255] = partselect_wrapper_out_flat[6];
assign out_flat[256] = partselect_wrapper_out_flat[7];
assign out_flat[257] = partselect_wrapper_out_flat[8];
assign out_flat[258] = relational_wrapper_out_flat[0];
assign out_flat[259] = relational_wrapper_out_flat[1];
assign out_flat[260] = relational_wrapper_out_flat[2];
assign out_flat[261] = relational_wrapper_out_flat[3];
assign out_flat[262] = relational_wrapper_out_flat[4];
assign out_flat[263] = relational_wrapper_out_flat[5];
assign out_flat[264] = relational_wrapper_out_flat[6];
assign out_flat[265] = relational_wrapper_out_flat[7];
assign out_flat[266] = select_wrapper_out_flat[0];
assign out_flat[267] = select_wrapper_out_flat[1];
assign out_flat[268] = select_wrapper_out_flat[2];
assign out_flat[269] = select_wrapper_out_flat[3];
assign out_flat[270] = select_wrapper_out_flat[4];
assign out_flat[271] = select_wrapper_out_flat[5];
assign out_flat[272] = select_wrapper_out_flat[6];
assign out_flat[273] = select_wrapper_out_flat[7];
assign out_flat[274] = select_wrapper_out_flat[8];
assign out_flat[275] = shift_wrapper_out_flat[0];
assign out_flat[276] = shift_wrapper_out_flat[1];
assign out_flat[277] = shift_wrapper_out_flat[2];
assign out_flat[278] = shift_wrapper_out_flat[3];
assign out_flat[279] = shift_wrapper_out_flat[4];
assign out_flat[280] = shift_wrapper_out_flat[5];
assign out_flat[281] = shift_wrapper_out_flat[6];
assign out_flat[282] = shift_wrapper_out_flat[7];
assign out_flat[283] = shift_wrapper_out_flat[8];
assign out_flat[284] = shift_wrapper_out_flat[9];
assign out_flat[285] = shift_wrapper_out_flat[10];
assign out_flat[286] = shift_wrapper_out_flat[11];
assign out_flat[287] = shift_wrapper_out_flat[12];
assign out_flat[288] = shift_wrapper_out_flat[13];
assign out_flat[289] = shift_wrapper_out_flat[14];
assign out_flat[290] = shift_wrapper_out_flat[15];
assign out_flat[291] = width_enum_wrapper_out_flat[0];
assign out_flat[292] = width_enum_wrapper_out_flat[1];
assign out_flat[293] = width_enum_wrapper_out_flat[2];
assign out_flat[294] = width_enum_wrapper_out_flat[3];
assign out_flat[295] = width_enum_wrapper_out_flat[4];
assign out_flat[296] = width_logic_wrapper_out_flat[0];
assign out_flat[297] = width_logic_wrapper_out_flat[1];
assign out_flat[298] = width_logic_wrapper_out_flat[2];
assign out_flat[299] = width_logic_wrapper_out_flat[3];
assign out_flat[300] = width_logic_wrapper_out_flat[4];
assign out_flat[301] = width_logic_wrapper_out_flat[5];
assign out_flat[302] = width_struct_wrapper_out_flat[0];
assign out_flat[303] = width_struct_wrapper_out_flat[1];
assign out_flat[304] = width_struct_wrapper_out_flat[2];
assign out_flat[305] = width_struct_wrapper_out_flat[3];
assign out_flat[306] = width_struct_wrapper_out_flat[4];
assign out_flat[307] = width_struct_wrapper_out_flat[5];
assign out_flat[308] = width_struct_wrapper_out_flat[6];
assign out_flat[309] = width_struct_wrapper_out_flat[7];
assign out_flat[310] = width_struct_wrapper_out_flat[8];
assign out_flat[311] = width_struct_wrapper_out_flat[9];
assign out_flat[312] = width_struct_wrapper_out_flat[10];
assign out_flat[313] = width_struct_wrapper_out_flat[11];
assign out_flat[314] = width_union_wrapper_out_flat[0];
assign out_flat[315] = width_union_wrapper_out_flat[1];
assign out_flat[316] = width_union_wrapper_out_flat[2];
assign out_flat[317] = width_union_wrapper_out_flat[3];
assign out_flat[318] = width_union_wrapper_out_flat[4];
assign out_flat[319] = width_union_wrapper_out_flat[5];
assign out_flat[320] = width_union_wrapper_out_flat[6];
assign out_flat[321] = width_union_wrapper_out_flat[7];
assign out_flat[322] = width_union_wrapper_out_flat[8];
assign out_flat[323] = width_union_wrapper_out_flat[9];
assign out_flat[324] = width_union_wrapper_out_flat[10];
assign out_flat[325] = width_union_wrapper_out_flat[11];
assign out_flat[326] = width_union_wrapper_out_flat[12];
assign out_flat[327] = width_union_wrapper_out_flat[13];
assign out_flat[328] = width_union_wrapper_out_flat[14];
assign out_flat[329] = width_union_wrapper_out_flat[15];

// Instantiate all module wrappers
arithmetic_reduce_wrapper u_arithmetic_reduce_wrapper (
    .in_flat(arithmetic_reduce_wrapper_in_flat),
    .out_flat(arithmetic_reduce_wrapper_out_flat)
);
array_wrapper u_array_wrapper (
    .in_flat(array_wrapper_in_flat),
    .out_flat(array_wrapper_out_flat)
);
bitwise_logic_wrapper u_bitwise_logic_wrapper (
    .in_flat(bitwise_logic_wrapper_in_flat),
    .out_flat(bitwise_logic_wrapper_out_flat)
);
bitwise_reduce_wrapper u_bitwise_reduce_wrapper (
    .in_flat(bitwise_reduce_wrapper_in_flat),
    .out_flat(bitwise_reduce_wrapper_out_flat)
);
cast_wrapper u_cast_wrapper (
    .in_flat(cast_wrapper_in_flat),
    .out_flat(cast_wrapper_out_flat)
);
conditional_wrapper u_conditional_wrapper (
    .in_flat(conditional_wrapper_in_flat),
    .out_flat(conditional_wrapper_out_flat)
);
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
logical_op_wrapper u_logical_op_wrapper (
    .in_flat(logical_op_wrapper_in_flat),
    .out_flat(logical_op_wrapper_out_flat)
);
numbers_concat_repl_wrapper u_numbers_concat_repl_wrapper (
    .in_flat(numbers_concat_repl_wrapper_in_flat),
    .out_flat(numbers_concat_repl_wrapper_out_flat)
);
partselect_wrapper u_partselect_wrapper (
    .in_flat(partselect_wrapper_in_flat),
    .out_flat(partselect_wrapper_out_flat)
);
relational_wrapper u_relational_wrapper (
    .in_flat(relational_wrapper_in_flat),
    .out_flat(relational_wrapper_out_flat)
);
select_wrapper u_select_wrapper (
    .in_flat(select_wrapper_in_flat),
    .out_flat(select_wrapper_out_flat)
);
shift_wrapper u_shift_wrapper (
    .in_flat(shift_wrapper_in_flat),
    .out_flat(shift_wrapper_out_flat)
);
width_enum_wrapper u_width_enum_wrapper (
    .in_flat(width_enum_wrapper_in_flat),
    .out_flat(width_enum_wrapper_out_flat)
);
width_logic_wrapper u_width_logic_wrapper (
    .in_flat(width_logic_wrapper_in_flat),
    .out_flat(width_logic_wrapper_out_flat)
);
width_struct_wrapper u_width_struct_wrapper (
    .in_flat(width_struct_wrapper_in_flat),
    .out_flat(width_struct_wrapper_out_flat)
);
width_union_wrapper u_width_union_wrapper (
    .in_flat(width_union_wrapper_in_flat),
    .out_flat(width_union_wrapper_out_flat)
);
endmodule