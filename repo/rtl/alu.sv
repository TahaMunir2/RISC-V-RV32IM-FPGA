module alu#(
    DATA_WIDTH=32
    )(
    input logic [DATA_WIDTH-1:0] ALUop1, //RS1 or PCsave
    input logic [DATA_WIDTH-1:0] ALUop2, //RS2 or IMM
    input logic  [4:0]           ALUCtrl, //ALUCtrl is now 4 bits (in order to accomodate all 37 instrcutions we need a more extensive use of the ALU)
    output logic [DATA_WIDTH-1: 0] ALUout,
    output logic                   EQ,
    output logic                   LT,
    output logic                   LTU
    );

    logic [63:0] unsigned_mult; //I might need to get rid of these intermediaries
    logic [63:0] signed_mult;   //because they are computed regardless of whether they are used
    logic [63:0] signed_unsigned_mult; //... and I just did get rid of it

    assign unsigned_mult = $unsigned(ALUop1) * $unsigned(ALUop2);
    assign signed_mult = $signed(ALUop1) * $signed(ALUop2);
    assign signed_unsigned_mult = $signed(ALUop1) * $unsigned(ALUop2);

//extra signals:
//branch signals: (currently we have EQ): LTU= Less Then Unsigned , LT = Less Then (Signed)


    always_comb
    begin
        //default to avoid latches
        ALUout = 0;
        EQ = 1'b0;
        
        //the two instructions implemented
        if (ALUop1 == ALUop2) EQ = 1'b1;
        else EQ = 1'b0;


        //the extra two signals for branch
        LT  = ($signed(ALUop1) < $signed(ALUop2));
        LTU = (ALUop1 < ALUop2);

        case (ALUCtrl)
        5'b0000 : ALUout = ALUop1 + ALUop2; // add
        5'b0001 : ALUout = ALUop1 - ALUop2; // subtract
        5'b0010 : ALUout = ALUop1 & ALUop2; // and
        5'b0011 : ALUout = ALUop1 | ALUop2; // or
        5'b0100: ALUout = ALUop1 ^ ALUop2; // xor
        5'b0101 : ALUout = ALUop1 << (ALUop2 &32'h1F) ; // SLL
        5'b0110 : ALUout = ALUop1 >> (ALUop2 & 32'h1F) ; // SRL
        5'b0111 : ALUout = $signed(ALUop1) >>> (ALUop2 & 32'h1F); //SRA : Shift Right Arithmetic
        5'b1000: ALUout = ($signed(ALUop1) < $signed(ALUop2)) ? 32'b1 : 32'b0; // SLT: Set Less Then (Signed)
        5'b1001: ALUout = (ALUop1 < ALUop2) ? 32'b1 : 32'b0; // SLTU: Set Less Then Unsigned     
        5'b1010: ALUout = ALUop2; // Out = Entry for LUI: Load Upper Immediate
        5'b1011: ALUout = ALUop1 + ALUop2 - 32'd4;  // AUIPC : Add Upper Immediate and Program Counter (we need the current program counter: pc = pc_save -4)
        5'b1100: ALUout = unsigned_mult[31:0]; //MUL
        5'b1101: ALUout = signed_mult[63:32]; //MULH
        5'b1110: ALUout = unsigned_mult[63:32]; //MULHU
        5'b1111: ALUout = signed_unsigned_mult[63:32]; //MULHSU
        5'b10000: begin //DIV
            if (ALUop2 == 0) begin
                ALUout = -1;
            end
            else if (ALUop1 == 32'h80000000 && ALUop2 == 32'hFFFFFFFF) begin
                ALUout = 32'h80000000;
            end
            else begin
                ALUout = $signed(ALUop1)/$signed(ALUop2);
            end
        end
        5'b10001: begin //DIVU
            if (ALUop2 == 0) begin
                ALUout = -1;
            end
            else begin
                ALUout = $unsigned(ALUop1)/$unsigned(ALUop2);
            end
        end
        5'b10010: begin //REM
            if (ALUop2 == 0) begin
                ALUout = ALUop1;
            end
            else if (ALUop1 == 32'h80000000 && ALUop2 == 32'hFFFFFFFF) begin
                ALUout = 32'h00000000;
            end
            else begin
                ALUout = $signed(ALUop1) % $signed(ALUop2);
            end
        end
        5'b10011: begin //REMU
            if (ALUop2 == 0) begin
                ALUout = ALUop1;
            end
            else begin
                ALUout = $unsigned(ALUop1) % $unsigned(ALUop2);
            end
        end
        




        default: ALUout = 32'b0;
        endcase
    end
endmodule









