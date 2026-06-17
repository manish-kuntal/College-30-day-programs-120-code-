/*
 * Q38: Reverse Pyramid (Centered, Inverted)
 * -------------------------------------------
 * This program prints an inverted centered pyramid using stars (*).
 *
 * For n = 5:
 * *********
 *  *******
 *   *****
 *    ***
 *     *
 *
 * Logic: For row i (n down to 1):
 *   - Print (n - i) spaces for centering
 *   - Print (2*i - 1) stars
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (single star)
 *   - Negative input (error message)
 */

#include <stdio.h>

/* Function to print the reverse (inverted) pyramid */
void printReversePyramid(int n) {
    for (int i = n; i >= 1; i--) {
        /* Print leading spaces for centering */
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        /* Print stars: (2*i - 1) stars per row */
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n"); /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Reverse Pyramid (Centered) ===\n\n");
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

    printf("\nReverse Pyramid with %d rows:\n\n", rows);
    printReversePyramid(rows);

    return 0;
}
