module mw_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst,
    input logic enable,
    // data logic
    input logic [DATA_WIDTH-1:0] pc_save_m,
    input logic [4:0] Rd_m,
    input logic [DATA_WIDTH-1:0] ALU_Result_m,
    input logic [DATA_WIDTH-1:0] dout_m,    
    input logic [11:0] csr_addrM,
    output logic [DATA_WIDTH-1:0] pc_save_w,
    output logic [4:0] Rd_w,
    output logic [DATA_WIDTH-1:0] ALU_Result_w,
    output logic [DATA_WIDTH-1:0] dout_w,
    output logic [11:0] csr_addrW,
    

    // control logic
    input logic RegWrite_m,
    input logic [1:0] ResultSrc_m,
    input logic [1:0] csr_typeM,
    output logic RegWrite_w,
    output logic [1:0] ResultSrc_w,
    output logic [1:0] csr_typeW

);

    always @(posedge clk) begin
        
        if(rst) begin
            // data
            pc_save_w <= 0;
            Rd_w <= 0;
            ALU_Result_w <= 0;
            dout_w <= 0;
            csr_addrW <= 0;

            // control
            RegWrite_w <= 0;
            ResultSrc_w <= 0;
            csr_typeW <= 0;
        end
        
        else if (enable) begin
            // data
            pc_save_w <= pc_save_m;
            Rd_w <= Rd_m;
            ALU_Result_w <= ALU_Result_m;
            dout_w <= dout_m;
            csr_addrW <= csr_addrM;

            // control
            RegWrite_w <= RegWrite_m;
            ResultSrc_w <= ResultSrc_m;
            csr_typeW <= csr_typeM;
        end
    end

endmodule
