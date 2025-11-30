module evalprediction(
    input logic [1:0] PCSrcE,
    input logic BranchE,
    input logic pred_taken,
    output logic false_prediction
);

always_comb begin
    false_prediction = 0; //by default we don't have a false prediction (so that we avoid flushing by default)
    if (BranchE ==1) begin
        case (PCSrcE)
            2'b00: if (pred_taken) false_prediction = 1;
            2'b01: if (!pred_taken) false_prediction = 1;
            default : false_prediction = 0;
        endcase
    end
end
endmodule

