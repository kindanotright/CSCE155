/**This is a program that lets the user input a number and got back and forth between rounds to determine a winner.
 * Author: Megan Bogatz; kindanotright 
 * 2023-09-23
 */
#include <stdlib.h> 
#include <stdio.h>
 
int main(int argc, char **argv) {
 
    if(argc != 2) {
        printf("ERROR: incorrect input\n");
        exit (1);
    }
    int startingValue = atoi(argv[1]);
    if (startingValue <= 1) {
        printf("ERROR: enter a better number");
        exit(1);
    }
 
    printf("Starting Value: %d\n", startingValue);
 
    int playerARound = 0;
    int playerAScore = 0;
    int playerBRound = 0;
    int playerBScore = 0;
    int roundCounter = 1;
 
    while (startingValue > 1){
        printf("Round %d : %d... ", roundCounter, startingValue);
        roundCounter += 1;
        if ((startingValue % 2 ) == 0) {
           printf("even, player A scores!\n");
            startingValue /= 2;
            playerARound += 1;
        } else {
            startingValue = (3 * startingValue) + 1;
            printf(" odd, player B scores!\n");
            playerBRound += 1;
        }
    }
    printf("Game over!\n");
    printf("Results: \n");
    printf("Player\tPoints\tTotal Score\n");
    playerAScore += ((2 * playerARound) - 1) / 3;
    playerBScore += ((3* playerBRound) + 1) / 2;
    printf("A\t%d\t%d\n", playerARound, playerAScore);
    printf("B\t%d\t%d\n", playerBRound, playerBScore);
 
    if (playerAScore > playerBScore) {
        printf("A wins!\n");
    } else if (playerAScore < playerBScore) {
        printf("B wins!\n");
    } else {
        printf("Tie!\n");
    }
    return 0;
}
