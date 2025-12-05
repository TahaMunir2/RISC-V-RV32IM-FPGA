module sup_control #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    output logic [3:0] ALUCtrl,
    output logic ALUSrc,
    output logic [2:0] ImmSrc,
    output logic ALUsrc2,
    output logic [1:0] ResultSrc,
    output logic [1:0] LoadSize,
    output logic LoadUnsigned
);


logic [6:0] op;
logic [2:0] funct3;
logic [6:0] funct7;
assign op = instr[6:0];
assign funct3 = instr[14:12];
assign funct7 = instr [31:25];

logic [6:0] imm_11_5;
assign imm_11_5 = instr[31:25];


    // Opcodes
    logic [6:0]
        OPC_LUI    = 7'b0110111,
        OPC_AUIPC  = 7'b0010111,
        OPC_LOAD   = 7'b0000011,
        OPC_OPIMM  = 7'b0010011,
        OPC_OP     = 7'b0110011;

    always_comb begin
    
        ALUCtrl      = 4'b0000;
        ALUSrc       = 0;
        ImmSrc       = 3'b000;
        ALUsrc2      = 0;
        ResultSrc    = 2'b00;
        LoadSize     = 2'b10;  // default = word
        LoadUnsigned = 1'b0;   // signed by default

        case(op)

            // Upper types
            // Load Upper Immediate
            OPC_LUI: begin
                ALUCtrl   = 4'b1010;
                ALUSrc    = 1;
                ImmSrc    = 3'b100;
                ALUsrc2   = 0;
                ResultSrc = 2'b00;
            end

            // Add Upper Immediate AND Program Counter
            OPC_AUIPC: begin
                ALUCtrl   = 4'b1011;
                ALUSrc    = 1;
                ImmSrc    = 3'b100;
                ALUsrc2   = 1;
                ResultSrc = 2'b00;
            end

            // LOAD INSTRUCTIONS
            OPC_LOAD: begin
                ALUCtrl   = 4'b0000;  // ADD (for address calculation)
                ALUSrc    = 1;        // immediate
                ImmSrc    = 3'b000;   // I-type immediate
                ALUsrc2   = 0;
                ResultSrc = 2'b01;    // result from data memory

                case (funct3)
                    3'b000: begin // LB
                        LoadSize     = 2'b00;
                        LoadUnsigned = 1'b0;
                    end
                    3'b001: begin // LH
                        LoadSize     = 2'b01;
                        LoadUnsigned = 1'b0;
                    end
                    3'b010: begin // LW
                        LoadSize     = 2'b10;
                        LoadUnsigned = 1'b0;
                    end
                    3'b100: begin // LBU
                        LoadSize     = 2'b00;
                        LoadUnsigned = 1'b1;
                    end
                    3'b101: begin // LHU
                        LoadSize     = 2'b01;
                        LoadUnsigned = 1'b1;
                    end
                    default: begin
                        LoadSize     = 2'b10;  // word
                        LoadUnsigned = 1'b0;   // signed
                    end
                endcase
            end

            // OP-IMM: I-type ALU instructions
            OPC_OPIMM: begin

                // ADDI
                if (funct3 == 3'b000) begin
                    ALUCtrl   = 4'b0000;
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    ALUsrc2   = 0;
                    ResultSrc = 2'b00;
                end

                // SLTI (signed)
                else if (funct3 == 3'b010) begin
                    ALUCtrl   = 4'b1000;
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    ALUsrc2   = 0;
                    ResultSrc = 2'b00;
                end

                // SLTIU (unsigned)
                else if (funct3 == 3'b011) begin
                    ALUCtrl   = 4'b1001;
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    ALUsrc2   = 0;
                    ResultSrc = 2'b00;
                end

                // XORI
                else if (funct3 == 3'b100) begin
                    ALUCtrl   = 4'b0100;
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    ALUsrc2   = 0;
                    ResultSrc = 2'b00;
                end

                // ORI
                else if (funct3 == 3'b110) begin
                    ALUCtrl   = 4'b0011;
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    ALUsrc2   = 0;
                    ResultSrc = 2'b00;
                end

                // ANDI
                else if (funct3 == 3'b111) begin
                    ALUCtrl   = 4'b0010;
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    ALUsrc2   = 0;
                    ResultSrc = 2'b00;
                end

                // SLLI (shift left logical imm)
                else if (funct3 == 3'b001) begin
                    if (imm_11_5 == 7'b0000000) begin
                        ALUCtrl   = 4'b0101;
                        ALUSrc    = 1;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // SRLI / SRAI (shift right immediate)
                else if (funct3 == 3'b101) begin
                    if (imm_11_5 == 7'b0000000) begin
                        // SRLI
                        ALUCtrl   = 4'b0110;
                        ALUSrc    = 1;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                    else if (imm_11_5 == 7'b0100000) begin
                        // SRAI
                        ALUCtrl   = 4'b0111;
                        ALUSrc    = 1;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end
            end

            // OP (R-type ALU)
            OPC_OP: begin

                // ADD / SUB
                if (funct3 == 3'b000) begin
                    if (funct7 == 7'b0000000) begin
                        // ADD
                        ALUCtrl   = 4'b0000;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                    else if (funct7 == 7'b0100000) begin
                        // SUB
                        ALUCtrl   = 4'b0001;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // SLL
                else if (funct3 == 3'b001) begin
                    if (funct7 == 7'b0000000) begin
                        ALUCtrl   = 4'b0101;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // SLT (signed)
                else if (funct3 == 3'b010) begin
                    if (funct7 == 7'b0000000) begin
                        ALUCtrl   = 4'b1000;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // SLTU (unsigned)
                else if (funct3 == 3'b011) begin
                    if (funct7 == 7'b0000000) begin
                        ALUCtrl   = 4'b1001;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // XOR
                else if (funct3 == 3'b100) begin
                    if (funct7 == 7'b0000000) begin
                        ALUCtrl   = 4'b0100;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // SRL / SRA
                else if (funct3 == 3'b101) begin
                    if (funct7 == 7'b0000000) begin
                        // SRL
                        ALUCtrl   = 4'b0110;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                    else if (funct7 == 7'b0100000) begin
                        // SRA
                        ALUCtrl   = 4'b0111;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // OR
                else if (funct3 == 3'b110) begin
                    if (funct7 == 7'b0000000) begin
                        ALUCtrl   = 4'b0011;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end

                // AND
                else if (funct3 == 3'b111) begin
                    if (funct7 == 7'b0000000) begin
                        ALUCtrl   = 4'b0010;
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        ALUsrc2   = 0;
                        ResultSrc = 2'b00;
                    end
                end
            end

            default: begin
                ALUCtrl      = 4'b0000;
                ALUSrc       = 0;
                ImmSrc       = 3'b000;
                ALUsrc2      = 0;
                ResultSrc    = 2'b00;
                LoadSize     = 2'b10;
                LoadUnsigned = 1'b0;
            end
        endcase
    end
endmodule

