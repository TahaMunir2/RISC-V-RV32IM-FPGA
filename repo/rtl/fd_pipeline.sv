module fd_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic enable,
    input logic rst,
    input logic [DATA_WIDTH-1:0] instr1_f,
    input logic [DATA_WIDTH-1:0] instr2_f,
    input logic [DATA_WIDTH-1:0] pc_f,
    input logic [DATA_WIDTH-1:0] pc_save_f,
    output logic [DATA_WIDTH-1:0] instr1_d,
    output logic [DATA_WIDTH-1:0] instr2_d,
    output logic [DATA_WIDTH-1:0] pc_d,
    output logic [DATA_WIDTH-1:0] pc_save_d
);

    always @(posedge clk) begin

        if (rst) begin
            instr1_d <= 32'h00000033;
            pc_d <= 0;
            pc_save_d <= 0;
            instr2_d <= 32'h00000033;
        end
        
        else if(enable) begin
            instr1_d <= instr1_f;
            instr2_d <= instr2_f;
            pc_d <= pc_f;
            pc_save_d <= pc_save_f;
        end

    end

endmodule
