/*
 * Q36: Hollow Square Pattern
 * ----------------------------
 * This program prints a hollow square pattern of size n x n.
 * Stars appear only on the borders (first row, last row, first column,
 * last column), with spaces in the interior.
 *
 * For n = 5:
 * *****
 * *   *
 * *   *
 * *   *
 * *****
 *
 * Logic: Print '*' if on the border (first/last row or first/last column),
 *        otherwise print a space.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (single star)
 *   - n = 2 (a 2x2 filled square, no hollow interior)
 *   - Negative input (error message)
 */

#include <stdio.h>

/* Function to print the hollow square pattern */
void printHollowSquare(int n) {
    for (int i = 1; i <= n; i++) {           /* Loop through each row */
        for (int j = 1; j <= n; j++) {       /* Loop through each column */
            /* Print '*' if on the border, else print space */
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");                         /* Move to the next line */
    }
}

int main() {
    int size;

    printf("=== Hollow Square Pattern ===\n\n");
    printf("Enter the size of the square: ");
    scanf("%d", &size);

    /* Validate input */
    if (size < 0) {
        printf("Error: Size cannot be negative.\n");
        return 1;
    }

    if (size == 0) {
        printf("Nothing to print for size 0.\n");
        return 0;
    }

    printf("\nHollow Square of size %d:\n\n", size);
    printHollowSquare(size);

    return 0;
}
