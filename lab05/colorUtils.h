/**
 * Megan Bogatz; kindanotright
 * 2023-09-26
 *
 * A collection of utility functions to manipualte RGB
 * values of an image
 */
 
/**
 * Scales the given rgb integer component (on the
 * scale [0, 255]) to a floating point number on the
 * scale [0, 1].
 *
 * Note: this function is only included to demonstrate
 * how to unit test floating point values.  See the
 * colorUtilsTester.c for more.
 */
double rgbIntToFloat(int c);
 
/**
 * Returns the maximum value among the three
 * given integer values.
 */
int max(int x, int y, int z);
 
/**
 * Returns a gray-scaled RGB value of the three
 * given RGB values using the average technique.
 *
 */
int toGrayScaleAverage(int r, int g, int b);
 
/**
 * Returns the minumum value among the three
 * given interger values.
*/
int min(int x, int y, int z);
 
/**
 * Converts an image into gray-scale using
 * the "lightness" technique.
*/
int toGrayScaleLightness(int r, int g, int b);
 
/**
 * Converts an image into gray-scale using
 * the Luminosity technique.
*/
int toGrayScaleLuminosity(int r, int g, int b);
 
/**
 * Converts an image into Sepia Red
*/
int toSepiaRed(int r, int g, int b);
 
/**
 * Converts an image into Green Red
*/
int toSepiaGreen(int r, int g, int b);
 
/**
 * Converts an image into Sepia Blue
*/
int toSepiaBlue(int r, int g, int b);
