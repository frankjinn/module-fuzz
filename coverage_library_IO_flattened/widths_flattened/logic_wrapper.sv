//------------------------------------------------------------------------------
// Wrapper for logic
// Flattens 2 inputs (8 bits) into `in_flat`,
// and flattens 6 outputs (6 bits) into `out_flat`.
//------------------------------------------------------------------------------
module logic_wrapper (
    input  wire [7:0] in_flat,
    output wire [5:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] x = in_flat[7:4];
  wire [3:0] y = in_flat[3:0];

  // Wires to capture original module outputs
  wire eq;
  wire neq;
  wire gt;
  wire red_and;
  wire red_or;
  wire red_xor;

  // Instantiate the original module
  logic u_logic (
    .x(x),
    .y(y),
    .eq(eq),
    .neq(neq),
    .gt(gt),
    .red_and(red_and),
    .red_or(red_or),
    .red_xor(red_xor)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[5] = eq;
  assign out_flat[4] = neq;
  assign out_flat[3] = gt;
  assign out_flat[2] = red_and;
  assign out_flat[1] = red_or;
  assign out_flat[0] = red_xor;

endmodule  // logic_wrapper