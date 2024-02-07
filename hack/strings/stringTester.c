**
 * Author: Megan Bogatz
 * 2023-10-26
*/
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#include "string_utils.h"
 
int main(int argc, char **argv) {
 
  char cityName[20] = "Big Bussin City";
  char stateName[25] = "New New Nebraska";
  char countryName[30] = "Country of Megan Rooles";
 
  int cityNameLength = strlen(cityName);
  int stateNameLength = strlen(stateName);
  int countryNameLength = strlen(countryName);
 
  //test deepCopyString
  char *cityNameCopy = deepCopyString(cityName, cityNameLength);
  printf("Original: %s\nCopy: %s\n", cityName, cityNameCopy);
 
  char *stateNameCopy = deepCopyString(stateName, stateNameLength);
  printf("Original: %s\nCopy: %s\n", stateName, stateNameCopy);
 
  char *countryNameCopy = deepCopyString(countryName, countryNameLength);
  printf("Original: %s\nCopy: %s\n", countryName, countryNameCopy);
  printf("\n");
 
 
  //test replaceChar function
  replaceChar(cityNameCopy, 'B', 'D');
  printf("Replace B with D : %s\n", cityNameCopy);
  replaceChar(cityNameCopy, 'D', 'B');
  printf("Replace D with B : %s\n", cityNameCopy);
 
  replaceChar(stateNameCopy, 'N', 'P');
  printf("Replace N with P : %s\n", stateNameCopy);
  replaceChar(stateNameCopy, 'P', 'N');
  printf("Replace P with N : %s\n", stateNameCopy);
 
  replaceChar(countryNameCopy, 'o', 'u');
  printf("Replace o with u : %s\n", countryNameCopy);
  replaceChar(countryNameCopy, 'u', 'o');
  printf("Replace u with o : %s\n", countryNameCopy);
  printf("\n");
 
 
  //test replaceCharCopy
  printf("%s\n", cityName);
  cityNameCopy = replaceCharCopy(cityName, 'i', 'u');
  printf("Replace Copy i for u: %s\n", cityNameCopy);
  cityNameCopy = replaceCharCopy(cityName, 's', 'k');
  printf("Replace s for k: %s\n", cityNameCopy);
 
  printf("%s\n", stateName);
  stateNameCopy = replaceCharCopy(stateName, 'e', 'u');
  printf("Replace e for u: %s\n",  stateNameCopy);
  stateNameCopy = replaceCharCopy(stateName, 'a', 'f');
  printf("Replace a for f: %s\n", stateNameCopy);
 
  printf("%s\n", countryName);
  countryNameCopy = replaceCharCopy(countryName, 'e', 'y');
  printf("replace e for y: %s\n", countryNameCopy);
  countryNameCopy = replaceCharCopy(countryName, 'r', 'k');
  printf("replace r for k: %s\n", countryNameCopy);
  printf("\n");
 
 
  //test removeChar
  removeChar(cityNameCopy, 'u');
  printf("remove u from string: %s\n", cityNameCopy);
 
  removeChar(cityNameCopy, 's');
  printf("remove s from string: %s\n", cityNameCopy);
 
  removeChar(stateNameCopy, 'n');
  printf("remove n from string: %s\n", stateNameCopy);
 
  removeChar(stateNameCopy, 'N');
  printf("remove N from string: %s\n", stateNameCopy);
 
  removeChar(countryNameCopy, 'r');
  printf("remove r from string: %s\n", countryNameCopy);
 
  removeChar(countryNameCopy, 'e');
  printf("remove e from string: %s\n", countryNameCopy);
  printf("\n");
 
 
  //test removeCharCopy
  cityNameCopy = removeCharCopy(cityName, 's');
  printf("remove s :\n%s\n", cityNameCopy);
 
  stateNameCopy = removeCharCopy(stateName, 'N');
  printf("remove N :\n%s\n", cityNameCopy);
 
  countryNameCopy = removeCharCopy(countryName, 'R');
  printf("remove R :\n%s\n", cityNameCopy);
  printf("\n");
 
 
  //testing lengthSplit
  int arraySize = 3;
  printf("split the string into a size of %d\n", arraySize);
  lengthSplit(cityName, arraySize);
 
  arraySize = 4;
  printf("split the string into a size of %d\n", arraySize);
  lengthSplit(cityName, arraySize);
 
  arraySize = 5;
  printf("split the string into a size of %d\n", arraySize);
  lengthSplit(cityName, arraySize);
 
 
  return 0;
}
