/**
 * Author: Megan Bogatz
 * 2023-10-20
*/
 
/**
 * converts volume to cubic feet returning either liters or gallons.
*/
int convertVolume(double liters, double *cuft, double *gal);
 
/**
 * caluclates how much water each user has remaining.
*/
double * getRemainingWater(double limit, const double *usage, int n);
 
/**
 * calculates how much rainfall has occured on average.
*/
int averageRainfall(double **map, int n, int m, double *average);
