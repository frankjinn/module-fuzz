`timescale 1ns/1ps
`default_nettype none

module numbers_reduce_case (
    input  logic [3:0] a,
    input  logic [3:0] b,
    output logic       wild_eq,   // treat b’s X/Z bits as “don’t care”
    output logic       wild_neq
);

  // per-bit match: if b[i] is X/Z → match, else require a[i]===b[i]
  logic [3:0] match_bits;

  always_comb begin
    for (int i = 0; i < 4; i++) begin
      if ($isunknown(b[i]))
        match_bits[i] = 1'b1;
      else
        match_bits[i] = (a[i] === b[i]);
    end
  end

  // all bits must match for equality; not-equal is its complement
  assign wild_eq  = &match_bits;
  assign wild_neq = ~wild_eq;

endmodule

`default_nettype wire
