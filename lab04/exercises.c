/**
 * Author(s): Megan Bogatz; kindanotright
 * Date: 2023-09-12
 *
 * This is a series of exercises to introduce loop
 * control structures.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
int main(int argc, char **argv) {
 
  if(argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }
 
  int n = atoi(argv[1]);
 
  // A simple for loop that prints 0 thru 9
  for(int i=0; i<10; i++) {
    printf("%d\n", i);
  }
 
  //1. Rewrite the given for loop as an equivalent while loop
  int i = 10;
  while (i < 20) {
    printf ("%d ", i);
    i += 3;
  }
  /* for(int i=10; i<20; i+=3) {
    printf("%d ", i);
  }*/
  printf("\n");
 
  //2. Rewrite the given while loop as an equivalent for loop
  for (int k = 3; k > -4; --k) {
    printf("%d ", k);
  }
  /*int k = 3;
  while(k > -4) {
    printf("%d ", k);
    k--;
  }*/
  printf("\n");
 
  //3. Print numbers 1 thru n separated by a comma except for
  //   the last one; example: 1, 2, 3, 4, 5
  for (i = 1; i < n; ++i) {
    printf("%d, ", i);
  }
  printf("%d\n", n);
  /*i = 1;
  while (i < n) {
    printf("%d, ", i);
    i += 1;
  }
  printf("%d\n", n);*/
 
  int square = 0;
  //4. Print squares of numbers 1 thru n separated by a comma
  //   except for the last one; example: 1, 4, 9, 16, 25
  for (int i = 1; i < n; i++) {
    square = i * i;
    printf("%d, ", square);
  }
  printf ("%d\n", n * n);
 
  //5. Compute the summation of numbers 1 thru n and print
  //   the result; example: 1 + 2 + 3 + 4 + 5 = 15
  int sum = 0;
  for (i = 1; i <= n; ++i) {
    sum += i;
  }
  printf("Sum of 1 thru %d = %d\n", n, sum);
 
  //6. Compute the summation of squares of numbers 1 thru n
  //   and print the result; example: 1^2 + 2^2 + 3^2 + 4^2 + 5^2 = 55
  square = 0;
  sum = 0;
  for (i = 1; i <= n; i++) {
    square = i * i;
    sum += square;
  }
  printf("Sum of 1^2 thru %d^2 = %d\n", n, sum);
 
  //7. Compute the summation of even numbers 1 thru n and print
  //   the result; example (n=5): 2 + 4 = 6
  sum = 0;
  for (i = 1; i <= n; i++){
    if((i % 2) == 0){ //mean positive
      sum += i;
    }
  }
  printf("Sum of even numbers 1 thru %d = %d\n", n, sum);
 
  //8. Write a solution to the following variation of the FizzBuzz
  //   problem.  Print out integers 1 thru n, one to a line, except
  //   that if the integer is divisible by 7 print "Foo" instead.
  //   If the integer is divisible by 11 print "Bar" instead.  If
  //   the integer is divisible by both 7 and 11, print "FooBar"
  //   instead.
  sum = 0;
  for (i=1; i <= n; i++){
    if (((i % 7) == 0) || ((i % 11) == 0)){
      if ((i % 7) == 0) {
      printf("Foo");
      } if ((i % 11) == 0){
      printf("Bar");
      }
    printf(" ");
    }
    else if (((i % 7) != 0) || ((i % 11) != 0)){
      printf("%d ", i);
    }
  }
  printf("\n");
 
  return 0;
}
