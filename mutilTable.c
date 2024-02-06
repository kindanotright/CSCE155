/**
 * Author: Megan Bogatz; kindanotright
 * Date: 2023-09-12
 *
 * This program generates a multiplication table
 * of the size given as a command line argument.
 */
#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char **argv) {
 
  if(argc != 2) {
    printf("Error: provide an integer\n");
    exit(1);
  }
 
  int n = atoi(argv[1]);
  if(n <= 0) {
    printf("empty table!\n");
    exit(0);
  }
 
  printf("---\t");
  for(int i = 1; i <= n; i++){
    printf("%d\t", i);
  }
  printf("\n");
 
  for(int i = 1; i <= n; i++) {
    printf("%d\t", i);
    for(int j = 1; j <= n; j++) {
      int product = i * j;
      printf("%d\t", product);
    }
    printf("\n");
  }
 
  return 0;
}
