module signext #(
    parameter IMM_LENGTH = 12,
              DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    input logic [1:0] ImmSrc,
    output logic [DATA_WIDTH-1 : 0] immext
);

///sign extension depending on value of ImmSrc
always_comb begin
    if (ImmSrc == 2'b0) begin  
        immext = {{20{intr[31]}}, instr[31:20]};
    end
    else if (ImmSrc == 2'b1) begin 
        immext = {{20{instr[31]}}, instr[31:25], instr[11:7]};
    end
    else if (ImmSrc == 2'b10) begin
        immext = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
    end
end
endmodule
