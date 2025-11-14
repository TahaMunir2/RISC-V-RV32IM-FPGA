module alu#(
    DATA_WIDTH=32
    )(
    input logic [DATA_WIDTH-1:0] ALUop1,
    input logic [DATA_WIDTH-1:0] ALUop2,
    input logic                  ALUctrl,
    output logic [DATA_WIDTH-1: 0] ALUout,
    output logic                   EQ
    );

    always_comb
    begin
        if(!ALUctrl)
            assign ALUout=ALUop1 + ALUop2;
        else begin
            if (ALUop1-ALUop2 == 0) EQ=0;
            else                    EQ=1;
        end
    end

endmodule



