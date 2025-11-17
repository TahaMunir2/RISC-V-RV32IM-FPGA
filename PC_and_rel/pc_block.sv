module pc_block #(
    parameter WIDTH = 32
)
(
    input logic clk,
    input logic [WIDTH-1:0] Imm_op, 
    input logic rst,
    input logic pc_src,
    output logic [WIDTH-1:0] pc
);

logic [WIDTH-1:0] branch_pc, inc_pc, internal_pc;
assign branch_pc = internal_pc+Imm_op;
assign inc_pc = internal_pc+4;



always_ff @(posedge clk)
    if (rst) internal_pc <={WIDTH{1'b0}};
    else internal_pc <= (pc_src?branch_pc:inc_pc);

assign pc = internal_pc;

endmodule
