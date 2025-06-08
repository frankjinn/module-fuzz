

//------------------------------------------------------------------------------
// Module: select
// Exercises static and dynamic part‐select, plus overflow detection.
//------------------------------------------------------------------------------
module numbers_select (
    input  wire [15:0] data_in,
    input  wire [3:0]  idx,          // allow up to 15
    output wire [3:0]  static_ps,    // bits [7:4]
    output wire [3:0]  dynamic_ps,   // bits [idx +: 4]
    output wire        ovf_range     // idx > 12 → overflow for width-4
);
    // Static part-select: bits [7:4]
    assign static_ps = data_in[7:4];
    // Dynamic part-select (requires idx ≤ 12)
    assign dynamic_ps = data_in[idx +: 4];
    // Overflow if idx > 12 (so idx+3 > 15)
    assign ovf_range  = (idx > 4'd12);
endmodule
