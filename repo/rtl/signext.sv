module signext #(
    parameter IMM_LENGTH = 12,
              DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    input logic [2:0] ImmSrc,
    output logic [DATA_WIDTH-1 : 0] immext
);

///sign extension depending on value of ImmSrc
always_comb begin
    if (ImmSrc == 3'b000) begin  
        immext = {{20{instr[31]}}, instr[31:20]};
    end
    else if (ImmSrc == 3'b001) begin 
        immext = {{20{instr[31]}}, instr[31:25], instr[11:7]};
    end
    else if (ImmSrc == 3'b010) begin
        immext = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
    end

    else if (ImmSrc == 3'b100) begin
        immext = {{instr[31:12]}, 12'b0};
    end

    else if (ImmSrc == 3'b011) begin 
        immext = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
    end

    else if(ImmSrc == 3'b101) begin
        immext = {27'b0, instr[19:15]};
    end

    else immext = 32'b0;
end
endmodule

