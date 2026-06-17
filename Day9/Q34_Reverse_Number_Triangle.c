/*
 * Q34: Reverse Number Triangle
 * ------------------------------
 * This program prints a reverse (inverted) number triangle where each
 * row starts from 1 and the number of columns decreases with each row.
 *
 * For n = 5:
 * 12345
 * 1234
 * 123
 * 12
 * 1
 *
 * Logic: For row i (n down to 1), print numbers from 1 to i.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (prints "1")
 *   - Negative input (error message)
 */

#include <stdio.h>

/* Function to print the reverse number triangle */
void printReverseNumberTriangle(int n) {
    for (int i = n; i >= 1; i--) {       /* Start from n, decrease rows */
        for (int j = 1; j <= i; j++) {   /* Print numbers 1 to i */
            printf("%d", j);
        }
        printf("\n");                     /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Reverse Number Triangle ===\n\n");
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

    printf("\nReverse Number Triangle with %d rows:\n\n", rows);
    printReverseNumberTriangle(rows);

    return 0;
}
