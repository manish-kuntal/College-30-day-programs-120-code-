/*
 * Q101_Number_Guessing_Game.c
 * ---------------------------
 * A number guessing game where the computer generates a random number
 * and the player tries to guess it with hints (too high / too low).
 *
 * Features:
 *   - Random number between 1 and 100
 *   - Hint system (higher / lower)
 *   - Attempt counter
 *   - Play again option
 *   - Input validation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Display welcome banner */
void displayBanner(void) {
    printf("\n============================================\n");
    printf("       NUMBER GUESSING GAME\n");
    printf("============================================\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Try to guess it with as few attempts as possible!\n");
    printf("============================================\n\n");
}

/* Rate the player based on number of attempts */
void ratePerformance(int attempts) {
    printf("\n--- Performance Rating ---\n");
    if (attempts <= 3) {
        printf("EXCELLENT! You're a mind reader! (%d attempts)\n", attempts);
    } else if (attempts <= 5) {
        printf("GREAT job! Very impressive! (%d attempts)\n", attempts);
    } else if (attempts <= 7) {
        printf("GOOD work! Not bad at all! (%d attempts)\n", attempts);
    } else if (attempts <= 10) {
        printf("DECENT effort. Keep practicing! (%d attempts)\n", attempts);
    } else {
        printf("You got it, but try to be more strategic next time! (%d attempts)\n", attempts);
    }
}

int main(void) {
    int secretNumber, guess, attempts;
    char playAgain;
    int gamesPlayed = 0, totalAttempts = 0, bestScore = 0;

    /* Seed random number generator with current time */
    srand((unsigned int)time(NULL));

    printf("*******************************************\n");
    printf("*     WELCOME TO NUMBER GUESSING GAME     *\n");
    printf("*******************************************\n");

    do {
        /* Generate random number between 1 and 100 */
        secretNumber = (rand() % 100) + 1;
        attempts = 0;

        displayBanner();

        /* Main guessing loop */
        do {
            printf("Enter your guess (1-100): ");
            if (scanf("%d", &guess) != 1) {
                /* Clear invalid input from buffer */
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n');
                continue;
            }

            /* Edge case: out-of-range guess */
            if (guess < 1 || guess > 100) {
                printf("Please enter a number between 1 and 100!\n\n");
                continue;
            }

            attempts++;

            if (guess > secretNumber) {
                printf("Too HIGH! Try a lower number.\n");
                /* Give additional hint when close */
                if (guess - secretNumber <= 5) {
                    printf("(You're very close!)\n");
                }
            } else if (guess < secretNumber) {
                printf("Too LOW! Try a higher number.\n");
                /* Give additional hint when close */
                if (secretNumber - guess <= 5) {
                    printf("(You're very close!)\n");
                }
            } else {
                printf("\n*** CONGRATULATIONS! ***\n");
                printf("You guessed the number %d correctly!\n", secretNumber);
                printf("Total attempts: %d\n", attempts);
            }
            printf("\n");
        } while (guess != secretNumber);

        /* Track statistics */
        gamesPlayed++;
        totalAttempts += attempts;
        if (bestScore == 0 || attempts < bestScore) {
            bestScore = attempts;
        }

        ratePerformance(attempts);

        /* Display cumulative statistics */
        printf("\n--- Game Statistics ---\n");
        printf("Games played : %d\n", gamesPlayed);
        printf("Total attempts: %d\n", totalAttempts);
        printf("Average attempts: %.1f\n", (float)totalAttempts / gamesPlayed);
        printf("Best score   : %d attempts\n", bestScore);

        /* Ask to play again */
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThank you for playing! Goodbye!\n");
    return 0;
}
