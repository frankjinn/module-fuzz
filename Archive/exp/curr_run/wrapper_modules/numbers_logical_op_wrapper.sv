
//------------------------------------------------------------------------------
// Wrapper for numbers_logical_op
// Flattens 2 inputs (2 bits) into `in_flat`,
// and flattens 3 outputs (3 bits) into `out_flat`.
//------------------------------------------------------------------------------
module numbers_logical_op_wrapper (
    input  wire [1:0] in_flat,
    output wire [2:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire a = in_flat[1];
  wire b = in_flat[0];

  // Wires to capture original module outputs
  wire land_ab;
  wire lor_ab;
  wire lnot_a;

  // Instantiate the original module
  numbers_logical_op u_numbers_logical_op (
    .a(a),
    .b(b),
    .land_ab(land_ab),
    .lor_ab(lor_ab),
    .lnot_a(lnot_a)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[2] = land_ab;
  assign out_flat[1] = lor_ab;
  assign out_flat[0] = lnot_a;

endmodule  // numbers_logical_op_wrapper