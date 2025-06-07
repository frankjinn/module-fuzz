

//------------------------------------------------------------------------------
// Module: partselect
// Uses static [7:4] and dynamic [idx +:4]; also checks overflow.
//------------------------------------------------------------------------------
module partselect (
    input  wire [15:0] data_in,
    input  wire [2:0]  idx,
    output wire [3:0]  static_ps,
    output wire [3:0]  dynamic_ps,
    output wire        ovf_range
);
    // bits [7:4]
    assign static_ps = data_in[7:4];

    // dynamic [idx +: 4], idx <= 12 required
    assign dynamic_ps = data_in[idx +: 4];

    // overflow if idx > 12
    assign ovf_range = (idx > 3'd12);
endmodule
