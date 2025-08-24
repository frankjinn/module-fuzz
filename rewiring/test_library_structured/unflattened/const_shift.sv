

//------------------------------------------------------------------------------
// Module: const_shift
// Takes one 8-bit vector and a 3-bit shift amount; performs logical and arithmetic shifts.
//------------------------------------------------------------------------------
module const_shift (
    input  wire [7:0] data_in,
    input  wire [2:0] shift_amt,
    output wire [7:0] shl_c,
    output wire [7:0] shr_c,
    output wire [7:0] ashr_c
);
    assign shl_c  = data_in << shift_amt;            // logical left shift
    assign shr_c  = data_in >> shift_amt;            // logical right shift
    assign ashr_c = $signed(data_in) >>> shift_amt;  // arithmetic right shift
endmodule
