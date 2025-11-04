
//------------------------------------------------------------------------------
// Wrapper for const_conditional
// Flattens 6 inputs (34 bits) into `in_flat`,
// and flattens 3 outputs (24 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_conditional_wrapper (
    input  wire [33:0] in_flat,
    output wire [23:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] a = in_flat[33:26];
  wire [7:0] b = in_flat[25:18];
  wire [7:0] c = in_flat[17:10];
  wire [7:0] d = in_flat[9:2];
  wire sel1 = in_flat[1];
  wire sel2 = in_flat[0];

  // Wires to capture original module outputs
  wire [7:0] cond1_c;
  wire [7:0] cond2_c;
  wire [7:0] cond3_c;

  // Instantiate the original module
  const_conditional u_const_conditional (
    .a(a),
    .b(b),
    .c(c),
    .d(d),
    .sel1(sel1),
    .sel2(sel2),
    .cond1_c(cond1_c),
    .cond2_c(cond2_c),
    .cond3_c(cond3_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[23:16] = cond1_c;
  assign out_flat[15:8] = cond2_c;
  assign out_flat[7:0] = cond3_c;

endmodule  // const_conditional_wrapper