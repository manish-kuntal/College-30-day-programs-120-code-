/*
 * Q31: Character Triangle Pattern
 * ---------------------------------
 * This program prints a character triangle pattern where each row i
 * contains characters from 'A' to the i-th letter.
 *
 * For n = 5:
 * A
 * AB
 * ABC
 * ABCD
 * ABCDE
 *
 * Logic: For row i (1 to n), print characters starting from 'A',
 *        incrementing for i characters.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (prints "A")
 *   - Negative input (error message)
 *   - n > 26 (wraps around the alphabet or caps at 26)
 */

#include <stdio.h>

/* Function to print the character triangle */
void printCharTriangle(int n) {
    for (int i = 1; i <= n; i++) {       /* Loop through each row */
        for (int j = 0; j < i; j++) {    /* Print i characters starting from 'A' */
            printf("%c", 'A' + j);
        }
        printf("\n");                     /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Character Triangle Pattern ===\n\n");
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

    printf("\nCharacter Triangle with %d rows:\n\n", rows);
    printCharTriangle(rows);

    return 0;
}
