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
double max(double a, double b, double c);
 
/**
 * Converts images from RGB to CMKY.
 */
int rgbToCMYK (int r, int g, int b, double *c, double *m, double *y, double *k);
 
/**
 * Converts images from CMKY to RGB
*/
int cmykToRGB (double c, double m, double y, double k, int *r, int *g, int *b);
