module data_cache #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 32,
    BLOCK_SIZE = 4,
    ASSOCIATIVITY = 2
) (
    input logic clk,
    input logic wr_en,
    input logic rd_en,
    input logic u_en,
    input logic d_en,
    input logic d,
    input logic u,
    input logic [ADDRESS_WIDTH-1 : 0] addr,
    input logic [(DATA_WIDTH * BLOCK_SIZE)-1 : 0] write_data,
    input logic [(DATA_WIDTH * BLOCK_SIZE)-1 : 0] wmask,
    input logic way,

    output logic [21:0] tags_ways [2],
    output logic [DATA_WIDTH-1 : 0] data_out,
    output logic dirty_out,
    output logic used_out,
    output logic valid_out
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
    logic used;
    block_store block1;
    block_store block0;
} set_store;

set_store cache [128];

//initialising bits in the cache
for (int i = 0; i < 128; i++) begin
    cache[i].block0.valid = 1'b0;
    cache[i].block1.valid = 1'b0;
end

assign tag_bits = addr[ADDR_WIDTH-1:11];
assign set = addr[10:4];
assign block_offset = addr[3:2];
assign byte_offset = addr[1:0];

always_comb begin

end

always @(posedge clk) begin

//update tag_ways synchronously
    tags_ways[0] <= cache[set].block0.tag;
    tags_ways[1] <= cache[set].block1.tag;

//read logic
    if (rd_en == 1'b1) begin

        if (way == 1'b0) begin

            if (block_offset == 2'b0) begin
                data_out <= cache[set].block0.word0;
                dirty_out <= cache[set].block0.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block0.valid;
            end

            else if (block_offset == 2'b1) begin
                data_out <= cache[set].block0.word1;
                dirty_out <= cache[set].block0.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block0.valid;
            end

            else if (block_offset == 2'b10) begin
                data_out <= cache[set].block0.word2;
                dirty_out <= cache[set].block0.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block0.valid;
            end

            else if (block_offset == 2'b11) begin
                data_out <= cache[set].block0.word3;
                dirty_out <= cache[set].block0.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block0.valid;
            end
        end

        else if (way == 1'b1) begin

            if (block_offset == 2'b0) begin
                data_out <= cache[set].block1.word0;
                dirty_out <= cache[set].block1.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block1.valid;
            end

            else if (block_offset == 2'b1) begin
                data_out <= cache[set].block1.word1;
                dirty_out <= cache[set].block1.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block1.valid;
            end

            else if (block_offset == 2'b10) begin
                data_out <= cache[set].block1.word2;
                dirty_out <= cache[set].block1.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block1.valid;
            end

            else if (block_offset == 2'b11) begin
                data_out <= cache[set].block1.word3;
                dirty_out <= cache[set].block1.dirty;
                used_out <= cache[set].used;
                valid_out <= cache[set].block1.valid;
            end
        end
    end
    
//write logic
    if (wr_en == 1'b1) begin
        if (way == 1'b0) begin
            cache[set].block0[(DATA_WIDTH * BLOCK_SIZE)-1 : 0] <= (write_data & wmask);
            cache[set].block0.tag <= tag_bits;
            cache[set].block0.valid <= 1'b1;
            cache[set].block0.dirty <= d;
        end

        else if (way == 1'b1) begin
            cache[set].block1[(DATA_WIDTH * BLOCK_SIZE)-1 : 0] <= (write_data & wmask);
            cache[set].block1.tag <= tag_bits;
            cache[set].block1.valid <= 1'b1;
            cache[set].block1.dirty <= d;
        end
    end

//u bit write logic
    if (u_en == 1'b1) begin
        cache[set].used <= u;
    end

//d bit write logic
    if (d_en == 1'b1) begin
        if (way == 1'b0) begin
            cache[set].block0.dirty <= d;
        end

        if (way == 1'b1) begin
            cache[set].block1.dirty <= d;
        end
    end

end
endmodule
