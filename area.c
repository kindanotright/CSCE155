/**
 * Author: Chris Bourke
 *
 * This program prompts the user to enter the
 * base and the height of a triangle and computes
 * its area using the well-known formula
 *  1/2 * base * height
 *
 */
#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char **argv) {
 
  double area;
  double base = atof(argv[1]);
  double height = atof(argv[2]);
 
  area = (double) 1/2 * base * height;
 
  printf("The area is %f square units.\n", area);
 
  return 0;
}
 
