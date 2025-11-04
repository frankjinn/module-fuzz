// Auto-generated Top Module for flattened IO

module top (
    input  wire clk,
    input  wire rst_n,
    input  wire [263:0] in_flat,
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
assign const_arith_wrapper_in_flat[0] = in_flat[0];
assign const_arith_wrapper_in_flat[2] = in_flat[1];
assign const_arith_wrapper_in_flat[5] = in_flat[2];
assign const_arith_wrapper_in_flat[6] = in_flat[3];
assign const_arith_wrapper_in_flat[7] = in_flat[4];
assign const_arith_wrapper_in_flat[8] = in_flat[5];
assign const_arith_wrapper_in_flat[9] = in_flat[6];
assign const_arith_wrapper_in_flat[10] = in_flat[7];
assign const_arith_wrapper_in_flat[11] = in_flat[8];
assign const_arith_wrapper_in_flat[13] = in_flat[9];
assign const_arith_wrapper_in_flat[14] = in_flat[10];
assign const_arith_wrapper_in_flat[15] = in_flat[11];
assign const_compare_wrapper_in_flat[0] = in_flat[12];
assign const_compare_wrapper_in_flat[1] = in_flat[13];
assign const_compare_wrapper_in_flat[2] = in_flat[14];
assign const_compare_wrapper_in_flat[3] = in_flat[15];
assign const_compare_wrapper_in_flat[4] = in_flat[16];
assign const_compare_wrapper_in_flat[5] = in_flat[17];
assign const_compare_wrapper_in_flat[6] = in_flat[18];
assign const_compare_wrapper_in_flat[7] = in_flat[19];
assign const_compare_wrapper_in_flat[8] = in_flat[20];
assign const_compare_wrapper_in_flat[9] = in_flat[21];
assign const_compare_wrapper_in_flat[10] = in_flat[22];
assign const_compare_wrapper_in_flat[11] = in_flat[23];
assign const_compare_wrapper_in_flat[12] = in_flat[24];
assign const_compare_wrapper_in_flat[13] = in_flat[25];
assign const_compare_wrapper_in_flat[15] = in_flat[26];
assign const_compare_wrapper_in_flat[16] = in_flat[27];
assign const_compare_wrapper_in_flat[17] = in_flat[28];
assign const_compare_wrapper_in_flat[18] = in_flat[29];
assign const_compare_wrapper_in_flat[19] = in_flat[30];
assign const_compare_wrapper_in_flat[20] = in_flat[31];
assign const_compare_wrapper_in_flat[21] = in_flat[32];
assign const_compare_wrapper_in_flat[22] = in_flat[33];
assign const_compare_wrapper_in_flat[23] = in_flat[34];
assign const_concat_repl_wrapper_in_flat[0] = in_flat[35];
assign const_concat_repl_wrapper_in_flat[1] = in_flat[36];
assign const_concat_repl_wrapper_in_flat[3] = in_flat[37];
assign const_concat_repl_wrapper_in_flat[4] = in_flat[38];
assign const_concat_repl_wrapper_in_flat[6] = in_flat[39];
assign const_concat_repl_wrapper_in_flat[7] = in_flat[40];
assign const_concat_repl_wrapper_in_flat[8] = in_flat[41];
assign const_concat_repl_wrapper_in_flat[9] = in_flat[42];
assign const_conditional_wrapper_in_flat[0] = in_flat[43];
assign const_conditional_wrapper_in_flat[3] = in_flat[44];
assign const_conditional_wrapper_in_flat[5] = in_flat[45];
assign const_conditional_wrapper_in_flat[6] = in_flat[46];
assign const_conditional_wrapper_in_flat[7] = in_flat[47];
assign const_conditional_wrapper_in_flat[8] = in_flat[48];
assign const_conditional_wrapper_in_flat[9] = in_flat[49];
assign const_conditional_wrapper_in_flat[10] = in_flat[50];
assign const_conditional_wrapper_in_flat[11] = in_flat[51];
assign const_conditional_wrapper_in_flat[12] = in_flat[52];
assign const_conditional_wrapper_in_flat[13] = in_flat[53];
assign const_conditional_wrapper_in_flat[14] = in_flat[54];
assign const_conditional_wrapper_in_flat[15] = in_flat[55];
assign const_conditional_wrapper_in_flat[16] = in_flat[56];
assign const_conditional_wrapper_in_flat[17] = in_flat[57];
assign const_conditional_wrapper_in_flat[18] = in_flat[58];
assign const_conditional_wrapper_in_flat[19] = in_flat[59];
assign const_conditional_wrapper_in_flat[20] = in_flat[60];
assign const_conditional_wrapper_in_flat[21] = in_flat[61];
assign const_conditional_wrapper_in_flat[22] = in_flat[62];
assign const_conditional_wrapper_in_flat[23] = in_flat[63];
assign const_conditional_wrapper_in_flat[24] = in_flat[64];
assign const_conditional_wrapper_in_flat[25] = in_flat[65];
assign const_conditional_wrapper_in_flat[26] = in_flat[66];
assign const_conditional_wrapper_in_flat[27] = in_flat[67];
assign const_conditional_wrapper_in_flat[28] = in_flat[68];
assign const_conditional_wrapper_in_flat[29] = in_flat[69];
assign const_conditional_wrapper_in_flat[30] = in_flat[70];
assign const_conditional_wrapper_in_flat[31] = in_flat[71];
assign const_logic_wrapper_in_flat[0] = in_flat[72];
assign const_logic_wrapper_in_flat[2] = in_flat[73];
assign const_logic_wrapper_in_flat[4] = in_flat[74];
assign const_logic_wrapper_in_flat[5] = in_flat[75];
assign const_logic_wrapper_in_flat[7] = in_flat[76];
assign const_logic_wrapper_in_flat[9] = in_flat[77];
assign const_nested_wrapper_in_flat[0] = in_flat[78];
assign const_nested_wrapper_in_flat[1] = in_flat[79];
assign const_nested_wrapper_in_flat[2] = in_flat[80];
assign const_nested_wrapper_in_flat[3] = in_flat[81];
assign const_nested_wrapper_in_flat[5] = in_flat[82];
assign const_nested_wrapper_in_flat[6] = in_flat[83];
assign const_nested_wrapper_in_flat[8] = in_flat[84];
assign const_nested_wrapper_in_flat[9] = in_flat[85];
assign const_nested_wrapper_in_flat[11] = in_flat[86];
assign const_nested_wrapper_in_flat[12] = in_flat[87];
assign const_nested_wrapper_in_flat[13] = in_flat[88];
assign const_nested_wrapper_in_flat[14] = in_flat[89];
assign const_nested_wrapper_in_flat[16] = in_flat[90];
assign const_nested_wrapper_in_flat[17] = in_flat[91];
assign const_nested_wrapper_in_flat[18] = in_flat[92];
assign const_nested_wrapper_in_flat[19] = in_flat[93];
assign const_nested_wrapper_in_flat[20] = in_flat[94];
assign const_nested_wrapper_in_flat[21] = in_flat[95];
assign const_nested_wrapper_in_flat[22] = in_flat[96];
assign const_nested_wrapper_in_flat[23] = in_flat[97];
assign const_nested_wrapper_in_flat[24] = in_flat[98];
assign const_nested_wrapper_in_flat[25] = in_flat[99];
assign const_nested_wrapper_in_flat[26] = in_flat[100];
assign const_partselect_wrapper_in_flat[0] = in_flat[101];
assign const_partselect_wrapper_in_flat[1] = in_flat[102];
assign const_partselect_wrapper_in_flat[2] = in_flat[103];
assign const_partselect_wrapper_in_flat[3] = in_flat[104];
assign const_partselect_wrapper_in_flat[4] = in_flat[105];
assign const_partselect_wrapper_in_flat[5] = in_flat[106];
assign const_partselect_wrapper_in_flat[7] = in_flat[107];
assign const_partselect_wrapper_in_flat[8] = in_flat[108];
assign const_partselect_wrapper_in_flat[10] = in_flat[109];
assign const_partselect_wrapper_in_flat[11] = in_flat[110];
assign const_partselect_wrapper_in_flat[12] = in_flat[111];
assign const_partselect_wrapper_in_flat[13] = in_flat[112];
assign const_partselect_wrapper_in_flat[14] = in_flat[113];
assign const_partselect_wrapper_in_flat[15] = in_flat[114];
assign const_partselect_wrapper_in_flat[17] = in_flat[115];
assign const_partselect_wrapper_in_flat[19] = in_flat[116];
assign const_reduce_wrapper_in_flat[1] = in_flat[117];
assign const_shift_wrapper_in_flat[0] = in_flat[118];
assign const_shift_wrapper_in_flat[1] = in_flat[119];
assign const_shift_wrapper_in_flat[2] = in_flat[120];
assign const_shift_wrapper_in_flat[3] = in_flat[121];
assign const_shift_wrapper_in_flat[4] = in_flat[122];
assign const_shift_wrapper_in_flat[7] = in_flat[123];
assign const_shift_wrapper_in_flat[8] = in_flat[124];
assign const_shift_wrapper_in_flat[10] = in_flat[125];
assign arithmetic_reduce_wrapper_in_flat[0] = in_flat[126];
assign arithmetic_reduce_wrapper_in_flat[1] = in_flat[127];
assign arithmetic_reduce_wrapper_in_flat[2] = in_flat[128];
assign arithmetic_reduce_wrapper_in_flat[3] = in_flat[129];
assign arithmetic_reduce_wrapper_in_flat[7] = in_flat[130];
assign arithmetic_reduce_wrapper_in_flat[8] = in_flat[131];
assign arithmetic_reduce_wrapper_in_flat[9] = in_flat[132];
assign arithmetic_reduce_wrapper_in_flat[10] = in_flat[133];
assign arithmetic_reduce_wrapper_in_flat[11] = in_flat[134];
assign arithmetic_reduce_wrapper_in_flat[12] = in_flat[135];
assign arithmetic_reduce_wrapper_in_flat[14] = in_flat[136];
assign bitwise_logic_wrapper_in_flat[0] = in_flat[137];
assign bitwise_logic_wrapper_in_flat[1] = in_flat[138];
assign bitwise_logic_wrapper_in_flat[2] = in_flat[139];
assign bitwise_logic_wrapper_in_flat[3] = in_flat[140];
assign bitwise_logic_wrapper_in_flat[5] = in_flat[141];
assign bitwise_logic_wrapper_in_flat[6] = in_flat[142];
assign bitwise_logic_wrapper_in_flat[8] = in_flat[143];
assign bitwise_logic_wrapper_in_flat[9] = in_flat[144];
assign bitwise_logic_wrapper_in_flat[10] = in_flat[145];
assign bitwise_logic_wrapper_in_flat[14] = in_flat[146];
assign bitwise_logic_wrapper_in_flat[15] = in_flat[147];
assign bitwise_reduce_wrapper_in_flat[0] = in_flat[148];
assign bitwise_reduce_wrapper_in_flat[1] = in_flat[149];
assign bitwise_reduce_wrapper_in_flat[3] = in_flat[150];
assign bitwise_reduce_wrapper_in_flat[4] = in_flat[151];
assign bitwise_reduce_wrapper_in_flat[5] = in_flat[152];
assign logical_op_wrapper_in_flat[1] = in_flat[153];
assign relational_wrapper_in_flat[0] = in_flat[154];
assign relational_wrapper_in_flat[1] = in_flat[155];
assign relational_wrapper_in_flat[2] = in_flat[156];
assign relational_wrapper_in_flat[3] = in_flat[157];
assign relational_wrapper_in_flat[4] = in_flat[158];
assign relational_wrapper_in_flat[5] = in_flat[159];
assign relational_wrapper_in_flat[6] = in_flat[160];
assign select_wrapper_in_flat[0] = in_flat[161];
assign select_wrapper_in_flat[1] = in_flat[162];
assign select_wrapper_in_flat[2] = in_flat[163];
assign select_wrapper_in_flat[3] = in_flat[164];
assign select_wrapper_in_flat[4] = in_flat[165];
assign select_wrapper_in_flat[5] = in_flat[166];
assign select_wrapper_in_flat[6] = in_flat[167];
assign select_wrapper_in_flat[7] = in_flat[168];
assign select_wrapper_in_flat[8] = in_flat[169];
assign select_wrapper_in_flat[9] = in_flat[170];
assign select_wrapper_in_flat[11] = in_flat[171];
assign select_wrapper_in_flat[12] = in_flat[172];
assign select_wrapper_in_flat[13] = in_flat[173];
assign select_wrapper_in_flat[14] = in_flat[174];
assign select_wrapper_in_flat[15] = in_flat[175];
assign select_wrapper_in_flat[17] = in_flat[176];
assign select_wrapper_in_flat[18] = in_flat[177];
assign select_wrapper_in_flat[19] = in_flat[178];
assign shift_wrapper_in_flat[0] = in_flat[179];
assign shift_wrapper_in_flat[1] = in_flat[180];
assign shift_wrapper_in_flat[2] = in_flat[181];
assign shift_wrapper_in_flat[3] = in_flat[182];
assign shift_wrapper_in_flat[4] = in_flat[183];
assign shift_wrapper_in_flat[5] = in_flat[184];
assign shift_wrapper_in_flat[6] = in_flat[185];
assign shift_wrapper_in_flat[7] = in_flat[186];
assign shift_wrapper_in_flat[8] = in_flat[187];
assign shift_wrapper_in_flat[9] = in_flat[188];
assign shift_wrapper_in_flat[10] = in_flat[189];
assign array_wrapper_in_flat[0] = in_flat[190];
assign array_wrapper_in_flat[1] = in_flat[191];
assign array_wrapper_in_flat[2] = in_flat[192];
assign array_wrapper_in_flat[3] = in_flat[193];
assign array_wrapper_in_flat[4] = in_flat[194];
assign array_wrapper_in_flat[5] = in_flat[195];
assign array_wrapper_in_flat[7] = in_flat[196];
assign array_wrapper_in_flat[8] = in_flat[197];
assign array_wrapper_in_flat[9] = in_flat[198];
assign array_wrapper_in_flat[11] = in_flat[199];
assign array_wrapper_in_flat[12] = in_flat[200];
assign array_wrapper_in_flat[13] = in_flat[201];
assign array_wrapper_in_flat[14] = in_flat[202];
assign array_wrapper_in_flat[15] = in_flat[203];
assign array_wrapper_in_flat[16] = in_flat[204];
assign array_wrapper_in_flat[17] = in_flat[205];
assign cast_wrapper_in_flat[0] = in_flat[206];
assign cast_wrapper_in_flat[1] = in_flat[207];
assign cast_wrapper_in_flat[2] = in_flat[208];
assign cast_wrapper_in_flat[3] = in_flat[209];
assign cast_wrapper_in_flat[5] = in_flat[210];
assign cast_wrapper_in_flat[6] = in_flat[211];
assign cast_wrapper_in_flat[7] = in_flat[212];
assign cast_wrapper_in_flat[9] = in_flat[213];
assign cast_wrapper_in_flat[10] = in_flat[214];
assign conditional_wrapper_in_flat[1] = in_flat[215];
assign conditional_wrapper_in_flat[2] = in_flat[216];
assign conditional_wrapper_in_flat[3] = in_flat[217];
assign conditional_wrapper_in_flat[8] = in_flat[218];
assign partselect_wrapper_in_flat[1] = in_flat[219];
assign partselect_wrapper_in_flat[2] = in_flat[220];
assign partselect_wrapper_in_flat[4] = in_flat[221];
assign partselect_wrapper_in_flat[5] = in_flat[222];
assign partselect_wrapper_in_flat[7] = in_flat[223];
assign partselect_wrapper_in_flat[8] = in_flat[224];
assign partselect_wrapper_in_flat[10] = in_flat[225];
assign partselect_wrapper_in_flat[11] = in_flat[226];
assign partselect_wrapper_in_flat[12] = in_flat[227];
assign partselect_wrapper_in_flat[13] = in_flat[228];
assign partselect_wrapper_in_flat[15] = in_flat[229];
assign partselect_wrapper_in_flat[16] = in_flat[230];
assign partselect_wrapper_in_flat[17] = in_flat[231];
assign width_enum_wrapper_in_flat[2] = in_flat[232];
assign width_struct_wrapper_in_flat[0] = in_flat[233];
assign width_struct_wrapper_in_flat[1] = in_flat[234];
assign width_struct_wrapper_in_flat[2] = in_flat[235];
assign width_struct_wrapper_in_flat[3] = in_flat[236];
assign width_struct_wrapper_in_flat[5] = in_flat[237];
assign width_struct_wrapper_in_flat[7] = in_flat[238];
assign width_struct_wrapper_in_flat[8] = in_flat[239];
assign width_struct_wrapper_in_flat[9] = in_flat[240];
assign width_struct_wrapper_in_flat[10] = in_flat[241];
assign width_struct_wrapper_in_flat[11] = in_flat[242];
assign width_union_wrapper_in_flat[0] = in_flat[243];
assign width_union_wrapper_in_flat[1] = in_flat[244];
assign width_union_wrapper_in_flat[2] = in_flat[245];
assign width_union_wrapper_in_flat[3] = in_flat[246];
assign width_union_wrapper_in_flat[4] = in_flat[247];
assign width_union_wrapper_in_flat[5] = in_flat[248];
assign width_union_wrapper_in_flat[6] = in_flat[249];
assign width_union_wrapper_in_flat[7] = in_flat[250];
assign width_union_wrapper_in_flat[8] = in_flat[251];
assign width_union_wrapper_in_flat[9] = in_flat[252];
assign width_union_wrapper_in_flat[11] = in_flat[253];
assign width_union_wrapper_in_flat[12] = in_flat[254];
assign width_union_wrapper_in_flat[14] = in_flat[255];
assign width_union_wrapper_in_flat[15] = in_flat[256];
assign width_logic_wrapper_in_flat[0] = in_flat[257];
assign width_logic_wrapper_in_flat[4] = in_flat[258];
assign width_logic_wrapper_in_flat[5] = in_flat[259];
assign width_logic_wrapper_in_flat[7] = in_flat[260];
assign numbers_concat_repl_wrapper_in_flat[1] = in_flat[261];
assign numbers_concat_repl_wrapper_in_flat[2] = in_flat[262];
assign numbers_concat_repl_wrapper_in_flat[3] = in_flat[263];

// Internal MTM connections (module-to-module)
assign conditional_wrapper_in_flat[6] = const_arith_wrapper_out_flat[6];
assign width_struct_wrapper_in_flat[6] = const_arith_wrapper_out_flat[25];
assign partselect_wrapper_in_flat[0] = const_compare_wrapper_out_flat[0];
assign array_wrapper_in_flat[10] = const_compare_wrapper_out_flat[0];
assign const_conditional_wrapper_in_flat[4] = const_compare_wrapper_out_flat[1];
assign arithmetic_reduce_wrapper_in_flat[5] = const_compare_wrapper_out_flat[1];
assign const_logic_wrapper_in_flat[6] = const_compare_wrapper_out_flat[5];
assign cast_wrapper_in_flat[4] = const_compare_wrapper_out_flat[6];
assign bitwise_logic_wrapper_in_flat[13] = const_concat_repl_wrapper_out_flat[3];
assign const_partselect_wrapper_in_flat[16] = const_concat_repl_wrapper_out_flat[3];
assign const_nested_wrapper_in_flat[15] = const_concat_repl_wrapper_out_flat[6];
assign bitwise_reduce_wrapper_in_flat[7] = const_concat_repl_wrapper_out_flat[7];
assign const_arith_wrapper_in_flat[12] = const_conditional_wrapper_out_flat[7];
assign numbers_concat_repl_wrapper_in_flat[4] = const_conditional_wrapper_out_flat[7];
assign partselect_wrapper_in_flat[9] = const_conditional_wrapper_out_flat[17];
assign width_enum_wrapper_in_flat[1] = const_logic_wrapper_out_flat[0];
assign bitwise_reduce_wrapper_in_flat[2] = const_logic_wrapper_out_flat[3];
assign partselect_wrapper_in_flat[3] = const_logic_wrapper_out_flat[11];
assign arithmetic_reduce_wrapper_in_flat[4] = const_logic_wrapper_out_flat[17];
assign const_conditional_wrapper_in_flat[2] = const_logic_wrapper_out_flat[18];
assign const_arith_wrapper_in_flat[4] = const_nested_wrapper_out_flat[5];
assign width_union_wrapper_in_flat[13] = const_partselect_wrapper_out_flat[7];
assign bitwise_logic_wrapper_in_flat[4] = const_reduce_wrapper_out_flat[3];
assign width_enum_wrapper_in_flat[0] = const_shift_wrapper_out_flat[7];
assign const_logic_wrapper_in_flat[8] = const_shift_wrapper_out_flat[20];
assign arithmetic_reduce_wrapper_in_flat[6] = const_shift_wrapper_out_flat[23];
assign partselect_wrapper_in_flat[6] = arithmetic_reduce_wrapper_out_flat[1];
assign numbers_concat_repl_wrapper_in_flat[5] = arithmetic_reduce_wrapper_out_flat[4];
assign const_conditional_wrapper_in_flat[33] = arithmetic_reduce_wrapper_out_flat[6];
assign bitwise_reduce_wrapper_in_flat[6] = arithmetic_reduce_wrapper_out_flat[9];
assign conditional_wrapper_in_flat[7] = bitwise_logic_wrapper_out_flat[7];
assign width_logic_wrapper_in_flat[1] = bitwise_reduce_wrapper_out_flat[0];
assign conditional_wrapper_in_flat[0] = bitwise_reduce_wrapper_out_flat[2];
assign const_reduce_wrapper_in_flat[2] = logical_op_wrapper_out_flat[1];
assign width_struct_wrapper_in_flat[4] = logical_op_wrapper_out_flat[1];
assign bitwise_logic_wrapper_in_flat[11] = logical_op_wrapper_out_flat[2];
assign const_compare_wrapper_in_flat[14] = relational_wrapper_out_flat[1];
assign width_logic_wrapper_in_flat[6] = relational_wrapper_out_flat[2];
assign const_logic_wrapper_in_flat[1] = relational_wrapper_out_flat[3];
assign const_partselect_wrapper_in_flat[9] = relational_wrapper_out_flat[5];
assign const_concat_repl_wrapper_in_flat[2] = relational_wrapper_out_flat[5];
assign width_union_wrapper_in_flat[10] = relational_wrapper_out_flat[6];
assign bitwise_logic_wrapper_in_flat[7] = select_wrapper_out_flat[3];
assign conditional_wrapper_in_flat[4] = select_wrapper_out_flat[8];
assign const_partselect_wrapper_in_flat[18] = shift_wrapper_out_flat[0];
assign cast_wrapper_in_flat[8] = shift_wrapper_out_flat[7];
assign relational_wrapper_in_flat[7] = shift_wrapper_out_flat[9];
assign const_logic_wrapper_in_flat[3] = shift_wrapper_out_flat[10];
assign partselect_wrapper_in_flat[14] = shift_wrapper_out_flat[10];
assign const_conditional_wrapper_in_flat[1] = shift_wrapper_out_flat[10];
assign width_enum_wrapper_in_flat[3] = shift_wrapper_out_flat[11];
assign array_wrapper_in_flat[6] = shift_wrapper_out_flat[12];
assign const_shift_wrapper_in_flat[6] = shift_wrapper_out_flat[12];
assign const_partselect_wrapper_in_flat[6] = array_wrapper_out_flat[0];
assign const_nested_wrapper_in_flat[4] = array_wrapper_out_flat[6];
assign const_shift_wrapper_in_flat[5] = array_wrapper_out_flat[9];
assign numbers_concat_repl_wrapper_in_flat[0] = array_wrapper_out_flat[10];
assign const_conditional_wrapper_in_flat[32] = array_wrapper_out_flat[10];
assign arithmetic_reduce_wrapper_in_flat[13] = array_wrapper_out_flat[13];
assign cast_wrapper_in_flat[11] = array_wrapper_out_flat[14];
assign const_shift_wrapper_in_flat[9] = cast_wrapper_out_flat[1];
assign const_concat_repl_wrapper_in_flat[5] = cast_wrapper_out_flat[2];
assign arithmetic_reduce_wrapper_in_flat[15] = cast_wrapper_out_flat[11];
assign const_arith_wrapper_in_flat[1] = partselect_wrapper_out_flat[5];
assign logical_op_wrapper_in_flat[0] = partselect_wrapper_out_flat[8];
assign select_wrapper_in_flat[16] = width_struct_wrapper_out_flat[1];
assign bitwise_logic_wrapper_in_flat[12] = width_struct_wrapper_out_flat[5];
assign const_reduce_wrapper_in_flat[0] = width_union_wrapper_out_flat[3];
assign width_logic_wrapper_in_flat[3] = width_union_wrapper_out_flat[4];
assign const_nested_wrapper_in_flat[10] = width_union_wrapper_out_flat[11];
assign select_wrapper_in_flat[10] = width_logic_wrapper_out_flat[2];
assign conditional_wrapper_in_flat[5] = width_logic_wrapper_out_flat[5];
assign width_logic_wrapper_in_flat[2] = numbers_concat_repl_wrapper_out_flat[4];
assign const_arith_wrapper_in_flat[3] = numbers_concat_repl_wrapper_out_flat[10];
assign partselect_wrapper_in_flat[18] = numbers_concat_repl_wrapper_out_flat[11];
assign const_nested_wrapper_in_flat[7] = numbers_concat_repl_wrapper_out_flat[15];
assign const_reduce_wrapper_in_flat[3] = numbers_concat_repl_wrapper_out_flat[16];

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
assign out_flat[159] = arithmetic_reduce_wrapper_out_flat[0];
assign out_flat[160] = arithmetic_reduce_wrapper_out_flat[1];
assign out_flat[161] = arithmetic_reduce_wrapper_out_flat[2];
assign out_flat[162] = arithmetic_reduce_wrapper_out_flat[3];
assign out_flat[163] = arithmetic_reduce_wrapper_out_flat[4];
assign out_flat[164] = arithmetic_reduce_wrapper_out_flat[5];
assign out_flat[165] = arithmetic_reduce_wrapper_out_flat[6];
assign out_flat[166] = arithmetic_reduce_wrapper_out_flat[7];
assign out_flat[167] = arithmetic_reduce_wrapper_out_flat[8];
assign out_flat[168] = arithmetic_reduce_wrapper_out_flat[9];
assign out_flat[169] = bitwise_logic_wrapper_out_flat[0];
assign out_flat[170] = bitwise_logic_wrapper_out_flat[1];
assign out_flat[171] = bitwise_logic_wrapper_out_flat[2];
assign out_flat[172] = bitwise_logic_wrapper_out_flat[3];
assign out_flat[173] = bitwise_logic_wrapper_out_flat[4];
assign out_flat[174] = bitwise_logic_wrapper_out_flat[5];
assign out_flat[175] = bitwise_logic_wrapper_out_flat[6];
assign out_flat[176] = bitwise_logic_wrapper_out_flat[7];
assign out_flat[177] = bitwise_logic_wrapper_out_flat[8];
assign out_flat[178] = bitwise_logic_wrapper_out_flat[9];
assign out_flat[179] = bitwise_logic_wrapper_out_flat[10];
assign out_flat[180] = bitwise_logic_wrapper_out_flat[11];
assign out_flat[181] = bitwise_logic_wrapper_out_flat[12];
assign out_flat[182] = bitwise_logic_wrapper_out_flat[13];
assign out_flat[183] = bitwise_logic_wrapper_out_flat[14];
assign out_flat[184] = bitwise_logic_wrapper_out_flat[15];
assign out_flat[185] = bitwise_logic_wrapper_out_flat[16];
assign out_flat[186] = bitwise_logic_wrapper_out_flat[17];
assign out_flat[187] = bitwise_logic_wrapper_out_flat[18];
assign out_flat[188] = bitwise_logic_wrapper_out_flat[19];
assign out_flat[189] = bitwise_logic_wrapper_out_flat[20];
assign out_flat[190] = bitwise_logic_wrapper_out_flat[21];
assign out_flat[191] = bitwise_logic_wrapper_out_flat[22];
assign out_flat[192] = bitwise_logic_wrapper_out_flat[23];
assign out_flat[193] = bitwise_reduce_wrapper_out_flat[0];
assign out_flat[194] = bitwise_reduce_wrapper_out_flat[1];
assign out_flat[195] = bitwise_reduce_wrapper_out_flat[2];
assign out_flat[196] = logical_op_wrapper_out_flat[0];
assign out_flat[197] = logical_op_wrapper_out_flat[1];
assign out_flat[198] = logical_op_wrapper_out_flat[2];
assign out_flat[199] = relational_wrapper_out_flat[0];
assign out_flat[200] = relational_wrapper_out_flat[1];
assign out_flat[201] = relational_wrapper_out_flat[2];
assign out_flat[202] = relational_wrapper_out_flat[3];
assign out_flat[203] = relational_wrapper_out_flat[4];
assign out_flat[204] = relational_wrapper_out_flat[5];
assign out_flat[205] = relational_wrapper_out_flat[6];
assign out_flat[206] = relational_wrapper_out_flat[7];
assign out_flat[207] = select_wrapper_out_flat[0];
assign out_flat[208] = select_wrapper_out_flat[1];
assign out_flat[209] = select_wrapper_out_flat[2];
assign out_flat[210] = select_wrapper_out_flat[3];
assign out_flat[211] = select_wrapper_out_flat[4];
assign out_flat[212] = select_wrapper_out_flat[5];
assign out_flat[213] = select_wrapper_out_flat[6];
assign out_flat[214] = select_wrapper_out_flat[7];
assign out_flat[215] = select_wrapper_out_flat[8];
assign out_flat[216] = shift_wrapper_out_flat[0];
assign out_flat[217] = shift_wrapper_out_flat[1];
assign out_flat[218] = shift_wrapper_out_flat[2];
assign out_flat[219] = shift_wrapper_out_flat[3];
assign out_flat[220] = shift_wrapper_out_flat[4];
assign out_flat[221] = shift_wrapper_out_flat[5];
assign out_flat[222] = shift_wrapper_out_flat[6];
assign out_flat[223] = shift_wrapper_out_flat[7];
assign out_flat[224] = shift_wrapper_out_flat[8];
assign out_flat[225] = shift_wrapper_out_flat[9];
assign out_flat[226] = shift_wrapper_out_flat[10];
assign out_flat[227] = shift_wrapper_out_flat[11];
assign out_flat[228] = shift_wrapper_out_flat[12];
assign out_flat[229] = shift_wrapper_out_flat[13];
assign out_flat[230] = shift_wrapper_out_flat[14];
assign out_flat[231] = shift_wrapper_out_flat[15];
assign out_flat[232] = array_wrapper_out_flat[0];
assign out_flat[233] = array_wrapper_out_flat[1];
assign out_flat[234] = array_wrapper_out_flat[2];
assign out_flat[235] = array_wrapper_out_flat[3];
assign out_flat[236] = array_wrapper_out_flat[4];
assign out_flat[237] = array_wrapper_out_flat[5];
assign out_flat[238] = array_wrapper_out_flat[6];
assign out_flat[239] = array_wrapper_out_flat[7];
assign out_flat[240] = array_wrapper_out_flat[8];
assign out_flat[241] = array_wrapper_out_flat[9];
assign out_flat[242] = array_wrapper_out_flat[10];
assign out_flat[243] = array_wrapper_out_flat[11];
assign out_flat[244] = array_wrapper_out_flat[12];
assign out_flat[245] = array_wrapper_out_flat[13];
assign out_flat[246] = array_wrapper_out_flat[14];
assign out_flat[247] = array_wrapper_out_flat[15];
assign out_flat[248] = cast_wrapper_out_flat[0];
assign out_flat[249] = cast_wrapper_out_flat[1];
assign out_flat[250] = cast_wrapper_out_flat[2];
assign out_flat[251] = cast_wrapper_out_flat[3];
assign out_flat[252] = cast_wrapper_out_flat[4];
assign out_flat[253] = cast_wrapper_out_flat[5];
assign out_flat[254] = cast_wrapper_out_flat[6];
assign out_flat[255] = cast_wrapper_out_flat[7];
assign out_flat[256] = cast_wrapper_out_flat[8];
assign out_flat[257] = cast_wrapper_out_flat[9];
assign out_flat[258] = cast_wrapper_out_flat[10];
assign out_flat[259] = cast_wrapper_out_flat[11];
assign out_flat[260] = conditional_wrapper_out_flat[0];
assign out_flat[261] = conditional_wrapper_out_flat[1];
assign out_flat[262] = conditional_wrapper_out_flat[2];
assign out_flat[263] = conditional_wrapper_out_flat[3];
assign out_flat[264] = partselect_wrapper_out_flat[0];
assign out_flat[265] = partselect_wrapper_out_flat[1];
assign out_flat[266] = partselect_wrapper_out_flat[2];
assign out_flat[267] = partselect_wrapper_out_flat[3];
assign out_flat[268] = partselect_wrapper_out_flat[4];
assign out_flat[269] = partselect_wrapper_out_flat[5];
assign out_flat[270] = partselect_wrapper_out_flat[6];
assign out_flat[271] = partselect_wrapper_out_flat[7];
assign out_flat[272] = partselect_wrapper_out_flat[8];
assign out_flat[273] = width_enum_wrapper_out_flat[0];
assign out_flat[274] = width_enum_wrapper_out_flat[1];
assign out_flat[275] = width_enum_wrapper_out_flat[2];
assign out_flat[276] = width_enum_wrapper_out_flat[3];
assign out_flat[277] = width_enum_wrapper_out_flat[4];
assign out_flat[278] = width_struct_wrapper_out_flat[0];
assign out_flat[279] = width_struct_wrapper_out_flat[1];
assign out_flat[280] = width_struct_wrapper_out_flat[2];
assign out_flat[281] = width_struct_wrapper_out_flat[3];
assign out_flat[282] = width_struct_wrapper_out_flat[4];
assign out_flat[283] = width_struct_wrapper_out_flat[5];
assign out_flat[284] = width_struct_wrapper_out_flat[6];
assign out_flat[285] = width_struct_wrapper_out_flat[7];
assign out_flat[286] = width_struct_wrapper_out_flat[8];
assign out_flat[287] = width_struct_wrapper_out_flat[9];
assign out_flat[288] = width_struct_wrapper_out_flat[10];
assign out_flat[289] = width_struct_wrapper_out_flat[11];
assign out_flat[290] = width_union_wrapper_out_flat[0];
assign out_flat[291] = width_union_wrapper_out_flat[1];
assign out_flat[292] = width_union_wrapper_out_flat[2];
assign out_flat[293] = width_union_wrapper_out_flat[3];
assign out_flat[294] = width_union_wrapper_out_flat[4];
assign out_flat[295] = width_union_wrapper_out_flat[5];
assign out_flat[296] = width_union_wrapper_out_flat[6];
assign out_flat[297] = width_union_wrapper_out_flat[7];
assign out_flat[298] = width_union_wrapper_out_flat[8];
assign out_flat[299] = width_union_wrapper_out_flat[9];
assign out_flat[300] = width_union_wrapper_out_flat[10];
assign out_flat[301] = width_union_wrapper_out_flat[11];
assign out_flat[302] = width_union_wrapper_out_flat[12];
assign out_flat[303] = width_union_wrapper_out_flat[13];
assign out_flat[304] = width_union_wrapper_out_flat[14];
assign out_flat[305] = width_union_wrapper_out_flat[15];
assign out_flat[306] = width_logic_wrapper_out_flat[0];
assign out_flat[307] = width_logic_wrapper_out_flat[1];
assign out_flat[308] = width_logic_wrapper_out_flat[2];
assign out_flat[309] = width_logic_wrapper_out_flat[3];
assign out_flat[310] = width_logic_wrapper_out_flat[4];
assign out_flat[311] = width_logic_wrapper_out_flat[5];
assign out_flat[312] = numbers_concat_repl_wrapper_out_flat[0];
assign out_flat[313] = numbers_concat_repl_wrapper_out_flat[1];
assign out_flat[314] = numbers_concat_repl_wrapper_out_flat[2];
assign out_flat[315] = numbers_concat_repl_wrapper_out_flat[3];
assign out_flat[316] = numbers_concat_repl_wrapper_out_flat[4];
assign out_flat[317] = numbers_concat_repl_wrapper_out_flat[5];
assign out_flat[318] = numbers_concat_repl_wrapper_out_flat[6];
assign out_flat[319] = numbers_concat_repl_wrapper_out_flat[7];
assign out_flat[320] = numbers_concat_repl_wrapper_out_flat[8];
assign out_flat[321] = numbers_concat_repl_wrapper_out_flat[9];
assign out_flat[322] = numbers_concat_repl_wrapper_out_flat[10];
assign out_flat[323] = numbers_concat_repl_wrapper_out_flat[11];
assign out_flat[324] = numbers_concat_repl_wrapper_out_flat[12];
assign out_flat[325] = numbers_concat_repl_wrapper_out_flat[13];
assign out_flat[326] = numbers_concat_repl_wrapper_out_flat[14];
assign out_flat[327] = numbers_concat_repl_wrapper_out_flat[15];
assign out_flat[328] = numbers_concat_repl_wrapper_out_flat[16];
assign out_flat[329] = numbers_concat_repl_wrapper_out_flat[17];

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