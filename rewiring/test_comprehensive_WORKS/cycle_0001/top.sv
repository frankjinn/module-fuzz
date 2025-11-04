// Auto-generated Top Module for flattened IO

module top (
    input  wire clk,
    input  wire rst_n,
    input  wire [342:0] in_flat,
    output wire [414:0] out_flat
);

// Per-module I/O buses
wire [0:0] arith_wrapper_in_flat;
wire [0:0] arith_wrapper_out_flat;
wire [15:0] arithmetic_reduce_wrapper_in_flat;
wire [9:0] arithmetic_reduce_wrapper_out_flat;
wire [0:0] arithmetic_wrapper_in_flat;
wire [0:0] arithmetic_wrapper_out_flat;
wire [17:0] array_wrapper_in_flat;
wire [15:0] array_wrapper_out_flat;
wire [15:0] bitwise_logic_wrapper_in_flat;
wire [23:0] bitwise_logic_wrapper_out_flat;
wire [7:0] bitwise_reduce_wrapper_in_flat;
wire [2:0] bitwise_reduce_wrapper_out_flat;
wire [11:0] cast_wrapper_in_flat;
wire [11:0] cast_wrapper_out_flat;
wire [5:0] concat_repl_wrapper_in_flat;
wire [17:0] concat_repl_wrapper_out_flat;
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
wire [0:0] constant_wrapper_in_flat;
wire [79:0] constant_wrapper_out_flat;
wire [1:0] logical_op_wrapper_in_flat;
wire [2:0] logical_op_wrapper_out_flat;
wire [0:0] param_wrapper_in_flat;
wire [0:0] param_wrapper_out_flat;
wire [18:0] partselect_wrapper_in_flat;
wire [8:0] partselect_wrapper_out_flat;
wire [7:0] reduce_case_wrapper_in_flat;
wire [1:0] reduce_case_wrapper_out_flat;
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
assign const_arith_wrapper_in_flat[1] = in_flat[1];
assign const_arith_wrapper_in_flat[2] = in_flat[2];
assign const_arith_wrapper_in_flat[3] = in_flat[3];
assign const_arith_wrapper_in_flat[4] = in_flat[4];
assign const_arith_wrapper_in_flat[5] = in_flat[5];
assign const_arith_wrapper_in_flat[6] = in_flat[6];
assign const_arith_wrapper_in_flat[7] = in_flat[7];
assign const_arith_wrapper_in_flat[8] = in_flat[8];
assign const_arith_wrapper_in_flat[9] = in_flat[9];
assign const_arith_wrapper_in_flat[10] = in_flat[10];
assign const_arith_wrapper_in_flat[11] = in_flat[11];
assign const_arith_wrapper_in_flat[12] = in_flat[12];
assign const_arith_wrapper_in_flat[13] = in_flat[13];
assign const_arith_wrapper_in_flat[14] = in_flat[14];
assign const_arith_wrapper_in_flat[15] = in_flat[15];
assign const_compare_wrapper_in_flat[0] = in_flat[16];
assign const_compare_wrapper_in_flat[1] = in_flat[17];
assign const_compare_wrapper_in_flat[2] = in_flat[18];
assign const_compare_wrapper_in_flat[3] = in_flat[19];
assign const_compare_wrapper_in_flat[4] = in_flat[20];
assign const_compare_wrapper_in_flat[5] = in_flat[21];
assign const_compare_wrapper_in_flat[7] = in_flat[22];
assign const_compare_wrapper_in_flat[8] = in_flat[23];
assign const_compare_wrapper_in_flat[9] = in_flat[24];
assign const_compare_wrapper_in_flat[10] = in_flat[25];
assign const_compare_wrapper_in_flat[11] = in_flat[26];
assign const_compare_wrapper_in_flat[12] = in_flat[27];
assign const_compare_wrapper_in_flat[13] = in_flat[28];
assign const_compare_wrapper_in_flat[14] = in_flat[29];
assign const_compare_wrapper_in_flat[15] = in_flat[30];
assign const_compare_wrapper_in_flat[16] = in_flat[31];
assign const_compare_wrapper_in_flat[17] = in_flat[32];
assign const_compare_wrapper_in_flat[18] = in_flat[33];
assign const_compare_wrapper_in_flat[19] = in_flat[34];
assign const_compare_wrapper_in_flat[21] = in_flat[35];
assign const_compare_wrapper_in_flat[22] = in_flat[36];
assign const_compare_wrapper_in_flat[23] = in_flat[37];
assign const_concat_repl_wrapper_in_flat[0] = in_flat[38];
assign const_concat_repl_wrapper_in_flat[1] = in_flat[39];
assign const_concat_repl_wrapper_in_flat[2] = in_flat[40];
assign const_concat_repl_wrapper_in_flat[3] = in_flat[41];
assign const_concat_repl_wrapper_in_flat[4] = in_flat[42];
assign const_concat_repl_wrapper_in_flat[5] = in_flat[43];
assign const_concat_repl_wrapper_in_flat[6] = in_flat[44];
assign const_concat_repl_wrapper_in_flat[7] = in_flat[45];
assign const_concat_repl_wrapper_in_flat[8] = in_flat[46];
assign const_concat_repl_wrapper_in_flat[9] = in_flat[47];
assign const_conditional_wrapper_in_flat[0] = in_flat[48];
assign const_conditional_wrapper_in_flat[1] = in_flat[49];
assign const_conditional_wrapper_in_flat[2] = in_flat[50];
assign const_conditional_wrapper_in_flat[3] = in_flat[51];
assign const_conditional_wrapper_in_flat[4] = in_flat[52];
assign const_conditional_wrapper_in_flat[5] = in_flat[53];
assign const_conditional_wrapper_in_flat[6] = in_flat[54];
assign const_conditional_wrapper_in_flat[7] = in_flat[55];
assign const_conditional_wrapper_in_flat[8] = in_flat[56];
assign const_conditional_wrapper_in_flat[9] = in_flat[57];
assign const_conditional_wrapper_in_flat[10] = in_flat[58];
assign const_conditional_wrapper_in_flat[11] = in_flat[59];
assign const_conditional_wrapper_in_flat[12] = in_flat[60];
assign const_conditional_wrapper_in_flat[13] = in_flat[61];
assign const_conditional_wrapper_in_flat[14] = in_flat[62];
assign const_conditional_wrapper_in_flat[15] = in_flat[63];
assign const_conditional_wrapper_in_flat[16] = in_flat[64];
assign const_conditional_wrapper_in_flat[17] = in_flat[65];
assign const_conditional_wrapper_in_flat[18] = in_flat[66];
assign const_conditional_wrapper_in_flat[19] = in_flat[67];
assign const_conditional_wrapper_in_flat[20] = in_flat[68];
assign const_conditional_wrapper_in_flat[21] = in_flat[69];
assign const_conditional_wrapper_in_flat[22] = in_flat[70];
assign const_conditional_wrapper_in_flat[23] = in_flat[71];
assign const_conditional_wrapper_in_flat[24] = in_flat[72];
assign const_conditional_wrapper_in_flat[25] = in_flat[73];
assign const_conditional_wrapper_in_flat[26] = in_flat[74];
assign const_conditional_wrapper_in_flat[27] = in_flat[75];
assign const_conditional_wrapper_in_flat[28] = in_flat[76];
assign const_conditional_wrapper_in_flat[29] = in_flat[77];
assign const_conditional_wrapper_in_flat[30] = in_flat[78];
assign const_conditional_wrapper_in_flat[31] = in_flat[79];
assign const_conditional_wrapper_in_flat[32] = in_flat[80];
assign const_conditional_wrapper_in_flat[33] = in_flat[81];
assign const_logic_wrapper_in_flat[0] = in_flat[82];
assign const_logic_wrapper_in_flat[1] = in_flat[83];
assign const_logic_wrapper_in_flat[2] = in_flat[84];
assign const_logic_wrapper_in_flat[3] = in_flat[85];
assign const_logic_wrapper_in_flat[4] = in_flat[86];
assign const_logic_wrapper_in_flat[5] = in_flat[87];
assign const_logic_wrapper_in_flat[6] = in_flat[88];
assign const_logic_wrapper_in_flat[7] = in_flat[89];
assign const_logic_wrapper_in_flat[8] = in_flat[90];
assign const_logic_wrapper_in_flat[9] = in_flat[91];
assign const_nested_wrapper_in_flat[0] = in_flat[92];
assign const_nested_wrapper_in_flat[1] = in_flat[93];
assign const_nested_wrapper_in_flat[2] = in_flat[94];
assign const_nested_wrapper_in_flat[3] = in_flat[95];
assign const_nested_wrapper_in_flat[4] = in_flat[96];
assign const_nested_wrapper_in_flat[5] = in_flat[97];
assign const_nested_wrapper_in_flat[6] = in_flat[98];
assign const_nested_wrapper_in_flat[7] = in_flat[99];
assign const_nested_wrapper_in_flat[8] = in_flat[100];
assign const_nested_wrapper_in_flat[9] = in_flat[101];
assign const_nested_wrapper_in_flat[10] = in_flat[102];
assign const_nested_wrapper_in_flat[11] = in_flat[103];
assign const_nested_wrapper_in_flat[12] = in_flat[104];
assign const_nested_wrapper_in_flat[13] = in_flat[105];
assign const_nested_wrapper_in_flat[14] = in_flat[106];
assign const_nested_wrapper_in_flat[15] = in_flat[107];
assign const_nested_wrapper_in_flat[16] = in_flat[108];
assign const_nested_wrapper_in_flat[17] = in_flat[109];
assign const_nested_wrapper_in_flat[18] = in_flat[110];
assign const_nested_wrapper_in_flat[19] = in_flat[111];
assign const_nested_wrapper_in_flat[20] = in_flat[112];
assign const_nested_wrapper_in_flat[21] = in_flat[113];
assign const_nested_wrapper_in_flat[22] = in_flat[114];
assign const_nested_wrapper_in_flat[23] = in_flat[115];
assign const_nested_wrapper_in_flat[24] = in_flat[116];
assign const_nested_wrapper_in_flat[25] = in_flat[117];
assign const_nested_wrapper_in_flat[26] = in_flat[118];
assign const_partselect_wrapper_in_flat[0] = in_flat[119];
assign const_partselect_wrapper_in_flat[1] = in_flat[120];
assign const_partselect_wrapper_in_flat[2] = in_flat[121];
assign const_partselect_wrapper_in_flat[3] = in_flat[122];
assign const_partselect_wrapper_in_flat[4] = in_flat[123];
assign const_partselect_wrapper_in_flat[5] = in_flat[124];
assign const_partselect_wrapper_in_flat[6] = in_flat[125];
assign const_partselect_wrapper_in_flat[7] = in_flat[126];
assign const_partselect_wrapper_in_flat[8] = in_flat[127];
assign const_partselect_wrapper_in_flat[9] = in_flat[128];
assign const_partselect_wrapper_in_flat[11] = in_flat[129];
assign const_partselect_wrapper_in_flat[12] = in_flat[130];
assign const_partselect_wrapper_in_flat[13] = in_flat[131];
assign const_partselect_wrapper_in_flat[14] = in_flat[132];
assign const_partselect_wrapper_in_flat[15] = in_flat[133];
assign const_partselect_wrapper_in_flat[16] = in_flat[134];
assign const_partselect_wrapper_in_flat[17] = in_flat[135];
assign const_partselect_wrapper_in_flat[18] = in_flat[136];
assign const_partselect_wrapper_in_flat[19] = in_flat[137];
assign const_reduce_wrapper_in_flat[0] = in_flat[138];
assign const_reduce_wrapper_in_flat[1] = in_flat[139];
assign const_reduce_wrapper_in_flat[2] = in_flat[140];
assign const_shift_wrapper_in_flat[0] = in_flat[141];
assign const_shift_wrapper_in_flat[1] = in_flat[142];
assign const_shift_wrapper_in_flat[2] = in_flat[143];
assign const_shift_wrapper_in_flat[4] = in_flat[144];
assign const_shift_wrapper_in_flat[5] = in_flat[145];
assign const_shift_wrapper_in_flat[6] = in_flat[146];
assign const_shift_wrapper_in_flat[7] = in_flat[147];
assign const_shift_wrapper_in_flat[8] = in_flat[148];
assign const_shift_wrapper_in_flat[9] = in_flat[149];
assign const_shift_wrapper_in_flat[10] = in_flat[150];
assign arithmetic_wrapper_in_flat[0] = in_flat[151];
assign arithmetic_reduce_wrapper_in_flat[0] = in_flat[152];
assign arithmetic_reduce_wrapper_in_flat[2] = in_flat[153];
assign arithmetic_reduce_wrapper_in_flat[3] = in_flat[154];
assign arithmetic_reduce_wrapper_in_flat[4] = in_flat[155];
assign arithmetic_reduce_wrapper_in_flat[5] = in_flat[156];
assign arithmetic_reduce_wrapper_in_flat[6] = in_flat[157];
assign arithmetic_reduce_wrapper_in_flat[8] = in_flat[158];
assign arithmetic_reduce_wrapper_in_flat[9] = in_flat[159];
assign arithmetic_reduce_wrapper_in_flat[10] = in_flat[160];
assign arithmetic_reduce_wrapper_in_flat[11] = in_flat[161];
assign arithmetic_reduce_wrapper_in_flat[12] = in_flat[162];
assign arithmetic_reduce_wrapper_in_flat[13] = in_flat[163];
assign arithmetic_reduce_wrapper_in_flat[14] = in_flat[164];
assign arithmetic_reduce_wrapper_in_flat[15] = in_flat[165];
assign bitwise_logic_wrapper_in_flat[0] = in_flat[166];
assign bitwise_logic_wrapper_in_flat[1] = in_flat[167];
assign bitwise_logic_wrapper_in_flat[2] = in_flat[168];
assign bitwise_logic_wrapper_in_flat[3] = in_flat[169];
assign bitwise_logic_wrapper_in_flat[4] = in_flat[170];
assign bitwise_logic_wrapper_in_flat[5] = in_flat[171];
assign bitwise_logic_wrapper_in_flat[6] = in_flat[172];
assign bitwise_logic_wrapper_in_flat[7] = in_flat[173];
assign bitwise_logic_wrapper_in_flat[8] = in_flat[174];
assign bitwise_logic_wrapper_in_flat[10] = in_flat[175];
assign bitwise_logic_wrapper_in_flat[11] = in_flat[176];
assign bitwise_logic_wrapper_in_flat[12] = in_flat[177];
assign bitwise_logic_wrapper_in_flat[13] = in_flat[178];
assign bitwise_logic_wrapper_in_flat[14] = in_flat[179];
assign bitwise_logic_wrapper_in_flat[15] = in_flat[180];
assign bitwise_reduce_wrapper_in_flat[0] = in_flat[181];
assign bitwise_reduce_wrapper_in_flat[1] = in_flat[182];
assign bitwise_reduce_wrapper_in_flat[2] = in_flat[183];
assign bitwise_reduce_wrapper_in_flat[3] = in_flat[184];
assign bitwise_reduce_wrapper_in_flat[4] = in_flat[185];
assign bitwise_reduce_wrapper_in_flat[5] = in_flat[186];
assign bitwise_reduce_wrapper_in_flat[6] = in_flat[187];
assign bitwise_reduce_wrapper_in_flat[7] = in_flat[188];
assign concat_repl_wrapper_in_flat[0] = in_flat[189];
assign concat_repl_wrapper_in_flat[1] = in_flat[190];
assign concat_repl_wrapper_in_flat[2] = in_flat[191];
assign concat_repl_wrapper_in_flat[3] = in_flat[192];
assign concat_repl_wrapper_in_flat[4] = in_flat[193];
assign concat_repl_wrapper_in_flat[5] = in_flat[194];
assign constant_wrapper_in_flat[0] = in_flat[195];
assign logical_op_wrapper_in_flat[0] = in_flat[196];
assign logical_op_wrapper_in_flat[1] = in_flat[197];
assign reduce_case_wrapper_in_flat[0] = in_flat[198];
assign reduce_case_wrapper_in_flat[1] = in_flat[199];
assign reduce_case_wrapper_in_flat[2] = in_flat[200];
assign reduce_case_wrapper_in_flat[3] = in_flat[201];
assign reduce_case_wrapper_in_flat[4] = in_flat[202];
assign reduce_case_wrapper_in_flat[5] = in_flat[203];
assign reduce_case_wrapper_in_flat[6] = in_flat[204];
assign reduce_case_wrapper_in_flat[7] = in_flat[205];
assign relational_wrapper_in_flat[0] = in_flat[206];
assign relational_wrapper_in_flat[1] = in_flat[207];
assign relational_wrapper_in_flat[2] = in_flat[208];
assign relational_wrapper_in_flat[3] = in_flat[209];
assign relational_wrapper_in_flat[4] = in_flat[210];
assign relational_wrapper_in_flat[5] = in_flat[211];
assign relational_wrapper_in_flat[6] = in_flat[212];
assign relational_wrapper_in_flat[7] = in_flat[213];
assign select_wrapper_in_flat[0] = in_flat[214];
assign select_wrapper_in_flat[1] = in_flat[215];
assign select_wrapper_in_flat[2] = in_flat[216];
assign select_wrapper_in_flat[3] = in_flat[217];
assign select_wrapper_in_flat[4] = in_flat[218];
assign select_wrapper_in_flat[5] = in_flat[219];
assign select_wrapper_in_flat[6] = in_flat[220];
assign select_wrapper_in_flat[7] = in_flat[221];
assign select_wrapper_in_flat[8] = in_flat[222];
assign select_wrapper_in_flat[9] = in_flat[223];
assign select_wrapper_in_flat[10] = in_flat[224];
assign select_wrapper_in_flat[11] = in_flat[225];
assign select_wrapper_in_flat[12] = in_flat[226];
assign select_wrapper_in_flat[13] = in_flat[227];
assign select_wrapper_in_flat[14] = in_flat[228];
assign select_wrapper_in_flat[15] = in_flat[229];
assign select_wrapper_in_flat[16] = in_flat[230];
assign select_wrapper_in_flat[17] = in_flat[231];
assign select_wrapper_in_flat[18] = in_flat[232];
assign select_wrapper_in_flat[19] = in_flat[233];
assign shift_wrapper_in_flat[0] = in_flat[234];
assign shift_wrapper_in_flat[1] = in_flat[235];
assign shift_wrapper_in_flat[2] = in_flat[236];
assign shift_wrapper_in_flat[3] = in_flat[237];
assign shift_wrapper_in_flat[4] = in_flat[238];
assign shift_wrapper_in_flat[5] = in_flat[239];
assign shift_wrapper_in_flat[6] = in_flat[240];
assign shift_wrapper_in_flat[7] = in_flat[241];
assign shift_wrapper_in_flat[8] = in_flat[242];
assign shift_wrapper_in_flat[9] = in_flat[243];
assign shift_wrapper_in_flat[10] = in_flat[244];
assign array_wrapper_in_flat[0] = in_flat[245];
assign array_wrapper_in_flat[1] = in_flat[246];
assign array_wrapper_in_flat[2] = in_flat[247];
assign array_wrapper_in_flat[3] = in_flat[248];
assign array_wrapper_in_flat[4] = in_flat[249];
assign array_wrapper_in_flat[5] = in_flat[250];
assign array_wrapper_in_flat[6] = in_flat[251];
assign array_wrapper_in_flat[7] = in_flat[252];
assign array_wrapper_in_flat[8] = in_flat[253];
assign array_wrapper_in_flat[9] = in_flat[254];
assign array_wrapper_in_flat[10] = in_flat[255];
assign array_wrapper_in_flat[11] = in_flat[256];
assign array_wrapper_in_flat[12] = in_flat[257];
assign array_wrapper_in_flat[13] = in_flat[258];
assign array_wrapper_in_flat[14] = in_flat[259];
assign array_wrapper_in_flat[15] = in_flat[260];
assign array_wrapper_in_flat[16] = in_flat[261];
assign array_wrapper_in_flat[17] = in_flat[262];
assign cast_wrapper_in_flat[0] = in_flat[263];
assign cast_wrapper_in_flat[1] = in_flat[264];
assign cast_wrapper_in_flat[2] = in_flat[265];
assign cast_wrapper_in_flat[3] = in_flat[266];
assign cast_wrapper_in_flat[4] = in_flat[267];
assign cast_wrapper_in_flat[5] = in_flat[268];
assign cast_wrapper_in_flat[6] = in_flat[269];
assign cast_wrapper_in_flat[7] = in_flat[270];
assign cast_wrapper_in_flat[8] = in_flat[271];
assign cast_wrapper_in_flat[9] = in_flat[272];
assign cast_wrapper_in_flat[10] = in_flat[273];
assign cast_wrapper_in_flat[11] = in_flat[274];
assign conditional_wrapper_in_flat[0] = in_flat[275];
assign conditional_wrapper_in_flat[1] = in_flat[276];
assign conditional_wrapper_in_flat[2] = in_flat[277];
assign conditional_wrapper_in_flat[3] = in_flat[278];
assign conditional_wrapper_in_flat[4] = in_flat[279];
assign conditional_wrapper_in_flat[5] = in_flat[280];
assign conditional_wrapper_in_flat[6] = in_flat[281];
assign conditional_wrapper_in_flat[7] = in_flat[282];
assign conditional_wrapper_in_flat[8] = in_flat[283];
assign param_wrapper_in_flat[0] = in_flat[284];
assign partselect_wrapper_in_flat[0] = in_flat[285];
assign partselect_wrapper_in_flat[1] = in_flat[286];
assign partselect_wrapper_in_flat[2] = in_flat[287];
assign partselect_wrapper_in_flat[3] = in_flat[288];
assign partselect_wrapper_in_flat[4] = in_flat[289];
assign partselect_wrapper_in_flat[5] = in_flat[290];
assign partselect_wrapper_in_flat[6] = in_flat[291];
assign partselect_wrapper_in_flat[7] = in_flat[292];
assign partselect_wrapper_in_flat[8] = in_flat[293];
assign partselect_wrapper_in_flat[9] = in_flat[294];
assign partselect_wrapper_in_flat[10] = in_flat[295];
assign partselect_wrapper_in_flat[11] = in_flat[296];
assign partselect_wrapper_in_flat[12] = in_flat[297];
assign partselect_wrapper_in_flat[13] = in_flat[298];
assign partselect_wrapper_in_flat[14] = in_flat[299];
assign partselect_wrapper_in_flat[15] = in_flat[300];
assign partselect_wrapper_in_flat[16] = in_flat[301];
assign partselect_wrapper_in_flat[17] = in_flat[302];
assign partselect_wrapper_in_flat[18] = in_flat[303];
assign width_enum_wrapper_in_flat[0] = in_flat[304];
assign width_enum_wrapper_in_flat[1] = in_flat[305];
assign width_enum_wrapper_in_flat[2] = in_flat[306];
assign width_enum_wrapper_in_flat[3] = in_flat[307];
assign width_struct_wrapper_in_flat[0] = in_flat[308];
assign width_struct_wrapper_in_flat[1] = in_flat[309];
assign width_struct_wrapper_in_flat[2] = in_flat[310];
assign width_struct_wrapper_in_flat[3] = in_flat[311];
assign width_struct_wrapper_in_flat[4] = in_flat[312];
assign width_struct_wrapper_in_flat[5] = in_flat[313];
assign width_struct_wrapper_in_flat[6] = in_flat[314];
assign width_struct_wrapper_in_flat[7] = in_flat[315];
assign width_struct_wrapper_in_flat[8] = in_flat[316];
assign width_struct_wrapper_in_flat[9] = in_flat[317];
assign width_struct_wrapper_in_flat[10] = in_flat[318];
assign width_struct_wrapper_in_flat[11] = in_flat[319];
assign width_union_wrapper_in_flat[0] = in_flat[320];
assign width_union_wrapper_in_flat[1] = in_flat[321];
assign width_union_wrapper_in_flat[2] = in_flat[322];
assign width_union_wrapper_in_flat[3] = in_flat[323];
assign width_union_wrapper_in_flat[4] = in_flat[324];
assign width_union_wrapper_in_flat[5] = in_flat[325];
assign width_union_wrapper_in_flat[6] = in_flat[326];
assign width_union_wrapper_in_flat[7] = in_flat[327];
assign width_union_wrapper_in_flat[8] = in_flat[328];
assign width_union_wrapper_in_flat[9] = in_flat[329];
assign width_union_wrapper_in_flat[11] = in_flat[330];
assign width_union_wrapper_in_flat[12] = in_flat[331];
assign width_union_wrapper_in_flat[13] = in_flat[332];
assign width_union_wrapper_in_flat[14] = in_flat[333];
assign width_union_wrapper_in_flat[15] = in_flat[334];
assign width_logic_wrapper_in_flat[0] = in_flat[335];
assign width_logic_wrapper_in_flat[1] = in_flat[336];
assign width_logic_wrapper_in_flat[2] = in_flat[337];
assign width_logic_wrapper_in_flat[3] = in_flat[338];
assign width_logic_wrapper_in_flat[4] = in_flat[339];
assign width_logic_wrapper_in_flat[5] = in_flat[340];
assign width_logic_wrapper_in_flat[6] = in_flat[341];
assign width_logic_wrapper_in_flat[7] = in_flat[342];

