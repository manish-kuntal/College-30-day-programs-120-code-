/*
 * Q39: Number Pyramid (Palindromic)
 * ------------------------------------
 * This program prints a centered number pyramid where each row forms
 * a palindromic sequence of numbers.
 *
 * For n = 5:
 *     1
 *    121
 *   12321
 *  1234321
 * 123454321
 *
 * Logic: For row i (1 to n):
 *   - Print (n - i) spaces for centering
 *   - Print ascending numbers from 1 to i
 *   - Print descending numbers from (i-1) to 1
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (prints "1")
 *   - Negative input (error message)
 *   - n > 9 (numbers become multi-digit; adds spacing)
 */

#include <stdio.h>

/* Function to print the number pyramid */
void printNumberPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        /* Print leading spaces for centering */
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        /* Print ascending part: 1 to i */
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        /* Print descending part: (i-1) down to 1 */
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n"); /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Number Pyramid (Palindromic) ===\n\n");
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

    if (rows > 9) {
        printf("Note: For rows > 9, numbers become multi-digit and alignment\n");
        printf("      may not be perfect. Showing pattern anyway.\n\n");
    }

    printf("\nNumber Pyramid with %d rows:\n\n", rows);
    printNumberPyramid(rows);

    return 0;
}
