

//------------------------------------------------------------------------------
// Module: conditional
// Ternary operator with mixed signed/unsigned resolution.
//------------------------------------------------------------------------------
module conditional (
    input  wire        sel,
    input  wire [3:0]  x,
    input  wire signed [3:0] y,
    output wire signed [3:0] z
);
    // If sel=1, zero‐extend x into 4‐bit signed; else use y
    wire signed [3:0] x_signed = $signed({1'b0, x[2:0]});
    assign z = sel ? x_signed : y;
endmodule
