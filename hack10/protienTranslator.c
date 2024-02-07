/**
 * Author: Megan Bogatz
 * 2023-11-02
 */
#include <stdio.h>
#include <string.h>
 
// this week makes very little sense
int main(int argc, char **argv) {
    if (argc <= 0) {
        return 1;
    }
    const char *filePath = argv[1];
    int *numLines;
    const char *rna;
    const void *a = 0;
    const void *b = 0;
    char **fileContents = getFileContents(filePath);
    char **fileLines = getFileLines(filePath, numLines);
    char *imLostThisWeek = rnaToProtein(rna); 
    int *likeReallyLost = proteinMapComp(a, b);
}
