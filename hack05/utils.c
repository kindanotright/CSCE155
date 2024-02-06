/** 
 * Calculates the air distance between 2 points
 * and calcuates the Lorentz Time Dialation.
 * 
 * Author: Megan Bogatz; kindanotright
*/
 
#include "utils.h" 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
double degreesToRadians (double degree) {
    double degreeRadian = (degree * M_PI) / 180;
    return degreeRadian;
}
 
double getAirDistance (double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {
        if (originLatitude < -90 || originLatitude > 90 || destinationLatitude < -90 || destinationLatitude > 90){
            printf("Error: Latitude must be between -90 degrees and 90 degrees.\n"); 
            exit(1); 
        }
        if (originLongitude < -180 || originLongitude > 180 || destinationLongitude < -180 || destinationLongitude > 180){
            printf("Error: Longitude must be between -180 degrees and 180 degrees.\n");
            exit (1);
        }
    double origLatRadian, origLongRadian, destLatRadian, destLongRadian;
    origLatRadian = degreesToRadians(originLatitude);
    origLongRadian = degreesToRadians(originLongitude);
    destLatRadian = degreesToRadians(destinationLatitude);
    destLongRadian = degreesToRadians(destinationLongitude);
    double airDistance = acos((sin(origLatRadian)*sin(destLatRadian))+(cos(origLatRadian)*cos(destLatRadian)*cos(destLongRadian-origLongRadian))) * 6371;
    return airDistance;
}
 
double lorentzTimeDilation(double t, double percentC) {
    double timeDilation = t / (sqrt(1 - (pow(percentC, 2))));
    printf("%f\t%f\n", t, percentC);
    return timeDilation;
}