// Internal MTM connections (module-to-module)
assign const_compare_wrapper_in_flat[6] = const_arith_wrapper_out_flat[36];
assign const_compare_wrapper_in_flat[20] = const_logic_wrapper_out_flat[1];
assign arith_wrapper_in_flat[0] = const_reduce_wrapper_out_flat[5];
assign width_union_wrapper_in_flat[10] = const_shift_wrapper_out_flat[14];
assign arithmetic_reduce_wrapper_in_flat[1] = bitwise_logic_wrapper_out_flat[0];
assign bitwise_logic_wrapper_in_flat[9] = concat_repl_wrapper_out_flat[13];
assign arithmetic_reduce_wrapper_in_flat[7] = constant_wrapper_out_flat[5];
assign const_partselect_wrapper_in_flat[10] = constant_wrapper_out_flat[22];
assign const_reduce_wrapper_in_flat[3] = constant_wrapper_out_flat[74];
assign const_shift_wrapper_in_flat[3] = width_struct_wrapper_out_flat[9];

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
assign out_flat[159] = arithmetic_wrapper_out_flat[0];
assign out_flat[160] = arithmetic_reduce_wrapper_out_flat[0];
assign out_flat[161] = arithmetic_reduce_wrapper_out_flat[1];
assign out_flat[162] = arithmetic_reduce_wrapper_out_flat[2];
assign out_flat[163] = arithmetic_reduce_wrapper_out_flat[3];
assign out_flat[164] = arithmetic_reduce_wrapper_out_flat[4];
assign out_flat[165] = arithmetic_reduce_wrapper_out_flat[5];
assign out_flat[166] = arithmetic_reduce_wrapper_out_flat[6];
assign out_flat[167] = arithmetic_reduce_wrapper_out_flat[7];
assign out_flat[168] = arithmetic_reduce_wrapper_out_flat[8];
assign out_flat[169] = arithmetic_reduce_wrapper_out_flat[9];
assign out_flat[170] = bitwise_logic_wrapper_out_flat[0];
assign out_flat[171] = bitwise_logic_wrapper_out_flat[1];
assign out_flat[172] = bitwise_logic_wrapper_out_flat[2];
assign out_flat[173] = bitwise_logic_wrapper_out_flat[3];
assign out_flat[174] = bitwise_logic_wrapper_out_flat[4];
assign out_flat[175] = bitwise_logic_wrapper_out_flat[5];
assign out_flat[176] = bitwise_logic_wrapper_out_flat[6];
assign out_flat[177] = bitwise_logic_wrapper_out_flat[7];
assign out_flat[178] = bitwise_logic_wrapper_out_flat[8];
assign out_flat[179] = bitwise_logic_wrapper_out_flat[9];
assign out_flat[180] = bitwise_logic_wrapper_out_flat[10];
assign out_flat[181] = bitwise_logic_wrapper_out_flat[11];
assign out_flat[182] = bitwise_logic_wrapper_out_flat[12];
assign out_flat[183] = bitwise_logic_wrapper_out_flat[13];
assign out_flat[184] = bitwise_logic_wrapper_out_flat[14];
assign out_flat[185] = bitwise_logic_wrapper_out_flat[15];
assign out_flat[186] = bitwise_logic_wrapper_out_flat[16];
assign out_flat[187] = bitwise_logic_wrapper_out_flat[17];
assign out_flat[188] = bitwise_logic_wrapper_out_flat[18];
assign out_flat[189] = bitwise_logic_wrapper_out_flat[19];
assign out_flat[190] = bitwise_logic_wrapper_out_flat[20];
assign out_flat[191] = bitwise_logic_wrapper_out_flat[21];
assign out_flat[192] = bitwise_logic_wrapper_out_flat[22];
assign out_flat[193] = bitwise_logic_wrapper_out_flat[23];
assign out_flat[194] = bitwise_reduce_wrapper_out_flat[0];
assign out_flat[195] = bitwise_reduce_wrapper_out_flat[1];
assign out_flat[196] = bitwise_reduce_wrapper_out_flat[2];
assign out_flat[197] = concat_repl_wrapper_out_flat[0];
assign out_flat[198] = concat_repl_wrapper_out_flat[1];
assign out_flat[199] = concat_repl_wrapper_out_flat[2];
assign out_flat[200] = concat_repl_wrapper_out_flat[3];
assign out_flat[201] = concat_repl_wrapper_out_flat[4];
assign out_flat[202] = concat_repl_wrapper_out_flat[5];
assign out_flat[203] = concat_repl_wrapper_out_flat[6];
assign out_flat[204] = concat_repl_wrapper_out_flat[7];
assign out_flat[205] = concat_repl_wrapper_out_flat[8];
assign out_flat[206] = concat_repl_wrapper_out_flat[9];
assign out_flat[207] = concat_repl_wrapper_out_flat[10];
assign out_flat[208] = concat_repl_wrapper_out_flat[11];
assign out_flat[209] = concat_repl_wrapper_out_flat[12];
assign out_flat[210] = concat_repl_wrapper_out_flat[13];
assign out_flat[211] = concat_repl_wrapper_out_flat[14];
assign out_flat[212] = concat_repl_wrapper_out_flat[15];
assign out_flat[213] = concat_repl_wrapper_out_flat[16];
assign out_flat[214] = concat_repl_wrapper_out_flat[17];
assign out_flat[215] = constant_wrapper_out_flat[0];
assign out_flat[216] = constant_wrapper_out_flat[1];
assign out_flat[217] = constant_wrapper_out_flat[2];
assign out_flat[218] = constant_wrapper_out_flat[3];
assign out_flat[219] = constant_wrapper_out_flat[4];
assign out_flat[220] = constant_wrapper_out_flat[5];
assign out_flat[221] = constant_wrapper_out_flat[6];
assign out_flat[222] = constant_wrapper_out_flat[7];
assign out_flat[223] = constant_wrapper_out_flat[8];
assign out_flat[224] = constant_wrapper_out_flat[9];
assign out_flat[225] = constant_wrapper_out_flat[10];
assign out_flat[226] = constant_wrapper_out_flat[11];
assign out_flat[227] = constant_wrapper_out_flat[12];
assign out_flat[228] = constant_wrapper_out_flat[13];
assign out_flat[229] = constant_wrapper_out_flat[14];
assign out_flat[230] = constant_wrapper_out_flat[15];
assign out_flat[231] = constant_wrapper_out_flat[16];
assign out_flat[232] = constant_wrapper_out_flat[17];
assign out_flat[233] = constant_wrapper_out_flat[18];
assign out_flat[234] = constant_wrapper_out_flat[19];
assign out_flat[235] = constant_wrapper_out_flat[20];
assign out_flat[236] = constant_wrapper_out_flat[21];
assign out_flat[237] = constant_wrapper_out_flat[22];
assign out_flat[238] = constant_wrapper_out_flat[23];
assign out_flat[239] = constant_wrapper_out_flat[24];
assign out_flat[240] = constant_wrapper_out_flat[25];
assign out_flat[241] = constant_wrapper_out_flat[26];
assign out_flat[242] = constant_wrapper_out_flat[27];
assign out_flat[243] = constant_wrapper_out_flat[28];
assign out_flat[244] = constant_wrapper_out_flat[29];
assign out_flat[245] = constant_wrapper_out_flat[30];
assign out_flat[246] = constant_wrapper_out_flat[31];
assign out_flat[247] = constant_wrapper_out_flat[32];
assign out_flat[248] = constant_wrapper_out_flat[33];
assign out_flat[249] = constant_wrapper_out_flat[34];
assign out_flat[250] = constant_wrapper_out_flat[35];
assign out_flat[251] = constant_wrapper_out_flat[36];
assign out_flat[252] = constant_wrapper_out_flat[37];
assign out_flat[253] = constant_wrapper_out_flat[38];
assign out_flat[254] = constant_wrapper_out_flat[39];
assign out_flat[255] = constant_wrapper_out_flat[40];
assign out_flat[256] = constant_wrapper_out_flat[41];
assign out_flat[257] = constant_wrapper_out_flat[42];
assign out_flat[258] = constant_wrapper_out_flat[43];
assign out_flat[259] = constant_wrapper_out_flat[44];
assign out_flat[260] = constant_wrapper_out_flat[45];
assign out_flat[261] = constant_wrapper_out_flat[46];
assign out_flat[262] = constant_wrapper_out_flat[47];
assign out_flat[263] = constant_wrapper_out_flat[48];
assign out_flat[264] = constant_wrapper_out_flat[49];
assign out_flat[265] = constant_wrapper_out_flat[50];
assign out_flat[266] = constant_wrapper_out_flat[51];
assign out_flat[267] = constant_wrapper_out_flat[52];
assign out_flat[268] = constant_wrapper_out_flat[53];
assign out_flat[269] = constant_wrapper_out_flat[54];
assign out_flat[270] = constant_wrapper_out_flat[55];
assign out_flat[271] = constant_wrapper_out_flat[56];
assign out_flat[272] = constant_wrapper_out_flat[57];
assign out_flat[273] = constant_wrapper_out_flat[58];
assign out_flat[274] = constant_wrapper_out_flat[59];
assign out_flat[275] = constant_wrapper_out_flat[60];
assign out_flat[276] = constant_wrapper_out_flat[61];
assign out_flat[277] = constant_wrapper_out_flat[62];
assign out_flat[278] = constant_wrapper_out_flat[63];
assign out_flat[279] = constant_wrapper_out_flat[64];
assign out_flat[280] = constant_wrapper_out_flat[65];
assign out_flat[281] = constant_wrapper_out_flat[66];
assign out_flat[282] = constant_wrapper_out_flat[67];
assign out_flat[283] = constant_wrapper_out_flat[68];
assign out_flat[284] = constant_wrapper_out_flat[69];
assign out_flat[285] = constant_wrapper_out_flat[70];
assign out_flat[286] = constant_wrapper_out_flat[71];
assign out_flat[287] = constant_wrapper_out_flat[72];
assign out_flat[288] = constant_wrapper_out_flat[73];
assign out_flat[289] = constant_wrapper_out_flat[74];
assign out_flat[290] = constant_wrapper_out_flat[75];
assign out_flat[291] = constant_wrapper_out_flat[76];
assign out_flat[292] = constant_wrapper_out_flat[77];
assign out_flat[293] = constant_wrapper_out_flat[78];
assign out_flat[294] = constant_wrapper_out_flat[79];
assign out_flat[295] = logical_op_wrapper_out_flat[0];
assign out_flat[296] = logical_op_wrapper_out_flat[1];
assign out_flat[297] = logical_op_wrapper_out_flat[2];
assign out_flat[298] = reduce_case_wrapper_out_flat[0];
assign out_flat[299] = reduce_case_wrapper_out_flat[1];
assign out_flat[300] = relational_wrapper_out_flat[0];
assign out_flat[301] = relational_wrapper_out_flat[1];
assign out_flat[302] = relational_wrapper_out_flat[2];
assign out_flat[303] = relational_wrapper_out_flat[3];
assign out_flat[304] = relational_wrapper_out_flat[4];
assign out_flat[305] = relational_wrapper_out_flat[5];
assign out_flat[306] = relational_wrapper_out_flat[6];
assign out_flat[307] = relational_wrapper_out_flat[7];
assign out_flat[308] = select_wrapper_out_flat[0];
assign out_flat[309] = select_wrapper_out_flat[1];
assign out_flat[310] = select_wrapper_out_flat[2];
assign out_flat[311] = select_wrapper_out_flat[3];
assign out_flat[312] = select_wrapper_out_flat[4];
assign out_flat[313] = select_wrapper_out_flat[5];
assign out_flat[314] = select_wrapper_out_flat[6];
assign out_flat[315] = select_wrapper_out_flat[7];
assign out_flat[316] = select_wrapper_out_flat[8];
assign out_flat[317] = shift_wrapper_out_flat[0];
assign out_flat[318] = shift_wrapper_out_flat[1];
assign out_flat[319] = shift_wrapper_out_flat[2];
assign out_flat[320] = shift_wrapper_out_flat[3];
assign out_flat[321] = shift_wrapper_out_flat[4];
assign out_flat[322] = shift_wrapper_out_flat[5];
assign out_flat[323] = shift_wrapper_out_flat[6];
assign out_flat[324] = shift_wrapper_out_flat[7];
assign out_flat[325] = shift_wrapper_out_flat[8];
assign out_flat[326] = shift_wrapper_out_flat[9];
assign out_flat[327] = shift_wrapper_out_flat[10];
assign out_flat[328] = shift_wrapper_out_flat[11];
assign out_flat[329] = shift_wrapper_out_flat[12];
assign out_flat[330] = shift_wrapper_out_flat[13];
assign out_flat[331] = shift_wrapper_out_flat[14];
assign out_flat[332] = shift_wrapper_out_flat[15];
assign out_flat[333] = arith_wrapper_out_flat[0];
assign out_flat[334] = array_wrapper_out_flat[0];
assign out_flat[335] = array_wrapper_out_flat[1];
assign out_flat[336] = array_wrapper_out_flat[2];
assign out_flat[337] = array_wrapper_out_flat[3];
assign out_flat[338] = array_wrapper_out_flat[4];
assign out_flat[339] = array_wrapper_out_flat[5];
assign out_flat[340] = array_wrapper_out_flat[6];
assign out_flat[341] = array_wrapper_out_flat[7];
assign out_flat[342] = array_wrapper_out_flat[8];
assign out_flat[343] = array_wrapper_out_flat[9];
assign out_flat[344] = array_wrapper_out_flat[10];
assign out_flat[345] = array_wrapper_out_flat[11];
assign out_flat[346] = array_wrapper_out_flat[12];
assign out_flat[347] = array_wrapper_out_flat[13];
assign out_flat[348] = array_wrapper_out_flat[14];
assign out_flat[349] = array_wrapper_out_flat[15];
assign out_flat[350] = cast_wrapper_out_flat[0];
assign out_flat[351] = cast_wrapper_out_flat[1];
assign out_flat[352] = cast_wrapper_out_flat[2];
assign out_flat[353] = cast_wrapper_out_flat[3];
assign out_flat[354] = cast_wrapper_out_flat[4];
assign out_flat[355] = cast_wrapper_out_flat[5];
assign out_flat[356] = cast_wrapper_out_flat[6];
assign out_flat[357] = cast_wrapper_out_flat[7];
assign out_flat[358] = cast_wrapper_out_flat[8];
assign out_flat[359] = cast_wrapper_out_flat[9];
assign out_flat[360] = cast_wrapper_out_flat[10];
assign out_flat[361] = cast_wrapper_out_flat[11];
assign out_flat[362] = conditional_wrapper_out_flat[0];
assign out_flat[363] = conditional_wrapper_out_flat[1];
assign out_flat[364] = conditional_wrapper_out_flat[2];
assign out_flat[365] = conditional_wrapper_out_flat[3];
assign out_flat[366] = param_wrapper_out_flat[0];
assign out_flat[367] = partselect_wrapper_out_flat[0];
assign out_flat[368] = partselect_wrapper_out_flat[1];
assign out_flat[369] = partselect_wrapper_out_flat[2];
assign out_flat[370] = partselect_wrapper_out_flat[3];
assign out_flat[371] = partselect_wrapper_out_flat[4];
assign out_flat[372] = partselect_wrapper_out_flat[5];
assign out_flat[373] = partselect_wrapper_out_flat[6];
assign out_flat[374] = partselect_wrapper_out_flat[7];
assign out_flat[375] = partselect_wrapper_out_flat[8];
assign out_flat[376] = width_enum_wrapper_out_flat[0];
assign out_flat[377] = width_enum_wrapper_out_flat[1];
assign out_flat[378] = width_enum_wrapper_out_flat[2];
assign out_flat[379] = width_enum_wrapper_out_flat[3];
assign out_flat[380] = width_enum_wrapper_out_flat[4];
assign out_flat[381] = width_struct_wrapper_out_flat[0];
assign out_flat[382] = width_struct_wrapper_out_flat[1];
assign out_flat[383] = width_struct_wrapper_out_flat[2];
assign out_flat[384] = width_struct_wrapper_out_flat[3];
assign out_flat[385] = width_struct_wrapper_out_flat[4];
assign out_flat[386] = width_struct_wrapper_out_flat[5];
assign out_flat[387] = width_struct_wrapper_out_flat[6];
assign out_flat[388] = width_struct_wrapper_out_flat[7];
assign out_flat[389] = width_struct_wrapper_out_flat[8];
assign out_flat[390] = width_struct_wrapper_out_flat[9];
assign out_flat[391] = width_struct_wrapper_out_flat[10];
assign out_flat[392] = width_struct_wrapper_out_flat[11];
assign out_flat[393] = width_union_wrapper_out_flat[0];
assign out_flat[394] = width_union_wrapper_out_flat[1];
assign out_flat[395] = width_union_wrapper_out_flat[2];
assign out_flat[396] = width_union_wrapper_out_flat[3];
assign out_flat[397] = width_union_wrapper_out_flat[4];
assign out_flat[398] = width_union_wrapper_out_flat[5];
assign out_flat[399] = width_union_wrapper_out_flat[6];
assign out_flat[400] = width_union_wrapper_out_flat[7];
assign out_flat[401] = width_union_wrapper_out_flat[8];
assign out_flat[402] = width_union_wrapper_out_flat[9];
assign out_flat[403] = width_union_wrapper_out_flat[10];
assign out_flat[404] = width_union_wrapper_out_flat[11];
assign out_flat[405] = width_union_wrapper_out_flat[12];
assign out_flat[406] = width_union_wrapper_out_flat[13];
assign out_flat[407] = width_union_wrapper_out_flat[14];
assign out_flat[408] = width_union_wrapper_out_flat[15];
assign out_flat[409] = width_logic_wrapper_out_flat[0];
assign out_flat[410] = width_logic_wrapper_out_flat[1];
assign out_flat[411] = width_logic_wrapper_out_flat[2];
assign out_flat[412] = width_logic_wrapper_out_flat[3];
assign out_flat[413] = width_logic_wrapper_out_flat[4];
assign out_flat[414] = width_logic_wrapper_out_flat[5];

