module data_cache #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 32,
    BLOCK_SIZE = 4,
    ASSOCIATIVITY = 2
) (
    input logic clk,
    input logic fetch, // ******* we need to use this as a cache enable
    input  logic [ADDRESS_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH*BLOCK_SIZE-1:0] line_from_mem,
    output logic [DATA_WIDTH-1 : 0] data_out,
    output logic [DATA_WIDTH*BLOCK_SIZE-1:0] write_back,
    output logic write_back_en
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
    logic [20:0] tag; // ****** changed to 20 idk if its meant to be 21 or 20
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


    logic wr_en;
    logic rd_en;
    logic [(DATA_WIDTH * BLOCK_SIZE)-1 : 0] write_data;
    logic way;
    logic [ADDRESS_WIDTH-1:11] tag_bits;
    logic [6:0] set;
    logic [1:0] block_offset;
    logic [1:0] byte_offset;
    logic cpu_write; // ********* need to implement for store insturctions
    logic [DATA_WIDTH*BLOCK_SIZE-1:0] wmask;


set_store cache [128];

assign tag_bits = addr[ADDRESS_WIDTH-1:11];
assign set = addr[10:4];
assign block_offset = addr[3:2];
assign byte_offset = addr[1:0];
assign cpu_write = 0;

initial begin // initialise CACHE
    for (int i = 0; i < 128; i++) begin
        cache[i].block0.valid = 1'b0;
        cache[i].block1.valid = 1'b0;
    end
end

    logic hit0, hit1;
    logic miss;


    // hit detection
    always_comb begin
        hit0 = (cache[set].block0.tag == tag_bits && fetch && cache[set].block0.valid); // if the tags are the same, its a valid set and we are working with the cache
        hit1 = (cache[set].block1.tag == tag_bits && fetch && cache[set].block1.valid);
        miss = ~(hit0 | hit1) && fetch; // we need to know if we are accessing the cache 
    end

    always_comb begin
//this whole part of the circuit relies on prioritizing validity for replacement over most recently used (which is only taken into account when both ways are valid)
        wmask = '0;
        if (miss) begin
            logic valid0 = cache[set].block0.valid;
            logic valid1 = cache[set].block1.valid;
            wmask = '1;

            //both bits are invalid, we choose at default 
            if (!valid0 && !valid1) begin
                way = 1'b0;
            end
            
            //way0 is invalid
            else if (!valid0) begin
                way = 1'b0;
            end

            //way1 is invalid
            else if (!valid1) begin
                way = 1'b1;
            end

            //both bits are valid, we take into account which way was least recently used (LRU logic)
            else begin
                way= ~cache[set].used; 
            end
        end
        else begin
            way = hit1;
        end
    end

    always_comb begin
        // defaults
        wr_en= 1'b0;
        rd_en = 1'b0;
        write_data = '0;

        if (!fetch) begin
            //no access this cycle: do nothing (no fetching from ROM)
        end
        else begin
            if (miss) begin
                // write full line into chosen way
                wr_en      = 1'b1;
                write_data = line_from_mem; // **** not sure what this means
            end

            rd_en= 1'b1;
        end
    end

always_ff @(posedge clk) begin
    write_back_en <= 0;
//read logic
    if (rd_en == 1'b1) begin
        
        cache[set].used = way; // set the last used to whichever one you are reading from
        
        if (way == 1'b0) begin

            if (block_offset == 2'b0) begin
                data_out <= cache[set].block0.word0;
            end

            else if (block_offset == 2'b1) begin
                data_out <= cache[set].block0.word1;
            end

            else if (block_offset == 2'b10) begin
                data_out <= cache[set].block0.word2;
            end

            else if (block_offset == 2'b11) begin
                data_out <= cache[set].block0.word3;
            end

        end

        else if (way == 1'b1) begin

            if (block_offset == 2'b0) begin
                data_out <= cache[set].block1.word0;
            end

            else if (block_offset == 2'b1) begin
                data_out <= cache[set].block1.word1;
            end

            else if (block_offset == 2'b10) begin
                data_out <= cache[set].block1.word2;
            end

            else if (block_offset == 2'b11) begin
                data_out <= cache[set].block1.word3;
            end

        end
    end
    
//write logic
if (wr_en) begin
        // Update LRU on write
        cache[set].used <= way;

        if (way == 1'b0) begin
            if (cache[set].block0.dirty == 1) begin
                write_back <= cache[set].block0[127:0];
                write_back_en <= 1;
            end
            if (!cpu_write) cache[set].block0.dirty <= 1'b0; // if first time then clean
            else cache[set].block0.dirty <= 1'b1; // if we are writing over it then it is dirty
            cache[set].block0[127:0] <= (write_data & wmask);
            cache[set].block0.tag <= tag_bits;
            cache[set].block0.valid <= 1'b1;
        end
        else begin
            if (cache[set].block1.dirty == 1) begin
                write_back <= cache[set].block1[127:0];
                write_back_en <= 1;
            end
            if (!cpu_write) cache[set].block1.dirty <= 1'b0;
            else cache[set].block1.dirty <= 1'b1;
            cache[set].block1[127:0] <= (write_data & wmask);
            cache[set].block1.tag <= tag_bits;
            cache[set].block1.valid <= 1'b1;
        end
    end
end
endmodule
