/**
 * Author: Megan Bogatz
 * 2023-11-09
 */
 
typedef struct Airport_struct {
  const char* gpsId;
  const char* type;
  const char* name;
  double latitude;
  double longitude;
  int elevationFeet;
  const char* city;
  const char* countryAbbrv;
} Airport;
 
typedef enum {
  PASS,
  FAIL
} ERROR;
 
 
/**
 * creates a deep copy of a string.
*/
char * deepCopyString(const char *str, int n);
 
/**
 * A factory function to create a new Airport with the given
 * attributes.  This function should make *deep* copies of each
 * of the relevant fields and return a pointer to the newly
 * created Airport structure.
 */
Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv);
 
/**
 * This function initializes an existing allocated
 * Airport structure with the given attributes. This
 * function should make *deep* copies of each of the
 * relevant fields.
 */
void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv);
 
/**
 * Constructs a new string representation of the given
 * Airport structure.
 */
char* airportToString(const Airport* a);
 
/**
 * Computes the air distance, in kilometers, between
 * the two Airports using their latitude/longitude
 */
double getAirDistance(const Airport* origin, const Airport* destination);
 
/**
 * Converts the number into Radians.
 */
double convertRadian(double unradian);
 
/**
 * Computes the estimated travel time (in hours) for a flight
 * that involves the given stops (an array of Airport structures
 * of the given size) using the average flight speed
 * (kilometers per hour).  Thus there are size - 1 "legs" of the
 * trip.
 *
 * The first stop is the origin and the last stop is the destination.
 * Each stop in between is a layover each incurring a wait time
 * of aveLayoverTimeHrs
 */
double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs);
 
double testAccuracyCheck(double expected, double result);
