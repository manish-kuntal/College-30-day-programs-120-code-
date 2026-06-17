/*
 * Q32: Repeated Number Pattern
 * ------------------------------
 * This program prints a pattern where row i contains the digit i
 * repeated i times.
 *
 * For n = 5:
 * 1
 * 22
 * 333
 * 4444
 * 55555
 *
 * Logic: For row i (1 to n), print the digit i exactly i times.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (prints "1")
 *   - Negative input (error message)
 *   - n > 9 (numbers become multi-digit; separated by spaces for clarity)
 */

#include <stdio.h>

/* Function to print the repeated number pattern */
void printRepeatedNumberPattern(int n) {
    for (int i = 1; i <= n; i++) {       /* Loop through each row */
        for (int j = 1; j <= i; j++) {   /* Print the digit i, exactly i times */
            if (i <= 9) {
                printf("%d", i);         /* Single digit: no spacing needed */
            } else {
                printf("%d ", i);        /* Multi-digit: add space for readability */
            }
        }
        printf("\n");                     /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Repeated Number Pattern ===\n\n");
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

    printf("\nRepeated Number Pattern with %d rows:\n\n", rows);
    printRepeatedNumberPattern(rows);

    return 0;
}
