module f-d_pipeline #(
    DATA_WIDTH = 32
) (
    input clk,
    input logic [DATA_WIDTH-1:0] instr_f,
    input logic [DATA_WIDTH-1:0] pc_f,
    input logic [DATA_WIDTH-1:0] pc_save_f,
    output logic [DATA_WIDTH-1:0] instr_d,
    output logic [DATA_WIDTH-1:0] pc_d,
    output logic [DATA_WIDTH-1:0] pc_save_d
);

    always @(posedge clk) begin
        instr_d <= instr_f;
        pc_d <= pc_f;
        pc_save_d <= pc_f;
    end

endmodule