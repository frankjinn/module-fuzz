`include "numbers_bitwise_reduce.sv"

//------------------------------------------------------------------------------
// Wrapper for numbers_bitwise_reduce
// Flattens 1 inputs (8 bits) into `in_flat`,
// and flattens 3 outputs (3 bits) into `out_flat`.
//------------------------------------------------------------------------------
module numbers_bitwise_reduce_wrapper (
    input  wire [7:0] in_flat,
    output wire [2:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] in_vec = in_flat[7:0];

  // Wires to capture original module outputs
  wire red_and;
  wire red_or;
  wire red_xor;

  // Instantiate the original module
  numbers_bitwise_reduce u_numbers_bitwise_reduce (
    .in_vec(in_vec),
    .red_and(red_and),
    .red_or(red_or),
    .red_xor(red_xor)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[2] = red_and;
  assign out_flat[1] = red_or;
  assign out_flat[0] = red_xor;

endmodule  // numbers_bitwise_reduce_wrapper