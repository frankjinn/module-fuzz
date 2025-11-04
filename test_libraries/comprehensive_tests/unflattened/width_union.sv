

//------------------------------------------------------------------------------
// Module: union
// Splits a 16‐bit input into low and high bytes (flat version of SV union).
//------------------------------------------------------------------------------
module width_union (
    input  wire [15:0] u_in,
    output wire [7:0]  u_low,
    output wire [7:0]  u_high
);
    assign u_low  = u_in[7:0];
    assign u_high = u_in[15:8];
endmodule
