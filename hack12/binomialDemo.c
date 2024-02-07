/**
 * Author: Megan Bogatz
 * 2023-11-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "binomial.h"

int main(int argc, char **argv){
    if (argc != 3) {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        exit(1);
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);


    long **cache = (long **) malloc((n+1) * sizeof(long*));
    for(int i=0; i<(n+1); i++) {
        cache[i] = (long *) malloc((k+1) * sizeof(long));
        for(int j=0; j<(k+1); j++) {
            cache[i][j] = -1;
        }
    }

    time_t start, end;

    start = time(NULL);
    long chooseResult = 0;
    end = time(NULL);

    int totalTime = (end - start);

    printf("choose(%d,%d) = %ld\n", n, k, chooseResult);
    printf("Time: %d\n", totalTime);

    start = time(NULL);
    chooseResult = chooseCache(n, k, cache);
    end = time(NULL);

    totalTime = (end - start);

    printf("Memoization: choose(%d,%d) = %ld\n", n, k, chooseResult);
    printf("Time: %d\n", totalTime);

    /**
     * time estimations
     * assuming:
     * choose(36, 18) = 9075135300 = 59s
     *
     * choose(54, 27) = 12657599.2882 s
     * choose(56, 28) = 49726282.9178 s
     * choose(58, 29) = 195475732.849 s
     * choose(60, 30) = 768871215.873 s
     * choose(62, 31) = 3025880268.92 s
     * choose(64, 32) = 11914403558.9 s
     * choose(66, 33) = 46935529171.3 s
     */


    return 0;
}
