`include "const_logic.sv"

//------------------------------------------------------------------------------
// Wrapper for const_logic
// Flattens 4 inputs (10 bits) into `in_flat`,
// and flattens 7 outputs (19 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_logic_wrapper (
    input  wire [9:0] in_flat,
    output wire [18:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] x = in_flat[9:6];
  wire [3:0] y = in_flat[5:2];
  wire a = in_flat[1];
  wire b = in_flat[0];

  // Wires to capture original module outputs
  wire [3:0] and_c;
  wire [3:0] or_c;
  wire [3:0] xor_c;
  wire [3:0] not_c;
  wire land_c;
  wire lor_c;
  wire lnot_c;

  // Instantiate the original module
  const_logic u_const_logic (
    .x(x),
    .y(y),
    .a(a),
    .b(b),
    .and_c(and_c),
    .or_c(or_c),
    .xor_c(xor_c),
    .not_c(not_c),
    .land_c(land_c),
    .lor_c(lor_c),
    .lnot_c(lnot_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[18:15] = and_c;
  assign out_flat[14:11] = or_c;
  assign out_flat[10:7] = xor_c;
  assign out_flat[6:3] = not_c;
  assign out_flat[2] = land_c;
  assign out_flat[1] = lor_c;
  assign out_flat[0] = lnot_c;

endmodule  // const_logic_wrapper