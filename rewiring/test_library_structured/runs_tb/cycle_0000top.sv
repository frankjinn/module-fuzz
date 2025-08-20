// Auto-generated Top Module for flattened IO
`include "adder_wrapper.sv"
`include "multiplier_wrapper.sv"
`include "subtractor_wrapper.sv"

module top (
    input  wire clk,
    input  wire [8:0] in_flat,
    output wire [10:0] out_flat
);

// Per-module I/O buses
wire [3:0] adder_wrapper_in_flat;
wire [2:0] adder_wrapper_out_flat;
wire [3:0] multiplier_wrapper_in_flat;
wire [4:0] multiplier_wrapper_out_flat;
wire [3:0] subtractor_wrapper_in_flat;
wire [2:0] subtractor_wrapper_out_flat;

// Registered output shadows for looped modules
reg [4:0] multiplier_wrapper_out_reg;
always @(posedge clk) multiplier_wrapper_out_reg <= multiplier_wrapper_out_flat;

// Initialize registered outputs to zero for simulation
initial begin
    multiplier_wrapper_out_reg = 5'b0;
end

// External inputs to module inputs
assign adder_wrapper_in_flat[0] = in_flat[0];
assign adder_wrapper_in_flat[1] = in_flat[1];
assign adder_wrapper_in_flat[2] = in_flat[2];
assign adder_wrapper_in_flat[3] = in_flat[3];
assign subtractor_wrapper_in_flat[1] = in_flat[4];
assign subtractor_wrapper_in_flat[2] = in_flat[5];
assign multiplier_wrapper_in_flat[1] = in_flat[6];
assign multiplier_wrapper_in_flat[2] = in_flat[7];
assign multiplier_wrapper_in_flat[3] = in_flat[8];

// Internal MTM connections (module-to-module)
assign subtractor_wrapper_in_flat[3] = adder_wrapper_out_flat[2];
assign multiplier_wrapper_in_flat[0] = subtractor_wrapper_out_flat[1];
assign subtractor_wrapper_in_flat[0] = multiplier_wrapper_out_reg[0];

// External outputs (MTO + MTM wires)
assign out_flat[0] = adder_wrapper_out_flat[0];
assign out_flat[1] = adder_wrapper_out_flat[1];
assign out_flat[2] = adder_wrapper_out_flat[2];
assign out_flat[3] = subtractor_wrapper_out_flat[0];
assign out_flat[4] = subtractor_wrapper_out_flat[1];
assign out_flat[5] = subtractor_wrapper_out_flat[2];
assign out_flat[6] = multiplier_wrapper_out_reg[0];
assign out_flat[7] = multiplier_wrapper_out_reg[1];
assign out_flat[8] = multiplier_wrapper_out_reg[2];
assign out_flat[9] = multiplier_wrapper_out_reg[3];
assign out_flat[10] = multiplier_wrapper_out_reg[4];

// Instantiate all module wrappers
adder_wrapper u_adder_wrapper (
    .in_flat(adder_wrapper_in_flat),
    .out_flat(adder_wrapper_out_flat)
);
multiplier_wrapper u_multiplier_wrapper (
    .in_flat(multiplier_wrapper_in_flat),
    .out_flat(multiplier_wrapper_out_flat)
);
subtractor_wrapper u_subtractor_wrapper (
    .in_flat(subtractor_wrapper_in_flat),
    .out_flat(subtractor_wrapper_out_flat)
);
endmodule