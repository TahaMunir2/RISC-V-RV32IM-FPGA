module fd_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic flush,
    input logic enable,
    input logic rst,
    input logic [DATA_WIDTH-1:0] pc_f,
    input logic [DATA_WIDTH-1:0] pc_save_f,
    output logic [DATA_WIDTH-1:0] pc_d,
    output logic [DATA_WIDTH-1:0] pc_save_d,
    input logic pred_takenF,
    output logic pred_takenD
);

    always @(posedge clk) begin

        if (rst || flush) begin
            pc_d <= 0;
            pc_save_d <= 0;
            pred_takenD <= 0;
        end
        
        else if(enable) begin

            pc_d <= pc_f;
            pc_save_d <= pc_save_f;
            pred_takenD <= pred_takenF;
        end

    end

endmodule
