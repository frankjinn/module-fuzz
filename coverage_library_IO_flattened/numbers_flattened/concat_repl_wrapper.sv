//------------------------------------------------------------------------------
// Wrapper for concat_repl
// Flattens 2 inputs (6 bits) into `in_flat`,
// and flattens 3 outputs (22 bits) into `out_flat`.
//------------------------------------------------------------------------------
module concat_repl_wrapper (
    input  wire [5:0] in_flat,
    output wire [21:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] a = in_flat[5:2];
  wire [1:0] b = in_flat[1:0];

  // Wires to capture original module outputs
  wire [7:0] cat_ab;
  wire [7:0] rep_a;
  wire [5:0] rep_b;

  // Instantiate the original module
  concat_repl u_concat_repl (
    .a(a),
    .b(b),
    .cat_ab(cat_ab),
    .rep_a(rep_a),
    .rep_b(rep_b)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[21:14] = cat_ab;
  assign out_flat[13:6] = rep_a;
  assign out_flat[5:0] = rep_b;

endmodule  // concat_repl_wrapper