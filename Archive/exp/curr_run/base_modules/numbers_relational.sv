

//------------------------------------------------------------------------------
// Module: relational
// Exercises equality, inequality, relational, case-equality (===), case-inequality (!==).
//------------------------------------------------------------------------------
module numbers_relational (
    input  wire [3:0] x,
    input  wire [3:0] y,
    output wire       eq,       // x == y (logical equality)
    output wire       neq,      // x != y
    output wire       gt,       // x >  y
    output wire       lt,       // x <  y
    output wire       ge,       // x >= y
    output wire       le,       // x <= y
    output wire       case_eq,  // x === y (case-equality)
    output wire       case_neq  // x !== y (case-inequality)
);
    assign eq       = (x == y);
    assign neq      = (x != y);
    assign gt       = (x >  y);
    assign lt       = (x <  y);
    assign ge       = (x >= y);
    assign le       = (x <= y);
    assign case_eq  = (x === y);
    assign case_neq = (x !== y);
endmodule
