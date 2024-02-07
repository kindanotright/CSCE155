**
 * Author: Megan Bogatz 
 * 2023-10-26
*/
 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 
#include "string_utils.h"
 
 
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
 
void replaceChar(char *str, char oldChar, char newChar) {
    if (str == NULL) {
        return;
    }
    int n = strlen(str);
    for (int i=0; i < n; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
    return;
}
 
char * replaceCharCopy(const char *str, char oldChar, char newChar) {
    if (str == NULL) {
        return NULL;
    }
    char *tempStr;
    int n = strlen(str);
    tempStr = deepCopyString(str, n);
    replaceChar(tempStr, oldChar, newChar); 
    return tempStr;
}
 
void removeChar(char *str, char c) {
    if (str == NULL) {
        return;
    }
    int n = strlen(str);
    char *tempStr = (char *) malloc(sizeof(char) * n);
    int counter = 0;
    for (int i=0; i<n; i++) {
        if (str[i] != c) {
            tempStr[counter] = str[i];
            counter++;
        }
    }
    tempStr[counter]='\0';
    strcpy(str, tempStr);
    return;
}
 
char * removeCharCopy(const char *str, char c) {
    if (str == NULL) {
        return NULL;
    }
    char *tempStr;
    int n = strlen(str);
    tempStr = deepCopyString(str, n);
    removeChar(tempStr, c);
    return tempStr;
}
 
char ** newMatrix(int arraySize, int numberArrays) {
    if (arraySize < 0 || numberArrays <0) {
        return NULL;
    }
    char **newMatrix = (char **) malloc(arraySize * sizeof(char*));
    for(int i=0; i<arraySize; i++) {
        newMatrix[i] = (char *) malloc(numberArrays * sizeof(char));
        for (int j=0; j<numberArrays; j++) {
            newMatrix[i][j] = 'Y';
        }
    }
    return newMatrix;
}
 
char **printMatrix(char **arrSplit, int arraySize, int numberArrays) {
    if (arrSplit == NULL) {
        return NULL;
    }
    if (arraySize < 0 || numberArrays <0) {
        return NULL;
    }
    for(int i=0; i<arraySize; i++) {
        printf(" ");
        for(int j=0; j<numberArrays; j++) {
            printf("%c", arrSplit[i][j]);
        }
    }
    printf("\n");
    return arrSplit;
}
 
char **lengthSplit(const char *str, int arraySize) {
    if (str == NULL) {
        return NULL;
    }
    int strLength = strlen(str);
    int numberArrays;
    if (strLength % arraySize == 0) {
        numberArrays = strLength/arraySize;
    } else {
        numberArrays = (strLength/arraySize) + 1;
    }
    char **arrSplit = newMatrix(numberArrays, arraySize);
    int counter = 0;
    for (int i=0; i < numberArrays; i++) {
        for (int j=0; j<arraySize; j++){
            arrSplit[i][j] = str[counter];
            counter++;
        }
    }
    printMatrix(arrSplit, numberArrays, arraySize);
    return arrSplit;
}
 
