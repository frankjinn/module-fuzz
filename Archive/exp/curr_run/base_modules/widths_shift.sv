

//------------------------------------------------------------------------------
// Module: shift
// Simple left/right shifts.
//------------------------------------------------------------------------------
module widths_shift (
    input  wire [7:0] data_in,
    input  wire [2:0] shift_amt,
    output wire [7:0] shl_out,
    output wire [7:0] shr_out
);
    assign shl_out = data_in << shift_amt;
    assign shr_out = data_in >> shift_amt;
endmodule
