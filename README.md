# Maxx Curtis - TLB measurment program
# Operating Systems - CSCI 393 Fall Semester - Reed College

The bash script I used to measure my results in included in this zip
file as "tlb.sh".
The number of trials decreases as NUMPAGES increases, because very 
low values (1, 8, etc...) require a ton of iterations to produce 
stable results, while high values, (near 2048) become detrimentally
slow at trial counts over 10,000.

## RESULTS:
| Pages: | Access Time (us): |
|--------|-------------------|
| 1 | 0.000711 |
| 2 | 0.000531 |
| 4 | 0.000635 |
| 8 | 0.000398 |
| 16 | 0.000382 |
| 32 | 0.000650 |
| 64 | 0.001022 |
| 128 | 0.001460 |
| 256 | 0.001439 |
| 512 | 0.001440 |
| 1024 | 0.001442 |
| 2048 | 0.006352 |
| 4096 | 0.006267 |
![](tbl.png)
The above results are directly pulled from the terminal and have 
not been rounded. Additional tests (5 as of the last changes to 
the trial counts) were run to ensure the results are accurate to 
a resonable degree of variation.
(Two stable significant digits)

Notably, the lower-value tests are individually stable, but do not
increase in cost as NUMPAGES increases, nor are they roughly equal.
The average access time actually decreases as NUMPAGES increases,
until NUMPAGES = 32, when the access time takes a noticable leap.

When NUMPAGES = 32 or 64, the average access time is notably distinct
from the times above and below, which may suggest that the TLB
is having some effect, but without knowing my TLBs eviction policy,
it's difficult to speculate on why that might be.

Above 32, there are two distinct blocks of roughly equivalent
access times:
    128-1024:  ~0.0014
    2048-4096: ~0.0063

It seems that there is a small primary TLB that can hold 16 pages,
and a secondary TLB that holds up to 1024 pages.
