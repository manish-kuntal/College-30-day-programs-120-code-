/*
 * Q1: Sum of First N Natural Numbers
 * -----------------------------------
 * This program calculates the sum of the first N natural numbers.
 * Formula: sum = N * (N + 1) / 2
 * We also demonstrate the iterative approach using a loop.
 *
 * Edge cases handled:
 *   - N <= 0: No natural numbers to sum, result is 0.
 */

#include <stdio.h>

int main() {
    int n, sum;

    printf("=== Sum of First N Natural Numbers ===\n");
    printf("Enter a positive integer N: ");
    scanf("%d", &n);

    /* Edge case: non-positive input */
    if (n <= 0) {
        printf("Invalid input! N must be a positive integer.\n");
        printf("Sum = 0\n");
        return 0;
    }

    /* Method 1: Using the mathematical formula */
    int formula_sum = n * (n + 1) / 2;

    /* Method 2: Using an iterative loop */
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("\nSum of first %d natural numbers:\n", n);
    printf("  Using formula : %d\n", formula_sum);
    printf("  Using loop    : %d\n", sum);

    return 0;
}
