
//------------------------------------------------------------------------------
// Wrapper for const_concat_repl
// Flattens 3 inputs (10 bits) into `in_flat`,
// and flattens 3 outputs (22 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_concat_repl_wrapper (
    input  wire [9:0] in_flat,
    output wire [21:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] a = in_flat[9:6];
  wire [3:0] b = in_flat[5:2];
  wire [1:0] c = in_flat[1:0];

  // Wires to capture original module outputs
  wire [7:0] cat_c;
  wire [7:0] rep_c;
  wire [5:0] rep2_c;

  // Instantiate the original module
  const_concat_repl u_const_concat_repl (
    .a(a),
    .b(b),
    .c(c),
    .cat_c(cat_c),
    .rep_c(rep_c),
    .rep2_c(rep2_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[21:14] = cat_c;
  assign out_flat[13:6] = rep_c;
  assign out_flat[5:0] = rep2_c;

endmodule  // const_concat_repl_wrapper