#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -O3 -g tlb.c -o tlb
./tlb 1 100000000
./tlb 2 100000000
./tlb 4 100000000
./tlb 8 100000000
./tlb 16 100000000
./tlb 32 10000000
./tlb 64 10000000
./tlb 128 1000000
./tlb 256 1000000
./tlb 512 1000000
./tlb 1024 100000
./tlb 2048 10000
./tlb 4096 10000