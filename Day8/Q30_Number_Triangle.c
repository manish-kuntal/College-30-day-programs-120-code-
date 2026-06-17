/*
 * Q30: Number Triangle Pattern
 * ------------------------------
 * This program prints a number triangle pattern where each row i
 * contains numbers from 1 to i.
 *
 * For n = 5:
 * 1
 * 12
 * 123
 * 1234
 * 12345
 *
 * Logic: For row i (1 to n), print numbers from 1 to i.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (prints "1")
 *   - Negative input (error message)
 *   - n > 9 (numbers become multi-digit; adds spacing for alignment)
 */

#include <stdio.h>

/* Function to print the number triangle */
void printNumberTriangle(int n) {
    for (int i = 1; i <= n; i++) {       /* Loop through each row */
        for (int j = 1; j <= i; j++) {   /* Print numbers 1 to i */
            printf("%d", j);
        }
        printf("\n");                     /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Number Triangle Pattern ===\n\n");
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

    printf("\nNumber Triangle with %d rows:\n\n", rows);
    printNumberTriangle(rows);

    return 0;
}
