/*
 * Q35: Repeated Character Pattern
 * ---------------------------------
 * This program prints a pattern where row i contains the i-th letter
 * of the alphabet repeated i times.
 *
 * For n = 5:
 * A
 * BB
 * CCC
 * DDDD
 * EEEEE
 *
 * Logic: For row i (1 to n), print the character ('A' + i - 1) exactly i times.
 *
 * Edge cases handled:
 *   - n = 0 (no output)
 *   - n = 1 (prints "A")
 *   - Negative input (error message)
 *   - n > 26 (caps at 26 since there are only 26 letters)
 */

#include <stdio.h>

/* Function to print the repeated character pattern */
void printRepeatedCharPattern(int n) {
    for (int i = 1; i <= n; i++) {           /* Loop through each row */
        char ch = 'A' + (i - 1);             /* Determine the character for this row */
        for (int j = 1; j <= i; j++) {       /* Print the character i times */
            printf("%c", ch);
        }
        printf("\n");                         /* Move to the next line */
    }
}

int main() {
    int rows;

    printf("=== Repeated Character Pattern ===\n\n");
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

    printf("\nRepeated Character Pattern with %d rows:\n\n", rows);
    printRepeatedCharPattern(rows);

    return 0;
}
