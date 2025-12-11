module control #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    output logic RegWrite,
    output logic [4:0] ALUCtrl, //!!!!!!!!!!!!!!!Size of the signal changed from 3 bits to 4 bits !!!!!!!!!!!!!!!!!!!!!!!!!
    output logic ALUSrc,
    output logic [2:0] ImmSrc,
    output logic [1:0] ResultSrc, //adding the aditional output representing the select line of the additional multiplexer in the regaludmem block
    output logic MemWrite,
    output logic [1:0]SizeWrite, //!!!!!!!!!!!!!!!CHANGE from ByteWrite to SizeWrite (size of that signal changed) !!!!!!!!!!!!!!!!!!!!!!!!!
    output logic ALUsrc2, //additional output signal
    output logic [1:0]LoadSize, //additional output signal
    output logic LoadUnsigned, //additional output signal
    output logic Jump,
    output logic Branch,
    output logic [2:0] funct3OUT,
    output logic [1:0] csr_type,
    output logic ALUSrc3, // if high then pick immext instead of RS1
	 output logic mret_en

);


logic [6:0] op;
logic [2:0] funct3;
logic [6:0] funct7;
assign op = instr[6:0];
assign funct3 = instr[14:12];
assign funct7 = instr [31:25];

assign funct3OUT = funct3;

logic [6:0] imm_11_5;
assign imm_11_5 = instr[31:25];


    // Opcodes
// 1. Logic Declarations
logic [6:0] OPC_LUI;
logic [6:0] OPC_AUIPC;
logic [6:0] OPC_JAL;
logic [6:0] OPC_JALR;
logic [6:0] OPC_BRANCH;
logic [6:0] OPC_LOAD;
logic [6:0] OPC_STORE;
logic [6:0] OPC_OPIMM;
logic [6:0] OPC_OP;
logic [6:0] OPC_CSR;

// 2. Continuous Assignments
assign OPC_LUI    = 7'b0110111;
assign OPC_AUIPC  = 7'b0010111;
assign OPC_JAL    = 7'b1101111;
assign OPC_JALR   = 7'b1100111;
assign OPC_BRANCH = 7'b1100011;
assign OPC_LOAD   = 7'b0000011;
assign OPC_STORE  = 7'b0100011;
assign OPC_OPIMM  = 7'b0010011;
assign OPC_OP     = 7'b0110011;
assign OPC_CSR    = 7'b1110011;
    always_comb begin
    

        RegWrite  = 0;
        ALUCtrl   = 5'b0000; //indicates which operation takes place in the ALU
        ALUSrc    = 0; //indicates of the second operand is a register (ALUsrc = 0) or an immediate (ALUsrc = 1)
        ImmSrc    = 3'b000; //how to obtain the immediate value (control bit for the signext module)
        Jump = 0;
        Branch =0;
        ResultSrc = 0; //result taken from the ALU, from the datamem or from pc
        MemWrite  = 0; //enabling writing to memory
        SizeWrite = 0; //byte addressing or word addressing
        ALUsrc2 = 0; //indicates if the second source of the ALU is rs1 (ALUsrc2 =0) or the current value of pc from pc_save (ALUsrc2 =1)
        LoadSize     = 2'b10; // default=word
        LoadUnsigned = 1'b0;  // signed by default
        ALUSrc3 = 1'b0;
        csr_type = 2'b00;
		  mret_en   = 1'b0;


        case(op)

            // Upper types
            //Load Upper Immediate
            OPC_LUI: begin    RegWrite  = 1;
                        ALUCtrl = 5'b1010;
                        ALUSrc    = 1;
                        ImmSrc    = 3'b100; // =4 so we take the upper 20 bits of the instruction as an immediate
                        Jump    = 0; 
                        Branch    = 0; 
                        ResultSrc = 0;
                        MemWrite  = 0;
                        SizeWrite = 0;
                        ALUsrc2 = 0;
            end
            //Add Upper Immediate AND Program Counter and store it into the destination register (RD)
            OPC_AUIPC:begin  RegWrite  = 1;
                        ALUCtrl   = 5'b1011; 
                        ALUSrc    = 1;
                        ImmSrc    = 3'b100;
                        Jump =0;
                        Branch =0;
                        ResultSrc = 0;
                        MemWrite  = 0;
                        SizeWrite = 0;
                        ALUsrc2 = 1; //WE WANT THE VALUE OF PC AS OPERAND INTO THE ALU (AND NOT THE RS1) (but it is not the same value of pc because we need the value of pc of the current cycle and not the one corresponding to the next cycle)
            end
            //Jump And Link
            OPC_JAL:begin    RegWrite = 1; // as we are saving the old value in the destination register specified when calling this instruction
                        ALUCtrl = 5'b0; // doesn't matter, ALU not used
                        ALUSrc = 0; // //doesn't matter
                        ImmSrc = 3'b11; // 11 for j type instruction
                        Jump = 1; // for adding an offset to PC
                        Branch =0;
                        ResultSrc = 2'b10; // don't care
                        MemWrite = 0; // don't care
                        SizeWrite = 0; // don't care
            end
            // Jump And Link Register
            OPC_JALR:begin   RegWrite = 1; // as we are saving the old value
                        ALUCtrl = 5'b0; // we need to add r1 and imm
                        ALUSrc = 1; // to add imm
                        ImmSrc = 3'b000; // not j type -> we need 12 bit immediate (I-type)
                        Jump = 1; // for adding an offset to PC and register
                        Branch = 0;
                        ResultSrc = 2'b10; // don't care
                        MemWrite = 0; // don't care
                        SizeWrite = 0; // don't care
                       
            end
