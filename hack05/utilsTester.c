/**
 * This is a program to perform unit test on utils.c
 *
 * Author: Megan Bogatz; kindanotright
*/
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
 
#include "utils.h"
 
int main(int argc, char **argv) {
 
  double a, b, c, d, e, f;
  double expectedD, actualD;
  int numPassed = 0;
  int numFailed = 0;
 
  a = 41.948300, b = -87.655600, c = 40.820600, d = -96.705600;
  expectedD = 764.990931;
  printf("TESTING: getAirDistance\n\tstarting: [%.6lf, %.6lf]\n\tending: [%.6lf, %.6lf]\n", a, b, c, d);
  actualD = getAirDistance(a, b, c, d);
  if(fabs(expectedD - actualD) < 0.0001) {
    printf("PASSED\\t%.6lf\n", actualD);
    numPassed++;
  } else {
    printf("FAILED: returned %.6lf, expected %.6lf\n", actualD, expectedD);
    numFailed++;
  }
 
    a = 34.256300, b = 89.343200, c = -45.325200, d = -130.343500;
    expectedD = 16449.993384;
    printf("TESTING: getAirDistance\n\tstarting: [%.6lf, %.6lf]\n\tending: [%.6lf, %.6lf]\n", a, b, c, d);
    actualD = getAirDistance(a, b, c, d);
    if(fabs(expectedD - actualD) < 0.0001) {
        printf("PASSED\t%.6lf\n", actualD);
        numPassed++;
    } else {
        printf("FAILED: returned %.6lf, expected %.6lf\n", actualD, expectedD);
        numFailed++;
    }
 
 
    a = -68.432900, b = 83.829400, c = 58.432900, d = -23.593800;
    expectedD = 16480.322575;
    printf("TESTING: getAirDistance\n\tstarting: [%.6lf, %.6lf]\n\tending: [%.6lf, %.6lf]\n", a, b, c, d);
    actualD = getAirDistance(a, b, c, d);
    if(fabs(expectedD - actualD) < 0.0001) {
        printf("PASSED\t%.6lf\n", actualD);
        numPassed++;
    } else {
        printf("FAILED: returned %.6lf, expected %.6lf\n", actualD, expectedD);
        numFailed++;
    }
 
    a = 53.294830, b = -24.329500, c = 52.392800, d = -26.348300;
    expectedD = 168.640818;
    printf("TESTING: getAirDistanc\n\tstarting: [%.6lf, %.6lf]\n\tending: [%.6lf, %.6lf]\n", a, b, c, d);
    actualD = getAirDistance(a, b, c, d);
    if(fabs(expectedD - actualD) < 0.0001) {
        printf("PASSED\t%.6lf\n", actualD);
        numPassed++;
    } else {
        printf("FAILED: returned %.6lf, expected %.6lf\n", actualD, expectedD);
        numFailed++;
    }
 
    e = 2124, f = .66;
    expectedD = 2827.229149;
    printf("TESTING: lorentzTimeDilation\n\tTime: %.6lf\tPercentC:%.6lf\n", e, f);
    actualD = lorentzTimeDilation(e, f);
    if(fabs(expectedD - actualD) < 0.0001)  {
        printf("PASSED\n");
        numPassed++;
    } else {
        printf("FAILED: returned %.6lf, expected %.6lf\n", actualD, expectedD);
        numFailed++;
    }
 
    e = 213, f = .11;
    expectedD = 214.3004637;
    printf("TESTING: lorentzTimeDilation\n\tTime: %.6lf\tPercentC:%.6lf\n", e, f);
    actualD = lorentzTimeDilation(e, f);
    if(fabs(expectedD - actualD) < 0.0001)  {
        printf("PASSED\n");
        numPassed++;
    } else {
        printf("FAILED: returned %.6lf, expected %.6lf\n", actualD, expectedD);
        numFailed++;
    }
 
    e = 82, f = .07;
    expectedD = 82.20164134;
    printf("TESTING: lorentzTimeDilation\n\tTime: %.6lf\tPercentC:%.6lf\n", e, f);
    actualD = lorentzTimeDilation(e, f);
    if(fabs(expectedD - actualD) < 0.0001)  {
        printf("PASSED\n");
        numPassed++;
    } else {
        printf("FAILED: returned %.6lf, expected %.6lf\n", actualD, expectedD);
        numFailed++;
    }
 
  printf("Number Test Cases Passed: %6d\n", numPassed);
  printf("Number Test Cases Failed: %6d\n", numFailed);
  printf("Percent Passed:%6.2f\n", 100.0 * numPassed / (numPassed + numFailed));
 
  return(0);
  
} 
