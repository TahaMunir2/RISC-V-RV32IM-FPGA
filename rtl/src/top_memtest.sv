module top_memtest(
    input  logic        clk,
    input  logic        memwrite_in,
    input  logic [31:0] wd_in,
    input  logic [31:0] addr_in,
    input  logic [31:0] pc_in,
    output logic [31:0] instr_out,
    output logic [31:0] data_out
);

    new_insmem #(
        .MEM_BYTES (8192),
        .BASE_ADDR (32'hBFC0_0000)
    ) imem (
        .clk  (clk),
        .addr (pc_in),
        .instr(instr_out)
    );

    new_datamem #(
        .MEM_BYTES (16384),
        .BASE_ADDR (32'h0002_0000)
    ) dmem (
        .MemWrite     (memwrite_in),
        .WD           (wd_in),
        .SizeWrite    (2'b10),
        .A            (addr_in),
        .LoadSize     (2'b10),
        .LoadUnsigned (1'b1),
        .clk          (clk),
        .dout         (data_out)
    );

endmodule
