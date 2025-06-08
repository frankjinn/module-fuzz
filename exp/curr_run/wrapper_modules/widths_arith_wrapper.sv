`include "widths_arith.sv"

//------------------------------------------------------------------------------
// Wrapper for widths_arith
// Flattens 0 inputs (0 bits) into `in_flat`,
// and flattens 0 outputs (0 bits) into `out_flat`.
//------------------------------------------------------------------------------
module widths_arith_wrapper (
    input  wire [-1:0] in_flat,
    output wire [-1:0] out_flat
);

  // Slice `in_flat` into original inputs

  // Wires to capture original module outputs

  // Instantiate the original module
  widths_arith u_widths_arith (
  );

  // Pack original outputs into `out_flat`

endmodule  // widths_arith_wrapper