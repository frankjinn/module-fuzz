`include "widths_shift.sv"

//------------------------------------------------------------------------------
// Wrapper for widths_shift
// Flattens 2 inputs (11 bits) into `in_flat`,
// and flattens 2 outputs (16 bits) into `out_flat`.
//------------------------------------------------------------------------------
module widths_shift_wrapper (
    input  wire [10:0] in_flat,
    output wire [15:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [7:0] data_in = in_flat[10:3];
  wire [2:0] shift_amt = in_flat[2:0];

  // Wires to capture original module outputs
  wire [7:0] shl_out;
  wire [7:0] shr_out;

  // Instantiate the original module
  widths_shift u_widths_shift (
    .data_in(data_in),
    .shift_amt(shift_amt),
    .shl_out(shl_out),
    .shr_out(shr_out)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[15:8] = shl_out;
  assign out_flat[7:0] = shr_out;

endmodule  // widths_shift_wrapper