/**
 * Author: Megan Bogatz
 * 2023-10-24
 */

/**
 * Creates an empty string.
 * Used for storing the answer.
*/
void initializeBlankString(int n, char str[]);

/**
 * Prints the string with spaces between each character.
 * Reveled or not.
*/
void printWithSpaces(char str[]);

/**
 * Updates the letter once guessed.
*/
int revealGuessedLetter(char str[], char strGuess[], char guess);

/**
 * Verifies the guess matches the answer.
*/
int checkGuess(char strAns[], char strGuess[]);


//the following functions have been done for you.

/**
 * Sets the game up, checks for win condition,
 * prints relevant data
 */
void startGame(char *wordToGuess);

/**
 * Clears the unix terminal of previous input
 */
void clearScreen();

/**
 * Prints part of the horse based on the ratio between
 * the two numbers.
 */
void drawHorse(int guessedSoFar, int allowedGuesses);
