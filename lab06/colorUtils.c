/**
 * Author: Megan Bogatz
 * 2023-10-03
*/
#include <stdlib.h>
#include <math.h>
 
#include "colorUtils.h"
 
int max(int a, int b, int c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}
 
int min(int a, int b, int c) {
  return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}
 
ErrorCode toGrayScale(int *r, int *g, int *b, Mode mode) {
  ErrorCode error;
  error = SUCCESS;
  if (r == NULL || g == NULL || b == NULL) {
    error = NULL_INPUT;
  } else if (*r < 0 || *g < 0 || *b < 0) {
    error = INVALID_INPUT;
  } else if (*r > 255 || *g > 255 || *b > 255) {
    error = INVALID_INPUT;
  }
  if (error == SUCCESS) {
    if (mode == AVERAGE) {
      double grayScaleAverage = (*r + *g + *b) / 3.0;
      grayScaleAverage = round(grayScaleAverage);
      *r = grayScaleAverage;
      *g = grayScaleAverage;
      *b = grayScaleAverage;
    }
    if (mode == LIGHTNESS) {
      double grayScaleLightness = (max(*r, *g, *b) + min(*r, *g, *b)) / 2.0;
      grayScaleLightness = round(grayScaleLightness);
      *r = grayScaleLightness;
      *g = grayScaleLightness;
      *b = grayScaleLightness;
    }
    if (mode == LUMINOSITY) {
      double grayScaleLuminosity = (0.21 * *r) + (0.72 * *g) + (0.07 * *b);
      grayScaleLuminosity = round(grayScaleLuminosity);
      *r = grayScaleLuminosity;
      *g = grayScaleLuminosity;
      *b = grayScaleLuminosity;
    }
  }
 
  return error;
 
}
 
ErrorCode toSepia(int *r, int *g, int *b) {
  ErrorCode error;
  error = SUCCESS;
  if (r == NULL || g == NULL || b == NULL) {
    error = NULL_INPUT;
  } else if (*r < 0 || *g < 0 || *b < 0) {
    error = INVALID_INPUT;
  } else if (*r > 255 || *g > 255 || *b > 255) {
    error = INVALID_INPUT;
  }
 
  if (error == SUCCESS) {
    double sepiaRed = (0.393 * *r) + (0.769 * *g) + (0.189 * *b);
    sepiaRed = round(sepiaRed);
    double sepiaGreen = (0.349 * *r) + (0.686 * *g) + (0.168 * *b);
    sepiaGreen = round(sepiaGreen);
    double sepiaBlue = (0.272 * *r) + (0.534 * *g) + (0.131 * *b);
    sepiaBlue = round(sepiaBlue);
    if(sepiaBlue > 255){
      sepiaBlue = 255;
    }
    if(sepiaGreen > 255){
      sepiaGreen = 255;
    }
    if(sepiaRed > 255){
      sepiaRed = 255;
    }
    *r = sepiaRed;
    *g = sepiaGreen;
    *b = sepiaBlue;
  }
  //TODO: implement
  return error;
}
