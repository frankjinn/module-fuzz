`include "adder_wrapper.sv"
`include "multiplier_wrapper.sv"

// Automatically generated top module
module top (
    input  wire [5:0] in_flat,
    output wire [7:0] out_flat
);

  // Per-module flattened I/O buses
  wire [3:0] adder_wrapper_in_flat;
  wire [2:0] adder_wrapper_out_flat;
  wire [3:0] multiplier_wrapper_in_flat;
  wire [4:0] multiplier_wrapper_out_flat;

  // Drive module inputs from top-level in_flat
  assign multiplier_wrapper_in_flat[0] = in_flat[0];
  assign multiplier_wrapper_in_flat[1] = in_flat[4];
  assign multiplier_wrapper_in_flat[2] = in_flat[5];
  assign multiplier_wrapper_in_flat[3] = in_flat[1];
  assign adder_wrapper_in_flat[0] = in_flat[3];
  assign adder_wrapper_in_flat[1] = in_flat[2];

  // Internal connections: module-out → module-in
  assign adder_wrapper_in_flat[2] = multiplier_wrapper_out_flat[1];
  assign adder_wrapper_in_flat[3] = adder_wrapper_out_flat[0];

  // Drive top-level out_flat from module outputs
  assign out_flat[3] = multiplier_wrapper_out_flat[0];
  assign out_flat[7] = multiplier_wrapper_out_flat[1];
  assign out_flat[1] = multiplier_wrapper_out_flat[2];
  assign out_flat[5] = multiplier_wrapper_out_flat[3];
  assign out_flat[0] = multiplier_wrapper_out_flat[4];
  assign out_flat[6] = adder_wrapper_out_flat[0];
  assign out_flat[2] = adder_wrapper_out_flat[1];
  assign out_flat[4] = adder_wrapper_out_flat[2];

  // Instantiate each module's wrapper
  adder_wrapper u_adder_wrapper (
    .in_flat  (adder_wrapper_in_flat),
    .out_flat (adder_wrapper_out_flat)
  );
  multiplier_wrapper u_multiplier_wrapper (
    .in_flat  (multiplier_wrapper_in_flat),
    .out_flat (multiplier_wrapper_out_flat)
  );

endmodule

/*
--------------------------------------------------
| Iter |   in_flat   |      out_flat          |
--------------------------------------------------
|    0 | 100100 | 0x0x0x00 |
|    1 | 000001 | 0x0x0x00 |
|    2 | 001001 | 0x0x0x00 |
|    3 | 100011 | 1x0x1x00 |
|    4 | 001101 | 0x0x0x00 |
|    5 | 001101 | 0x0x0x00 |
|    6 | 100101 | 0x0x1x00 |
|    7 | 010010 | 0x0x0x10 |
|    8 | 000001 | 0x0x0x00 |
|    9 | 001101 | 0x0x0x00 |
|   10 | 110110 | 1x0x0x10 |
|   11 | 111101 | 1x0x1x00 |
|   12 | 101101 | 0x0x1x00 |
|   13 | 001100 | 0x0x0x00 |
|   14 | 111001 | 1x0x1x00 |
|   15 | 000110 | 0x0x0x00 |
|   16 | 000101 | 0x0x0x00 |
|   17 | 101010 | 0x0x0x00 |
|   18 | 100101 | 0x0x1x00 |
|   19 | 110111 | 0x1x1x00 |
--------------------------------------------------
*/