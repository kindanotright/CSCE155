/**
 * Author: Megan Bogatz 
 * 2022-11-02
*/
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#include "file_utils.h"
 
char *getFileContents(const char *filePath) {
    FILE * fileContents = NULL;
    fileContents = fopen(filePath, "r");
    if (fileContents == NULL) {
        return NULL;
    }
    char c = fgetc(fileContents);
    int counter = 0;
    while (c != EOF) {
        c = fgetc(fileContents);
        counter++;
    }
 
    rewind(fileContents);
    char *tempFileContents = (char *)malloc(sizeof(char) * (counter+1));
    for (int i=0; i < counter; i++) { 
        tempFileContents[i] = fgetc(fileContents); 
    } 
 
    fclose(fileContents);
    return tempFileContents;
}
 
 
char **getFileLines(const char *filePath, int *numLines) {
    FILE* fileLines = NULL;
    fileLines = fopen(filePath, "r");
    if (fileLines == NULL) {
        return NULL;
    }
    *numLines = 0;
    char c = fgetc(fileLines);
    while (c != EOF) { 
        if (c == '\n') { 
            (*numLines)++; 
        } 
    } 
    char **newLines = (char**)malloc(sizeof(char*) * (*numLines));
    // read the file, line by line
    char lineBuffer[1000];
    int lineIndex = 0;
    rewind(fileLines);
    while (fgets(lineBuffer, sizeof(lineBuffer), fileLines) != NULL) {
        int lineLength = strlen(lineBuffer);
        if (lineLength > 0 && lineBuffer[lineLength-1] == '\n') {
            lineBuffer[lineLength-1] = '\0';
        }
        newLines[lineIndex] = (char *)malloc(lineLength+1);
        strcpy(newLines[lineIndex], lineBuffer);
        lineIndex++;
 
    }
    fclose(fileLines);
    return newLines;
}
