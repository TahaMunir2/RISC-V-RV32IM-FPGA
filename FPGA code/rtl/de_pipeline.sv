module de_pipeline #(
    DATA_WIDTH = 32
) (
    input logic clk,
    input logic flush,
    input logic enable,
    input logic rst,
    // data logic
    input logic [DATA_WIDTH-1:0] pc_save_d,
    input logic [DATA_WIDTH-1:0] RD1_d,
    input logic [DATA_WIDTH-1:0] RD2_d,
    input logic [DATA_WIDTH-1:0] pc_d,
    input logic [4:0] Rd_d,
    input logic [DATA_WIDTH-1:0] ImmExt_d,
    input logic [4:0] Rs1D,
    input logic [4:0] Rs2D,
    input logic [11:0] csr_addrD,
    output logic [DATA_WIDTH-1:0] pc_save_e,
    output logic [DATA_WIDTH-1:0] RD1_e,
    output logic [DATA_WIDTH-1:0] RD2_e,
    output logic [DATA_WIDTH-1:0] pc_e,
    output logic [4:0] Rd_e,
    output logic [DATA_WIDTH-1:0] ImmExt_e,
    output logic [4:0] Rs1E,
    output logic [4:0] Rs2E,
    output logic [11:0] csr_addrE,
    output logic [31:0] pc_e_spc,


    // control logic
    input logic RegWrite_d,
    input logic [1:0] ResultSrc_d,
    input logic MemWrite_d,
    //input logic Jump_d, NO NEED FOR JUMP IN OUT CIRCUIT, IT IS EMBEDED IN PCSRC AND ALUSRC2
    //input logic Branch_d,
    input logic [4:0] ALUCtrl_d,
    input logic ALUSrc_d,
    input logic [1:0] SizeWrite_d,
    input logic [1:0]LoadSize_d, 
    input logic LoadUnsigned_d,
    input logic ALUSrc2_d,
    input logic [1:0] csr_typeD,
    input logic ALUSrc3D,
    output logic RegWrite_e,
    output logic [1:0] ResultSrc_e,
    output logic MemWrite_e,
    //output logic Jump_e, NO NEED FOR JUMP IN OUT CIRCUIT, IT IS EMBEDED IN PCSRC AND ALUSRC2
    //output logic Branch_e,
    output logic [4:0] ALUCtrl_e,
    output logic ALUSrc_e,
    output logic [1:0] SizeWrite_e,
    output logic [1:0]LoadSize_e, 
    output logic LoadUnsigned_e,
    output logic ALUSrc2_e,
    output logic [1:0] csr_typeE,
    output logic ALUSrc3E,
    
    input logic [2:0] funct3D,
    output logic [2:0] funct3E,

    input logic BranchD,
    output logic BranchE,
    input logic JumpD,
    output logic JumpE,

    input logic pred_takenD,
    output logic pred_takenE
);

    always @(posedge clk) begin
        
        if (rst || flush) begin 
             // data
            pc_save_e <= 0;
            RD1_e <= 0;
            RD2_e <= 0;
            pc_e <= 0;
            Rd_e <= 0;
            ImmExt_e <= 0;
            csr_addrE <= 0;

            // control
            RegWrite_e <= 0;
            ResultSrc_e <= 0;
            MemWrite_e <= 0;
            //Branch_e <= 0;
            ALUCtrl_e <= 0;
            ALUSrc_e <= 0;
            SizeWrite_e <= 0;
            LoadSize_e <= 0;
            LoadUnsigned_e <= 0;
            ALUSrc2_e <= 0;
            Rs1E <= 0;
            Rs2E <= 0;
            funct3E <= 0;
            BranchE <= 0;
            JumpE <= 0;
            pred_takenE <=0;
            ALUSrc3E <= 0;
            csr_typeE <= 0;
        end
        

        else if(enable) begin
            // data
            pc_save_e <= pc_save_d;
            RD1_e <= RD1_d;
            RD2_e <= RD2_d;
            pc_e <= pc_d;
            Rd_e <= Rd_d;
            ImmExt_e <= ImmExt_d;
            csr_addrE <= csr_addrD;
            pc_e_spc <= pc_d;

            // control
            RegWrite_e <= RegWrite_d;
            ResultSrc_e <= ResultSrc_d;
            MemWrite_e <= MemWrite_d;
           // Branch_e <= Branch_d;
            ALUCtrl_e <= ALUCtrl_d;
            ALUSrc_e <= ALUSrc_d;
            SizeWrite_e <= SizeWrite_d;
            LoadSize_e <= LoadSize_d;
            LoadUnsigned_e <= LoadUnsigned_d;
            ALUSrc2_e <= ALUSrc2_d;
            Rs1E <= Rs1D;
            Rs2E <= Rs2D;
            funct3E <= funct3D;
            BranchE <= BranchD;
            JumpE <= JumpD;
            pred_takenE <= pred_takenD;
            ALUSrc3E <= ALUSrc3D;
            csr_typeE <= csr_typeD;

        end
    end

endmodule
