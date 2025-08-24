

//------------------------------------------------------------------------------
// Module: const_conditional
// Takes four 8-bit vectors and two select bits; applies nested ternary logic.
//------------------------------------------------------------------------------
module const_conditional (
    input  wire [7:0] a,
    input  wire [7:0] b,
    input  wire [7:0] c,
    input  wire [7:0] d,
    input  wire       sel1,
    input  wire       sel2,
    output wire [7:0] cond1_c,  // sel1 ? a : b
    output wire [7:0] cond2_c,  // sel2 ? (sel1 ? a : b) : c
    output wire [7:0] cond3_c   // (signed c < signed d) ? a : b
);
    assign cond1_c = sel1 ? a : b;
    assign cond2_c = sel2 ? cond1_c : c;
    assign cond3_c = ($signed(c) < $signed(d)) ? a : b;
endmodule
