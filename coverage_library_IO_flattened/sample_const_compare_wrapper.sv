
//------------------------------------------------------------------------------
// Wrapper for const_compare
// Flattens 2 inputs (16 bits) into `in_flat`,
// and flattens 1 outputs (3 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_compare_wrapper (
    input  wire [15:0] in_flat,
    output wire [2:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] a = in_flat[15:8];
  wire [7:0] b = in_flat[7:0];

  // Wires to capture original module outputs
  wire [2:0] result;

  // Instantiate the original module
  const_compare u_const_compare (
    .a(a),
    .b(b),
    .result(result)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[2:0] = result;

endmodule  // const_compare_wrapper