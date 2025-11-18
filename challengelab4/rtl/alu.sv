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
        if(ALUctrl == 0)
            ALUout=ALUop1 + ALUop2;
        else begin
            if (ALUop1-ALUop2 == 0) EQ=1;
            else                    EQ=0;
        end
    end

endmodule



