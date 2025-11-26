module instr_cache_controller #(
    parameter DATA_WIDTH     = 32,
    parameter ADDRESS_WIDTH  = 32,
    parameter BLOCK_WORDS    = 4,   // words per cache line
    parameter TAG_WIDTH      = 21
) (

    //fetch = CPU wants to fetch instruction at addr
    input  logic fetch,
    input  logic [ADDRESS_WIDTH-1:0] addr,

    input  logic [DATA_WIDTH*BLOCK_WORDS-1:0] line_from_mem,

    // Output to CPU
    output logic [DATA_WIDTH-1:0]     instr_out,
    output logic hit, //high on hit

    // Connection to your instr_cache instance
    output logic wr_en,
    output logic rd_en,
    output logic u_en,
    output logic d_en,
    output logic d,
    output logic u,
    output logic [ADDRESS_WIDTH-1:0] cache_addr,
    output logic [DATA_WIDTH*BLOCK_WORDS-1:0] write_data,
    output logic [DATA_WIDTH*BLOCK_WORDS-1:0] wmask,
    output logic way_sel,

    input  logic [TAG_WIDTH-1:0] tags_ways [2],
    input  logic [DATA_WIDTH-1:0] data_out,
    // not used for Instruction cache : input  logic  dirty_out,   
    input  logic used_out,// we treat this as LRU bit
    input  logic valid_out  //valid bit for selected way (not fully used)
);

    //Address breakdown and tag bits (for tag compare)
    //[31:11] = tag (21 bits)
    //[10:4]= set index (7 bits)
    //[3:2] = block offset (word in line)
    //[1:0]= byte offset

    logic [TAG_WIDTH-1:0] tag_bits;
    assign tag_bits = addr[ADDRESS_WIDTH-1 : ADDRESS_WIDTH-TAG_WIDTH];
    assign cache_addr = addr;

    logic hit0, hit1;

    logic correct_way;

    // LRU-related internal signals
    logic access_valid;
    logic access_way;
    logic [1:0]  valid_ways;
    logic way_to_replace;

    // For now: assume both ways valid (no per-way valids exported)
    assign valid_ways = 2'b11;


    logic miss;

//hit detection
    always_comb begin
        hit0 = (tags_ways[0] == tag_bits);
        hit1 = (tags_ways[1] == tag_bits);
        miss = ~(hit0 | hit1);
    end
    

    always_comb begin
        // Default: no update
        u_en = 1'b0;
        u    = 1'b0;

        if (access_valid) begin
            u_en = 1'b1;
            u    = access_way;   //last used = this way
        end
    end


    always_comb begin
        // Default
        way_to_replace = 1'b0;
//this whole part of the circuit relies on prioritizing validity for replacement over most recently used (which is only taken into account when both ways are valid)
        if (miss) begin
            logic valid0 = valid_ways[0];
            logic valid1 = valid_ways[1];
            
            //both bits are invalid, we choose at random (way0)
            if (!valid0 && !valid1) begin
                way_to_replace = 1'b0;
            end
            
            //way0 is invalid
            else if (!valid0) begin
                way_to_replace = 1'b0;
            end

            //way1 is invalid
            else if (!valid1) begin
                way_to_replace = 1'b1;
            end

            //both bits are valid, we take into account which way was least recently used (LRU logic)
            else begin
                way_to_replace= ~used_out;
            end
        end
    end



    always_comb begin
        // defaults
        wr_en= 1'b0;
        rd_en = 1'b0;
        d_en = 1'b0;
        d = 1'b0;
        write_data = '0;
        wmask = '0;
        way_sel  = 1'b0;
        instr_out = '0;
        hit = 1'b0;
        access_valid = 1'b0;
        access_way = 1'b0;

        if (!fetch) begin
            //no access this cycle: do nothing (no fetching from ROM)
        end
        else begin

            if (!miss) begin //in case of a hit, we need to choose the right hit in the set
                correct_way = hit1;//equivalent to (hit1)?1:0 because as defined previously in the circuit if hit1 is 1 this means the tag of hit1 matched the address tag
            end

            else begin//in the case of a miss we use LRU to choose which way in the set we should evict
                correct_way = way_to_replace;
            end

            way_sel = correct_way;

            if (miss) begin
                // write full line into chosen way
                wr_en      = 1'b1;
                write_data =line_from_mem;
                wmask = {DATA_WIDTH*BLOCK_WORDS{1'b1}}; // write entire line
                d = 1'b0;   // instructions: always clean
            end

            rd_en= 1'b1;
            instr_out= data_out;
            hit = ~miss;

            access_valid = 1'b1;
            access_way = correct_way;
        end
    end

endmodule

