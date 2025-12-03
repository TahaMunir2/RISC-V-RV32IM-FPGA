//Issue-Execute pipeline register:
module ie_pipeline #(
    parameter DATA_WIDTH = 32,
    parameter PROD_BITS = 6
) (
    input logic clk,
    input logic enable,
    input logic rst,

    //ALU operands
    input logic [DATA_WIDTH-1:0] ALU1_op1Iss,
    input logic [DATA_WIDTH-1:0] ALU1_op2Iss,
    input logic [DATA_WIDTH-1:0] ALU2_op1Iss,
    input logic [DATA_WIDTH-1:0] ALU2_op2Iss,
    output logic [DATA_WIDTH-1:0] ALU1_op1E,
    output logic [DATA_WIDTH-1:0] ALU1_op2E,
    output logic [DATA_WIDTH-1:0] ALU2_op1E,
    output logic [DATA_WIDTH-1:0] ALU2_op2E,

    //ALU control signals
    input logic [3:0] ALU1CtrlIss,
    input logic [3:0] ALU2CtrlIss,
    output logic [3:0] ALU1CtrlE,
    output logic [3:0] ALU2CtrlE,

    //propagation of the destination tag signal:
    input logic [PROD_BITS-1 :0] ALU1_dest_tagIss,
    input logic [PROD_BITS-1 :0] ALU2_dest_tagIss,
    output logic [PROD_BITS-1 :0] ALU1_dest_tagE,
    output logic [PROD_BITS-1 :0] ALU2_dest_tagE
);

    always @(posedge clk) begin

        if (rst) begin
            ALU1_op1E <= 0;
            ALU1_op2E <= 0;
            ALU2_op1E <= 0;
            ALU2_op2E <= 0;
            ALU1CtrlE <= 0;
            ALU2CtrlE <= 0; 
            ALU1_dest_tagE <= 0;
            ALU2_dest_tagE <= 0;
        end
        
        else if(enable) begin
            ALU1_op1E <= ALU1_op1Iss;
            ALU1_op2E <= ALU1_op2Iss;
            ALU2_op1E <= ALU2_op1Iss;
            ALU2_op2E <= ALU2_op2Iss;
            ALU1CtrlE <= ALU1CtrlIss;
            ALU2CtrlE <= ALU2CtrlIss; 
            ALU1_dest_tagE <= ALU1_dest_tagIss;
            ALU2_dest_tagE <= ALU2_dest_tagIss;
        end

    end

endmodule

