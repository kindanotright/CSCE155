/**
 * Author:Megan Bogatz
 * 2023-12-04
 */
 
#include <stdio.h>
#include <stdlib.h>
 
#include "airport.h"
 
int main () {
    int airportCounter = 0;
 
    Airport airports[100];
 
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
    airports[airportCounter++] = *OMA;
 
    Airport* LNK = createAirport("LNK",
                             "Large",
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
    airports[airportCounter++] = *LNK;
 
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
    airports[airportCounter++] = *CDG;
 
    Airport* IAD = createAirport("IAD",
                             "large_airport",
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
    airports[airportCounter++] = *IAD;
 
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
    airports[airportCounter++] = *PHX;
 
 
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
    airports[airportCounter++] = *SVO;
 
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
    airports[airportCounter++] = *MDW;
 
    Airport* NYC = createAirport("NYC",
                             "large_airport",
                             "NYC Sky Harbor International Airport",
                             33.4352,
                             -112.0101,
                             1135,
                             "New York",
                             "United States");
    char* strNYC = airportToString(NYC);
    free(strNYC);
    strNYC = airportToString(NYC);
    printf("%s\n", strNYC);
    airports[airportCounter++] = *NYC;
 
 
    generateReports(airports, airportCounter); 
 
 
}
