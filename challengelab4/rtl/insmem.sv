module insmem #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1 : 0] addr,
    output logic [DATA_WIDTH-1 : 0] instr
);
logic [7 : 0] rom_array [255:0];

initial begin
    $display("Loading rom.", );
    $readmemh("../rtl/program.hex", rom_array);
end;

///asynchronous instruction read
always_comb begin
    instr = {rom_array[addr + 3], rom_array[addr + 2], rom_array[addr + 1], rom_array[addr]};
end;

endmodule
