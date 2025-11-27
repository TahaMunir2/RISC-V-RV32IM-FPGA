module mw_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst,
    // data logic
    input logic [DATA_WIDTH-1:0] pc_save_m,
    input logic [DATA_WIDTH-1:0] Rd_m,
    input logic [DATA_WIDTH-1:0] ALU_Result_m,
    input logic [DATA_WIDTH-1:0] dout_m,    
    output logic [DATA_WIDTH-1:0] pc_save_w,
    output logic [DATA_WIDTH-1:0] Rd_w,
    output logic [DATA_WIDTH-1:0] ALU_Result_w,
    output logic [DATA_WIDTH-1:0] dout_w,

    // control logic
    input logic RegWrite_m,
    input logic [1:0] ResultSrc_m,
    output logic RegWrite_w,
    output logic [1:0] ResultSrc_w

);

    always @(posedge clk) begin
        
        if(rst) begin
            // data
            pc_save_w <= 0;
            Rd_w <= 0;
            ALU_Result_w <= 0;
            dout_w <= 0;

            // control
            RegWrite_w <= 0;
            ResultSrc_w <= 0;
        end
        
        else begin
            // data
            pc_save_w <= pc_save_m;
            Rd_w <= Rd_m;
            ALU_Result_w <= ALU_Result_m;
            dout_w <= dout_m;

            // control
            RegWrite_w <= RegWrite_m;
            ResultSrc_w <= ResultSrc_m;
        end
    end

endmodule
