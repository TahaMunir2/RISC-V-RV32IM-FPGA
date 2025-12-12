# Leo Yin (02574254) Personal Statement

## Table of Contents

- [Overview](#overview)
- [Implementation](#implementation)
  - [Lab 4](#lab-4)
  - [Designing the L1d and L1i cache](#designing-the-d1d-and-d1i-cache)
  - [L1i and L1d cache testbenching](#l1i-and-l1d-cache-testbenching)
  - [Designing the L2 cache ](#designing-the-l2-cache)
  - [L2 cache testbenching](#l2-cache-testbenching)
- [Mistakes](#mistakes)
- [Reflection](#reflection)

---

## Overview

My main contributions were:
- Designing the control path for Lab 4
- Implementing L1d and L1i cache
- Test Benching the L1d and L1i cache
- Implementing the L2 cache
- Test Benching the L2 cache

I also wrote the full documentation of the cache section, which goes into much more detail about how the cache works. The file can be found here: [Cache README](https://github.com/TahaMunir2/Team5/blob/Hierarchical-cache/README.md)

---

## Implementation

### Lab 4

For Lab 4, we decided our roles using a random wheel. I was given the task of designing the part of the control path of the reduced RISC-V processor, including the instruction memory (which we decided to use a ROM block for), the control unit, and the sign extender. The components that I created are highlighted in green below:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/reducedRV.png)

It is, however, important to note that I did not testbench this code and that multiple bug fixes had to be made to the components that I created. Also, since Lab 4 was only using addi and bne instructions, i only implemented the addi and bne instructions to the decoder, and not the full RISC-V instruction set.

---

### Designing the L1d and L1i cache

Initially, my goal for this section was to create the cache array for the i cache and d cache, which were 2-way associative caches that included a valid bit in each block, and a used bit (for LRU replacement policy) in each set.

```SystemVerilog
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
```

I intended for the array to mirror the image below:

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/cache_array.png)

I intended for the instruction cache array to be able to load data from L2 on command, supply data to the processor when requested, and update its valid and dirty bits as directed by the cache controller. The controller would have specified the set, block offset, transfer size, and whether a read or write is enabled.

The data cache array was originally intended to support the same operations as the instruction cache array (and more), taking direction from the cache controller. In addition to the previously defined functions, each block would have a dirty bit that was going to be updated based on whether the write originated from L2 or the processor, and the array would implement a writeback mechanism to return dirty data to the L2 cache.

On write:
| cache[set].blocki.d | write from processor? | cach[set].blocki.d_next |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

On eviction:
| cache[set].blocki.d | write_back_en | cach[set].blocki.d_next |
| --- | --- | --- |
| 0 | 0 | 0 |
| 1 | 1 | 0 |

However, after my teammates designed the L1i and L1d cache controller, we decided to implement both the cache array and cache controller on the same SystemVerilog module, as it would be easier to understand from a top level view. Additionally, the cache controller required quite a few internal signals from the cache array, so placing both components on the same sheet made it easier to access these values directly without routing them out of the array as outputs.

Thus, after I finished the L1i and L1d cache array, and my teammates finished the cache controller, we integrated both onto the same .sv file.

---

### L1i and L1d cache testbenching

After completing both the L1i and L1d cache, I was tasked with testing them. This was my first testbenching experience for this project, so I turned to my teammates for help in getting started. This helped me learn how to testbench much more quickly compared to the time it would take if I learned by myself.

I decided to include every test in the same test instance for the L1 caches. This is because it would take far too long to reinitialise every test case (i.e. setting valid bits high, inputting correct data) and previous test cases would be useful in providing a scenario in which another test case would happen. Also, I decided not to use loops in my test and instead opted for running the simulation 1 cycle at a time since I wanted to study how the outputs of the cache changed for every individual cycle. With this design philosophy, I created the l1d_cache_tb.cpp and l1i_cache_tb.cpp files.

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/L1c_tb.png)

Since the data cache included all the features that the instruction cache had, I decided to design the data cache testbench first, and simply remove the tests that tested the features that the instruction cache didn't have to create the instruction cache testbench.

I initially had difficulty running the testbench because the ./doit.sh script relied on macOS-specific filesystem paths to locate GoogleTest, whereas I was using WSL, but I eventually resolved that issue. Additionally, the line_from_mem input was 128 bits wide (4 words), while the testbench only allowed modifying 32 bits at a time, so I had to manually update the signal in 32 bit segments.

Here is an example of a test case that I wrote for the data cache:
```c++
top->addr = 0x00F00000;
top->fetch = 1;

runSimulation(1);
//testing stall on non valid fetch (read)
EXPECT_EQ(top->stall, 1)
    << "Cache should assert stall on first access to a cold line (miss 1).";

//checking that the cache doesnt write back the invalid value
EXPECT_EQ(top->write_back_en, 0)
    << "Cache should not assert a write back for an invalid value.";
```

The testing proved very useful as many bugs were revealed, which I then fixed accordingly. After verifying that the caches returned the correct results on all the edge cases that I could think of, I progressed onto the L2 cache.

---

### Designing the L2 cache 

Along with the L1 caches, I was tasked with designing the full L2 cache (both controller and array). I decided to follow the same design philosophy as before, implementing both the controller and array on the same file.

Initially, our goal was to create an L2 cache that would have 3 read and 2 write ports. This would allow both the L1d and L1i cache to read from the L2 cache simultaneously, and for main memory to also read dirty data from the L2 cache while processing the L1 read request(s). The 2 write ports would enable the L2 cache to handle writebacks from the L1d cache and store data from main memory at the same time.

However, when it came to implementing this, I found that the logic was needlessly complicated as there would be many edge cases where the 5 different ports would be accessing the same data. We would also need multiple different way determination and read/write paths, which would increase the size of our module even further. Thus, I started to researched how real L2 caches handle data.

After looking into it, I found that most L2 caches use only 1 write port and 2 read ports (one for loading to L1 and one for writing back to main memory). This meant that if both the i cache and d cache issued a fetch request to the L2 cache, they would not be able to be processed concurrently. Thus, we used an arbiter to decide which request to handle first. This led me to redraw the schematic for the L2 cache to include an arbiter, and only 2 read ports and 1 write port.

| fetch_i | fetch_d | {req_i, req_d} (without arbiter) | {req_i, req_d} (with arbiter) |
| --- | --- | --- | --- |
| 0 | 0 | 00 | 00 |
| 0 | 1 | 01 | 01 |
| 1 | 0 | 10 | 10 |
| 1 | 1 | 11 | 01 |

```SystemVerilog
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
```

Furthermore, after running into complications with the writeback logic, I turned again to real world cache designs to better understand how it should be implemented. This led me to redraw the L2 schematic again to incorporate writeback buffers. These buffers allowed data to be captured immediately and processed later, preventing data loss during long writeback operations. They also resolved the limitation of having only a single writeback port with a fixed bus width while needing to handle both L1 writeback data (4 words) and L2 writeback data (8 words). I used a state machine to sequence the 8 word L2 writeback through the 4 word port.

| L2wb_buffer | L2wb_buffer_next (if writeback succesfful) |
| --- | --- |
| 00 | 00 |
| 01 | 00 |
| 10 | 01 |

```SystemVerilog
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
```

Additionally, I needed to separate the hit detection and way determination paths for the writeback requests (from L1d), and the read requests (from both L1d and L1i) as they would use different addresses.

read hit detection path:
```SystemVerilog
assign tag_bits_rd = addr[ADDRESS_WIDTH-1:13];
assign set_rd = addr[12:5];
assign block_offset_rd = addr[4:2];

...

// hit detection
hit0 = ((cache[set_rd].block0.tag == tag_bits_rd) && cache[set_rd].block0.valid);
hit1 = ((cache[set_rd].block1.tag == tag_bits_rd) && cache[set_rd].block1.valid);
hit2 = ((cache[set_rd].block2.tag == tag_bits_rd) && cache[set_rd].block2.valid);
hit3 = ((cache[set_rd].block3.tag == tag_bits_rd) && cache[set_rd].block3.valid);
miss = ~(hit0 | hit1 | hit2 | hit3);

...


```
writeback hit detection path:
```SystemVerilog
assign tag_bits_wb = l1write_back_addr_buffer[ADDRESS_WIDTH-1:13];
assign set_wb = l1write_back_addr_buffer[12:5];
assign block_offset_wb = l1write_back_addr_buffer[4:2];

...

hit0_wb = (cache[set_wb].block0.tag == tag_bits_wb && cache[set_wb].block0.valid);
hit1_wb = (cache[set_wb].block1.tag == tag_bits_wb && cache[set_wb].block1.valid);
hit2_wb = (cache[set_wb].block2.tag == tag_bits_wb && cache[set_wb].block2.valid);
hit3_wb = (cache[set_wb].block3.tag == tag_bits_wb && cache[set_wb].block3.valid);
miss_wb = ~(hit0_wb | hit1_wb | hit2_wb | hit3_wb);
```

Similar to the L1 caches, I decided to use a default fill in pattern of 0-3 on cold misses, and LRU eviction logic for capacity misses.

I initially approached this problem with a matrix

| i \ j |   0   |   1   |   2   |   3   |
|-------|-------|-------|-------|-------|
| **0** |   -   | u01   | u02   | u03   |
| **1** | u10   |   -   | u12   | u13   |
| **2** | u20   | u21   |   -   | u23   |
| **3** | u30   | u31   | u32   |   -   |

where u01 meant that 0 was used more recently than 1.

The cache would be able to determine which block was least recently used and select the right victim by following the pseudocode below:
```
victim = 0;
for each way k in {0,1,2,3}:
    if M[k][0] == 0 and M[k][1] == 0 and M[k][2] == 0 and M[k][3] == 0 (ignoring M[k][k]):
        victim = k;
        break;
```

However, because the upper triangle mirrors the lower triangle, I decided to only implement the upper triangle into the cache.

```SystemVerilog
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
```

As shown, each set only contains the upper half of the matrix mentioned above.

Furthermore, given that our cache was only 4-way associative, I decided to brute force the solution to the eviction logic rather than rewriting the pseudocode loop to work with only the upper triangle.

Eviction logic:
```SystemVerilog
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
```

Early psuedocode schematic of the L2 cache :
![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/l2ps_schem1.png)

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/l2ps_schem2.png)

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/l2ps_schem3.png)

This statement mainly talks about the timeline of events that led to the final design choices made. There is much more to be said about how the actual L2 cache works, but the [cache README](https://github.com/TahaMunir2/Team5/blob/Hierarchical-cache/README.md) already goes into deeper detail about this.

---

### L2 cache testbenching

When I began writing the testbench, my prior experience with the L1 caches made it easier to get started. However, the L2 cache proved to be more complex than the L1 designs, which led to longer hours debugging.

Previously, I had placed all test cases within a single instance, but for the L2 cache I created five separate test instances. This helped manage the increased complexity of the L2 logic and made each test case easier to follow. It also allowed me to properly test cold misses for both instruction and data cache fetches.

I also added helper functions to simplify things like loading words into the inputs. As noted earlier, the testbench could not directly assign values wider than 32 bits, and since all incoming data spanned at least four words, these functions saved me from manually writing the inputs 32 bits at a time.

Helper function to load the same word 8 times into line_from_mem:
```SystemVerilog
void setLineFromMemUniform(uint32_t word) {
    for (int i = 0; i < 8; ++i) {
        top->line_from_mem[i] = word;
    }
}
```

Debugging the L2 cache was considerably more difficult than the L1 designs, as it was nearly three times larger than L1D and much more complex. However, after testing all the edge cases I could identify, I was able to verify that the cache functions correctly.

Test instance for i cache fetch request:
```c++
// Basic I-cache fetch
// First fetch_i results in a miss
// L2 cache writes in line_from_mem when ready = 1
// L2 cache should assert ready_i after writing and hitting on the subsequent cycle
// Data_out should match data written in from line_from_mem

TEST_F(L2CacheTestbench, InstructionFetchMissAndHit) {
    initializeInputs();

    uint32_t addrI = 0x00000000;

    top->fetch_i = 1;
    top->fetch_d = 0;
    top->addr_i  = addrI;
    top->ready   = 0;

    runSimulation(1);

    EXPECT_EQ(top->ready_i, 0)
        << "L2 should not assert ready_i on first access to a cold line (miss).";
    EXPECT_EQ(top->write_back_en, 0)
        << "No write-back expected on a simple read miss.";
    EXPECT_EQ(top->main_mem_fetch, 1)
        << "L2 should assert fetch request on main mem on a miss";
    EXPECT_EQ(top->main_mem_addr, addrI)
        << "L2 should assert fetch request using addrI";

    // Memory returns a line: fill all words with a known pattern
    setLineFromMemUniform(0xCAFEBABE);
    top->ready = 1;

    runSimulation(1);

    EXPECT_EQ(top->ready_i, 0)
        << "L2 should not assert ready_i on the same cycle when memory has provided the line.";

    // Deassert ready, then hit again on same address
    top->ready = 0;
    runSimulation(1);

    EXPECT_EQ(top->ready_i, 1)
        << "L2 should hit on the same I address after fill.";

    EXPECT_EQ(top->data_out[0], 0xCAFEBABE)
        << "I-fetch should return the pattern written into line_from_mem.";
}
```
## Mistakes

Despite achieving substantial progress within such a short period, there were still many things that we could've improved on. For example, we were not very good at distributing tasks at first.

Originally, my first task after completing Lab 4 was to combine all of the modules in the pipelining and full RISC-V branches into one complete top.sv module. However, since I lacked understanding of the submodules compared to my teammates who actually worked on the modules, we decided that it was too inefficient to let me integrate the modules, as others could probably do it twice as fast. This led to my part being taken over, and so I moved onto developing the memory hierarchy. However, had we assigned the tasks more efficiently, perhaps I could've started developing the cache(s) earlier, leaving more time to complete further extensions.

Furthermore, I did not sufficiently research the L2 cache before starting to develop it. I had assumed that it would be similar to the L1i and L1d caches, and while it was, it was also a lot more complicated. This meant that I had to rewrite the whole script and the schematic numerous times, before finally arriving at the final design. If I had properly researched real-life examples of L2 caches from the start, I could've saved a lot of time in developing the L2 cache, leaving more time to do other tasks.

---

## Reflection

Overall, we accomplished much more than I expected. I consider myself very lucky to have been a member of this team, and I take pride not only in my individual efforts but also in the collective achievements of the group.

It was really fun and interesting to see what's going on inside modern day computers, and it really makes me grateful for the technology that we have, which is vastly more complex than I thought it would ever be. It's also great to get some hands-on experience in designing hardware, which I'm sure will be useful in the near future.

If we had more time, I would have liked to integrate the cache onto the FPGA, both to gain experience mapping HDL designs to hardware and because the cache subsection is the part I know best. Still, I recognise that this would go well beyond the project’s expectations, and so I am satisfied with what we were able to accomplish in such a short time frame.
