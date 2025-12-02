Testbench info:

We set x1 to 12345678 and csr[340] to 12345678 with t1 by running csr read and write

We use csr read and set with t2 which is 0000FFFF to set the bottom 2 bytes to 1 so csr[340] = 1234FFFF

We use csr read and clear with t3 which is 000000FF to clear the bottom byte to 0 to get csr[340] = 1234FF00

We use csr read and ser with x0 (0) to just copy csr[340] into a0 so a0 = 1234FF00

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/csr_tb.png)

Each time we are saving csr[340] into x1 so we can trace it to check its actually changing correctly as shown below:

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/gtkwave.png)
