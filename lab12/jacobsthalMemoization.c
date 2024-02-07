/**
 * Author: Megan Bogatz
 * 2023-11-14
 **/
 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
/**
 * Computes the n-th Jacobsthal number using an iterative
 * method
 */
long long jacobsthalIterative(int n);
 
/**
 * Computes the n-th Jacobsthal number using an Memoization
 * method
 */
long long jacobsthalMemoization (long long *cache, int n);
 
/**
 * This program computes the n-th Jacobsthal number using recursion.
 * It also reports how long the program takes to execute.
 */
int main(int argc, char **argv) {
 
  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);
 
long long *cache = (long long*)malloc(sizeof(long long) * n + 1);
for (int i =0; i < n + 1; i++) {
  cache[i]=-1;
}
cache[0]=0;
cache[1]=1;
 
  time_t start, end;
  long long iterativeResult = jacobsthalIterative(n);
 
  start = time(NULL);
 
  long long memoizationResult = jacobsthalMemoization(cache, n);//TODO: call your function here
 
  end = time(NULL);
 
  int time = (end - start);
 
  printf("Iterative:   Jacobsthal(%d) = %lld\n", n, iterativeResult);
  printf("Memoization: Jacobsthal(%d) = %lld\n", n, memoizationResult);
 
  printf("Total Computation Time: %d seconds\n", time);
 
  return 0;
}
 
long long jacobsthalMemoization (long long *cache, int n) {
if (cache[n] != -1) {
  return cache[n];
}
cache[n] = jacobsthalMemoization(cache, n - 1) + 2 * jacobsthalMemoization(cache, n - 2);
return cache[n];
}
 
 
 
long long jacobsthalIterative(int n) {
  if(n <= 1) {
    return n;
  }
  long long prev = 0;
  long long curr = 1;
  for(int i=2; i<=n; i++) {
    long long t = 2 * prev + curr;
    prev = curr;
    curr = t;
  }
  return curr;
}
