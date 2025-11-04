
//------------------------------------------------------------------------------
// Wrapper for widths_concat_repl
// Flattens 2 inputs (6 bits) into `in_flat`,
// and flattens 3 outputs (18 bits) into `out_flat`.
//------------------------------------------------------------------------------
module widths_concat_repl_wrapper (
    input  wire [5:0] in_flat,
    output wire [17:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] a = in_flat[5:2];
  wire [1:0] b = in_flat[1:0];

  // Wires to capture original module outputs
  wire [7:0] cat_ab;
  wire [3:0] rep_a;
  wire [5:0] rep_b;

  // Instantiate the original module
  widths_concat_repl u_widths_concat_repl (
    .a(a),
    .b(b),
    .cat_ab(cat_ab),
    .rep_a(rep_a),
    .rep_b(rep_b)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[17:10] = cat_ab;
  assign out_flat[9:6] = rep_a;
  assign out_flat[5:0] = rep_b;

endmodule  // widths_concat_repl_wrapper