/*
 * Q13: Generate Fibonacci Series
 * --------------------------------
 * The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 * Each term is the sum of the two preceding terms.
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
 *
 * This program prints the first N terms of the Fibonacci series.
 *
 * Edge cases handled:
 *   - N <= 0: no terms to print.
 *   - N = 1: print only 0.
 *   - N = 2: print 0 and 1.
 */

#include <stdio.h>

int main() {
    int n;

    printf("=== Fibonacci Series ===\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    /* Edge case: non-positive input */
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    printf("\nFirst %d Fibonacci term(s):\n", n);

    long long first = 0, second = 1;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("  F(%d) = %lld\n", i, first);
        } else if (i == 2) {
            printf("  F(%d) = %lld\n", i, second);
        } else {
            long long next = first + second;
            printf("  F(%d) = %lld\n", i, next);
            first = second;
            second = next;
        }
    }

    return 0;
}
