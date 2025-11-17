module signext #(
    parameter IMM_LENGTH = 12,
              DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    input logic [1:0] ImmSrc,
    output logic [DATA_WIDTH-1 : 0] immext
);

wire [IMM_LENGTH-1 : 0] imm12;
wire [IMM_LENGTH : 0] imm13;

///sign extension depending on value of ImmSrc
always_comb begin
    if (ImmSrc == 2'b0) begin  
        imm12 = instr[31:20];
        immext = {{(DATA_WIDTH - IMM_LENGTH){imm12[IMM_LENGTH-1]}}, imm12};
    end
    else if (ImmSrc == 2'b1) begin 
        imm12 = {instr[31:25], instr[11:7]};
        immext = {{(DATA_WIDTH - IMM_LENGTH){imm12[IMM_LENGTH-1]}}, imm12};
    end
    else if (ImmSrc == 2'b10) begin
        imm13 = {instr[31], instr[7], instr[30:25], instr[11:8], 0'b0};
        immext = {{(DATA_WIDTH - IMM_LENGTH + 1){imm13[IMM_LENGTH]}}, imm13};
    end
end
endmodule
