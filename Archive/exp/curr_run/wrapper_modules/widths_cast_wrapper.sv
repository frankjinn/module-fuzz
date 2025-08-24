`include "widths_cast.sv"

//------------------------------------------------------------------------------
// Wrapper for widths_cast
// Flattens 2 inputs (12 bits) into `in_flat`,
// and flattens 2 outputs (12 bits) into `out_flat`.
//------------------------------------------------------------------------------
module widths_cast_wrapper (
    input  wire [11:0] in_flat,
    output wire [11:0] out_flat
);

  // Slice `in_flat` into original inputs
  wire [3:0] in4 = in_flat[11:8];
  wire [7:0] in8 = in_flat[7:0];

  // Wires to capture original module outputs
  wire [7:0] cast_up;
  wire [3:0] cast_down;

  // Instantiate the original module
  widths_cast u_widths_cast (
    .in4(in4),
    .in8(in8),
    .cast_up(cast_up),
    .cast_down(cast_down)
  );

  // Pack original outputs into `out_flat`
  assign out_flat[11:4] = cast_up;
  assign out_flat[3:0] = cast_down;

endmodule  // widths_cast_wrapper