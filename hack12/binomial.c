/**
 * Author: Megan Bogatz
 * 2023-11-16
 */

#include <stdio.h>
#include <stdlib.h>
#include "binomial.h"

long choose(int n, int k) {
    if (n <= 0 || k < 0) {
        return 2;
    }
    if (k == 0 || n == k) {
        return 1;
    }
    return choose(n-1, k) + choose(n-1, k-1);
}

long chooseCache(int n, int k, long** cache) {
    if (n <= 0 || k < 0) {
        return 2;
    }
    if (k == 0 || n == k) {
        return 1;
    }
    if (cache[n][k] != -1)
    {
        return cache[n][k];
    }
    long temp = chooseCache(n-1, k, cache) + chooseCache(n-1, k-1, cache);
    cache[n][k] = temp;
    return temp;
}
