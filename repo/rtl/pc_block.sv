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
    input logic trap_en,
    input logic mret_en,
    input logic [WIDTH-1:0] handler_address,
    input logic [WIDTH-1:0] pc_saved,
    output logic [WIDTH-1:0] pc,
    output logic [WIDTH-1:0] pc_save
);

logic [WIDTH-1:0] branch_pc, inc_pc, internal_pc;
assign branch_pc = Imm_op;
assign inc_pc = internal_pc+4;
assign pc_save = inc_pc;



always_ff @(posedge clk)
    if (rst) internal_pc <={WIDTH{1'b0}}; 
    else if(trap_en || mret_en) internal_pc <= handler_address;
    else if (!enable) internal_pc <=pc;
    else begin
        case (pc_src)
            2'b00: internal_pc <= inc_pc;    // PC + 4
            2'b01: internal_pc <= branch_pc; // PC + Imm
            2'b10: internal_pc <= ALU;       // JALR / JAL
            2'b11: internal_pc <=pc_saved;
            default: internal_pc <= inc_pc;  
        endcase
    end
assign pc = internal_pc;

endmodule

