module datamem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 32
)(
    input  logic                  clk,
    input  logic [ADDRESS_WIDTH-1:0] A,
    output logic [DATA_WIDTH-1:0]    dout
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("sineram.mem", ram_array);
end

always_ff @(posedge clk)
    // output is synchronous
    dout <= rom_array[A];

endmodule