// Instantiate all module wrappers
arith_wrapper u_arith_wrapper (
    .in_flat(arith_wrapper_in_flat),
    .out_flat(arith_wrapper_out_flat)
);
arithmetic_reduce_wrapper u_arithmetic_reduce_wrapper (
    .in_flat(arithmetic_reduce_wrapper_in_flat),
    .out_flat(arithmetic_reduce_wrapper_out_flat)
);
arithmetic_wrapper u_arithmetic_wrapper (
    .in_flat(arithmetic_wrapper_in_flat),
    .out_flat(arithmetic_wrapper_out_flat)
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
concat_repl_wrapper u_concat_repl_wrapper (
    .in_flat(concat_repl_wrapper_in_flat),
    .out_flat(concat_repl_wrapper_out_flat)
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
constant_wrapper u_constant_wrapper (
    .in_flat(constant_wrapper_in_flat),
    .out_flat(constant_wrapper_out_flat)
);
logical_op_wrapper u_logical_op_wrapper (
    .in_flat(logical_op_wrapper_in_flat),
    .out_flat(logical_op_wrapper_out_flat)
);
param_wrapper u_param_wrapper (
    .in_flat(param_wrapper_in_flat),
    .out_flat(param_wrapper_out_flat)
);
partselect_wrapper u_partselect_wrapper (
    .in_flat(partselect_wrapper_in_flat),
    .out_flat(partselect_wrapper_out_flat)
);
reduce_case_wrapper u_reduce_case_wrapper (
    .in_flat(reduce_case_wrapper_in_flat),
    .out_flat(reduce_case_wrapper_out_flat)
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