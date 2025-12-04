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
    input  logic ready,
    input  logic wb_ready,
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
    logic wr_wb;
    logic [(DATA_WIDTH * BLOCK_SIZE)-1 : 0] write_data;
    logic [1:0] way_rd;
    logic [ADDRESS_WIDTH-1:13] tag_bits_rd;
    logic [7:0] set_rd;
    logic [2:0] block_offset_rd;
    logic [1:0] byte_offset_rd;
    logic [DATA_WIDTH*BLOCK_SIZE-1:0] wmask;
    logic fetch;
    logic req_d;
    logic req_i;
    logic l1write;
    logic hit0, hit1, hit2, hit3;
    logic valid0, valid1, valid2, valid3;
    logic miss;
    logic evict;
    logic [7:0] bottom_bit;

    assign tag_bits_rd = addr[ADDRESS_WIDTH-1:13];
    assign set_rd = addr[12:5];
    assign block_offset_rd = addr[4:2];
    assign byte_offset_rd = addr[1:0];

    //l1 write back request logic
    logic [DATA_WIDTH*4-1:0] l1write_back_data_buffer,
    logic l1write_buffer,
    logic [ADDRESS_WIDTH-1:0] l1write_back_addr_buffer,
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

    logic [1:0] way;
    logic [ADDRESS_WIDTH-1:13] tag_bits;
    logic [7:0] set;
    logic [2:0] block_offset;
    logic [1:0] byte_offset;    

    //l2 write back request logic
    logic [DATA_WIDTH*8-1:0] l2write_back_data_buffer,
    logic [1:0] l2write_buffer, //indicates number of 4 word blocks needed to be written back to main mekm
    logic [ADDRESS_WIDTH-1:0] l2write_back_addr_buffer,

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
        //default case
        ready_d = 0;
        ready_i = 0;
        req_d = 0;
        req_i = 0;

        //arbiter logic
        if (!fetch_i && !fetch_d) begin
            fetch = 0;
            l1write = 0;
        end

        else if (fetch_i && !fetch_d) begin
            fetch = 1;
            addr = addr_i;
            l1write = 0;
            req_i = 1;
        end

        else if (!fetch_i && fetch_d) begin
            fetch = 1;
            addr = addr_d;
            l1write = l1write_back_en;
            req_d = 1;
        end

        else if (fetch_i && fetch_d) begin
            fetch = 1;
            addr = addr_d;
            l1write = l1write_back_en;
            req_d = 1;
        end

        //read logic
        if (rd_en) begin
            //assert ready on the correct L1 cache
            if (req_d) begin
                ready_d = 1;
            end

            else if (req_i) begin
                ready_i = 1;
            end
 
            // we don't update valid or dirty since we are only reading        
            if (way == 2'b00) begin
                case(block_offset_rd[2])
                1'b0: data_out = cache[set].block0[127:0];
                1'b1: data_out = cache[set].block0[255:128];
                endcase
                cache[set].u01 = 1;
                cache[set].u02 = 1;
                cache[set].u03 = 1;
            end

            else if (way == 2'b01) begin
                case(block_offset[2])
                1'b0: data_out = cache[set].block1[127:0];
                1'b1: data_out = cache[set].block1[255:128];
                endcase
                cache[set].u01 = 0;
                cache[set].u12 = 1;
                cache[set].u13 = 1;
            end

            else if (way == 2'b10) begin
                case(block_offset[2])
                1'b0: data_out = cache[set].block2[127:0];
                1'b1: data_out = cache[set].block2[255:128];
                endcase
                cache[set].u02 = 0;
                cache[set].u12 = 0;
                cache[set].u23 = 1;
            end

            else if (way == 2'b11) begin
                case(block_offset_rd[2])
                1'b0: data_out = cache[set].block3[127:0];
                1'b1: data_out = cache[set].block3[255:128];
                endcase
                cache[set].u03 = 0;
                cache[set].u13 = 0;
                cache[set].u23 = 0;
            end
        end
    end

    always_ff @(posedge clk) begin // only write is synchronous
        //default case
        wmask <= '0;
        wr_en <= 1'b0;
        rd_en <= 1'b0;
        write_data <= '0;
        data_out <= '0;
        write_back_en <= 0;
        ready_i <= 0;
        ready_d <= 0;
        wb_ready_d <= 0;
        evict <= 0;

        if (l1write && !l1write_buffer) begin
            wb_ready_d = 1;

            l1write_buffer <= l1write;
            l1write_back_data_buffer <= l1write_back_data;
            l1write_back_addr_buffer <= l1write_back_addr;
        end

        if (l1write_buffer) begin
            // hit detection
            hit0_wb <= (cache[set_wb].block0.tag == tag_bits_rd && cache[set_wb].block0.valid && fetch); // if the tags are the same, and its a valid set_rd and we are working with the cache then its a hit0
            hit1_wb <= (cache[set_wb].block1.tag == tag_bits_rd && cache[set_wb].block1.valid && fetch);
            hit2_wb <= (cache[set_wb].block2.tag == tag_bits_rd && cache[set_wb].block2.valid && fetch);
            hit3_wb <= (cache[set_wb].block3.tag == tag_bits_rd && cache[set_wb].block3.valid && fetch);
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
        hit0 <= (cache[set_rd].block0.tag == tag_bits_rd && cache[set_rd].block0.valid && fetch); // if the tags are the same, and its a valid set_rd and we are working with the cache then its a hit0
        hit1 <= (cache[set_rd].block1.tag == tag_bits_rd && cache[set_rd].block1.valid && fetch);
        hit2 <= (cache[set_rd].block2.tag == tag_bits_rd && cache[set_rd].block2.valid && fetch);
        hit3 <= (cache[set_rd].block3.tag == tag_bits_rd && cache[set_rd].block3.valid && fetch);
        miss <= ~(hit0 | hit1 | hit2 | hit3) && fetch; // we need to know if we are accessing the cache 

        valid0 <= cache[set_rd].block0.valid; // check validityzzaz
        valid1 <= cache[set_rd].block1.valid;
        valid2 <= cache[set_rd].block2.valid;
        valid3 <= cache[set_rd].block3.valid;

        // wr and rd en logic
        if (fetch) begin
            if (miss) begin
                if (ready) begin
                    //way_rd determination
                    if (!valid0)      way_rd <= 2'b00;
                    else if (!valid1) way_rd <= 2'b01;
                    else if (!valid2) way_rd <= 2'b10;          
                    else if (!valid3) way_rd <= 2'b11;
                    else begin
                        evict = 1;

                        if (cache[set_rd].u01) begin

                            if (cache[set_rd].u12) begin

                                if (cache[set_rd].u23) begin
                                    way_rd <= 2'b11;
                                end

                                else way_rd <= 2'b10;
                            end

                            else if (cache[set_rd].u13) begin
                                way_rd <= 2'b11;
                            end

                            else way_rd <= 2'b01;

                        end

                        else if (cache[set_rd].u02) begin

                            if (cache[set_rd].u23) begin
                                way_rd <= 2'b11;
                            end

                            else way_rd <= 2'b10;
                        end

                        else if (cache[set_rd].u03) begin
                            way_rd <= 2'b11;
                        end

                        else way_rd <= 2'b00;
                    end

                    if (evict) begin
                        if (way_rd <= 2'b00) begin
                            if (cache[set_rd].block0.dirty && !l2write_buffer) begin 
                                l2write_back_data_buffer <= cache[set_rd].block0[255:0];
                                l2write_back_addr_buffer <= {cache[set_rd].block0.tag, set_rd, 6'b0};
                                cache[set_rd].block0.dirty <= 0;
                                l2write_buffer <= 2'b10;
                            end

                            else if (!cache[set_rd].block0.dirty && ready) begin
                                wr_en <= 1;
                                write_data <= line_from_mem;
                                wmask <= '1;
                                way <= way_rd;
                                tag_bits <= tag_bits_rd;
                                set <= set_rd;
                                block_offset <= block_offset_rd;
                                byte_offset <= byte_offset_rd;
                            end
                        end

                        else if (way_rd <= 2'b01) begin
                            if (cache[set_rd].block1.dirty && !l2write_buffer) begin 
                                l2write_back_data_buffer <= cache[set_rd].block1[255:0];
                                l2write_back_addr_buffer <= {cache[set_rd].block1.tag, set_rd, 6'b0};
                                cache[set_rd].block1.dirty <= 0;
                                l2write_buffer <= 2'b10;
                            end

                            else if (!cache[set_rd].block1.dirty && ready) begin
                                wr_en <= 1;
                                write_data <= line_from_mem;
                                wmask <= '1;
                                tag_bits <= tag_bits_rd;
                                set <= set_rd;
                                block_offset <= block_offset_rd;
                                byte_offset <= byte_offset_rd;
                            end
                        end

                        else if (way_rd <= 2'b10) begin
                            if (cache[set_rd].block2.dirty && !l2write_buffer) begin 
                                l2write_back_data_buffer <= cache[set_rd].block2[255:0];
                                l2write_back_addr_buffer <= {cache[set_rd].block2.tag, set_rd, 6'b0};
                                cache[set_rd].block2.dirty <= 0;
                                l2write_buffer <= 2'b10;
                            end

                            else if (!cache[set_rd].block2.dirty && ready) begin
                                wr_en <= 1;
                                write_data <= line_from_mem;
                                wmask <= '1;
                                tag_bits <= tag_bits_rd;
                                set <= set_rd;
                                block_offset <= block_offset_rd;
                                byte_offset <= byte_offset_rd;
                            end
                        end

                        else if (way_rd <= 2'b11) begin
                            if (cache[set_rd].block3.dirty && !l2write_buffer) begin 
                                l2write_back_data_buffer <= cache[set_rd].block3[255:0];
                                l2write_back_addr_buffer <= {cache[set_rd].block3.tag, set_rd, 6'b0};
                                cache[set_rd].block3.dirty <= 0;
                                l2write_buffer <= 2'b10;
                            end

                            else if (!cache[set_rd].block3.dirty && ready) begin
                                wr_en <= 1;
                                write_data <= line_from_mem;
                                wmask <= '1;
                                tag_bits <= tag_bits_rd;
                                set <= set_rd;
                                block_offset <= block_offset_rd;
                                byte_offset <= byte_offset_rd;
                            end
                        end
                    end

                    else if (ready) begin
                        wr_en      <= 1'b1;
                        write_data <= line_from_mem;
                        wmask <= '1;
                        tag_bits <= tag_bits_rd;
                        set <= set_rd;
                        block_offset <= block_offset_rd;
                        byte_offset <= byte_offset_rd;
                    end

                end

            end

            else if (!miss) begin
                //way_rd determination
                if (hit0) way_rd <= 0;
                else if (hit1) way_rd <= 1;
                else if (hit2) way_rd <= 2;
                else if (hit3) way_rd <= 3;

                if (!l1write || wb_ready_d) begin // if L1 cache ready to receive data, enable read
                    rd_en <= 1;
                    bottom_bit <= block_offset_rd * 32;
                    tag_bits <= tag_bits_rd;
                    set <= set_rd;
                    block_offset <= block_offset_rd;
                    byte_offset <= byte_offset_rd;
                end

            end

        end

        if ((l2write_buffer == 2'b10) && wb_ready) begin
            write_back_en <= 1;
            write_back_data <= l2write_back_data_buffer[127:0];
            write_back_addr <= l2write_back_addr_buffer;
            l2write_buffer <= l2write_buffer - 1;
        end

        else if ((l2write_buffer == 2'b01) && wb_ready) begin
            write_back_en <= 1;
            write_back_data <= l2write_back_data_buffer[255:128];
            write_back_addr <= {l2write_back_addr_buffer[31:5], 1'b1, l2write_back_addr_buffer[3:0]};
            l2write_buffer <= l2write_buffer - 1;
        end

        else if ((l1write_buffer && miss_wb) && wb_ready) begin
            write_back_en <= 1;
            write_back_data <= l1write_back_data_buffer
            write_back_addr <= l1write_back_addr_buffer
            l2write_buffer <= l1write_buffer - 1;
        end

        if (!rd_en && !wr_en && !miss_wb) begin
            
        end

        //write logic
        if (wr_en) begin
            
            if (way == 2'b00) begin

                if (wr_wb) begin
                    cache[set_rd].block0.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set_rd].block0.dirty <= 1'b0; // if first time then clean
                end
                cache[set_rd].block0[255:0] <= (cache[set_rd].block0[255:0] & ~wmask) | (write_data & wmask);
                cache[set_rd].block0.tag <= tag_bits;
                cache[set_rd].block0.valid <= 1'b1;
            end

            else if (way_rd == 2'b01) begin

                if (l1write && !miss_wb) begin
                    cache[set_rd].block1.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set_rd].block1.dirty <= 1'b0; // if first time then clean
                end
                cache[set_rd].block1[255:0] <= (cache[set_rd].block0[255:0] & ~wmask) | (write_data & wmask);
                cache[set_rd].block1.tag <= tag_bits_rd;
                cache[set_rd].block1.valid <= 1'b1;
            end

            else if (way_rd == 2'b10) begin

                if (l1write && !miss_wb) begin
                    cache[set_rd].block2.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set_rd].block2.dirty <= 1'b0; // if first time then clean
                end
                cache[set_rd].block2[255:0] <= (cache[set_rd].block2[255:0] & ~wmask) | (write_data & wmask);
                cache[set_rd].block2.tag <= tag_bits_rd;
                cache[set_rd].block2.valid <= 1'b1;
            end

            if (way_rd == 2'b11) begin

                if (l1write && !miss_wb) begin
                    cache[set_rd].block3.dirty <= 1'b1; // if we are writing over it then it is dirty
                end
                else begin
                    cache[set_rd].block3.dirty <= 1'b0; // if first time then clean
                end
                cache[set_rd].block3[255:0] <= (cache[set_rd].block0[255:0] & ~wmask) | (write_data & wmask);
                cache[set_rd].block3.tag <= tag_bits_rd;
                cache[set_rd].block3.valid <= 1'b1;
            end
        end
    end

endmodule
