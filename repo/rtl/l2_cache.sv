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
    output logic [DATA_WIDTH*4-1:0] write_back_data,
    output logic [ADDRESS_WIDTH-1:0] write_back_addr,
    output logic write_back_en,
    output logic [ADDRESS_WIDTH-1:0] main_mem_addr,
    output logic main_mem_fetch
);
    /* verilator lint_off UNUSED */
    /* verilator lint_off ALWCOMBORDER */
    /* verilator lint_off UNOPTFLAT */
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
        logic u12;
        logic u13;
        logic u23;
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
    logic clean;
    logic [1:0] way_rd;
    logic [ADDRESS_WIDTH-1:13] tag_bits_rd;
    logic [7:0] set_rd;
    logic [2:0] block_offset_rd;
    logic [DATA_WIDTH*BLOCK_SIZE-1:0] wmask;
    logic fetch;
    logic req_d;
    logic req_i;
    logic [ADDRESS_WIDTH-1:0]addr;
    logic l1write;
    logic hit0, hit1, hit2, hit3;
    logic valid0, valid1, valid2, valid3;
    logic miss;
    logic evict;
    logic wb_ready_d_next;
    logic write_back_en_next;
    logic [DATA_WIDTH*4-1:0] write_back_data_next;

    assign tag_bits_rd = addr[ADDRESS_WIDTH-1:13];
    assign set_rd = addr[12:5];
    assign block_offset_rd = addr[4:2];

    //l1 write back request logic
    logic [DATA_WIDTH*4-1:0] l1write_back_data_buffer;
    logic [DATA_WIDTH*4-1:0] l1write_back_data_buffer_next;
    logic l1write_buffer;
    logic l1write_buffer_next;
    logic [ADDRESS_WIDTH-1:0] l1write_back_addr_buffer;
    logic [ADDRESS_WIDTH-1:0] l1write_back_addr_buffer_next;
    logic [ADDRESS_WIDTH-1:13] tag_bits_wb;
    logic [7:0] set_wb;
    logic [2:0] block_offset_wb;
    logic hit0_wb, hit1_wb, hit2_wb, hit3_wb;
    logic miss_wb;

    assign tag_bits_wb = l1write_back_addr_buffer[ADDRESS_WIDTH-1:13];
    assign set_wb = l1write_back_addr_buffer[12:5];
    assign block_offset_wb = l1write_back_addr_buffer[4:2];

    logic [1:0] way;
    logic [ADDRESS_WIDTH-1:13] tag_bits;
    logic [7:0] set;
    logic [2:0] block_offset;

    //l2 write back request logic
    logic [DATA_WIDTH*8-1:0] l2write_back_data_buffer;
    logic [DATA_WIDTH*8-1:0] l2write_back_data_buffer_next;
    logic [1:0] l2write_buffer; //indicates number of 4 word blocks needed to be written back to main mem
    logic [1:0] l2write_buffer_next;
    logic [ADDRESS_WIDTH-1:0] l2write_back_addr_buffer;
    logic [ADDRESS_WIDTH-1:0] l2write_back_addr_buffer_next;

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
            cache[i].u01            = 1'b0;
            cache[i].u02            = 1'b0;
            cache[i].u03            = 1'b0;
            cache[i].u12            = 1'b0;
            cache[i].u13            = 1'b0;
            cache[i].u23            = 1'b0;
        end

        l1write_buffer = 1'b0;
        l2write_buffer = 2'b0;
    end


    always_comb begin
        //default case
        req_d = 0;
        req_i = 0;
        fetch = 0;
        addr = '0;
        l1write = 0;
        req_i = 0;
        req_d = 0;
        wmask = '0;
        wr_en = 1'b0;
        rd_en = 1'b0;
        wr_wb = 1'b0;
        write_data = '0;
        evict = 0;
        main_mem_addr = '0;
        main_mem_fetch = 0;
        wb_ready_d_next = 0;
        l1write_buffer_next = l1write_buffer;
        l1write_back_data_buffer_next = l1write_back_data_buffer;
        l1write_back_addr_buffer_next = l1write_back_addr_buffer;
        l2write_buffer_next = l2write_buffer;
        l2write_back_data_buffer_next = l2write_back_data_buffer;
        l2write_back_addr_buffer_next = l2write_back_addr_buffer;
        write_back_en_next = 0;
        write_back_addr = '0;
        write_back_data_next = '0;
        way = '0;
        way_rd = '0;
        clean = 0;
        tag_bits = '0;
        set = '0;
        block_offset = '0;

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

        // hit detection
        hit0 = ((cache[set_rd].block0.tag == tag_bits_rd) && cache[set_rd].block0.valid);
        hit1 = ((cache[set_rd].block1.tag == tag_bits_rd) && cache[set_rd].block1.valid);
        hit2 = ((cache[set_rd].block2.tag == tag_bits_rd) && cache[set_rd].block2.valid);
        hit3 = ((cache[set_rd].block3.tag == tag_bits_rd) && cache[set_rd].block3.valid);
        miss = ~(hit0 | hit1 | hit2 | hit3);

        valid0 = cache[set_rd].block0.valid;
        valid1 = cache[set_rd].block1.valid;
        valid2 = cache[set_rd].block2.valid;
        valid3 = cache[set_rd].block3.valid;

        hit0_wb = (cache[set_wb].block0.tag == tag_bits_wb && cache[set_wb].block0.valid);
        hit1_wb = (cache[set_wb].block1.tag == tag_bits_wb && cache[set_wb].block1.valid);
        hit2_wb = (cache[set_wb].block2.tag == tag_bits_wb && cache[set_wb].block2.valid);
        hit3_wb = (cache[set_wb].block3.tag == tag_bits_wb && cache[set_wb].block3.valid);
        miss_wb = ~(hit0_wb | hit1_wb | hit2_wb | hit3_wb);

        if (l1write && !l1write_buffer) begin
            wb_ready_d_next = 1;

            l1write_buffer_next = l1write;
            l1write_back_data_buffer_next = l1write_back_data;
            l1write_back_addr_buffer_next = l1write_back_addr;
        end
        
        // wr and rd en logic
        if (fetch) begin

            if (miss) begin
                
                main_mem_addr = addr;
                main_mem_fetch = 1;

                if (!valid0)      way_rd = 2'b00;
                else if (!valid1) way_rd = 2'b01;
                else if (!valid2) way_rd = 2'b10;          
                else if (!valid3) way_rd = 2'b11;
                else begin
                    evict = 1;

                    if (cache[set_rd].u01) begin
                        if (cache[set_rd].u12) begin
                            if (cache[set_rd].u23) begin
                                way_rd = 2'b11;
                            end
                            else way_rd = 2'b10;
                        end
                        else if (cache[set_rd].u13) begin
                            way_rd = 2'b11;
                        end
                        else way_rd = 2'b01;
                    end

                    else if (cache[set_rd].u02) begin
                        if (cache[set_rd].u23) begin
                            way_rd = 2'b11;
                        end
                        else way_rd = 2'b10;
                    end

                    else if (cache[set_rd].u03) begin
                        way_rd = 2'b11;
                    end

                    else way_rd = 2'b00;
                end

                if (evict) begin
                    if (way_rd == 2'b00) begin
                        if (cache[set_rd].block0.dirty && (l2write_buffer == 0)) begin 
                            l2write_back_data_buffer_next = cache[set_rd].block0[255:0];
                            l2write_back_addr_buffer_next = {{cache[set_rd].block0.tag}, {set_rd}, {5'b0}};
                            clean = 1;
                            l2write_buffer_next = 2'b10;
                        end

                        else if (!cache[set_rd].block0.dirty && ready) begin
                            wr_en = 1;
                            write_data = line_from_mem;
                            wmask = '1;
                            way = way_rd;
                            tag_bits = tag_bits_rd;
                            set = set_rd;
                            block_offset = block_offset_rd;
                        end
                    end

                    else if (way_rd == 2'b01) begin
                        if (cache[set_rd].block1.dirty && (l2write_buffer == 2'b00)) begin
                            l2write_back_data_buffer_next = cache[set_rd].block1[255:0];
                            l2write_back_addr_buffer_next = {{cache[set_rd].block1.tag}, {set_rd}, {5'b0}};
                            clean = 1;
                            l2write_buffer_next = 2'b10;
                        end

                        else if (!cache[set_rd].block1.dirty && ready) begin
                            wr_en = 1;
                            write_data = line_from_mem;
                            wmask = '1;
                            tag_bits = tag_bits_rd;
                            set = set_rd;
                            block_offset = block_offset_rd;
                            way = way_rd;
                        end
                    end

                    else if (way_rd == 2'b10) begin
                        if (cache[set_rd].block2.dirty && (l2write_buffer == 2'b00)) begin 
                            l2write_back_data_buffer_next = cache[set_rd].block2[255:0];
                            l2write_back_addr_buffer_next = {{cache[set_rd].block2.tag}, {set_rd}, {5'b0}};
                            clean = 1;
                            l2write_buffer_next = 2'b10;
                        end

                        else if (!cache[set_rd].block2.dirty && ready) begin
                            wr_en = 1;
                            write_data = line_from_mem;
                            wmask = '1;
                            tag_bits = tag_bits_rd;
                            set = set_rd;
                            block_offset = block_offset_rd;
                            way = way_rd;
                        end
                    end

                    else if (way_rd == 2'b11) begin
                        if (cache[set_rd].block3.dirty && (l2write_buffer == 0)) begin 
                            l2write_back_data_buffer_next = cache[set_rd].block3[255:0];
                            l2write_back_addr_buffer_next = {{cache[set_rd].block3.tag}, {set_rd}, {5'b0}};
                            clean = 1;
                            l2write_buffer_next = 2'b10;
                        end

                        else if (!cache[set_rd].block3.dirty && ready) begin
                            wr_en = 1;
                            write_data = line_from_mem;
                            wmask = '1;
                            tag_bits = tag_bits_rd;
                            set = set_rd;
                            block_offset = block_offset_rd;
                            way = way_rd;
                        end
                    end
                end

                else if (ready) begin
                    wr_en = 1'b1;
                    write_data = line_from_mem;
                    wmask = '1;
                    tag_bits = tag_bits_rd;
                    set = set_rd;
                    block_offset = block_offset_rd;
                    way = way_rd;
                    main_mem_fetch = 0;
                end
            end

            else if (!miss) begin
                if (hit0) way = 0;
                else if (hit1) way = 1;
                else if (hit2) way = 2;
                else if (hit3) way = 3;

                if (!l1write || wb_ready_d_next) begin
                    rd_en = 1;
                    tag_bits = tag_bits_rd;
                    set = set_rd;
                    block_offset = block_offset_rd;
                end
            end
        end

        if (wr_en && l1write_buffer && (addr[31:4] == l1write_back_addr_buffer[31:4])) begin
            wr_wb = 1;
            l1write_buffer_next = l1write_buffer - 1;
            if (block_offset_wb == 3'b000) begin
                write_data[127:0] = l1write_back_data_buffer;
            end
            else if (block_offset_wb == 3'b100) begin
                write_data[255:128] = l1write_back_data_buffer;
            end
        end

        if ((l1write_buffer && miss_wb) && wb_ready) begin
            write_back_en_next = 1;
            write_back_data_next = l1write_back_data_buffer;
            write_back_addr = l1write_back_addr_buffer;
            l1write_buffer_next = l1write_buffer - 1;
        end

        else if ((l2write_buffer == 2'b10) && wb_ready) begin
            write_back_en_next = 1;
            write_back_data_next = l2write_back_data_buffer[127:0];
            write_back_addr = l2write_back_addr_buffer;
            l2write_buffer_next = l2write_buffer - 1;
        end

        else if ((l2write_buffer == 2'b01) && wb_ready) begin
            write_back_en_next = 1;
            write_back_data_next = l2write_back_data_buffer[255:128];
            write_back_addr = {l2write_back_addr_buffer[31:5], 1'b1, l2write_back_addr_buffer[3:0]};
            l2write_buffer_next = l2write_buffer - 1;
        end

        if (l1write_buffer && !rd_en && !wr_en && !miss_wb) begin
            wr_en = 1;
            wr_wb = 1;
            write_data = {2{l1write_back_data_buffer}};
            l1write_buffer_next = l1write_buffer - 1;

            if (hit0_wb) way = 2'b00;
            else if (hit1_wb) way = 2'b01;
            else if (hit2_wb) way = 2'b10;
            else if (hit3_wb) way = 2'b11;

            tag_bits = tag_bits_wb;
            set = set_wb;
            block_offset = block_offset_wb;

            if (block_offset_wb == 3'b000) begin
                wmask = {{128{1'b0}}, {128{1'b1}}};
            end
            else if (block_offset_wb == 3'b100) begin
                wmask = {{128{1'b1}}, {128{1'b0}}};
            end
        end
    end


    always_ff @(posedge clk) begin
        // assign default values
        ready_i <= 0;
        ready_d <= 0;
        data_out <= '0;

        // assign all "next" values
        wb_ready_d <= wb_ready_d_next;
        l1write_buffer <= l1write_buffer_next;
        l1write_back_data_buffer <= l1write_back_data_buffer_next;
        l1write_back_addr_buffer <= l1write_back_addr_buffer_next;
        l2write_buffer <= l2write_buffer_next;
        l2write_back_data_buffer <= l2write_back_data_buffer_next;
        l2write_back_addr_buffer <= l2write_back_addr_buffer_next;
        write_back_en <= write_back_en_next;
        write_back_data <= write_back_data_next;

        if (clean) begin

            if (way_rd == 2'b00) begin
                cache[set_rd].block0.dirty <= 0;
            end
            else if (way_rd == 2'b01) begin
                cache[set_rd].block1.dirty <= 0;
            end
            if (way_rd == 2'b10) begin
                cache[set_rd].block2.dirty <= 0;
            end
            else if (way_rd == 2'b11) begin
                cache[set_rd].block3.dirty <= 0;
            end
    
        end

        //write logic
        if (wr_en) begin

            if (way == 2'b00) begin
                if (wr_wb) begin
                    cache[set].block0.dirty <= 1'b1; // if we are writing over it from L1 then it is dirty
                end
                else begin
                    cache[set].block0.dirty <= 1'b0; // if writing from main mem then clean
                end

                cache[set].block0[255:0] <= (cache[set].block0[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block0.tag <= tag_bits;
                cache[set].block0.valid <= 1'b1;
            end

            
            else if (way == 2'b01) begin

                if (wr_wb) begin
                    cache[set].block1.dirty <= 1'b1; // if we are writing over it from L1 then it is dirty
                end
                else begin
                    cache[set].block1.dirty <= 1'b0; // if writing from main mem then clean
                end

                cache[set].block1[255:0] <= (cache[set].block1[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block1.tag <= tag_bits;
                cache[set].block1.valid <= 1'b1;
            end

            else if (way == 2'b10) begin

                if (wr_wb) begin
                    cache[set].block2.dirty <= 1'b1; // if we are writing over it from L1 then it is dirty
                end
                else begin
                    cache[set].block2.dirty <= 1'b0; // if writing from main mem then clean
                end

                cache[set].block2[255:0] <= (cache[set].block2[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block2.tag <= tag_bits;
                cache[set].block2.valid <= 1'b1;
            end

            
            else if (way == 2'b11) begin

                if (wr_wb) begin
                    cache[set].block3.dirty <= 1'b1; // if we are writing over it from L1 then it is dirty
                end
                else begin
                    cache[set].block3.dirty <= 1'b0; // if writing from main mem then clean
                end

                cache[set].block3[255:0] <= (cache[set].block3[255:0] & ~wmask) | (write_data & wmask);
                cache[set].block3.tag <= tag_bits;
                cache[set].block3.valid <= 1'b1;
            end
        end

        //read logic
        if (rd_en) begin
            //assert ready on the correct L1 cache
            if (req_d) begin
                ready_d <= 1;
            end

            else if (req_i) begin
                ready_i <= 1;
            end
 
            // we don't update valid or dirty since we are only reading        
            if (way == 2'b00) begin
                case(block_offset_rd[2])
                1'b0: data_out <= cache[set].block0[127:0];
                1'b1: data_out <= cache[set].block0[255:128];
                endcase
                cache[set].u01 <= 1;
                cache[set].u02 <= 1;
                cache[set].u03 <= 1;
            end

            else if (way == 2'b01) begin
                case(block_offset[2])
                1'b0: data_out <= cache[set].block1[127:0];
                1'b1: data_out <= cache[set].block1[255:128];
                endcase
                cache[set].u01 <= 0;
                cache[set].u12 <= 1;
                cache[set].u13 <= 1;
            end

            else if (way == 2'b10) begin
                case(block_offset[2])
                1'b0: data_out <= cache[set].block2[127:0];
                1'b1: data_out <= cache[set].block2[255:128];
                endcase
                cache[set].u02 <= 0;
                cache[set].u12 <= 0;
                cache[set].u23 <= 1;
            end

            else if (way == 2'b11) begin
                case(block_offset_rd[2])
                1'b0: data_out <= cache[set].block3[127:0];
                1'b1: data_out <= cache[set].block3[255:128];
                endcase
                cache[set].u03 <= 0;
                cache[set].u13 <= 0;
                cache[set].u23 <= 0;
            end
        end
    end

endmodule
