module e-m_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst,
    // data logic
    input logic [DATA_WIDTH-1:0] pc_save_e,
    input logic [DATA_WIDTH-1:0] Rd_e,
    input logic [DATA_WIDTH-1:0] ALU_Result_e,
    input logic [DATA_WIDTH-1:0] Write_Data_e,
    output logic [DATA_WIDTH-1:0] pc_save_m,
    output logic [DATA_WIDTH-1:0] Rd_m,
    output logic [DATA_WIDTH-1:0] ALU_Result_m,
    output logic [DATA_WIDTH-1:0] RD2_m,
    

    // control logic
    input logic RegWrite_e,
    input logic [1:0] ResultSrc_e,
    input logic MemWrite_e,
    input logic [1:0] SizeWrite_e,
    input logic [1:0]LoadSize_e, 
    input logic LoadUnsigned_e,
    output logic RegWrite_m,
    output logic [1:0] ResultSrc_m,
    output logic MemWrite_m,
    output logic [1:0] SizeWrite_m
    output logic [1:0]LoadSize_m, 
    output logic LoadUnsigned_m
);

    always @(posedge clk) begin
      

        if (rst) begin
            //data
            pc_save_m <= 0;
            Rd_m <= 0;
            ALU_Result_m <= 0;
            Write_Data_m <= 0;

            // control
            RegWrite_m <= 0;
            ResultSrc_m <= 0;
            MemWrite_m <= 0;
            SizeWrite_m <= 0;
            LoadSize_m <= 0;
            LoadUnsigned_m <= 0;
        end

        else begin
            //data
            pc_save_m <= pc_save_e;
            Rd_m <= Rd_e;
            ALU_Result_m <= ALU_Result_e;
            Write_Data_m <= Write_Data_e;

            // control
            RegWrite_m <= RegWrite_e;
            ResultSrc_m <= ResultSrc_e;
            MemWrite_m <= MemWrite_e;
            SizeWrite_m <= SizeWrite_e;
            LoadSize_m <= LoadSize_e;
            LoadUnsigned_m <= LoadUnsigned_e;
        end
    end

endmodule