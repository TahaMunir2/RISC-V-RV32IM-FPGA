module datamem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 32
)(
    input  logic                     MemWrite,
    input  logic [ADDRESS_WIDTH-1:0] WD,
    input  logic                     ByteWrite,
    input  logic [ADDRESS_WIDTH-1:0] A, 
    input  logic                     clk,
    output logic [DATA_WIDTH-1:0]    dout
);

logic [7:0] ram_array [2**17-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("reference/gaussian.mem", ram_array, 0x10000);
end

always_comb begin
    if(ByteWrite) begin
        
        dout[7:0] = ram_array[A];
        dout[31:8] = 24'b0;
    end
    else  begin
        dout[7:0] = ram_array[A];
        dout[15:8] = ram_array[A+1];
        dout[23:16] = ram_array[A+2];
        dout[31:24] = ram_array[A+3];
    end
end
always_ff @(posedge clk) begin
    if (MemWrite) begin
        if (ByteWrite) begin
        ram_array[A] <= WD[7:0];
        end
    end
end

endmodule
