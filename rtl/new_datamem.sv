module new_datamem #(
    parameter ADDRESS_WIDTH = 32,
              MEM_BYTES     = 16384,
              BASE_ADDR     = 32'h0002_0000,
              DATA_WIDTH    = 32
)(
    input  logic                     MemWrite,
    input  logic [DATA_WIDTH-1:0]    WD,
    input  logic [1:0]               SizeWrite,
    input  logic [ADDRESS_WIDTH-1:0] A, 
    input  logic [1:0]               LoadSize,
    input  logic                     LoadUnsigned,
    input  logic                     clk,
    output logic [DATA_WIDTH-1:0]    dout
);

    localparam OFFSET_BITS = $clog2(MEM_BYTES);

    logic [7:0] mem [0:MEM_BYTES-1];

    logic [OFFSET_BITS-1:0] A_reg;
    logic [OFFSET_BITS-1:0] A_offset;
    logic [31:0]            data;
    logic [ADDRESS_WIDTH-1:0] A_minus_base;

    assign A_minus_base = A - BASE_ADDR;
    assign A_offset     = A_minus_base[OFFSET_BITS-1:0];

    always_ff @(posedge clk) begin
        A_reg <= A_offset;

        data[7:0]   <= mem[A_reg];
        data[15:8]  <= mem[A_reg+1];
        data[23:16] <= mem[A_reg+2];
        data[31:24] <= mem[A_reg+3];

        case (LoadSize)
            2'b00: begin
                if (LoadUnsigned)
                    dout <= {24'b0,         data[7:0]};
                else
                    dout <= {{24{data[7]}}, data[7:0]};
            end
            2'b01: begin
                if (LoadUnsigned)
                    dout <= {16'b0,         data[15:0]};
                else
                    dout <= {{16{data[15]}}, data[15:0]};
            end
            default: begin
                dout <= data;
            end
        endcase
    end

    always_ff @(posedge clk) begin
        if (MemWrite) begin
            if (SizeWrite == 2'b00) begin
                mem[A_offset] <= WD[7:0];
            end
            else if (SizeWrite == 2'b01) begin
                mem[A_offset]     <= WD[7:0];
                mem[A_offset + 1] <= WD[15:8];
            end
            else if (SizeWrite == 2'b10) begin
                mem[A_offset]     <= WD[7:0];
                mem[A_offset + 1] <= WD[15:8];
                mem[A_offset + 2] <= WD[23:16];
                mem[A_offset + 3] <= WD[31:24];
            end
        end
    end

endmodule