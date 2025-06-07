`include "adder_wrapper.sv"
`include "multiplier_wrapper.sv"

// Automatically generated top module
module top (
    input  wire [6:0] in_flat,
    output wire [7:0] out_flat
);

  // Per-module flattened I/O buses
  wire [3:0] adder_wrapper_in_flat;
  wire [2:0] adder_wrapper_out_flat;
  wire [3:0] multiplier_wrapper_in_flat;
  wire [4:0] multiplier_wrapper_out_flat;

  // Drive module inputs from top-level in_flat
  assign multiplier_wrapper_in_flat[0] = in_flat[1];
  assign multiplier_wrapper_in_flat[1] = in_flat[5];
  assign multiplier_wrapper_in_flat[3] = in_flat[6];
  assign adder_wrapper_in_flat[0] = in_flat[0];
  assign adder_wrapper_in_flat[1] = in_flat[4];
  assign adder_wrapper_in_flat[2] = in_flat[3];
  assign adder_wrapper_in_flat[3] = in_flat[2];

  // Internal connections: module-out → module-in
  assign multiplier_wrapper_in_flat[2] = adder_wrapper_out_flat[0];

  // Drive top-level out_flat from module outputs
  assign out_flat[6] = multiplier_wrapper_out_flat[0];
  assign out_flat[5] = multiplier_wrapper_out_flat[1];
  assign out_flat[0] = multiplier_wrapper_out_flat[2];
  assign out_flat[2] = multiplier_wrapper_out_flat[3];
  assign out_flat[3] = multiplier_wrapper_out_flat[4];
  assign out_flat[7] = adder_wrapper_out_flat[0];
  assign out_flat[4] = adder_wrapper_out_flat[1];
  assign out_flat[1] = adder_wrapper_out_flat[2];

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
|    0 | 0100100 | 00010000 |
|    1 | 0000001 | 10000000 |
|    2 | 0001001 | 00010000 |
|    3 | 1100011 | 11000100 |
|    4 | 0001101 | 00000010 |
|    5 | 0001101 | 00000010 |
|    6 | 1100101 | 10110001 |
|    7 | 0010010 | 00010000 |
|    8 | 0000001 | 10000000 |
|    9 | 0001101 | 00000010 |
|   10 | 1110110 | 00100011 |
|   11 | 0111101 | 00010010 |
|   12 | 1101101 | 00000011 |
|   13 | 0001100 | 10010000 |
|   14 | 1111001 | 00000011 |
|   15 | 1000110 | 00110000 |
|   16 | 1000101 | 10010000 |
|   17 | 0101010 | 11100000 |
|   18 | 1100101 | 10110001 |
|   19 | 1110111 | 11000110 |
--------------------------------------------------
*/