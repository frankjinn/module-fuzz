// Auto-generated Top Module for flattened IO
`include "adder.sv"
`include "adder_wrapper.sv"
`include "multiplier.sv"
`include "multiplier_wrapper.sv"
`include "subtractor.sv"
`include "subtractor_wrapper.sv"

module top (
    input  wire clk,
    input  wire [22:0] in_flat,
    output wire [21:0] out_flat
);

// Per-module I/O buses
wire [3:0] adder_in_flat;
wire [2:0] adder_out_flat;
wire [3:0] adder_wrapper_in_flat;
wire [2:0] adder_wrapper_out_flat;
wire [3:0] multiplier_in_flat;
wire [4:0] multiplier_out_flat;
wire [3:0] multiplier_wrapper_in_flat;
wire [4:0] multiplier_wrapper_out_flat;
wire [3:0] subtractor_in_flat;
wire [2:0] subtractor_out_flat;
wire [3:0] subtractor_wrapper_in_flat;
wire [2:0] subtractor_wrapper_out_flat;

// External inputs to module inputs
assign adder_wrapper_in_flat[0] = in_flat[0];
assign adder_wrapper_in_flat[2] = in_flat[1];
assign adder_wrapper_in_flat[3] = in_flat[2];
assign subtractor_wrapper_in_flat[0] = in_flat[3];
assign subtractor_wrapper_in_flat[1] = in_flat[4];
assign subtractor_wrapper_in_flat[2] = in_flat[5];
assign subtractor_wrapper_in_flat[3] = in_flat[6];
assign multiplier_in_flat[0] = in_flat[7];
assign multiplier_in_flat[1] = in_flat[8];
assign multiplier_in_flat[2] = in_flat[9];
assign multiplier_in_flat[3] = in_flat[10];
assign subtractor_in_flat[0] = in_flat[11];
assign subtractor_in_flat[1] = in_flat[12];
assign subtractor_in_flat[2] = in_flat[13];
assign subtractor_in_flat[3] = in_flat[14];
assign adder_in_flat[0] = in_flat[15];
assign adder_in_flat[1] = in_flat[16];
assign adder_in_flat[2] = in_flat[17];
assign adder_in_flat[3] = in_flat[18];
assign multiplier_wrapper_in_flat[0] = in_flat[19];
assign multiplier_wrapper_in_flat[1] = in_flat[20];
assign multiplier_wrapper_in_flat[2] = in_flat[21];
assign multiplier_wrapper_in_flat[3] = in_flat[22];

// Internal MTM connections (module-to-module)
assign adder_wrapper_in_flat[1] = multiplier_out_flat[1];

// External outputs (MTO + MTM wires)
assign out_flat[0] = adder_wrapper_out_flat[0];
assign out_flat[1] = adder_wrapper_out_flat[1];
assign out_flat[2] = adder_wrapper_out_flat[2];
assign out_flat[3] = subtractor_wrapper_out_flat[0];
assign out_flat[4] = subtractor_wrapper_out_flat[1];
assign out_flat[5] = subtractor_wrapper_out_flat[2];
assign out_flat[6] = multiplier_out_flat[0];
assign out_flat[7] = multiplier_out_flat[1];
assign out_flat[8] = multiplier_out_flat[2];
assign out_flat[9] = multiplier_out_flat[3];
assign out_flat[10] = multiplier_out_flat[4];
assign out_flat[11] = subtractor_out_flat[0];
assign out_flat[12] = subtractor_out_flat[1];
assign out_flat[13] = subtractor_out_flat[2];
assign out_flat[14] = adder_out_flat[0];
assign out_flat[15] = adder_out_flat[1];
assign out_flat[16] = adder_out_flat[2];
assign out_flat[17] = multiplier_wrapper_out_flat[0];
assign out_flat[18] = multiplier_wrapper_out_flat[1];
assign out_flat[19] = multiplier_wrapper_out_flat[2];
assign out_flat[20] = multiplier_wrapper_out_flat[3];
assign out_flat[21] = multiplier_wrapper_out_flat[4];

// Instantiate all module wrappers
adder u_adder (
    .in_flat(adder_in_flat),
    .out_flat(adder_out_flat)
);
adder_wrapper u_adder_wrapper (
    .in_flat(adder_wrapper_in_flat),
    .out_flat(adder_wrapper_out_flat)
);
multiplier u_multiplier (
    .in_flat(multiplier_in_flat),
    .out_flat(multiplier_out_flat)
);
multiplier_wrapper u_multiplier_wrapper (
    .in_flat(multiplier_wrapper_in_flat),
    .out_flat(multiplier_wrapper_out_flat)
);
subtractor u_subtractor (
    .in_flat(subtractor_in_flat),
    .out_flat(subtractor_out_flat)
);
subtractor_wrapper u_subtractor_wrapper (
    .in_flat(subtractor_wrapper_in_flat),
    .out_flat(subtractor_wrapper_out_flat)
);
endmodule