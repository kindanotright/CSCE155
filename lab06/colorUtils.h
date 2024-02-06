/**
 * Author: Megan Bogatz
 * 2023-10-03
*/
#ifndef MODE_H
#define MODE_H
 
typedef enum {
  AVERAGE,
  LIGHTNESS,
  LUMINOSITY
} Mode;
 
typedef enum {
  SUCCESS,
  INVALID_INPUT,
  NULL_INPUT
} ErrorCode;
 
#endif /* MODE_H */
 
/**
 * Returns the maximum value among the three given values
 */
int max(int a, int b, int c);
 
/**
 * Returns the minimum value among the three given values
 */
int min(int a, int b, int c);
 
/**
 * Converts images to gray scale. runs through error check first.
 */
ErrorCode toGrayScale(int *r, int *g, int *b, Mode mode);
 
/**
 * Converts images to sepia. runs through error check first.
 */
ErrorCode toSepia(int *r, int *g, int *b);
