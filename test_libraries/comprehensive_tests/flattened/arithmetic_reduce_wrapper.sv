//------------------------------------------------------------------------------
// Wrapper for arithmetic_reduce
// Flattens 2 inputs (16 bits) into `in_flat`,
// and flattens 3 outputs (10 bits) into `out_flat`.
//------------------------------------------------------------------------------
module arithmetic_reduce_wrapper (
    input  wire [15:0] in_flat,
    output wire [9:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] p = in_flat[15:8];
  wire [7:0] q = in_flat[7:0];

  // Wires to capture original module outputs
  wire [7:0] complex_expr;
  wire red_and_res;
  wire red_or_res;

  // Instantiate the original module
  arithmetic_reduce u_arithmetic_reduce (
    .p(p),
    .q(q),
    .complex_expr(complex_expr),
    .red_and_res(red_and_res),
    .red_or_res(red_or_res)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[9:2] = complex_expr;
  assign out_flat[1] = red_and_res;
  assign out_flat[0] = red_or_res;

endmodule  // arithmetic_reduce_wrapper