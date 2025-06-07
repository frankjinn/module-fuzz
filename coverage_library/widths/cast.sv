

//------------------------------------------------------------------------------
// Module: cast
// Zero‐extension/truncation between 4 and 8 bits.
//------------------------------------------------------------------------------
module cast (
    input  wire [3:0]  in4,
    input  wire [7:0]  in8,
    output wire [7:0]  cast_up,
    output wire [3:0]  cast_down
);
    // Zero‐extend 4→8
    assign cast_up   = { 4'b0000, in4 };
    // Truncate 8→4
    assign cast_down = in8[3:0];
endmodule
