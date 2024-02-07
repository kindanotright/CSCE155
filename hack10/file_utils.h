/**
 * Author: Megan Bogatz
 * 2023-11-02
 */
 
/**
 * get the entire information from a file and returns it as a string.
 */
char *getFileContents(const char *filePath);
 
/**
 * get the entire information from a file and returns each line as an array.
 */
char **getFileLines(const char *filePath, int *numLines);
