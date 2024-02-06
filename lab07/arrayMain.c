/**
 * Author: Megan Bogatz
 * 2023-10-10
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
#include "array_utils.h"
 
int main(int argc, char **argv) {
 
  //seed the random number generator with the current time
  srand(time(NULL));
 
  int n = 10;
  int *arr = generateRandomArray(n);
 
  printArray(arr, n);
 
  int sum = getSum(arr, n);
  printf("Sum of elements = %d\n", sum);
 
  int mean = getMean(arr, n);
  printf("Mean of elements = %d\n", mean);
 
  int min = getMin(arr, n);
  printf("Min of elements = %d\n", min);
 
  int indexMin = getIndexOfMin(arr, n);
  printf("Index of min of elements = %d\n", indexMin);
 
  int max = getMax(arr, n);
  printf("Max of elements = %d\n", max);
 
  int indexMax = getIndexOfMax(arr, n);
  printf("Index of max of elements = %d\n", indexMax);
 
  int threshold = 10;  // Adjust the threshold value as needed.
  int resultSize;
  int *filteredArr = filterThreshold(arr, n, threshold, &resultSize);
  printf("Filtered Threshold elements:\n[ ");
  for (int i = 0; i < resultSize; i++) {
    printf("%d ", filteredArr[i]);
  }
  printf("]\n");
  printf("Threshold size: %d\n", resultSize);
 
  int rows =12;
  int columns = 12;
  int **multiTable = createMultiplicationTable(rows, columns);
  printf("Multiplication Table:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d\t", multiTable[i][j]);
    }
    printf("\n");
  }
 
  if (filteredArr != NULL) {
    free(filteredArr);
  }
  if (multiTable != NULL) {
    for (int i = 0; i < rows; i++) {
      if (multiTable[i] != NULL) {
        free(multiTable[i]);
      }
    }
    free(multiTable);
  }
  free(arr);
  return 0;
}
