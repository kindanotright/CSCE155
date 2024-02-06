/**
 * Author: Megan Bogatz
 * 2023-10-10
 * 
 * A collection of array and 2-D array utility
 * functions.
 */

/**
 * Prints the given integer array to the standard output
 */
void printArray(const int *arr, int n);

/**
 * Prints the given (n x m) integer table to the standard
 * output.
 */
void printTable(int **table, int n, int m);

/**
 * Generates an array of integers of the given size filled
 * with random integer values between 0 and 100 (exclusive).
 * This function assumes that the random number
 * generator has already been seeded.
 */
int * generateRandomArray(int size);

/**
 * Sums the elements in the given array.
 */
int getSum(const int *arr, int size);

/**
 * Frees the given (n x m) table.  Only the first parameter
 * (n, number of rows) is necessary to free the table.
 */
void freeTable(int **table, int n);

/**
 * Gets the mean of the array
 */
double getMean(const int *arr, int size);

/**
 * gets the minimum number from an array
 */
int getMin(const int *arr, int size);

/**
 * tells you the location of the minumum number in the array
 */
int getIndexOfMin(const int *arr, int size);

/**
 * gets the maximum number from an array
 */
int getMax(const int *arr, int size);

/**
 * tells you the location of the maximum number in the array
 */
int getIndexOfMax(const int *arr, int size);

/**
 * removes any numbers under the threshold from the array,
 * and tells you how many have been removed
 */
int * filterThreshold(const int *arr, int size, int threshold, int *resultSize);

/**
 * creates a multiplication table
 */
int **createMultiplicationTable(int n, int m);
/**
 * Author: Megan Bogatz
 * 2023-10-10
 * 
 * A collection of array and 2-D array utility
 * functions.
 */
 
/**
 * Prints the given integer array to the standard output
 */
void printArray(const int *arr, int n);
 
/**
 * Prints the given (n x m) integer table to the standard
 * output.
 */
void printTable(int **table, int n, int m);
 
/**
 * Generates an array of integers of the given size filled
 * with random integer values between 0 and 100 (exclusive).
 * This function assumes that the random number
 * generator has already been seeded.
 */
int * generateRandomArray(int size);
 
/**
 * Sums the elements in the given array.
 */
int getSum(const int *arr, int size);
 
/**
 * Frees the given (n x m) table.  Only the first parameter
 * (n, number of rows) is necessary to free the table.
 */
void freeTable(int **table, int n);
 
/**
 * Gets the mean of the array
 */
double getMean(const int *arr, int size);
 
/**
 * gets the minimum number from an array
 */
int getMin(const int *arr, int size);
 
/**
 * tells you the location of the minumum number in the array
 */
int getIndexOfMin(const int *arr, int size);
 
/**
 * gets the maximum number from an array
 */
int getMax(const int *arr, int size);
 
/**
 * tells you the location of the maximum number in the array
 */
int getIndexOfMax(const int *arr, int size);
 
/**
 * removes any numbers under the threshold from the array,
 * and tells you how many have been removed
 */
int * filterThreshold(const int *arr, int size, int threshold, int *resultSize);
 
/**
 * creates a multiplication table
 */
int **createMultiplicationTable(int n, int m);