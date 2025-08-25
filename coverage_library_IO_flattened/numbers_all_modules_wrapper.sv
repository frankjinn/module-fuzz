`include "numbers_all_modules.sv"

//------------------------------------------------------------------------------
// Wrapper for numbers_constant
// Flattens 0 inputs (0 bits) into `in_flat`,
// and flattens 5 outputs (80 bits) into `out_flat`.
//------------------------------------------------------------------------------
module numbers_constant_wrapper (
    input  wire [-1:0] in_flat,
    output wire [79:0] out_flat
);

  // Slice `in_flat` into original inputs

  // Wires to capture original module outputs
  wire [31:0] const_dec;
  wire [15:0] const_bin;
  wire [11:0] const_oct;
  wire [15:0] const_hex;
  wire [3:0] const_unsized;

  // Instantiate the original module
  numbers_constant u_numbers_constant (
    .const_dec(const_dec),
    .const_bin(const_bin),
    .const_oct(const_oct),
    .const_hex(const_hex),
    .const_unsized(const_unsized)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[79:48] = const_dec;
  assign out_flat[47:32] = const_bin;
  assign out_flat[31:20] = const_oct;
  assign out_flat[19:4] = const_hex;
  assign out_flat[3:0] = const_unsized;

endmodule  // numbers_constant_wrapper