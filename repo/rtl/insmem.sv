module insmem #(
    parameter DATA_WIDTH = 8
)(
    input logic [31 : 0] addr,
    output logic [DATA_WIDTH-1 : 0] instr
);
logic [DATA_WIDTH-1 : 0] rom_array [255:0];

///instr mem reads from a file called "counterrom.mem"
initial begin
    $display("Loading rom.");
    $readmemh("counterrom.mem", rom_array);
end;

///asynchronous instruction read
always_comb begin
    instr = {rom_array[addr + 3], rom_array[addr + 2], rom_array[addr + 1], rom_array[addr]};
end;

endmodule
