
//------------------------------------------------------------------------------
// Wrapper for const_arith
// Flattens 3 inputs (19 bits) into `in_flat`,
// and flattens 1 outputs (8 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_arith_wrapper (
    input  wire [18:0] in_flat,
    output wire [7:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] a = in_flat[18:11];
  wire [7:0] b = in_flat[10:3];
  wire [2:0] op = in_flat[2:0];

  // Wires to capture original module outputs
  wire [7:0] result;

  // Instantiate the original module
  const_arith u_const_arith (
    .a(a),
    .b(b),
    .op(op),
    .result(result)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[7:0] = result;

endmodule  // const_arith_wrapper