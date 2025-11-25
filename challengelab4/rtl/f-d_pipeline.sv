module f-d_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic flush,
    input logic enable,
    input logic [DATA_WIDTH-1:0] instr_f,
    input logic [DATA_WIDTH-1:0] pc_f,
    input logic [DATA_WIDTH-1:0] pc_save_f,
    output logic [DATA_WIDTH-1:0] instr_d,
    output logic [DATA_WIDTH-1:0] pc_d,
    output logic [DATA_WIDTH-1:0] pc_save_d
);

    always @(posedge clk) begin
        if (flush) begin
            instr_d <= 8'h00000033; // add r0 r0
        end

        else if(enable) begin
            instr_d <= instr_f;
            pc_d <= pc_f;
            pc_save_d <= pc_f;
        end

    end

endmodule