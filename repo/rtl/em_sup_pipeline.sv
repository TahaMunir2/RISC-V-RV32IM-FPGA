module em_sup_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst,

    // control logic
    input logic [1:0] ResultSrc1_e,
    input logic [1:0]LoadSize1_e, 
    input logic LoadUnsigned1_e,
    output logic [1:0] ResultSrc1_m,
    output logic [1:0]LoadSize1_m, 
    output logic LoadUnsigned1_m,

    input logic [1:0] ResultSrc2_e,
    input logic [1:0]LoadSize2_e, 
    input logic LoadUnsigned2_e,
    output logic [1:0] ResultSrc2_m,
    output logic [1:0]LoadSize2_m, 
    output logic LoadUnsigned2_m,

    input logic [DATA_WIDTH-1 :0] address1_e, //value of RS1
    output logic [DATA_WIDTH-1 :0]address1_m,
    input logic [DATA_WIDTH-1 :0] address2_e,
    output logic [DATA_WIDTH-1 :0] address2_m,

    input logic [5:0] ALU1_tagE,
    input logic [5:0] ALU2_tagE,
    output logic [5:0]ALU1_tagM,
    output logic [5:0]ALU2_tagM
);

    always @(posedge clk) begin
      

        if (rst) begin

            // control
            ResultSrc1_m <= 0;
            LoadSize1_m <= 0;
            LoadUnsigned1_m <= 0;

            ResultSrc2_m <= 0;
            LoadSize2_m <= 0;
            LoadUnsigned2_m <= 0;
            address1_m <= 0;
            address2_m <= 0;
            ALU1_tagM <= 0;
            ALU2_tagM <= 0;
        end

        else begin

            // control
            ResultSrc1_m <= ResultSrc1_e;
            LoadSize1_m <= LoadSize1_e;
            LoadUnsigned1_m <= LoadUnsigned1_e;

            ResultSrc2_m <= ResultSrc2_e;
            LoadSize2_m <= LoadSize2_e;
            LoadUnsigned2_m <= LoadUnsigned2_e;

            address1_m <= address1_e;
            address2_m <= address2_e;
            ALU1_tagM <= ALU1_tagE;
            ALU2_tagM <= ALU2_tagE;
        end
    end

endmodule
