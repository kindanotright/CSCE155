/**
 * Author: Megan Bogatz
 * 2023-10-10
*/
#include <stdlib.h>
#include <stdio.h>
 
#include "array_utils.h"
 
void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}
 
void printTable(int **table, int n, int m) {
  if(table == NULL) {
    printf("[null]\n");
    return;
  }
  for(int i=0; i<n; i++) {
    printArray(table[i], m);
  }
  return;
}
 
int * generateRandomArray(int size) {
  if(size < 0) {
    return NULL;
  }
  int * randomArr = malloc(sizeof(int) * size);
  for(int i=0; i<size; i++) {
    randomArr[i] = rand() % 100;
  }
  return randomArr;
}
 
int getSum(const int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
  int total = 0;
  for(int i=0; i<size; i++) {
    total += arr[i];
  }
  return total;
}
 
void freeTable(int **table, int n) {
  if(table == NULL) {
    return;
  }
  for(int i=0; i<n; i++) {
    free(table[i]);
  }
  free(table);
}
 
double getMean(const int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
    double mean = (double) getSum(arr, size) / size;
    return mean;
}
 
int getMin(const int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
  int min = arr[0];
  for (int i=0; i<size; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}
 
int getIndexOfMin(const int *arr, int size) {
  int min = getMin(arr, size);
  int indexOfMin = 0;
  for (int i=0; i<size; ++i) {
    if (arr[i] == min) {
      indexOfMin = i;
    }
  }
  return indexOfMin;
}
 
int getMax(const int *arr, int size) {
  if(arr == NULL) {
  return 0;
  }
  int max = arr[0];
  for (int i=0; i<size; ++i) {
    if (arr[i] > max) {
    max = arr[i];
    }
  }
  return max;
}
 
int getIndexOfMax(const int *arr, int size) {
  int max = getMax(arr, size);
  int indexOfMax = 0;
  for (int i=0; i<size; ++i) {
    if (arr[i] == max) {
      indexOfMax = i;
    }
  }
  return indexOfMax;
}
 
int * filterThreshold(const int *arr, int size, int threshold, int *resultSize) {
   if (arr == NULL || size <= 0) {
    *resultSize = 0;
    return NULL;
  }
 
  int *filteredArr = (int *)malloc(sizeof(int) * size);
  if (filteredArr == NULL) {
    *resultSize = 0;
    return NULL;
  }
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] >= threshold) {
      filteredArr[count] = arr[i];
      count++;
    }
  }
  *resultSize = count;
  return filteredArr;
}
 
int **createMultiplicationTable(int n, int m) {
  if (n <= 0 || m <= 0) {
      return NULL;
  }
  int **multiTable = (int **)malloc(sizeof(int *) * n);
  if (multiTable == NULL) {
      return NULL;
  }
  for (int i = 0; i < n; i++) {
    multiTable[i] = (int *)malloc(sizeof(int) * m);
    if (multiTable[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(multiTable[j]);
      }
      free(multiTable);
      return NULL;
    }
    for (int j = 0; j < m; j++) {
      multiTable[i][j] = (i + 1) * (j + 1);
    }
  }
  return multiTable;
}
