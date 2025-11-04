
//------------------------------------------------------------------------------
// Wrapper for numbers_numbers_arithmetic
// Flattens 2 inputs (13 bits) into `in_flat`,
// and flattens 5 outputs (25 bits) into `out_flat`.
//------------------------------------------------------------------------------
module numbers_numbers_arithmetic_wrapper (
    input  wire [12:0] in_flat,
    output wire [24:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [4:0] b = in_flat[12:8];
  wire [7:0] a = in_flat[7:0];

  // Wires to capture original module outputs
  wire [4:0] sum_ab;
  wire [4:0] diff_ab;
  wire [4:0] prod_ab;
  wire [4:0] quot_ab;
  wire [4:0] rem_ab;

  // Instantiate the original module
  numbers_numbers_arithmetic u_numbers_numbers_arithmetic (
    .b(b),
    .a(a),
    .sum_ab(sum_ab),
    .diff_ab(diff_ab),
    .prod_ab(prod_ab),
    .quot_ab(quot_ab),
    .rem_ab(rem_ab)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[24:20] = sum_ab;
  assign out_flat[19:15] = diff_ab;
  assign out_flat[14:10] = prod_ab;
  assign out_flat[9:5] = quot_ab;
  assign out_flat[4:0] = rem_ab;

endmodule  // numbers_numbers_arithmetic_wrapper