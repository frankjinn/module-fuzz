
//------------------------------------------------------------------------------
// Wrapper for numbers_relational
// Flattens 2 inputs (8 bits) into `in_flat`,
// and flattens 8 outputs (8 bits) into `out_flat`.
//------------------------------------------------------------------------------
module numbers_relational_wrapper (
    input  wire [7:0] in_flat,
    output wire [7:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] x = in_flat[7:4];
  wire [3:0] y = in_flat[3:0];

  // Wires to capture original module outputs
  wire eq;
  wire neq;
  wire gt;
  wire lt;
  wire ge;
  wire le;
  wire case_eq;
  wire case_neq;

  // Instantiate the original module
  numbers_relational u_numbers_relational (
    .x(x),
    .y(y),
    .eq(eq),
    .neq(neq),
    .gt(gt),
    .lt(lt),
    .ge(ge),
    .le(le),
    .case_eq(case_eq),
    .case_neq(case_neq)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[7] = eq;
  assign out_flat[6] = neq;
  assign out_flat[5] = gt;
  assign out_flat[4] = lt;
  assign out_flat[3] = ge;
  assign out_flat[2] = le;
  assign out_flat[1] = case_eq;
  assign out_flat[0] = case_neq;

endmodule  // numbers_relational_wrapper