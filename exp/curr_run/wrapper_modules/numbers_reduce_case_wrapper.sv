`include "numbers_reduce_case.sv"

//------------------------------------------------------------------------------
// Wrapper for numbers_reduce_case
// Flattens 2 inputs (8 bits) into `in_flat`,
// and flattens 2 outputs (2 bits) into `out_flat`.
//------------------------------------------------------------------------------
module numbers_reduce_case_wrapper (
    input  wire [7:0] in_flat,
    output wire [1:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] a = in_flat[7:4];
  wire [3:0] b = in_flat[3:0];

  // Wires to capture original module outputs
  wire wild_eq;
  wire wild_neq;

  // Instantiate the original module
  numbers_reduce_case u_numbers_reduce_case (
    .a(a),
    .b(b),
    .wild_eq(wild_eq),
    .wild_neq(wild_neq)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[1] = wild_eq;
  assign out_flat[0] = wild_neq;

endmodule  // numbers_reduce_case_wrapper