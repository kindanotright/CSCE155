//*this s is a program to convert USD to GBP and JPY
//*
//* Name and Login: Megan Bogatz; kindanotright
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
int main () {
    double USD;
 
    printf("Please input the total amount of US Dollars :");
    scanf ("%lf", &USD);
 
    double feePercent=USD*.1;
    double afterFee=(USD-feePercent)/2;
    double GBP=afterFee*0.79;
    double JPY=afterFee*127.65;
    //*1 USD = .79 GBP
    //*1 USD = 127.65 JPY
 
    printf("Fee (10%%): $%.2lf\n", feePercent);
    printf("You get:\n");
    printf("%.2lf GBP\n", GBP);
    printf("%.lf JPY\n", JPY);
}
