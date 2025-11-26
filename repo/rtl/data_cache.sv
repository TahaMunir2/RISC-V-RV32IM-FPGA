module data_cache #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 32,
    BLOCK_SIZE = 4,
    ASSOCIATIVITY = 2
) (
    input logic clk,
    input logic wr_en,
    input logic rd_en,
    input logic [ADDRESS_WIDTH-1 : 0] addr,
    input logic [DATA_WIDTH-1 : 0] write_data,
    input logic way,

    output logic [DATA_WIDTH-1 : 0] out,
    output logic hit
);

typedef struct packed {
    logic [7:0] byte3;  
    logic [7:0] byte2;  
    logic [7:0] byte1;  
    logic [7:0] byte0;
} word_store;

typedef struct packed {
    logic valid;
    logic dirty;
    logic [21:0] tag;
    word_store word3;
    word_store word2;
    word_store word1;
    word_store word0;
} block_store;

typedef struct packed {
    logic u;
    block_store block1;
    block_store block0;
} set_store;

set_store cache [128];

//initialising bits in the cache
for (int i = 0; i < 128; i++) begin
    cache[i].block0.valid = 1'b0;
    cache[i].block1.valid = 1'b0;
end

assign tag = addr[ADDR_WIDTH-1:11];
assign set = addr[10:4];
assign block_offset = addr[3:2]
assign byte_offset = addr[1:0];

always_comb begin

end

always @(posedge clk) begin

    if (wr_en == 1'b1) begin

        if (way == 1'b0) begin

            if (block_offset == 2'b0) begin
                cache[set].block0.word0 <= write_data
            end

            else if (block_offset == 2'b1) begin
                cache[set].block0.word1 <= write_data
            end

            else if (block_offset == 2'b10) begin
                cache[set].block0.word2 <= write_data
            end

            else if (block_offset == 2'b11) begin
                cache[set].block0.word3 <= write_data
            end
        end

        else if (way == 1'b1) begin

            if (block_offset == 2'b0) begin
                cache[set].block1.word0 <= write_data
            end

            else if (block_offset == 2'b1) begin
                cache[set].block1.word1 <= write_data
            end

            else if (block_offset == 2'b10) begin
                cache[set].block1.word2 <= write_data
            end

            else if (block_offset == 2'b11) begin
                cache[set].block1.word3 <= write_data
            end
        end
    end

    if (rd_en == 1'b1) begin
        if (way == 1'b0) begin

        end

        else if (way == 1'b1) begin

        end
    end
end
endmodule
