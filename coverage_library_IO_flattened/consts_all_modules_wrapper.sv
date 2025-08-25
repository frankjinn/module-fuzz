`include "consts_all_modules.sv"

//------------------------------------------------------------------------------
// Wrapper for const_arith
// Flattens 2 inputs (16 bits) into `in_flat`,
// and flattens 5 outputs (40 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_arith_wrapper (
    input  wire [15:0] in_flat,
    output wire [39:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] a = in_flat[15:8];
  wire [7:0] b = in_flat[7:0];

  // Wires to capture original module outputs
  wire [7:0] sum_c;
  wire [7:0] diff_c;
  wire [7:0] prod_c;
  wire [7:0] quot_c;
  wire [7:0] rem_c;

  // Instantiate the original module
  const_arith u_const_arith (
    .a(a),
    .b(b),
    .sum_c(sum_c),
    .diff_c(diff_c),
    .prod_c(prod_c),
    .quot_c(quot_c),
    .rem_c(rem_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[39:32] = sum_c;
  assign out_flat[31:24] = diff_c;
  assign out_flat[23:16] = prod_c;
  assign out_flat[15:8] = quot_c;
  assign out_flat[7:0] = rem_c;

endmodule  // const_arith_wrapper