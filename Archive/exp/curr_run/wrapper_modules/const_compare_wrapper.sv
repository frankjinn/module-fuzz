
//------------------------------------------------------------------------------
// Wrapper for const_compare
// Flattens 4 inputs (24 bits) into `in_flat`,
// and flattens 8 outputs (8 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_compare_wrapper (
    input  wire [23:0] in_flat,
    output wire [7:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] a = in_flat[23:16];
  wire [7:0] b = in_flat[15:8];
  wire [3:0] c = in_flat[7:4];
  wire [3:0] d = in_flat[3:0];

  // Wires to capture original module outputs
  wire eq_c;
  wire neq_c;
  wire lt_c;
  wire le_c;
  wire gt_c;
  wire ge_c;
  wire case_eq_c;
  wire case_neq_c;

  // Instantiate the original module
  const_compare u_const_compare (
    .a(a),
    .b(b),
    .c(c),
    .d(d),
    .eq_c(eq_c),
    .neq_c(neq_c),
    .lt_c(lt_c),
    .le_c(le_c),
    .gt_c(gt_c),
    .ge_c(ge_c),
    .case_eq_c(case_eq_c),
    .case_neq_c(case_neq_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[7] = eq_c;
  assign out_flat[6] = neq_c;
  assign out_flat[5] = lt_c;
  assign out_flat[4] = le_c;
  assign out_flat[3] = gt_c;
  assign out_flat[2] = ge_c;
  assign out_flat[1] = case_eq_c;
  assign out_flat[0] = case_neq_c;

endmodule  // const_compare_wrapper