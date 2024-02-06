/**
 * Author: Megan Bogatz
 * 2023-10-12
*/
 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "array_utils.h"
 
bool contains(const int *arr, int size, int x) {
  if (arr == 0) {
    return 0; 
  }
  for (int i=0; i < size; ++i) {
    if (arr[i] == x) {
      return true;
    }
  }
  return false;
}
 
bool containsWithin(const int *arr, int size, int x, int i, int j) {
  if(arr == NULL) {
    return false;
  }
  bool countWithin = contains(&arr[i], (j-i)+1, x);
  return countWithin;
}
 
int *deepCopyArray(const int *arr, int n) {
  if (arr == NULL) {
    return NULL;
  }
  int *copy = (int *) malloc(sizeof(int) * n);
  if (copy == NULL) {
    return NULL;
  }
  for(int i=0; i<n; i++) {
    copy[i] = arr[i];
  }
 
  return copy;
}
 
int *paddedCopy(const int *arr, int oldSize, int newSize) {
  if (arr == NULL) {
    return NULL;
  }
  if (oldSize < 0) {
    return NULL;
  }
  int *deepPadded = deepCopyArray(arr, newSize);
  if (deepPadded == NULL) {
    return NULL;
  }
  if (newSize > oldSize) {
    for(int i = (oldSize); i < (newSize); i++) {
      deepPadded[i] = 0;
    }
  }
  return deepPadded;
}
 
void reverse(int *arr, int size) { 
  int *tempReverse = deepCopyArray(arr, size);
  if (tempReverse == NULL) {
    return;
  }
  for (int i=0; i<size; i++) {
    arr[i] = tempReverse[size-1-i];
  }
  return;
}
 
int *reverseCopy(const int *arr, int size) {
  int *tempReverse = deepCopyArray(arr, size);
  if (tempReverse == NULL) {
    return NULL;
  }
  for (int i=0; i<size; i++) {
    tempReverse[i] = arr[size-1-i];
  }
  return tempReverse;
}
