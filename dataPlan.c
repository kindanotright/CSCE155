* This program calculates if the user is over or under their data limit
 * also determines user's average data usage
 * Megan Bogatz:kindanotright*/ 
 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
 
int main(int argc, char ** argv){
 
    if(argc != 4) {
        printf("ERROR\n");
        exit (1);
    }
    double planAmount = atof (argv[1]);
    int monthDay = atoi (argv[2]);
    double userAmount = atof (argv[3]);
 
    if (planAmount < 0 || monthDay <= 0 || userAmount < 0) {
        printf ("ERROR\n");
        exit (1);
    }
    if (monthDay > 30) {
        printf ("ERROR\n");
        exit(1);
    }
 
    double planAverage, userAverage, userData, daysLeft;
    planAverage = planAmount / 30;
    userAverage = userAmount / monthDay;
    userData = planAmount - userAmount;
    daysLeft = 30 - monthDay;
 
    printf("%.d days used, %.lf days remaining\n", monthDay, daysLeft);
    printf("Average daily use: %.3lf GB/day\n\n", userAverage);
 
    if (userAmount > planAmount) {
        printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");
    }
    else if (userAverage <= planAverage) {
        printf("You are at or below your average daily use (%lf GB/day).\n", planAverage);
        double userDeceed = userData / daysLeft;
        printf("You can use up to %.3lf GB/day and stay below your data plan limit.\n", userDeceed);
    }
    else if(userAverage > planAverage) {
        printf("You are EXCEEDING your average daily use (%.3lf GB/day).\n", planAverage);
        double userExceed = userAverage * daysLeft - userData;
        printf("Continuing this high usage, you'll exceed your data plan by %.2lf GB.\n\n", userExceed);
        double userContinue =  userData / daysLeft;
        printf("To stay below your data plan, use no more than %.3lf GB/day.\n", userContinue);
    }
 
}
