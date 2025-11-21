module alu#(
    DATA_WIDTH=32
    )(
    input logic [DATA_WIDTH-1:0] ALUop1,
    input logic [DATA_WIDTH-1:0] ALUop2,
    input logic  [2:0]           ALUctrl,
    output logic [DATA_WIDTH-1: 0] ALUout,
    output logic                   EQ
    );

    always_comb
    begin
        //default to avoid latches
        ALUout = 0;
        EQ = 1'b0;
        
        //the two instructions implemented
        if (ALUop1 - ALUop2 == 0) EQ = 1'b1;
        else EQ = 1'b0;

        case (ALUctrl)
        3'b000 : ALUout = ALUop1 + ALUop2; // add
        3'b001 : ALUout = ALUop1 - ALUop2; // subtract
        3'b010 : ALUout = ALUop1 & ALUop2; // and
        3'b011 : ALUout = ALUop1 | ALUop2; // or
        3'b100: ALUout = ALUop2; // for LUI
        default: ALUout = 32'b0;
        endcase
    end
endmodule



