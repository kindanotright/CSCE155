/**
 * Author: Megan Bogatz 
 * 2023-10-20
 */
 
#include <stdio.h>
#include <stdlib.h>
 
//#define l_cuft 9.03531467 
//#define gal_cuft 0.264172 
 
//1 liter (l) is equivalent to 9.03531467 cubic feet (cuft).
//1 liter (l) is equivalent to 0.264172 gallons (gal).
int convertVolume(double liters, double *cuft, double *gal) {
    if (liters < 0) {
        return -1;
    }
    if (cuft == NULL) {
        return -1;
    }
    if (gal == NULL) {
        return -1;
    }
    *cuft = liters * 9.03531467;
    *gal = liters * 0.264172;
    return 0;
}
 
double * getRemainingWater(double limit, const double *usage, int n) {
    if (usage == NULL) {
        return NULL;
    }
    if (limit < 0) {
        return NULL;
    }
    double *waterRemain = (double *) malloc(sizeof(double) * n);
    for (int i=0; i<n; i++) {
        if (usage[i] >= limit) {
            waterRemain[i] = 0.0;
        } else {
            waterRemain[i] = limit - usage[i];
        }
    }
    return waterRemain;
}
 
int averageRainfall(double **map, int n, int m, double *average) {
    if (map == NULL || average == NULL) {
        return -1;
    }
    if (n <= 0 || m <= 0) {
        return -2;
    }
    double rainfall = 0;
    int rainfallCount = 0;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (map[i][j] < 0) { 
                //ignore this. toats not important. didnt happen rains. 
            } else {
                rainfall += map[i][j];
                rainfallCount++;
            }
        }
    }
    *average = rainfall/rainfallCount;
    return 0;
}
