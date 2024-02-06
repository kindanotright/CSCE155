/**
 * This is a library for calculating the air distance between 2 points
 * and calcuating the Lorentz Time Dialation.
 *
 * Author: Megan Bogatz; kindanotright
*/
 
 
//This function converts degrees into Radians
double degreesToRadians (double degree);
 
//This function calculates the air distances between two points
double getAirDistance (double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude);
 
//This function calculates the lorentzTimeDilation
double lorentzTimeDilation(double t, double percentC) ;
