#include "colorUtils.h"
#include <math.h>
 
double rgbIntToFloat(int c) {
  return (c / 255.0);
}
 
int max(int x, int y, int z) {
  int m = x > y ? x : y;
  m = m > z ? m : z;
  return m;
}
 
int toGrayScaleAverage(int r, int g, int b) {
  //TODO: test this, it may be wrong!
  double grayScaleAverage = (r + g + b) / 3.0;
  grayScaleAverage = round(grayScaleAverage);
  return grayScaleAverage;
}
 
int min(int x, int y, int z) {
  int m = x < y ? x : y;
  m = m < z ? m : z;
  return m;
}
 
 
int toGrayScaleLightness(int r, int g, int b) {
  double grayScaleLightness = (max(r, g, b) + min(r, g, b)) / 2.0;
  grayScaleLightness = round(grayScaleLightness);
  return grayScaleLightness;
 
}
 
 
int toGrayScaleLuminosity(int r, int g, int b) {
  double grayScaleLuminosity = (0.21 * r) + (0.72 * g) + (0.07 * b);
  grayScaleLuminosity = round(grayScaleLuminosity);
  return grayScaleLuminosity;
}
 
 
int toSepiaRed(int r, int g, int b) {
  double sepiaRed = (0.393 * r) + (0.769 * g) + (0.189 * b);
  sepiaRed = round(sepiaRed);
  if(sepiaRed > 255){
    sepiaRed = 255;
  }
  return sepiaRed;
}
 
 
int toSepiaGreen(int r, int g, int b){
  double sepiaGreen = (0.349 * r) + (0.686 * g) + (0.168 * b);
    sepiaGreen = round(sepiaGreen);
  if(sepiaGreen > 255){
    sepiaGreen = 255;
  }
  return sepiaGreen;
}
 
 
int toSepiaBlue(int r, int g, int b) {
  double sepiaBlue = (0.272 * r) + (0.534 * g) + (0.131 * b);
    sepiaBlue = round(sepiaBlue);
  if(sepiaBlue > 255){
    sepiaBlue = 255;
  }
  return sepiaBlue;
}
