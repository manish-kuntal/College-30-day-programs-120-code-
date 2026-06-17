/*
 * Q33: Reverse Star Pattern (Inverted Half Pyramid)
 * ---------------------------------------------------
 * This program prints an inverted half pyramid using stars (*).
 *
 * For n = 5:
 * *****
 * ****
 * ***
 * **
 * *
 *
 * Logic: For row i (n down to 1), print i stars.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (single star)
 *   - Negative input (error message)
 */

#include <stdio.h>

/* Function to print the reverse star pattern */
void printReverseStarPattern(int n) {
    for (int i = n; i >= 1; i--) {       /* Start from n rows, decreasing */
        for (int j = 1; j <= i; j++) {   /* Print i stars in row */
            printf("*");
        }
        printf("\n");                     /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Reverse Star Pattern ===\n\n");
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

    printf("\nReverse Star Pattern with %d rows:\n\n", rows);
    printReverseStarPattern(rows);

    return 0;
}
