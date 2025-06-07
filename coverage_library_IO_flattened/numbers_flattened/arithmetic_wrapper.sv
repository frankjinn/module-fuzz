//------------------------------------------------------------------------------
// Wrapper for arithmetic
// Flattens 0 inputs (0 bits) into `in_flat`,
// and flattens 0 outputs (0 bits) into `out_flat`.
//------------------------------------------------------------------------------
module arithmetic_wrapper (
    input  wire [-1:0] in_flat,
    output wire [-1:0] out_flat
);

  // Slice `in_flat` into original inputs

  // Wires to capture original module outputs

  // Instantiate the original module
  arithmetic u_arithmetic (
  );

  // Pack original outputs into `out_flat`

endmodule  // arithmetic_wrapper