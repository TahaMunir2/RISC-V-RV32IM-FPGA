module PCSrcF_assertion #(
    DATA_WIDTH = 32
)
(
input logic JumpE,
input logic BranchE,
input logic [6:0] opcodeF,
input logic [1:0] PCSrcE,
input logic prediction,
output logic [1:0] PCSrcF
);

//we check if the instruction fetched is a Branch Instruction
logic BranchF;
assign BranchF = (opcodeF == 7'b1100011);


always_comb begin
    PCSrcF = PCSrcE; //default case

    if (!(JumpE || BranchE) && BranchF) begin
        if (prediction) begin 
            PCSrcF = 2'b01;
        end
        else begin
            PCSrcF = 2'b00;
        end
    end
end
endmodule