//3 important signals in the branch instructions:
//EQ = EQUAL
//LT = LESS THEN
//LTU = LESS THEN UNSIGNED


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//THIS WHOLE CODE CAN BE SIMPLIFIED BECAUSE ALL THE BRANCHES OUTPUT THE SAME IN THIS NEW CONFIGURATION OF THE CONTROL UNIT
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //  Branch Instruction
            OPC_BRANCH: begin
                //Branch = 1;
                case (funct3)

                    //Branch If Equal (BEQ)
                    3'b000:begin
                            RegWrite  = 0;
                            ALUCtrl   = 5'b001;
                            ALUSrc    = 0;
                            ImmSrc    = 3'b010;
                            MemWrite  = 0; // don't care
                            SizeWrite = 0;
                            Jump =0;
                            Branch =1;
                            ResultSrc = 0; // don't care (no regfile write)         
                    end
                    
                    3'b001:begin
                            RegWrite = 0;
                            ALUCtrl = 5'b001;
                            ALUSrc = 0;
                            ImmSrc = 3'b010;
                            MemWrite = 0; // don't care
                            SizeWrite = 0;
                            Jump =0;
                            Branch = 1;
                            ResultSrc = 0; //Don't care can take any value (because we are not writing to the regfile)
                    end

                    //Less Then (Signed)
                    3'b100:begin
                            RegWrite  = 0;
                            ALUCtrl   = 5'b001;
                            ALUSrc    = 0;
                            ImmSrc    = 3'b010;
                            MemWrite  = 0; // don't care
                            SizeWrite = 0;
                            Jump =0;
                            Branch =1;
                            ResultSrc = 0; // don't care
                    end

                    3'b101:begin
                            RegWrite  = 0;
                            ALUCtrl   = 5'b001;
                            ALUSrc    = 0;
                            ImmSrc    = 3'b010;
                            MemWrite  = 0; // don't care
                            SizeWrite = 0;
                            Jump =0;
                            Branch =1;
                            ResultSrc = 0; // don't care

                    end

                    //Less Then (Unsigned)
                    3'b110:begin
                            RegWrite  = 0;
                            ALUCtrl   = 5'b001;
                            ALUSrc    = 0;
                            ImmSrc    = 3'b010;
                            MemWrite  = 0; // don't care
                            SizeWrite = 0;
                            Jump =0;
                            Branch =1;
                            ResultSrc = 0; // don't care

                    end
                    3'b111:begin
                            RegWrite  = 0;
                            ALUCtrl   = 5'b001;
                            ALUSrc    = 0;
                            ImmSrc    = 3'b010;
                            MemWrite  = 0; // don't care
                            SizeWrite = 0;
                            Jump =0;
                            Branch =1;
                            ResultSrc = 0; // don't care

                    end
                    default:begin
                                RegWrite  = 0;
                                ALUCtrl   = 5'b000; //indicates which operation takes place in the ALU
                                ALUSrc    = 0; //indicates of the second operand is a register (ALUsrc = 0) or an immediate (ALUsrc = 1)
                                ImmSrc    = 3'b000; //how to obtain the immediate value (control bit for the signext module)
                                Jump =0; 
                                Branch =1;
                                ResultSrc = 0; //result taken from the ALU, from the datamem or from pc
                                MemWrite  = 0; //enabling writing to memory
                                SizeWrite = 0; //byte addressing or word addressing
                                ALUsrc2 = 0; //indicates if the second source of the ALU is rs1 (ALUsrc2 =0) or the current value of pc from pc_save (ALUsrc2 =1);
                    end
                endcase
            end


            //LOAD_INSTRUCTIONS
            OPC_LOAD: begin

                RegWrite  = 1;
                ALUCtrl   = 5'b000;
                ALUSrc    = 1;
                ImmSrc    = 3'b000;
                Branch     = 0;
                Jump =0;
                MemWrite  = 0;
                ResultSrc = 2'b01;
                SizeWrite = 0; // don't care for loads


 //2 IMPORTANT ADDITIONAL SIGNALS FOR LOAD INSTRUCTIONS:
 //the size of the data we are loading in bytes
 //A 1-bit signal indicating if the the load is signed or unsigned
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
                        LoadSize  = 2'b10;// word
                        LoadUnsigned = 1'b0;  // signed
                    end
                endcase

            end



            // Store instructions
            OPC_STORE: begin

                // SB
                if (funct3 == 3'b000) begin
                    RegWrite  = 0;
                    ALUCtrl   = 5'b000;   // ADD
                    ALUSrc    = 1'b1;     // immediate
                    ImmSrc    = 3'b001;   // S-type imm
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;    // don't care
                    MemWrite  = 1;        // write to memory
                    SizeWrite = 2'b00;    // BYTE
                end

                // SH
                else if (funct3 == 3'b001) begin
                    RegWrite  = 0;
                    ALUCtrl   = 5'b000;
                    ALUSrc    = 1'b1;
                    ImmSrc    = 3'b001;
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;
                    MemWrite  = 1;
                    SizeWrite = 2'b01;    // HALFWORD
                end

                // SW
                else if (funct3 == 3'b010) begin
                    RegWrite  = 0;
                    ALUCtrl   = 5'b000;
                    ALUSrc    = 1'b1;
                    ImmSrc    = 3'b001;
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;
                    MemWrite  = 1;
                    SizeWrite = 2'b10;    // WORD
                end

            end

            // OP-IMM: I-type ALU instructions
            OPC_OPIMM: begin

                // ADDI
                if (funct3 == 3'b000) begin
                    RegWrite  = 1;
                    ALUCtrl   = 5'b0000;   // ADD
                    ALUSrc    = 1;         // rs1 + imm
                    ImmSrc    = 3'b000;    // I-type immediate
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;     // from ALU
                    MemWrite  = 0;
                    ALUsrc2   = 0;         // operand A = rs1
                end

                // SLTI (signed)
                else if (funct3 == 3'b010) begin
                    RegWrite  = 1;
                    ALUCtrl   = 5'b1000;   // SLT (signed less-than)
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;
                    MemWrite  = 0;
                    ALUsrc2   = 0;
                end

                // SLTIU (unsigned)
                else if (funct3 == 3'b011) begin
                    RegWrite  = 1;
                    ALUCtrl   = 5'b1001;   // SLTU (unsigned less-than)
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;
                    MemWrite  = 0;
                    ALUsrc2   = 0;
                end

                //XORI
                else if (funct3 == 3'b100) begin
                    RegWrite  = 1;
                    ALUCtrl   = 5'b0100;   // XOR
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;
                    MemWrite  = 0;
                    ALUsrc2   = 0;
                end

                //ORI
                else if (funct3 == 3'b110) begin
                    RegWrite  = 1;
                    ALUCtrl   = 5'b0011;   // OR
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;
                    MemWrite  = 0;
                    ALUsrc2   = 0;
                end

                //ANDI
                else if (funct3 == 3'b111) begin
                    RegWrite  = 1;
                    ALUCtrl   = 5'b0010;   // AND
                    ALUSrc    = 1;
                    ImmSrc    = 3'b000;
                    Branch     =0;    // normal PC+4
                    Jump =0;
                    ResultSrc = 2'b00;
                    MemWrite  = 0;
                    ALUsrc2   = 0;
                end

                // SLLI (shift left logical imm)
                else if (funct3 == 3'b001) begin
                    if (imm_11_5 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0101;   // SLL
                        ALUSrc    = 1;         // immediate contains shamt in [24:20]
                        ImmSrc    = 3'b000;    // I-type (shamt extraction done in ALU)
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end
                    else begin
                        // illegal encoding (reserved imm[11:5])
                        RegWrite  = 0;
                    end
                end

                //SRLI / SRAI (shift right immediate)
                else if (funct3 == 3'b101) begin
                    if (imm_11_5 == 7'b0000000) begin
                        // SRLI
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0110;   // SRL (logical right shift)
                        ALUSrc    = 1;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end
                    else if (imm_11_5 == 7'b0100000) begin
                        // SRAI
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0111;   // SRA (arithmetic right shift)
                        ALUSrc    = 1;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end
                    else begin
                        // illegal encoding for shift-immediate
                        RegWrite  = 0;
                    end
                end

                // anything else under OPC_OPIMM
                else begin
                    RegWrite = 0;  // illegal / not implemented
                end

            end




            //OP (R-type ALU)
            OPC_OP: begin

                // ADD / SUB
                if (funct3 == 3'b000) begin

                    // ADD
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0000;   // ADD
                        ALUSrc    = 0;         // rs2
                        ImmSrc    = 3'b000;    // don't care for R-type
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;     // from ALU
                        MemWrite  = 0;
                        ALUsrc2   = 0;         // A = rs1
                    end

                    // SUB
                    else if (funct7 == 7'b0100000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0001;   // SUB
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end

                    //MUL
                    else if(funct7 == 7'b0000001) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b1100; //MUL
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;

                    end
                    else begin
                        RegWrite = 0;          // illegal encoding
                    end
                end



                //SLL
                else if (funct3 == 3'b001) begin
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0101;   // SLL
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end

                    //MULH
                    else if (funct7 == 7'b0000001)begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b1101; //MULH
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;

                    end 
                    else begin
                        RegWrite = 0;
                    end
                end

                //SLT (signed)
                else if (funct3 == 3'b010) begin
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b1000;   // SLT (signed)
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end
                    //MULHU
                    else if (funct7 == 7'b0000001)begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b1110; //MULHU
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                        
                    end
                    else if (funct7 == 7'b0010000)begin // sh1add
                        RegWrite = 1;
                        ALUCtrl = 5'b10100;
                    end
                    else begin
                        RegWrite = 0;
                    end
                end

                //SLTU (unsigned)
                else if (funct3 == 3'b011) begin
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b1001;   // SLTU (unsigned)
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end

                    //MULHSU
                    else if (funct7 == 7'b0000001)begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b1111; //MULHSU
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                        
                    end 
                    else begin
                        RegWrite = 0;
                    end
                end

                //XOR
                else if (funct3 == 3'b100) begin
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0100;   // XOR
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end

                    //DIV
                    else if (funct7 == 7'b0000001)begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b10000; //DIV
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                        
                    end 
                    else if (funct7 == 7'b0010000)begin // sh2add
                        RegWrite = 1;
                        ALUCtrl = 5'b10101;
                    end
                    else begin
                        RegWrite = 0;
                    end
                end

                //SRL / SRA
                else if (funct3 == 3'b101) begin

                    // SRL
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0110;   // SRL
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end

                    // SRA
                    else if (funct7 == 7'b0100000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0111;   // SRA
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end

                    //DIVU
                    else if (funct7 == 7'b0000001)begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b10001; //DIVU
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                        
                    end 

                    else begin
                        RegWrite = 0;
                    end
                end

                //OR
                else if (funct3 == 3'b110) begin
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0011;   // OR
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end

                    //REM
                    else if (funct7 == 7'b0000001)begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b10010; //REM
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end 

                    else if (funct7 == 7'b0010000)begin // sh3add
                        RegWrite = 1;
                        ALUCtrl = 5'b10110;
                    end

                    else begin
                        RegWrite = 0;
                    end
                end

                //AND
                else if (funct3 == 3'b111) begin
                    if (funct7 == 7'b0000000) begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b0010;   // AND
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;    // normal PC+4
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                    end


                    //REMU
                    else if (funct7 == 7'b0000001)begin
                        RegWrite  = 1;
                        ALUCtrl   = 5'b10011; //REMU
                        ALUSrc    = 0;
                        ImmSrc    = 3'b000;
                        Branch     =0;
                        Jump =0;
                        ResultSrc = 2'b00;
                        MemWrite  = 0;
                        ALUsrc2   = 0;
                        
                    end
                    else begin
                        RegWrite = 0;
                    end
                end
                

                //illegal funct3
                else begin
                    RegWrite = 0;
                end

            end

            OPC_CSR: begin
                csr_type = funct3[1:0];
                ALUSrc3 = funct3[2];


                if(funct3 == 3'b001) RegWrite = 1'b1; // CSSRW
                if(funct3 == 3'b010) RegWrite = 1'b1; // CSSRS
                if(funct3 == 3'b011) RegWrite = 1'b1; // CSSRC
                
                if(funct3 == 3'b101) begin // CSSRWI
                    RegWrite = 1'b1;
                    ALUSrc3 = 1'b1; // to pick the int
                    ImmSrc = 3'b101; // for CSR--I instructions
                end
                
                if(funct3 == 3'b110) begin // CSSRSI
                    RegWrite = 1'b1;
                    ALUSrc3 = 1'b1;
                    ImmSrc = 3'b101;
                end 
                
                if(funct3 == 3'b111) begin // CSSRCI
                    RegWrite = 1'b1;
                    ALUSrc3 = 1'b1;
                    ImmSrc = 3'b101; 
                end
					 
					 if (funct3 == 3'b000 && funct7 == 7'b0011000) begin // mret
                    mret_en = 1'b1;
                end
					 
            end
				
				default: begin
					RegWrite = 0;
				end
        endcase
    end
endmodule


