/**
 * Author: Megan Bogatz
 * 2023-10-12
*/
 
#include <stdbool.h> 
 
/**
 * looks for a specific integer in the array
*/
bool contains(const int *arr, int size, int x);
 
/**
 * looks for a specific integer between two points in an array
*/
bool containsWithin(const int *arr, int size, int x, int i, int j);
 
/**
 * Creates a deep copy of the given integer array (of size n)
 * and returns a new array containing its elements...
 */
int *deepCopyArray(const int *arr, int n);
 
/**
 * creates and saves new array of a new size
*/
int *paddedCopy(const int *arr, int oldSize, int newSize);
 
/**
 * puts the array in reverse
*/
void reverse(int *arr, int size);
 
/**
 * saves a copy of the array in reverse
*/
int *reverseCopy(const int *arr, int size);
