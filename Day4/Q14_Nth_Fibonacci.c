/*
 * Q14: Find the Nth Fibonacci Term
 * ----------------------------------
 * This program finds the Nth term in the Fibonacci sequence.
 * F(1) = 0, F(2) = 1, F(n) = F(n-1) + F(n-2) for n > 2.
 *
 * Approach: Iterative computation (efficient O(n) time, O(1) space).
 *
 * Edge cases handled:
 *   - N <= 0: invalid input.
 *   - N = 1: result is 0.
 *   - N = 2: result is 1.
 */

#include <stdio.h>

int main() {
    int n;

    printf("=== Nth Fibonacci Term ===\n");
    printf("Enter the term number (N): ");
    scanf("%d", &n);

    /* Edge case: non-positive input */
    if (n <= 0) {
        printf("Error: N must be a positive integer.\n");
        return 0;
    }

    long long first = 0, second = 1, result;

    if (n == 1) {
        result = first;
    } else if (n == 2) {
        result = second;
    } else {
        /* Iterate from the 3rd term onward */
        for (int i = 3; i <= n; i++) {
            result = first + second;
            first = second;
            second = result;
        }
    }

    printf("F(%d) = %lld\n", n, result);

    return 0;
}
