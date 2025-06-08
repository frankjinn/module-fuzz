`include "numbers_bitwise_logic.sv"

//------------------------------------------------------------------------------
// Wrapper for numbers_bitwise_logic
// Flattens 2 inputs (16 bits) into `in_flat`,
// and flattens 3 outputs (24 bits) into `out_flat`.
//------------------------------------------------------------------------------
module numbers_bitwise_logic_wrapper (
    input  wire [15:0] in_flat,
    output wire [23:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] x = in_flat[15:8];
  wire [7:0] y = in_flat[7:0];

  // Wires to capture original module outputs
  wire [7:0] and_xy;
  wire [7:0] or_xy;
  wire [7:0] xor_xy;

  // Instantiate the original module
  numbers_bitwise_logic u_numbers_bitwise_logic (
    .x(x),
    .y(y),
    .and_xy(and_xy),
    .or_xy(or_xy),
    .xor_xy(xor_xy)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[23:16] = and_xy;
  assign out_flat[15:8] = or_xy;
  assign out_flat[7:0] = xor_xy;

endmodule  // numbers_bitwise_logic_wrapper