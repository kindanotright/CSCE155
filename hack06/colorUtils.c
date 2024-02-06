/** 
 * Author: Megan Bogatz
 * 2023-10-03
*/
#include <stdlib.h>
#include <math.h>
 
#include "colorUtils.h"
 
 
double max(double a, double b, double c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}
 
int rgbToCMYK (int r, int g, int b, double *c, double *m, double *y, double *k) {
    if (c == NULL || m == NULL || y == NULL || k == NULL) {
        return NULL_INPUT;
    } if (r < 0 || g < 0 || b < 0) {
        return INVALID_INPUT;
    } if (r > 255 || g > 255 || b > 255) {
        return INVALID_INPUT;
    } if (r == 0 && g == 0 && b == 0) {
        *c = 0.0;
        *m = 0.0;
        *y = 0.0;
        *k = 1.0;
        return SUCCESS;
    }
    double red = r / 255.0;
    double green = g / 255.0;
    double blue = b / 255.0;
 
    *k = 1.0 - max(red, green, blue);
    *c = (1.0 - red - *k) / (1.0 - *k);
    *m = (1.0 - green - *k) / (1.0 - *k);
    *y = (1.0 - blue - *k) / (1.0 - *k);
 
    return SUCCESS;
}
 
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
    if (r == NULL || g == NULL || b == NULL) {
        return NULL_INPUT;
    } if (c < 0 || m < 0 || y < 0 || k < 0) {
        return INVALID_INPUT;
    } if (c > 1 || m > 1 || k > 1 || y > 1) {
        return INVALID_INPUT;
    } if (c == 0 && m == 0 && y == 0 && k == 1) {
        *r = 0;
        *g = 0;
        *b = 0;
        return SUCCESS;
    }
    *r = (int) round (255.0 * (1.0 - c) * (1.0 - k));
    *g = (int) round (255.0 * (1.0 - m) * (1.0 - k));
    *b = (int) round (255.0 * (1.0 - y) * (1.0 - k));
 
    return SUCCESS;
}
