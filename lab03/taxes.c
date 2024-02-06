/**
 * This program computes income taxes based on adjusted
 * gross income and a child tax credit.
 *
 */
#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char **argv) {
 
  double agi = 0.0;
  char c = 'N';
  double tax = 0.0;
  double childCredit = 0.0;
  double totalTax = 0.0;
  int numChildren = 0;
 
  printf("Please enter your adjusted gross income (AGI): ");
  scanf("%lf", &agi);
  //remove the "enter" endline character
  getchar();
 
  if(agi < 0) {
    printf("Number cannot be less then 0\n");
  return 0;}
 
  if (agi <= 19900) {
    tax = (agi - 0) * 0.1;
  } else if (agi <= 81050) {
    tax = (agi - 19900) * 0.12 + 1990;
  } else if (agi <= 172751) {
    tax = (agi - 81050) * 0.22 + 9328;
  } else if (agi <= 329850) {
    tax = (agi - 172750) * 0.24 + 29502;
  } else if (agi <= 418850) {
    tax = (agi - 329850) * 0.32 + 67206;
  } else if (agi <= 628300) {
    tax = (agi - 418850) * 0.35 + 95686;
  } else if (agi >= 628301) {
    tax = (agi - 628300) * 0.37 + 168933.50;
  }
 
  printf("Do you have any children? (Y) or (N)? ");
  c = getchar();
 
  if(c == 'y' || c == 'Y') {
    printf("How many children do you have? ");
    scanf("%d", &numChildren);
    childCredit = numChildren * 2000;
  }
 
  totalTax = tax - childCredit;
  if (totalTax < 0){
    totalTax = 0;
  }
 
  printf("AGI:          $%10.2f\n", agi);
  printf("Tax:          $%10.2f\n", tax);
  printf("Child Credit: $%10.2f\n", childCredit);
  printf("Total Tax:    $%10.2f\n", totalTax);
 
  return 0;
}
