module PCSrcF_assertion #(
    parameter DATA_WIDTH = 32
)
(
input logic JumpE,
input logic BranchE,
input logic [6:0] opcodeF,
input logic [1:0] PCSrcE,
input logic predictionE,
input logic predictionF,
input logic false_prediction,
input logic [31:0] targetF,
input logic [31:0] targetE,
output logic [1:0] PCSrcF,
output logic [31:0] FinalTarget
);

//we check if the instruction fetched is a Branch Instruction
logic BranchF;
assign BranchF = (opcodeF == 7'b1100011);


always_comb begin
    PCSrcF = 2'b00; //default case
    FinalTarget = targetE; //we only care about this when pcsrc is equal to 01 (otherwise it is a don't care)


    if (JumpE)begin
        PCSrcF = PCSrcE;
        FinalTarget = targetE;
    end

    else if (BranchE && false_prediction) begin //we were in the wrong path: we completely ignore what is currently in fetch
        if(predictionE)begin
            PCSrcF = 2'b11; 
        end
        else begin
            PCSrcF = 2'b01;
            FinalTarget = targetE;
        end
    end

    else begin
        if (BranchF) begin //if there is a branch that is now fetched (and we are in the correct path)
            if(predictionF)begin
                PCSrcF = 2'b01;
                FinalTarget = targetF;
            end
            else begin
                PCSrcF = 2'b00;
            end
        end
    end
end

endmodule

