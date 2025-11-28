module l1i_cache #(
    DATA_WIDTH = 32,
    ADDRESS_WIDTH = 32,
    BLOCK_SIZE = 4,
    ASSOCIATIVITY = 2
) (
    input logic clk,
    input logic fetch, // ******* we need to use this as a cache enable
    input  logic [ADDRESS_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH*BLOCK_SIZE-1:0] line_from_mem,
    input  logic [1:0] LoadSize,
    input  logic LoadUnsigned,
    output logic [DATA_WIDTH-1 : 0] data_out,
    output logic stall
);

    typedef struct packed {
        logic [7:0] byte3;  
        logic [7:0] byte2;  
        logic [7:0] byte1;  
        logic [7:0] byte0;
    } word_store;

    typedef struct packed {
        logic valid;
        logic [20:0] tag;
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
        logic way;
        logic [ADDRESS_WIDTH-1:11] tag_bits;
        logic [6:0] set;
        logic [1:0] block_offset;
        logic [1:0] byte_offset;
        set_store cache [128];

        assign tag_bits = addr[ADDRESS_WIDTH-1:11];
        assign set = addr[10:4];
        assign block_offset = addr[3:2];
        assign byte_offset = addr[1:0];

    initial begin
        for (int i = 0; i < 128; i++) begin
            cache[i].used           = 1'b0;
            cache[i].block0.valid   = 1'b0;
            cache[i].block0.dirty   = 1'b0;
            cache[i].block1.valid   = 1'b0;
            cache[i].block1.dirty   = 1'b0;
        end
    end

    logic hit0, hit1;
    logic valid0, valid1;
    logic miss;

    always_comb begin
         // hit detection
        hit0 = (cache[set].block0.tag == tag_bits && cache[set].block0.valid && fetch); // if the tags are the same, and its a valid set and we are working with the cache then its a hit0
        hit1 = (cache[set].block1.tag == tag_bits && cache[set].block1.valid && fetch);
        miss = ~(hit0 | hit1) && fetch; // we need to know if we are accessing the cache 

        valid0 = cache[set].block0.valid; // check validity
        valid1 = cache[set].block1.valid;

        stall = 0;
        wr_en= 1'b0;
        rd_en = 1'b0;
        data_out = '0;

        // way determination
        if (miss) begin
            stall = 1'b1;

            if (!valid0 && !valid1)     way = 1'b0; //both bits are invalid, we choose the default 
            else if (!valid0)           way = 1'b0; //way0 is invalid
            else if (!valid1)           way = 1'b1; //way1 is invalid
            else                        way = ~cache[set].used;  //both bits are valid, we take into account which way was least recently used (LRU logic)
        end

    // wr and rd en logic
        if (fetch) begin //no access this cycle: do nothing (no fetching from ROM)
            rd_en= 1'b1;
            if (miss) begin  // write full line into chosen way
                wr_en      = 1'b1;
            end

            //read logic
        if (rd_en) begin
            // we don't update valid or dirty since we are only reading        
            

            if (way == 1'b0) begin
                case(block_offset)
                2'b00: data_out = cache[set].block0.word0;
                2'b01: data_out = cache[set].block0.word1;
                2'b10: data_out = cache[set].block0.word2;
                2'b11: data_out = cache[set].block0.word3;
                endcase
            end

            else if (way == 1'b1) begin
                case(block_offset)
                2'b00: data_out = cache[set].block1.word0;
                2'b01: data_out = cache[set].block1.word1;
                2'b10: data_out = cache[set].block1.word2;
                2'b11: data_out = cache[set].block1.word3;
                endcase
            end

        end
    end
end

    always_ff @(posedge clk) begin // only write is synchronous
        write_back_en <= 0; // default to prevent latching
        cache[set].used <= way; // set the last used to whichever one you are reading from
    //write logic
        if (wr_en) begin
            cache[set].used <= way; // update used
            if (~way) begin
                cache[set].block0[127:0] <= line_from_mem;
                cache[set].block0.tag <= tag_bits;
                cache[set].block0.valid <= 1'b1;
            end
            else begin
                cache[set].block1[127:0] <= line_from_mem;
                cache[set].block1.tag <= tag_bits;
                cache[set].block1.valid <= 1'b1;
            end
        end
    end

endmodule
