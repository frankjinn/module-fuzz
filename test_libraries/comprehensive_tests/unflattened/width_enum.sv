//------------------------------------------------------------------------------
// Module: enum
// Replaces the SV typedef‐enum with simple localparam constants.
//------------------------------------------------------------------------------
module width_enum (
    input  wire [3:0] e_in,      // pass enum value
    output wire [3:0] e_out_eq,  // 1 if e_in == E2, else 0
    output wire       is_E2
);
    // “Enum” constants:
    localparam [3:0] E0 = 4'h0;
    localparam [3:0] E1 = 4'd5;
    localparam [3:0] E2 = 4'd6;   // (implicit)
    localparam [3:0] E3 = 4'o7;   // octal 7 → 3'b111 → 4'h7
    localparam [3:0] E4 = 4'b1010;

    assign is_E2   = (e_in == E2);
    assign e_out_eq = is_E2 ? 4'd1 : 4'd0;
endmodule
