/**This program computes the distance between 2 points on the globe. 
 *Megan Bogatz, kindanotright, 2023-08-31*/ 
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846 
 
int main() {
    double latA, latB, lonA, lonB;
 
    //starting point
    do {
        printf("Please provide starting latitude and longitude with a space in between:\n");
        scanf("%lf %lf", &latA, &lonA);
        if (latA < -90 || latA > 90){
            printf("Error: Latitude must be between -90 degrees and 90 degrees.\n");
            }
        if (lonA < -180 || lonA > 180){
            printf("Error: Longitude must be between -180 degrees and 180 degrees.\n");
        }
    } while (latA < -90 || latA > 90 || lonA < -180 || lonA > 180);
    
    //ending point
    do{
        printf("Please provide ending latitude and longitude with a space in between: ");
        scanf("%lf %lf", &latB, &lonB);
        if (latB < -90 || latB > 90){
            printf("\nError: Latitude must be between -90 degrees and 90 degrees.\n");
            }
        if (lonB < -180 || lonB > 180){
            printf("\nError: Longitude must be between -180 degrees and 180 degrees.\n");
        }
    } while (latB < -90 || latB > 90 || lonB < -180 || lonB > 180);
 
    //convert latitude and longitude to radians
    double latAr=latA/180*PI;
    double lonAr=lonA/180*PI;
    double latBr=latB/180*PI;
    double lonBr=lonB/180*PI;
 
    //calculate distance
    double dis=acos(sin(latAr)*sin(latBr)+cos(latAr)*cos(latBr)*cos(lonBr-lonAr))*(6371);
    printf ("\nLocation Distance\n");
    printf ("=======================\n");
    printf ("Orgin:        (%lf, %lf)\n", latA, lonA);
    printf ("Destination:  (%lf, %lf)\n", latB, lonB);
    printf ("Air distance is %lf kms\n", dis);
 
    return 0;
}
