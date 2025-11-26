module pc_block #(
    parameter WIDTH = 32
)
(
    input logic clk,
    input logic enable,
    input logic [WIDTH-1:0] Imm_op, 
    input logic [WIDTH-1:0] ALU,
    input logic rst,
    input logic [1:0] pc_src,
    output logic [WIDTH-1:0] pc,
    output logic [WIDTH-1:0] pc_save
);

logic [WIDTH-1:0] branch_pc, inc_pc, internal_pc;
assign branch_pc = internal_pc+Imm_op;
assign inc_pc = internal_pc+4;
assign pc_save = inc_pc;



always_ff @(posedge clk)
    if (!enable) internal_pc <=pc;
    else if (rst) internal_pc <={WIDTH{1'b0}};
    else begin
        case (pc_src)
            2'b00: internal_pc <= inc_pc;    // PC + 4
            2'b01: internal_pc <= branch_pc; // PC + Imm
            2'b10: internal_pc <= ALU;       // JALR
            default: internal_pc <= inc_pc;  
        endcase
    end
assign pc = internal_pc;

endmodule
