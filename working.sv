module l1d_cache #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 32,
    parameter BLOCK_SIZE = 4
) (
    input logic clk,
    input logic fetch, // Used as cache enable
    input  logic [ADDRESS_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] wd,
    input  logic [DATA_WIDTH*BLOCK_SIZE-1:0] line_from_mem,
    input  logic [1:0] SizeWrite_m,
    input  logic MemWrite_m,
    input  logic [1:0] LoadSize,
    input  logic LoadUnsigned,
    input  logic ready,
    input  logic wb_ready,
    output logic [DATA_WIDTH-1 : 0] data_out,
    output logic [DATA_WIDTH*BLOCK_SIZE-1:0] write_back,
    output logic write_back_en,
    output logic [ADDRESS_WIDTH-1:0] write_back_addr,
    output logic [ADDRESS_WIDTH-1:0] l2_addr,
    output logic l2_fetch,
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

    logic hit0, hit1;
    logic valid0, valid1;
    logic miss;
    logic wb_valid;
    logic [6:0] bottom_bit;

    // Initialization (Note: In real hardware, use a reset signal)
    initial begin
        for (int i = 0; i < 128; i++) begin
            cache[i].used           = 1'b0;
            cache[i].block0.valid   = 1'b0;
            cache[i].block0.dirty   = 1'b0;
            cache[i].block1.valid   = 1'b0;
            cache[i].block1.dirty   = 1'b0;
        end
    end

    // --- FIX 1: Correct Endianness Alignment ---
    // Shift data to the correct byte lane (Little Endian)
    logic [DATA_WIDTH-1:0] wd_aligned;
    assign wd_aligned = wd << (byte_offset * 8);

    always_comb begin
        // Hit detection
        hit0 = (cache[set].block0.tag == tag_bits && cache[set].block0.valid && fetch);
        hit1 = (cache[set].block1.tag == tag_bits && cache[set].block1.valid && fetch);
        miss = ~(hit0 | hit1) && fetch; 

        valid0 = cache[set].block0.valid; 
        valid1 = cache[set].block1.valid;

        // Default values
        wmask = '0;
        stall = 0;
        wr_en = 1'b0;
        rd_en = 1'b0;
        write_data = '0;
        data_out = '0; // FIX: Prevent Latch
        write_back_en = 0;
        wb_valid = 1;
        l2_fetch = 1'b0;
        l2_addr = {addr[31:4], 4'b0000};
        way = 0; // Default way

        if (fetch) begin
            if (miss) begin
                
                // Way determination for Replacement (LRU)
                if (!valid0 && !valid1)     way = 1'b0; 
                else if (!valid0)           way = 1'b0; 
                else if (!valid1)           way = 1'b1; 
                else                        way = ~cache[set].used; 

                // Eviction Logic
                if (way == 0) begin
                    if (fetch && !ready && cache[set].block0.dirty) begin
                        if (wb_ready) begin
                            write_back_en = 0;
                            // Note: Dirty bit clearing happens in sequential block or implicitly by overwrite
                        end else begin
                            write_back_en = 1;
                            write_back = cache[set].block0[127:0];
                            write_back_addr = {cache[set].block0.tag, set, 4'b0000};    
                        end
                    end             
                end
                else begin
                    if (fetch && !ready && cache[set].block1.dirty) begin 
                        if (wb_ready) begin
                            write_back_en = 0;
                            wb_valid = 1;
                        end else begin
                            write_back_en = 1;
                            write_back = cache[set].block1[127:0];
                            write_back_addr = {cache[set].block1.tag, set, 4'b0000};
                            wb_valid = 0;  
                        end  
                    end
                end

                // Stall / Refill Logic
                if (!ready || !wb_valid) begin
                    rd_en      = 1'b0;
                    wr_en      = 1'b0;
                    stall      = 1'b1;
                    l2_fetch   = 1'b1;             
                end
                else begin
                    // L2 Ready -> Refill Line
                    rd_en      = 1'b0;
                    wr_en      = 1'b1;
                    stall      = 1'b1;
                    write_data = line_from_mem;
                    wmask      = '1; // Write full line
                end

            end
            else begin
                // Hit Logic
                way = hit1; 

                if (MemWrite_m) begin 
                    wr_en = 1'b1;
                    
                    // FIX: Replicate the ALIGNED data across all 4 words
                    write_data = {4{wd_aligned}}; 

                    // FIX: Generate mask based on Size
                    wmask = '0; 
                    if(SizeWrite_m == 2'b00) begin // SB
                        bottom_bit = block_offset * 32 + byte_offset * 8;
                        wmask[bottom_bit +: 8] = '1;
                    end
                    else if(SizeWrite_m == 2'b01) begin // SH
                        bottom_bit = block_offset * 32 + byte_offset * 8;
                        wmask[bottom_bit +: 16] = '1;
                    end
                    else if(SizeWrite_m == 2'b10) begin // SW
                        bottom_bit = block_offset * 32;
                        wmask[bottom_bit +: 32] = '1;
                    end
                end
                rd_en = 1'b1;
            end
        end


        // Read Logic
        if (rd_en) begin
            // Select data from the correct way and word
            logic [DATA_WIDTH-1:0] raw_word;
            
            if (way == 1'b0) begin
                case(block_offset)
                    2'b00: raw_word = cache[set].block0.word0;
                    2'b01: raw_word = cache[set].block0.word1;
                    2'b10: raw_word = cache[set].block0.word2;
                    2'b11: raw_word = cache[set].block0.word3;
                endcase
            end else begin
                case(block_offset)
                    2'b00: raw_word = cache[set].block1.word0;
                    2'b01: raw_word = cache[set].block1.word1;
                    2'b10: raw_word = cache[set].block1.word2;
                    2'b11: raw_word = cache[set].block1.word3;
                endcase
            end

            // Sub-word Selection / Extension (LB, LH, LW)
            case (LoadSize)
                // LB / LBU
                2'b00: begin
                    bottom_bit = 8 * byte_offset;
                    if (LoadUnsigned)
                        data_out = {24'b0, raw_word[bottom_bit[4:0] +:8]};
                    else
                        data_out = {{24{raw_word[bottom_bit[4:0] + 7]}}, raw_word[bottom_bit[4:0] +:8]};
                end

                // LH / LHU
                2'b01: begin
                    bottom_bit = 16 * byte_offset;
                    if (LoadUnsigned)
                        data_out = {16'b0, raw_word[bottom_bit[4:0] +:16]};
                    else
                        data_out = {{16{raw_word[bottom_bit[4:0] + 15]}}, raw_word[bottom_bit[4:0]+:16]};
                end

                // LW (Default)
                default: begin
                    data_out = raw_word;
                end
            endcase
        end
    end

            logic new_dirty;
    // Synchronous Write Logic
    always_ff @(posedge clk) begin 
        if (wr_en) begin
            cache[set].used <= way; 
            
            // Determine dirty status

            if (!MemWrite_m) new_dirty = 1'b0;  // Refill
            else if (ready)  new_dirty = 1'b0;  // Store Miss (Refill first)
            else             new_dirty = 1'b1;  // Store Hit

            if (~way) begin // Way 0
                if (!MemWrite_m || ready) cache[set].block0.dirty <= 1'b0;
                else                      cache[set].block0.dirty <= 1'b1;

                cache[set].block0.tag   <= tag_bits;
                cache[set].block0.valid <= 1'b1;

                // --- FIX 2: Correct Masked Write for Way 0 ---
                // (Old Data & ~Mask) | (New Data & Mask)
                cache[set].block0[127:0] <= (cache[set].block0[127:0] & ~wmask) | (write_data & wmask);
            end

            else begin // Way 1
                if (!MemWrite_m || ready) cache[set].block1.dirty <= 1'b0;
                else                      cache[set].block1.dirty <= 1'b1;

                cache[set].block1.tag   <= tag_bits;
                cache[set].block1.valid <= 1'b1;
                
                // Masked Write for Way 1
                cache[set].block1[127:0] <= (cache[set].block1[127:0] & ~wmask) | (write_data & wmask);
            end
        end
    end

endmodule
