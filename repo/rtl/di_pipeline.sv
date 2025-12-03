module di_pipeline #(
    parameter DATA_WIDTH = 32,
    parameter PROD_BITS = 6
)(
    input logic clk,
    input logic enable,
    input logic rst,

    // data logic
    input logic [DATA_WIDTH-1 :0] ALU1_op1D,
    input logic [DATA_WIDTH-1 :0] ALU1_op2D,
    input logic [DATA_WIDTH-1 :0] ALU2_op1D,
    input logic [DATA_WIDTH-1 :0] ALU2_op2D,
    output logic [DATA_WIDTH-1 :0] ALU1_op1I,
    output logic [DATA_WIDTH-1 :0] ALU1_op2I,
    output logic [DATA_WIDTH-1 :0] ALU2_op1I,
    output logic [DATA_WIDTH-1 :0] ALU2_op2I,

    // control logic
    input logic [3:0] ALUCtrl1_d,
    output logic [3:0] ALUCtrl1_i,
    input logic [3:0] ALUCtrl2_d,
    output logic [3:0] ALUCtrl2_i,

    //propagating the destination tags
    input logic [PROD_BITS-1 : 0] instr1_tag_d,
    input logic [PROD_BITS-1 : 0] instr2_tag_d,
    output logic [PROD_BITS-1 : 0] instr1_tag_i,
    output logic [PROD_BITS-1 : 0] instr2_tag_i,

    //propagating enable signals to avoid hazards when we have no-ops:
    input logic instr1_alloc_rob,
    input logic instr2_alloc_rob,
    output logic Instr1_enableRUU,
    output logic Instr2_enableRUU,

    //propagating the validity of the sources:
    input logic validity_source1,
    input logic validity_source2,
    input logic validity_source3,
    input logic validity_source4,

    output logic validity_source1I,
    output logic validity_source2I,
    output logic validity_source3I,
    output logic validity_source4I,

    //propagating the source tags: 
    input logic [PROD_BITS-1 :0] tag_source1,
    input logic [PROD_BITS-1 :0] tag_source2,
    input logic [PROD_BITS-1 :0] tag_source3,
    input logic [PROD_BITS-1 :0] tag_source4,

    output logic [PROD_BITS-1 :0] tag_source1I,
    output logic [PROD_BITS-1 :0] tag_source2I,
    output logic [PROD_BITS-1 :0] tag_source3I,
    output logic [PROD_BITS-1 :0] tag_source4I
);

    always_ff @(posedge clk) begin
            
            if (rst) begin 
                // data
                ALU1_op1I <= '0;
                ALU1_op2I <= '0;
                ALU2_op1I <= '0;
                ALU2_op2I <= '0;

                // control
                ALUCtrl1_i <= '0;
                ALUCtrl2_i <= '0;
                // destination tags
                instr1_tag_i <= '0;
                instr2_tag_i <= '0;
                Instr1_enableRUU <= '0;
                Instr2_enableRUU <= '0;

                validity_source1I <= '0;
                validity_source2I <= '0;
                validity_source3I <= '0;
                validity_source4I <= '0;

                tag_source1I <= '0;
                tag_source2I <= '0;
                tag_source3I <= '0;
                tag_source4I <= '0;

            end
            
            else if (enable) begin
                // data
                ALU1_op1I <= ALU1_op1D;
                ALU1_op2I <= ALU1_op2D;
                ALU2_op1I <= ALU2_op1D;
                ALU2_op2I <=ALU2_op2D;

                // control
                ALUCtrl1_i <= ALUCtrl1_d;
                ALUCtrl2_i <= ALUCtrl2_d;
                // destination tags
                instr1_tag_i <= instr1_tag_d;
                instr2_tag_i <= instr2_tag_d;

                Instr1_enableRUU <= instr1_alloc_rob;
                Instr2_enableRUU <= instr2_alloc_rob;

                validity_source1I <= validity_source1;
                validity_source2I <= validity_source2;
                validity_source3I <= validity_source3;
                validity_source4I <= validity_source4;

                tag_source1I <= tag_source1;
                tag_source2I <= tag_source2;
                tag_source3I <= tag_source3;
                tag_source4I <= tag_source4;
                
            end
        end

endmodule
