module l2_cache #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 32,
    parameter BLOCK_SIZE = 8
) (
    input logic clk,
    input logic fetch_i,
    input logic fetch_d,
    input  logic [ADDRESS_WIDTH-1:0] addr_i,
    input  logic [ADDRESS_WIDTH-1:0] addr_d,
    input  logic [DATA_WIDTH*BLOCK_SIZE-1:0] line_from_mem,
    input  logic [DATA_WIDTH*4-1:0] l1write_back_data,
    input  logic l1write_back_en,
    input  logic [ADDRESS_WIDTH-1:0] l1write_back_addr,
    input  logic ready1,
    input  logic ready2,
    output logic ready_i,
    output logic ready_d,
    output logic wb_ready_d,
    output logic [DATA_WIDTH*4-1 : 0] data_out,
    output logic [DATA_WIDTH*BLOCK_SIZE-1:0] write_back_data,
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
        logic [18:0] tag;
        word_store word7;
        word_store word6;
        word_store word5;
        word_store word4;
        word_store word3;
        word_store word2;
        word_store word1;
        word_store word0;
    } block_store;

    typedef struct packed {
        logic u01;
        logic u02;
        logic u03;
        logic u04;
        logic u05;
        logic u06;
        block_store block3;
        block_store block2;
        block_store block1;
        block_store block0;
    } set_store;

    set_store cache [256];

    logic wr_en;
    logic rd_en;
    logic [(DATA_WIDTH * BLOCK_SIZE)-1 : 0] write_data;
    logic [1:0] way;
    logic [ADDRESS_WIDTH-1:13] tag_bits;
    logic [7:0] set;
    logic [2:0] block_offset;
    logic [1:0] byte_offset;
    logic [DATA_WIDTH*BLOCK_SIZE-1:0] wmask;
    logic fetch;
    logic l1write;
    logic hit0, hit1, hit2, hit3;
    logic valid0, valid1, valid2, valid3;
    logic miss;
    logic [7:0] bottom_bit;

    assign tag_bits = addr[ADDRESS_WIDTH-1:13];
    assign set = addr[12:5];
    assign block_offset = addr[4:2];
    assign byte_offset = addr[1:0];

    //l1 write back request logic
    logic [DATA_WIDTH*4-1:0] l1write_back_data_buffer,
    logic l1write_buffer,
    logic [ADDRESS_WIDTH-1:0] l1write_back_addr_buffer,
    logic wb_buffer_full;
    logic wb_buffer_miss;
    logic [1:0] way_wb;
    logic [7:0]bottom_bit_wb;
    logic [ADDRESS_WIDTH-1:13] tag_bits_wb;
    logic [7:0] set_wb;
    logic [2:0] block_offset_wb;
    logic [1:0] byte_offset_wb;
    logic hit0_wb, hit1_wb, hit2_wb, hit3_wb;
    logic miss_wb;
    logic dirty_write;

    assign tag_bits_wb = l1write_back_addr_buffer[ADDRESS_WIDTH-1:13];
    assign set_wb = l1write_back_addr_buffer[12:5];
    assign block_offset_wb = l1write_back_addr_buffer[4:2];
    assign byte_offset_wb = l1write_back_addr_buffer[1:0];


    initial begin
        for (int i = 0; i < 128; i++) begin
            cache[i].block0.valid   = 1'b0;
            cache[i].block0.dirty   = 1'b0;
            cache[i].block1.valid   = 1'b0;
            cache[i].block1.dirty   = 1'b0;
            cache[i].block2.valid   = 1'b0;
            cache[i].block2.dirty   = 1'b0;
            cache[i].block3.valid   = 1'b0;
            cache[i].block3.dirty   = 1'b0;            
        end
    end


    always_comb begin
        //arbiter logic
        if (!fetch_i && !fetch_d) begin
            fetch = 0;
            l1write = 0;
        end

        else if (fetch_i && !fetch_d) begin
            fetch = 1;
            addr = addr_i;
            l1write = 0;
        end

        else if (!fetch_i && fetch_d) begin
            fetch = 1;
            addr = addr_d;
            l1write = l1write_back_en;
        end

        else if (fetch_i && fetch_d) begin
            fetch = 1;
            addr = addr_d;
            l1write = l1write_back_en;
        end

        //read logic
        if (rd_en) begin
            //assert ready on the correct L1 cache
            if (fetch_d && !fetch_i) begin
                ready_d = 1;
            end

            else if (!fetch_d && fetch_i) begin
                ready_i = 1;
            end

            else if (fetch_d && fetch_i) begin
                ready_d = 1;
            end

            // we don't update valid or dirty since we are only reading        
            if (way == 2'b00) begin
                case(block_offset[2])
                1'b0: data_out = cache[set].block0[127:0];
                1'b1: data_out = cache[set].block0[255:128];
                endcase
                u01 = 1;
                u02 = 1;
                u03 = 1;
            end

            else if (way == 2'b01) begin
                case(block_offset[2])
                1'b0: data_out = cache[set].block1[127:0];
                1'b1: data_out = cache[set].block1[255:128];
                endcase
                u01 = 0;
                u12 = 1;
                u13 = 1;
            end

            else if (way == 2'b10) begin
                case(block_offset[2])
                1'b0: data_out = cache[set].block2[127:0];
                1'b1: data_out = cache[set].block2[255:128];
                endcase
                u02 = 0;
                u12 = 0;
                u23 = 1;
            end

            else if (way == 2'b11) begin
                case(block_offset[2])
                1'b0: data_out = cache[set].block3[127:0];
                1'b1: data_out = cache[set].block3[255:128];
                endcase
                u03 = 0;
                u13 = 0;
                u23 = 0;
            end
        end
    end

    always_ff @(posedge clk) begin // only write is synchronous
    //default case
    wmask = '0;
    wr_en= 1'b0;
    rd_en = 1'b0;
    write_data = '0;
    data_out = '0;
    write_back_en = 0;
    ready_i = 0;
    ready_d = 0;
    wb_ready_d = 0;

    if (l1write && !l1write_buffer) begin
        wb_ready_d = 1;

        l1write_buffer <= l1write;
        l1write_back_data_buffer <= l1write_back_data;
        l1write_back_addr_buffer <= l1write_back_addr;
    end

    if (l1write_buffer) begin
        // hit detection
        hit0_wb <= (cache[set_wb].block0.tag == tag_bits && cache[set_wb].block0.valid && fetch); // if the tags are the same, and its a valid set and we are working with the cache then its a hit0
        hit1_wb <= (cache[set_wb].block1.tag == tag_bits && cache[set_wb].block1.valid && fetch);
        hit2_wb <= (cache[set_wb].block2.tag == tag_bits && cache[set_wb].block2.valid && fetch);
        hit3_wb <= (cache[set_wb].block3.tag == tag_bits && cache[set_wb].block3.valid && fetch);
        miss_wb <= ~(hit0 | hit1 | hit2 | hit3);
    end


    //pass on the write back from the buffer to main mem
    if (l1write_buffer && (ready | !fetch_d)) begin
        write_back_en <= 1;
        write_back_addr <= l1write_back_addr_buffer;
        write_back_data <= l1write_back_data_buffer;
        l1write_buffer <= 0;
    end


    // hit detection
    hit0 <= (cache[set].block0.tag == tag_bits && cache[set].block0.valid && fetch); // if the tags are the same, and its a valid set and we are working with the cache then its a hit0
    hit1 <= (cache[set].block1.tag == tag_bits && cache[set].block1.valid && fetch);
    hit2 <= (cache[set].block2.tag == tag_bits && cache[set].block2.valid && fetch);
    hit3 <= (cache[set].block3.tag == tag_bits && cache[set].block3.valid && fetch);
    miss <= ~(hit0 | hit1 | hit2 | hit3) && fetch; // we need to know if we are accessing the cache 

    valid0 <= cache[set].block0.valid; // check validityzzaz
    valid1 <= cache[set].block1.valid;
    valid2 <= cache[set].block2.valid;
    valid3 <= cache[set].block3.valid;

    // wr and rd en logic
    if (fetch) begin
        if (miss) begin
            if (ready) begin
                //way determination
                if (!valid0)      way <= 2'b00;
                else if (!valid1) way <= 2'b01;
                else if (!valid2) way <= 2'b10;          
                else if (!valid3) way <= 2'b11;
                else begin 
                    if (cache[set].u01) begin

                        if (cache[set].u12) begin

                            if (cache[set].u23) begin
                                way = 2'b11;
                            end

                            else way = 2'b10;
                        end

                        else if (cache[set].u13) begin
                            way = 2'b11;
                        end

                        else way = 2'b01;

                    end

                    else if (cache[set].u02) begin

                        if (cache[set].u23) begin
                            way = 2'b11;
                        end

                        else way = 2'b10;
                    end

                    else if (cache[set].u03) begin
                        way = 2'b11;
                    end

                    else way = 2'b00;

                    if (way = 2'b00) begin
                        if (fetch && !ready && cache[set].block0.dirty) begin 
                            write_back_en = 1;
                            write_back_data = cache[set].block0[255:0];      
                        end
                    end
                    else if (way = 2'b01) begin
                        if (fetch && !ready && cache[set].block1.dirty) begin 
                            write_back_en = 1;
                            write_back_data = cache[set].block1[255:0];
                        end
                    end
                    else if (way = 2'b10) begin
                        if (fetch && !ready && cache[set].block2.dirty) begin 
                            write_back_en = 1;
                            write_back_data = cache[set].block2[255:0];      
                        end
                    end
                    else if (way = 2'b11) begin
                        if (fetch && !ready && cache[set].block3.dirty) begin 
                            write_back_en = 1;
                            write_back_data = cache[set].block3[255:0];
                        end
                    end
                end

                rd_en      = 1'b0;
                wr_en      = 1'b1;
                write_data = line_from_mem;
            end

            // When main memory wakes cache back up: fill the line (as L2 cache has retrieved the data), but don't read from cache this cycle
            else begin
                //way determination
                if (!valid0)      way_wb <= 2'b00;
                else if (!valid1) way_wb <= 2'b01;
                else if (!valid2) way_wb <= 2'b10;          
                else if (!valid3) way_wb <= 2'b11;
                else begin 
                    if (cache[set].u01) begin

                        if (cache[set].u12) begin

                            if (cache[set].u23) begin
                                way_wb = 2'b11;
                            end

                            else way_wb = 2'b10;
                        end

                        else if (cache[set].u13) begin
                            way_wb = 2'b11;
                        end

                        else way_wb = 2'b01;

                    end

                    else if (cache[set].u02) begin

                        if (cache[set].u23) begin
                            way_wb = 2'b11;
                        end

                        else way_wb = 2'b10;
                    end

                    else if (cache[set].u03) begin
                        way_wb = 2'b11;
                    end

                    else way_wb = 2'b00;

                    if (way_wb = 2'b00) begin
                        if (fetch && !ready && cache[set].block0.dirty) begin 
                            if (wb_ready) begin
                                write_back_en = 0;
                                cache[set].block0.dirty <= 0;   
                            end

                            else begin
                                write_back_en = 1;
                                write_back_data = cache[set].block0[255:0];   
                            end   
                        end
                    end
                    else if (way_wb = 2'b01) begin
                        if (fetch && !ready && cache[set].block1.dirty) begin 
                            if (wb_ready) begin
                                write_back_en = 0;
                                cache[set].block1.dirty <= 0;   
                            end

                            else begin
                                write_back_en = 1;
                                write_back_data = cache[set].block1[255:0];   
                            end   
                        end
                    end
                    else if (way_wb = 2'b10) begin
                        if (fetch && !ready && cache[set].block2.dirty) begin 
                            if (wb_ready) begin
                                write_back_en = 0;
                                cache[set].block2.dirty <= 0;   
                            end

                            else begin
                                write_back_en = 1;
                                write_back_data = cache[set].block2[255:0];   
                            end   
                        end
                    end
                    else if (way_wb = 2'b11) begin
                        if (fetch && !ready && cache[set].block3.dirty) begin 
                            if (wb_ready) begin
                                write_back_en = 0;
                                cache[set].block3.dirty <= 0;   
                            end

                            else begin
                                write_back_en = 1;
                                write_back_data = cache[set].block3[255:0];   
                            end   
                        end
                    end
                end
            end

        end

        else begin

            //way determination
            if (hit0) way = 0;
            else if (hit1) way = 1;
            else if (hit2) way = 2;
            else if (hit3) way = 3;

            if (l1write) begin // sb logic, determine size
                wr_en = 1'b1;
                wmask = '0;
                write_data = {2{wd}};

                bottom_bit = block_offset * 32;
                wmask[bottom_bit +: 32] = '1;

                wmask = ~wmask;
            end

            // On a hit: enable read from cache
            rd_en = 1'b1;
        end
    end

    else if (!fetch) begin
        if (wb_buffer_full) begin
            // hit detection
            hit0_wb_bf <= (cache[set_wb].block0.tag == tag_bits && cache[set_wb].block0.valid && fetch); // if the tags are the same, and its a valid set and we are working with the cache then its a hit0
            hit1_wb_bf <= (cache[set_wb].block1.tag == tag_bits && cache[set_wb].block1.valid && fetch);
            hit2_wb_bf <= (cache[set_wb].block2.tag == tag_bits && cache[set_wb].block2.valid && fetch);
            hit3_wb_bf <= (cache[set_wb].block3.tag == tag_bits && cache[set_wb].block3.valid && fetch);
            miss_wb_bf <= ~(hit0 | hit1 | hit2 | hit3);

            if (miss_wb_bf)
        end
    end

    //write logic
        if (wr_en) begin
            
            if (way == 2'b00) begin

                if (l1write && !miss_wb) begin
                    cache[set].block0.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set].block0.dirty <= 1'b0; // if first time then clean
                end
                cache[set].block0[255:0] <= (cache[set].block0[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block0.tag <= tag_bits;
                cache[set].block0.valid <= 1'b1;
            end

            else if (way == 2'b01) begin

                if (l1write && !miss_wb) begin
                    cache[set].block1.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set].block1.dirty <= 1'b0; // if first time then clean
                end
                cache[set].block1[255:0] <= (cache[set].block0[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block1.tag <= tag_bits;
                cache[set].block1.valid <= 1'b1;
            end

            else if (way == 2'b10) begin

                if (l1write && !miss_wb) begin
                    cache[set].block2.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set].block2.dirty <= 1'b0; // if first time then clean
                end
                cache[set].block2[255:0] <= (cache[set].block2[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block2.tag <= tag_bits;
                cache[set].block2.valid <= 1'b1;
            end

            if (way == 2'b11) begin

                if (l1write && !miss_wb) begin
                    cache[set].block3.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set].block3.dirty <= 1'b0; // if first time then clean
                end
                cache[set].block3[255:0] <= (cache[set].block0[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block3.tag <= tag_bits;
                cache[set].block3.valid <= 1'b1;
            end
        end
    end

endmodule
