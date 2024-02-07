/** 
 * Author:Megan Bogatz
 * 2023-12-04 
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
 
#include "airport.h"
 
void generateReports(Airport *airports, int n) {
 
  printf("Airports (original): \n");
  printf("==============================\n");
  printAirports(airports, n);
 
  printf("\nAirports By GPS ID: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByGPSId);
  printAirports(airports, n);
 
 
  printf("\nAirports By Type: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  printAirports(airports, n);
 
  printf("\nAirports By Name: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByName);
  printAirports(airports, n);
 
  printf("\nAirports By Name - Reversed: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByNameDesc);
  printAirports(airports, n);
 
  printf("\nAirports By Country/City: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  printAirports(airports, n);
 
  printf("\nAirports By Latitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLatitude);
  printAirports(airports, n);
 
  printf("\nAirports By Longitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printAirports(airports, n);
 
  printf("\nAirports By Distance from Lincoln: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  printAirports(airports, n);
 
  printf("\nClosest Airport to Lincoln: \n");
  printf("==============================\n");
  printAirports(&airports[0], 1);
 
  printf("\nFurthest Airport from Lincoln: \n");
  printf("==============================\n");
  printAirports(&airports[n-1], 1);
 
  printf("\nEast-West Geographic Center: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  if(n%2 == 0){
    printAirports(&airports[(n)/2], 1);
 
  }else {
    printAirports(&airports[(n-1)/2], 1);
    }
 
  printf("\nNew York, NY airport: \n");
  printf("==============================\n");
  //if none found, print: "No New York airport found!\n"
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
 
  bool success = false;
  for(int i=0; i < n; i++){ 
    if(strcmp(airports[i].city,"New York") == 0){ 
      if(strcmp(airports[i].countryAbbrv, "United States") == 0){ 
      printAirports(&airports[i], 1); 
      success = true; 
      } 
    } 
  }
  if (success == false)
  {
    printf("No New York airport found!\n");
  }
 
  printf("\nLarge airport: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  success = false;
  for(int i=0; i < n; i++){
    if(strcmp(airports[i].type,"large_airport") == 0){
      printAirports(&airports[i], 1);
      success = true;
    }
  }
  if (success == false)
  {
    printf("No large airport found!\n");
  }
  return;
}
 
char* airportToString(const Airport* a) {
  char temp[1000];
  //this formatting is required but the code may need to be adapted
  // to your definiion of your Airport structure.
  sprintf(temp, "%-8s %-15s %-20s %.2f %.2f %d %-10s %-2s", a->gpsId, a->type, a->name,
          a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);
  char* result = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
  strcpy(result, temp);
  return result;
}
 
void printAirports(Airport *airports, int n) {
 
  for(int i=0; i<n; i++) {
    char *s = airportToString(&airports[i]);
    printf("%s\n", s);
    free(s);
  }
 
  return;
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
 
 
int cmpByGPSId(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
 
  if (strcmp(a1->gpsId, a2->gpsId)<0){
    return -1;
  }
  if (strcmp(a1->gpsId, a2->gpsId)>0){
    return 1;
  }
  return 0;
}
 
int cmpByType(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
 
  if (strcmp(a1->type, a2->type)<0){
    return -1;
  }
  if (strcmp(a1->type, a2->type)>0){
    return 1;
  }
  return 0;
}
 
int cmpByName(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
 
  if (strcmp(a1->name, a2->name)<0){
    return -1;
  }
  if (strcmp(a1->name, a2->name)>0){
    return 1;
  }
  return 0;
}
 
int cmpByNameDesc(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
 
  if (strcmp(a1->name, a2->name)>0){
    return -1;
  }
  if (strcmp(a1->name, a2->name)<0){
    return 1;
  }
  return 0;
}
 
int cmpByCountryCity(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
    if (strcmp(a1->countryAbbrv, a2->countryAbbrv)<0){
    return -1;
  }
  if (strcmp(a1->countryAbbrv, a2->countryAbbrv)>0){
    return 1;
  }
if (strcmp(a1->countryAbbrv, a2->countryAbbrv)==0){
  if (strcmp(a1->city, a2->city)<0){
    return -1;
  }
  if (strcmp(a1->city, a2->city)>0){
    return 1;
  }
}
 
  return 0;
}
 
int cmpByLatitude(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
 
  if (a1->latitude< a2->latitude){
    return -1;
  }
  if (a1->latitude > a2->latitude){
    return 1;
  }
  return 0;
}
 
int cmpByLongitude(const void* a, const void* b){
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
 
  if (a1->longitude< a2->longitude){
    return -1;
  }
  if (a1->longitude > a2->longitude){
    return 1;
  }
  return 0;
}
 
int cmpByLincolnDistance(const void* a, const void* b){
 
  const Airport *a1 = (const Airport *)a;
  const Airport *b1 = (const Airport *)b;
  Airport* LNK = createAirport("LNK",
                          "Domestic",
                          "Lincoln Airport",
                          40.8485,
                          -96.7603,
                          1219,
                          "Lincoln",
                          "United States");
  double distanceA = getAirDistance(LNK, a1);
  double distanceB = getAirDistance(LNK, b1);
  if (distanceA< distanceB){
    return -1;
  }
  if (distanceA > distanceB){
    return 1;
  }
  return 0;
}
 
 
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
