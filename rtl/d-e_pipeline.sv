module d-e_pipeline #(
    DATA_WIDTH = 32
) (
    input clk,
    // data logic
    input logic [DATA_WIDTH-1:0] pc_save_d,
    input logic [DATA_WIDTH-1:0] RD1_d,
    input logic [DATA_WIDTH-1:0] RD2_d,
    input logic [DATA_WIDTH-1:0] pc_d,
    input logic [DATA_WIDTH-1:0] Rd_d,
    input logic [DATA_WIDTH-1:0] ImmExt_d,
    output logic [DATA_WIDTH-1:0] pc_save_e,
    output logic [DATA_WIDTH-1:0] RD1_e,
    output logic [DATA_WIDTH-1:0] RD2_e,
    output logic [DATA_WIDTH-1:0] pc_e,
    output logic [DATA_WIDTH-1:0] Rd_e,
    output logic [DATA_WIDTH-1:0] ImmExt_e,

    // control logic
    input logic RegWrite_d,
    input logic [1:0] ResultSrc_d,
    input logic MemWrite_d,
    input logic Jump_d,
    input logic Branch_d,
    input logic [3:0] ALUCtrl_d,
    input logic ALUSrc_d,
    input logic [1:0] SizeWrite_d,
    input logic [1:0]LoadSize_d, 
    input logic LoadUnsigned_d,
    input logic ALUSrc2_d,
    output logic RegWrite_e,
    output logic [1:0] ResultSrc_e,
    output logic MemWrite_e,
    output logic Jump_e,
    output logic Branch_e,
    output logic [3:0] ALUCtrl_e,
    output logic ALUSrc_e,
    output logic [1:0] SizeWrite_e
    output logic [1:0]LoadSize_e, 
    output logic LoadUnsigned_e,
    output logic ALUSrc2_e
);

    always @(posedge clk) begin
        // data
        pc_save_e <= pc_save_d;
        RD1_e <= RD1_d;
        RD2_e <= RD2_d;
        pc_e <= pc_d;
        Rd_e <= Rd_d;
        ImmExt_e <= ImmExt_d;

        // control
        RegWrite_e <= RegWrite_d;
        ResultSrc_e <= ResultSrc_d;
        MemWrite_e <= MemWrite_d;
        Jump_e <= Jump_d;
        Branch_e <= Branch_d;
        ALUCtrl_e <= ALUCtrl_d;
        ALUSrc_e <= ALUSrc_d;
        SizeWrite_e <= SizeWrite_d;
        LoadSize_e <= LoadSize_d;
        LoadUnsigned_e <= LoadUnsigned_d;
        ALUSrc2_e <= ALUSrc2_d;
    end

endmodule