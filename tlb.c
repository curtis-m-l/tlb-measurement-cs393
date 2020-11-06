#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main (int argc, char* argv[]) {

    /////////////////////////////////////////////////
    // Takes NUMPAGES and NUMTRIALS as arguments.  //
    // Reads from NUMAPAGES in an array in a loop. //
    // measuring average access time.              //
    /////////////////////////////////////////////////

    if (argc != 3) {
        printf("Expected arguments: int NUMPAGES int NUMTRIALS\n");
        return 1;
    }

    const long PAGESIZE   = sysconf(_SC_PAGE_SIZE);   // Size of a page, determined at runtime
    const int  NUMPAGES   = atoi(argv[1]);            // Number of pages to read from in a row
    const int  NUMTRIALS  = atoi(argv[2]);            // Number of iterations
    const int  jump       = PAGESIZE / sizeof(int);   // Size of a page, measured in int-s
    const int  buffersize = NUMPAGES * jump;          // Number of integers needed to adequately fill the buffer
    unsigned long  outsum = 0;                        // Output sum (only used to make the read mandatory for the optimizer)
    int* a = (int*) malloc(buffersize * sizeof(int)); // Array to read from

    // Randomly Initialize buffer //
    srand(time(0));
	for (int i = 0; i < buffersize; i++) {
        a[i] = (int)(rand() % 50);
	}
    
    struct timeval t0, t1;
    gettimeofday(&t0, NULL); // Begin Timer
    for (int i = 0; i < NUMTRIALS; i++) {
        for (int j = 0; j < buffersize; j += jump) {
            outsum += a[j]; // Sum values to fool compiler
        }
    }
    gettimeofday(&t1, NULL); // End Timer

    free(a);
    float totaltime = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    totaltime /= (float)NUMTRIALS * (float)NUMPAGES;

    printf("This run summed to: %lu\n", outsum);
    printf("That took %fms\n", totaltime);
    return 0;
}