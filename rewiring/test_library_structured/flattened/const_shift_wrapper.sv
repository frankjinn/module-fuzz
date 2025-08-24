`include "const_shift.sv"

//------------------------------------------------------------------------------
// Wrapper for const_shift
// Flattens 2 inputs (11 bits) into `in_flat`,
// and flattens 3 outputs (24 bits) into `out_flat`.
//------------------------------------------------------------------------------
module const_shift_wrapper (
    input  wire [10:0] in_flat,
    output wire [23:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] data_in = in_flat[10:3];
  wire [2:0] shift_amt = in_flat[2:0];

  // Wires to capture original module outputs
  wire [7:0] shl_c;
  wire [7:0] shr_c;
  wire [7:0] ashr_c;

  // Instantiate the original module
  const_shift u_const_shift (
    .data_in(data_in),
    .shift_amt(shift_amt),
    .shl_c(shl_c),
    .shr_c(shr_c),
    .ashr_c(ashr_c)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[23:16] = shl_c;
  assign out_flat[15:8] = shr_c;
  assign out_flat[7:0] = ashr_c;

endmodule  // const_shift_wrapper