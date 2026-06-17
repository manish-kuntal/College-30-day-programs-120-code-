/*
 * Q40: Character Pyramid (Palindromic)
 * ---------------------------------------
 * This program prints a centered character pyramid where each row forms
 * a palindromic sequence of characters.
 *
 * For n = 5:
 *     A
 *    ABA
 *   ABCBA
 *  ABCDCBA
 * ABCDEDCBA
 *
 * Logic: For row i (1 to n):
 *   - Print (n - i) spaces for centering
 *   - Print ascending characters from 'A' to 'A'+i-1
 *   - Print descending characters from 'A'+i-2 down to 'A'
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (prints "A")
 *   - Negative input (error message)
 *   - n > 26 (caps at 26 since there are only 26 letters)
 */

#include <stdio.h>

/* Function to print the character pyramid */
void printCharPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        /* Print leading spaces for centering */
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        /* Print ascending part: 'A' to 'A' + i - 1 */
        for (int j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }

        /* Print descending part: 'A' + i - 2 down to 'A' */
        for (int j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        printf("\n"); /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Character Pyramid (Palindromic) ===\n\n");
    printf("Enter the number of rows (1-26): ");
    scanf("%d", &rows);

    /* Validate input */
    if (rows < 0) {
        printf("Error: Number of rows cannot be negative.\n");
        return 1;
    }

    if (rows == 0) {
        printf("Nothing to print for 0 rows.\n");
        return 0;
    }

    /* Cap at 26 since there are only 26 letters */
    if (rows > 26) {
        printf("Warning: Capping rows at 26 (number of letters in the alphabet).\n");
        rows = 26;
    }

    printf("\nCharacter Pyramid with %d rows:\n\n", rows);
    printCharPyramid(rows);

    return 0;
}
