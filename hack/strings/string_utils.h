/**
 * Author: Megan Bogatz
 * 2023-10-26
*/

/**
 * creates a deep copy of a string.
*/
char * deepCopyString(const char *str, int n);

/**
 * Replaces a character in a string with a new character.
*/
void replaceChar(char *s, char oldChar, char newChar);

/**
 * Creates a copy of the string and replaces a character with a new character.
*/
char * replaceCharCopy(const char *s, char oldChar, char newChar);

/**
 * removes a character from the string. and updates the string length to adapt removal.
*/
void removeChar(char *s, char c);

/**
 * creates a copy of the string and removes a character from the string.
 * updates the length of the string to adapt for the removal.
*/
char * removeCharCopy(const char *s, char c);

/**
 * Creates a 3d arrays of strings.
*/
char ** newMatrix(int arraySize, int numberArrays);

/**
 * prints an array of strings.
*/
char **printMatrix(char **arrSplit, int arraySize, int numberArrays);

/**
 * splits the string into smaller arrays with a length of n.
*/
char **lengthSplit(const char *s, int n);
/** 
 * Author: Megan Bogatz 
 * 2023-10-26 
*/ 
 
/**
 * creates a deep copy of a string. 
*/ 
char * deepCopyString(const char *str, int n);
 
/**
 * Replaces a character in a string with a new character.
*/
void replaceChar(char *s, char oldChar, char newChar);
 
/**
 * Creates a copy of the string and replaces a character with a new character.
*/
char * replaceCharCopy(const char *s, char oldChar, char newChar);
 
/**
 * removes a character from the string. and updates the string length to adapt removal.
*/
void removeChar(char *s, char c);
 
/**
 * creates a copy of the string and removes a character from the string.
 * updates the length of the string to adapt for the removal.
*/
char * removeCharCopy(const char *s, char c);
 
/**
 * Creates a 3d arrays of strings.
*/
char ** newMatrix(int arraySize, int numberArrays);
 
/**
 * prints an array of strings.
*/
char **printMatrix(char **arrSplit, int arraySize, int numberArrays);
 
/**
 * splits the string into smaller arrays with a length of n.
*/
char **lengthSplit(const char *s, int n);
