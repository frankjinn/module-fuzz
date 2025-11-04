//------------------------------------------------------------------------------
// Module: constant
// Exercises numeric literal parsing: decimal, binary, octal, hex, sized, unsized.
//------------------------------------------------------------------------------
module constant (
    output wire [31:0] const_dec,
    output wire [15:0] const_bin,
    output wire [11:0] const_oct,
    output wire [15:0] const_hex,
    output wire [3:0]  const_unsized    // unsized binary constant
);
    // Decimal literal
    assign const_dec     = 123456789;
    // 16-bit binary literal (with underscores)
    assign const_bin     = 16'b1010_1011_1100_1101;
    // 12-bit octal literal
    assign const_oct     = 12'o7523;
    // 16-bit hex literal
    assign const_hex     = 16'hABCD;
    // Unsized binary literal: width = number of digits (4), value = 1010₂
    assign const_unsized = 'b1010;
endmodule
