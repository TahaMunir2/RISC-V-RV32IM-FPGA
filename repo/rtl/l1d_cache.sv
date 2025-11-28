module l1d_cache #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 32,
    parameter BLOCK_SIZE = 4
) (
    input logic clk,
    input logic fetch, // ******* we need to use this as a cache enable
    input  logic [ADDRESS_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] wd,
    input  logic [DATA_WIDTH*BLOCK_SIZE-1:0] line_from_mem,
    input  logic [1:0] SizeWrite_m,
    input  logic MemWrite_m,
    input  logic [1:0] LoadSize,
    input  logic LoadUnsigned,
    output logic [DATA_WIDTH-1 : 0] data_out,
    output logic [DATA_WIDTH*BLOCK_SIZE-1:0] write_back,
    output logic write_back_en,
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
        logic dirty;
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
    logic [(DATA_WIDTH * BLOCK_SIZE)-1 : 0] write_data;
    logic way;
    logic [ADDRESS_WIDTH-1:11] tag_bits;
    logic [6:0] set;
    logic [1:0] block_offset;
    logic [1:0] byte_offset;
    logic [DATA_WIDTH*BLOCK_SIZE-1:0] wmask;
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
        logic [6:0] bottom_bit;

    always_comb begin
         // hit detection
        hit0 = (cache[set].block0.tag == tag_bits && cache[set].block0.valid && fetch); // if the tags are the same, and its a valid set and we are working with the cache then its a hit0
        hit1 = (cache[set].block1.tag == tag_bits && cache[set].block1.valid && fetch);
        miss = ~(hit0 | hit1) && fetch; // we need to know if we are accessing the cache 

        valid0 = cache[set].block0.valid; // check validity
        valid1 = cache[set].block1.valid;

        wmask = '0;
        stall = 0;
        wr_en= 1'b0;
        rd_en = 1'b0;
        write_data = '0;
        data_out = '0;

        // way determination
        if (miss) begin
            stall = 1'b1;
            wmask = '1;

            if (!valid0 && !valid1)     way = 1'b0; //both bits are invalid, we choose the default 
            else if (!valid0)           way = 1'b0; //way0 is invalid
            else if (!valid1)           way = 1'b1; //way1 is invalid
            else                        way = ~cache[set].used;  //both bits are valid, we take into account which way was least recently used (LRU logic)
        end

        else begin
            way = hit1;   // if hit1 = 1 then way = 1 if hit1 = 0 then way = 0 as hit0 = 1
            if (MemWrite_m && fetch) begin // sb logic, determine size
                wr_en = 1'b1;
                wmask = '1;
                if(SizeWrite_m == 2'b00) begin //sb
                    bottom_bit = block_offset * 32 + byte_offset * 8;
                    wmask[bottom_bit[6:0] +: 8] = '0;
                end

                else if(SizeWrite_m == 2'b01) begin // sh
                    bottom_bit = block_offset * 32 + byte_offset * 8;
                    wmask[bottom_bit[6:0] +: 16] = '0;
                end

                else if(SizeWrite_m == 2'b10) begin // sw
                    bottom_bit = block_offset * 32;
                    wmask[bottom_bit[6:0] +: 32] = '0;
                end

                wmask = ~wmask;
            end
        end

        // wr and rd en logic
        if (fetch) begin
            if (miss) begin
                // On a miss: fill the line, but don't read from cache this cycle
                rd_en      = 1'b0;
                wr_en      = 1'b1;
                write_data = line_from_mem;
            end
            else begin
                // On a hit: enable read from cache
                rd_en = 1'b1;

                //If it is also a store, enable write
                if (MemWrite_m) begin
                    wr_en      = 1'b1;
                    write_data = {4{wd}};
                end
            end
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

            // lw logic
            case (LoadSize)
                // LB / LBU
                2'b00: begin
                    bottom_bit = 8 * byte_offset;
                    if (LoadUnsigned)
                        data_out = {24'b0, data_out[bottom_bit[4:0] +:8]};
                    else
                        data_out = {{24{data_out[bottom_bit[4:0] + 7]}}, data_out[bottom_bit[4:0] +:8]};
                end

                // LH / LHU
                2'b01: begin
                    bottom_bit = 16 * byte_offset;
                    if (LoadUnsigned)
                        data_out = {16'b0, data_out[bottom_bit[4:0] +:16]};
                    else
                        data_out = {{16{data_out[bottom_bit[4:0] + 15]}},data_out[bottom_bit[4:0]+:16]};
                end

                // LW
                default: begin
                    data_out = data_out;
                end
            endcase
        end
    end

    always_ff @(posedge clk) begin // only write is synchronous
        write_back_en <= 0; // default to prevent latching
        cache[set].used <= way; // set the last used to whichever one you are reading from
    //write logic
        if (wr_en) begin
            cache[set].used <= way; // update used
            if (~way) begin
                if (cache[set].block0.dirty == 1 && miss) begin
                    write_back <= cache[set].block0[127:0];
                    write_back_en <= 1;
                end
                if (!MemWrite_m) begin
                    cache[set].block0.dirty <= 1'b0; // if first time then clean
                end
                else begin
                   cache[set].block0.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                cache[set].block0[127:0] <= (cache[set].block0[127:0] & ~wmask) | (write_data & wmask);
                cache[set].block0.tag <= tag_bits;
                cache[set].block0.valid <= 1'b1;
            end
            else begin
                if (cache[set].block1.dirty == 1 && miss) begin
                    write_back <= cache[set].block1[127:0];
                    write_back_en <= 1;
                end
                if (!MemWrite_m) begin
                    cache[set].block1.dirty <= 1'b0; // if first time then clean
                end
                else begin
                   cache[set].block1.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                cache[set].block1[127:0] <= (cache[set].block1[127:0] & ~wmask) | (write_data & wmask);
                cache[set].block1.tag <= tag_bits;
                cache[set].block1.valid <= 1'b1;
            end
        end
    end

endmodule
