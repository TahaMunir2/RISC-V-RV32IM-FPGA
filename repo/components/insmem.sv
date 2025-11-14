module insmem #(
    parameter ADDRESS_WIDTH = 16,
              DATA_WIDTH = 32
)(
    input logic [ADDRESS_WIDTH-1 : 0] addr,
    output logic [DATA_WIDTH-1 : 0] instr
);

logic [DATA_WIDTH-1 : 0] rom_array [2**ADDRESS_WIDTH-1:0];

///instr mem reads from a file called "counterrom.mem"
initial begin
    $display("Loading rom.");
    $readmemh("counterrom.mem", rom_array);
end;

///asynchronous instruction read
always_comb begin
    instr = rom_array [addr];
end;

endmodule
