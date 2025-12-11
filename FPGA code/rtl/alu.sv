module alu#(
    parameter DATA_WIDTH=32
    )(
    input logic [DATA_WIDTH-1:0] ALUop1, //RS1 or PCsave
    input logic [DATA_WIDTH-1:0] ALUop2, //RS2 or IMM
    input logic  [4:0]          ALUCtrl, //ALUCtrl is now 4 bits
    output logic [DATA_WIDTH-1: 0] ALUout,
    output logic                   EQ,
    output logic                   LT,
    output logic                   LTU
    );


    // Branch signals
    always_comb
    begin
        // Defaults
        ALUout = 32'b0;
        EQ = 1'b0;
        
        // Equality check
        if (ALUop1 == ALUop2) EQ = 1'b1;
        else EQ = 1'b0;

        // Branch comparisons
        LT  = ($signed(ALUop1) < $signed(ALUop2));
        LTU = (ALUop1 < ALUop2);

        case (ALUCtrl)
        5'b0000 : ALUout = ALUop1 + ALUop2; // add
        5'b0001 : ALUout = ALUop1 - ALUop2; // subtract
        5'b0010 : ALUout = ALUop1 & ALUop2; // and
        5'b0011 : ALUout = ALUop1 | ALUop2; // or
        5'b0100 : ALUout = ALUop1 ^ ALUop2; // xor
        5'b0101 : ALUout = ALUop1 << (ALUop2 & 32'h1F); // SLL
        5'b0110 : ALUout = ALUop1 >> (ALUop2 & 32'h1F); // SRL
        5'b0111 : ALUout = $signed(ALUop1) >>> (ALUop2 & 32'h1F); // SRA
        5'b1000 : ALUout = ($signed(ALUop1) < $signed(ALUop2)) ? 32'b1 : 32'b0; // SLT
        5'b1001 : ALUout = (ALUop1 < ALUop2) ? 32'b1 : 32'b0; // SLTU     
        5'b1010 : ALUout = ALUop2; // LUI
        5'b1011 : ALUout = ALUop1 + ALUop2 - 32'd4; // AUIPC

       -
        // The Division and Modulo logic below has been disabled.
        // This removes the "lpm_divide" hardware that was causing the -132ns timing slack.
        
        5'b10000: ALUout = 32'b0; // DIV (Disabled for Timing)
        5'b10001: ALUout = 32'b0; // DIVU (Disabled for Timing)
        5'b10010: ALUout = 32'b0; // REM (Disabled for Timing)
        5'b10011: ALUout = 32'b0; // REMU (Disabled for Timing)

        // --- CRITICAL FIX END ---

        5'b10100: ALUout = (ALUop1 << 1) + ALUop2; // sh1add
        5'b10101: ALUout = (ALUop1 << 2) + ALUop2; // sh2add
        5'b10110: ALUout = (ALUop1 << 3) + ALUop2; // sh3add

        default: ALUout = 32'b0;
        endcase
    end
endmodule
