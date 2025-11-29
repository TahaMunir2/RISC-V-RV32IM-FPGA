module alu#(
    DATA_WIDTH=32
    )(
    input logic [DATA_WIDTH-1:0] ALUop1, //RS1 or PCsave
    input logic [DATA_WIDTH-1:0] ALUop2, //RS2 or IMM
    input logic  [3:0]           ALUCtrl, //ALUCtrl is now 4 bits (in order to accomodate all 37 instrcutions we need a more extensive use of the ALU)
    output logic [DATA_WIDTH-1: 0] ALUout,
    output logic                   EQ,
    output logic                   LT,
    output logic                   LTU
    );


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
        4'b0000 : ALUout = ALUop1 + ALUop2; // add
        4'b0001 : ALUout = ALUop1 - ALUop2; // subtract
        4'b0010 : ALUout = ALUop1 & ALUop2; // and
        4'b0011 : ALUout = ALUop1 | ALUop2; // or
        4'b0100: ALUout = ALUop1 ^ ALUop2; // xor
        4'b0101 : ALUout = ALUop1 << (ALUop2 &32'h1F) ; // SLL
        4'b0110 : ALUout = ALUop1 >> (ALUop2 & 32'h1F) ; // SRL
        4'b0111 : ALUout = $signed(ALUop1) >>> (ALUop2 & 32'h1F); //SRA : Shift Right Arithmetic
        4'b1000: ALUout = ($signed(ALUop1) < $signed(ALUop2)) ? 32'b1 : 32'b0; // SLT: Set Less Then (Signed)
        4'b1001: ALUout = (ALUop1 < ALUop2) ? 32'b1 : 32'b0; // SLTU: Set Less Then Unsigned     
        4'b1010: ALUout = ALUop2; // Out = Entry for LUI: Load Upper Immediate
        4'b1011: ALUout = ALUop1 + ALUop2 - 32'd4;  // AUIPC : Add Upper Immediate and Program Counter (we need the current program counter: pc = pc_save -4)
    
        default: ALUout = 32'b0;
        endcase
    end
endmodule









