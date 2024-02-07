/** 
 * Author: Megan Bogatz 
 * 2023-11-09 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "airport.h"
 
int main(int argc, char **argv) {
    double counterPassed = 0;
    double counterFailed = 0;
    double result = 0;
 
    printf("Testing Convert to Radian:\n");
    double t = 12321;
    double expected = 215.0420171;
    result = convertRadian(t);
    if ((testAccuracyCheck(expected, result)) == PASS) {
        counterPassed++;
    } else {
        counterFailed++;
    }
    t = -1231;
    expected = -21.48500309;
    result = convertRadian(t);
    if ((testAccuracyCheck(expected, result)) == PASS) {
        counterPassed++;
    } else {
        counterFailed++;
    }
    t = 328.341;
    expected = 5.730631519;
    result = convertRadian(t);
    if ((testAccuracyCheck(expected, result)) == PASS) {
        counterPassed++;
    } else {
        counterFailed++;
    }
    printf("Number Test Passed: %.1f\n", counterPassed);
    printf("Number Test Failed: %.1f\n", counterFailed);
    printf("\n");
 
 
printf("Testing createAirport and airportToString\n");
Airport* OMA = createAirport("OMA",
                             "Domestic",
                             "Epply Airfield",
                             41.3015,
                             -95.8945,
                             984,
                             "Omaha",
                             "United States");
char* strOMA = airportToString(OMA);
free(strOMA);
strOMA = airportToString(OMA);
printf("%s\n", strOMA);
 
Airport* LNK = createAirport("LNK",
                             "Domestic",
                             "Lincoln Airport",
                             40.8485,
                             -96.7603,
                             1219,
                             "Lincoln",
                             "United States");
char* strLNK = airportToString(LNK);
free(strLNK);
strLNK = airportToString(LNK);
printf("%s\n", strLNK);
 
Airport* CDG = createAirport("CDG",
                             "International",
                             "Paris Charles de Gaulle Airport",
                             49.0079,
                             2.5508,
                             390,
                             "Paris",
                             "French");
char* strCDG = airportToString(CDG);
free(strCDG);
strCDG = airportToString(CDG);
printf("%s\n", strCDG);
 
Airport* IAD = createAirport("IAD",
                             "International",
                             "Dulles International Airport",
                             38.9523,
                             -77.4586,
                             313,
                             "Dulles",
                             "United States");
char* strIAD = airportToString(IAD);
free(strIAD);
strIAD = airportToString(IAD);
printf("%s\n", strIAD);
 
Airport* PHX = createAirport("PHX",
                             "International",
                             "Phoenix Sky Harbor International Airport",
                             33.4352,
                             -112.0101,
                             1135,
                             "Pheonix",
                             "United States");
char* strPHX = airportToString(PHX);
free(strPHX);
strPHX = airportToString(PHX);
printf("%s\n", strPHX);
 
Airport* SVO = createAirport("SVO",
                             "International",
                             "Sheremetyevo - A.S. Pushkin international airport",
                             55.9736,
                             37.4125,
                             630,
                             "Moscow",
                             "Russia");
char* strSVO = airportToString(SVO);
free(strSVO);
strSVO = airportToString(SVO);
printf("%s\n", strSVO);
 
Airport* MDW = createAirport("MDW",
                             "International",
                             "Chicago Midway International Airport",
                             41.7868,
                             -87.7522,
                             620,
                             "Chicago",
                             "United States");
char* strMDW = airportToString(MDW);
free(strMDW);
strMDW = airportToString(MDW);
printf("%s\n", strMDW);
 
 
printf("\n");
printf("Testing getAirDistance\n");
counterPassed = 0;
counterFailed = 0;
result = 0;
 
expected = 1585.943141;
result = getAirDistance(OMA, IAD);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 1667.221898;
result = getAirDistance(OMA, PHX);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 1656.536391;
result = getAirDistance(LNK, IAD);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 6197.452595;
result = getAirDistance(IAD, CDG);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 6668.880848;
result = getAirDistance(CDG, MDW);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 7810.805425;
result = getAirDistance(IAD, SVO);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 1579.793832;
result = getAirDistance(LNK, PHX);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 679.517120;
result = getAirDistance(OMA, MDW);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
expected = 759.141592;
result = getAirDistance(MDW, LNK);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
 
printf("Number Test Passed: %.1f\nNumber Test Failed: %.1f\n", counterPassed, counterFailed);
printf("\n");
 
printf("Testing Travel Time\n");
 
int numStop = 5;
int speed = 926;
int layoverTime = 3;
Airport stops[10];
stops[0] = *OMA;
stops[1] = *IAD;
stops[2] = *CDG;
stops[3] = *MDW;
stops[4] = *OMA;
counterPassed = 0;
counterFailed = 0;
expected = 25.341031;
result=getEstimatedTravelTime(stops, numStop, speed, layoverTime);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
 
layoverTime = 7;
speed = 852;
numStop = 4;
stops[0] = *PHX;
stops[1] = *SVO;
stops[1] = *PHX;
stops[3] = *OMA;
expected = 32.785814;
result=getEstimatedTravelTime(stops, numStop, speed, layoverTime);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
 
layoverTime = 2;
speed = 1111;
numStop = 6;
stops[0] = *OMA;
stops[1] = *PHX;
stops[2] = *MDW;
stops[3] = *CDG;
stops[4] = *IAD;
stops[5] = *LNK;
expected = 24.660288;
result=getEstimatedTravelTime(stops, numStop, speed, layoverTime);
if (testAccuracyCheck(expected, result) == PASS) {
    counterPassed++;
} else {
    counterFailed++;
}
 
 
printf("Number Test Passed: %.1f\nNumber Test Failed: %.1f\n", counterPassed, counterFailed);
 
return 0;
}
