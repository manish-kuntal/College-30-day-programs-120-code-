/*
 * Q29: Half Pyramid Pattern (Stars)
 * ------------------------------------
 * This program prints a half (left-aligned) pyramid pattern using stars (*).
 *
 * For n = 5:
 * *
 * **
 * ***
 * ****
 * *****
 *
 * Logic: For row i (1 to n), print i stars.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (single star)
 *   - Negative input (error message)
 */

#include <stdio.h>

/* Function to print half pyramid pattern */
void printHalfPyramid(int n) {
    for (int i = 1; i <= n; i++) {       /* Loop through each row */
        for (int j = 1; j <= i; j++) {   /* Print i stars in row i */
            printf("*");
        }
        printf("\n");                     /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Half Pyramid Pattern (Stars) ===\n\n");
    printf("Enter the number of rows: ");
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

    printf("\nHalf Pyramid with %d rows:\n\n", rows);
    printHalfPyramid(rows);

    return 0;
}
