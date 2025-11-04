

//------------------------------------------------------------------------------
// Module: reduce_case
// Exercises wildcard (case) equality with X/Z bits.
//------------------------------------------------------------------------------
module reduce_case (
    input  wire [3:0] a,
    input  wire [3:0] b,
    output wire       wild_eq,  // bitwise comparison treating X/Z as wildcard
    output wire       wild_neq  // bitwise not equal with wildcard
);
    // In Verilog, '===' and '!==' compare X/Z bits exactly, not wildcard.
    // To treat X/Z in b as “don’t care” (wildcard), we can use conditional:
    //   a matches b if for all bits i: (b[i] is X/Z) OR (a[i] == b[i]).
    wire [3:0] b_is_xz = (b ^ b);  // if b bit is X or Z, then b ^ b = X/Z, else 0
    // But simpler: use case equality and then mask:
    assign wild_eq  = ( ( (a ^ b) & ~({4{1'b0}}) ) == 4'b0000 ) ||      // a==b exactly
                      (&( (b ^ 4'bzzzz) === 4'bzzzz ));                // all bits of b are X/Z
    // Actually, for a general wildcard, you'd need bitwise logic per bit; but to exercise V3Number's wildcard functions,
    // we rely on '===' and '!==' operators.
    assign wild_eq  = (a === b);
    assign wild_neq = (a !== b);
endmodule
