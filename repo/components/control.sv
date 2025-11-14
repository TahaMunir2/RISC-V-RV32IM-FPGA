module control #(
    parameter ADDRESS_WIDTH = 16,
              DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    input logic EQ,
    output logic RegWrite,
    output logic [2:0] ALUCtrl,
    output logic ALUSrc,
    output logic [1:0] ImmSrc,
    output logic PCsrc
);

wire [6:0] op;
wire [2:0] funct3;
wire [6:0] funct7;
assign op = instr[6:0];
assign funct3 = instr[14:12];
assign funct7 = instr [31:25];

always_comb begin

    if (op == 7'b0010011) begin
        ///logic for addi instruction
        if (funct3 == 3'b0) begin
            RegWrite = 1;
            ALUCtrl = 3'b0;
            ALUSrc = 1;
            ImmSrc = 2'b0;
            PCSrc = 0;
        end
    end

    else if (op == 7'b1100011) begin
        ///logic for bne instruction
        if (funct3 == 3'b1) begin
            RegWrite = 0;
            ALUCtrl = 3'b1;
            ALUSrc = 0;
            ImmSrc = 2'b10;
            if (EQ) begin
                PCSrc = 0;
            end
            else begin
                PCSrc = 1;
            end
        end
    end
end

endmodule
