module control #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] instr,
    input logic EQ,
    output logic RegWrite,
    output logic [2:0] ALUCtrl,
    output logic ALUSrc,
    output logic [1:0] ImmSrc,
    output logic PCSrc,
    output logic reg_entry //adding the aditional output representing the select line of the additional multiplexer in the regaludmem block
);

logic [6:0] op;
logic [2:0] funct3;
logic [6:0] funct7;
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
            reg_entry = 1'b0; //we want to write the output of the ALU to the regfile
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
            reg_entry = 0; //Don't care can take any value (because we are not writing to the regfile)
        end
    end

    else if (op== 7'b0000011) begin
        //logic for the load word instruction
        if (funct3 == 3'b010) begin
            RegWrite=1;
            ALUCtrl =3'b0; 
            ALUSrc = 1'b1; 
            ImmSrc = 2'b0; //must be 00 because it is an immediate type instruction
            PCSrc = 0; //normal PC incrementation
            reg_entry = 1; //we are writing the output of the data mem to the regfile
        end
    end

end

endmodule
