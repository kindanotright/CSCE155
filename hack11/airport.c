/**
 * Author: Megan Bogatz
 * 2023-11-09
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#include "airport.h"
 
 
char * deepCopyString(const char *str, int n) {
  if (str == NULL) {
    return NULL;
  }
  char *copyStr = (char *) malloc(sizeof(char) * n);
  if (copyStr == NULL) {
    return NULL;
  }
  for(int i=0; i<n; i++) {
    copyStr[i] = str[i];
  }
 
  return copyStr;
}
 
Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv){
  Airport *airport = (Airport *)malloc(sizeof(Airport) * 1);
 
  initAirport(airport, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);
 
  return airport;
}
 
 
void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {
  if (airport == NULL) {
    return;
  } if (latitude < -90 || latitude > 90) {
    return;
  } if (longitude < -180 || longitude > 180) {
    return;
  }
  airport->gpsId = deepCopyString(gpsId, strlen(gpsId));
 
  airport->type = deepCopyString(type, strlen(type));
 
  airport->name = deepCopyString(name, strlen(name));
 
  airport->latitude = latitude;
  airport->longitude = longitude;
  airport->elevationFeet = elevationFeet;
 
  airport->city = deepCopyString(city, strlen(city));
 
  airport->countryAbbrv = deepCopyString(countryAbbrv, strlen(countryAbbrv));
}
 
 
char* airportToString(const Airport* a) {
   if (a == NULL) {
   char *result = deepCopyString("(null)", strlen("(null)"));
   return result;
   }
 
  int n = strlen(a->gpsId) +
          strlen(a->type) +
          strlen(a->name) +
          strlen(a->city) +
          strlen(a->countryAbbrv) +
          20 + //latitude
          20 + //longitude
          10 + //elevation
          15; //whitespace
 
    char *str = (char *) malloc(sizeof(char) * n);
 
  sprintf(str, "%s, %s, %s, %s, %s, %.2f, %.2f, %d",
            a->gpsId,
            a->type,
            a->name,
            a->city,
            a->countryAbbrv,
            a->latitude,
            a->longitude,
            a->elevationFeet);
 
  return str;
}
 
 
double convertRadian(double unradian) {
  double radian = 0;
  radian = unradian/180*M_PI;
  return radian;
}
 
 
double getAirDistance(const Airport* origin, const Airport* destination) {
  double earthRadius = 6371;
  double latOrig = convertRadian(origin->latitude);
  double lonOrig = convertRadian(origin->longitude);
  double latDest = convertRadian(destination->latitude);
  double lonDest = convertRadian(destination->longitude);
  double distance = acos(sin(latOrig) *
                    sin(latDest) +
                    cos(latOrig) *
                    cos(latDest) *
                    cos(lonDest-lonOrig)) *
                    (earthRadius);
 
   return distance;
}
 
 
double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs){
   double distance;
   double distanceTotal;
   double totalTime = 0;
   for (int i = 0; i < (size-1); i++) {
      distance = getAirDistance(&stops[i], &stops[i+1]);
      distanceTotal +=distance;
   }
   totalTime += (distanceTotal / aveKmsPerHour);
   totalTime += aveLayoverTimeHrs * (size - 2);
   return totalTime;
}
 
 
 
double testAccuracyCheck(double expected, double result) { 
if (fabs(expected - result) < 0.01) { 
  printf("PASSED\nexpected:%f\nresult:%f\n", expected, result); 
  return PASS; 
} else { 
  printf("FAILED!\nexpected:%f\nresult:%f\n", expected, result); 
  return FAIL; 
    }
}
