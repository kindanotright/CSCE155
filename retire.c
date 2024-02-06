//TODO: clean up code!
/* This program will calulate a users 401k and write a table showing the progression. 
 * Author: Megan Bogatz; kindanotright 
 * 2023-09-14 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(int argc, char **argv) {
 
    if(argc != 6) {
        printf("ERROR: provide all the information\n");
        exit(1);
    }
    double startingBalance = atof(argv[1]);
    if (startingBalance < 0) { 
        printf("ERROR: one or more of your inputs is invalid\n"); 
        exit(0); 
    } 
    double monthlyContribution = atof(argv[2]); 
    if (monthlyContribution < 0) { 
        printf("ERROR: one or more of your inputs is invalid"); 
        exit(0); 
    } 
    if ((monthlyContribution * 12) > 18500){ 
        printf("ERROR: monthly contribution exceeds $18500 annual limit"); 
        exit(0); 
    } 
    double rateOfReturn = atof(argv[3]); 
    if (rateOfReturn < 0) { 
        printf("ERROR: one or more of your inputs is invalid"); 
        exit(0); 
    } 
    double inflationRate = atof(argv[4]); 
    if (inflationRate < 0) { 
        printf("ERROR: one or more of your inputs is invalid"); 
        exit(0); 
    } 
    double timeFrame = atof(argv[5]); 
    if (timeFrame < 0){ 
        printf("ERROR: one or more of your inputs is invalid"); 
        exit(0); 
    } 
    timeFrame *= 12; 
 
    double interestTotal = 0;
    double interest = (((1 + rateOfReturn) / (1 + inflationRate)) - 1) / 12;
    double interestBalance = 0;
    int month = 0;
 
    printf("Month\tIntrest\tBalance\n");
    while (timeFrame > 0){
        month += 1;
        interestBalance = startingBalance * interest;
        startingBalance += interestBalance;
        startingBalance += monthlyContribution;
        interestBalance = round(interestBalance *100) / 100;
        startingBalance = round(startingBalance * 100.00) / 100.00;
        timeFrame -= 1; 
        interestTotal += interestBalance;
        interestTotal = round(interestTotal * 100) / 100;
        printf("%d\t$%.2lf\t$%.2lf\n", month, interestBalance, startingBalance);
}
printf("Total Interest Earned: $%.2lf\n", interestTotal);
printf("Total Nest Egg: $%.2lf\n", startingBalance);
 
    return (0);
}
