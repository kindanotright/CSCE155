/**
 * Author: Megan Bogatz
 * 2023-11-16
 */

/**
 * This function returns the number of ways to choose 'k' elements from a set of 'n'
 */
long choose(int n, int k);

/**
 * This function returns the number of ways to choose 'k' elements from a set of 'n'
 * but uses a 3D array to store the information.
 */
long chooseCache(int n, int k, long** cache);
