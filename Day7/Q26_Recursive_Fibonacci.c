/*
 * Q26: Recursive Fibonacci
 * --------------------------
 * This program computes the nth Fibonacci number using recursion.
 * The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 *
 * Base cases: F(0) = 0, F(1) = 1
 * Recursive case: F(n) = F(n-1) + F(n-2)
 *
 * Edge cases handled:
 *   - Input of 0 (F(0) = 0)
 *   - Input of 1 (F(1) = 1)
 *   - Negative numbers (not valid for Fibonacci)
 *   - Large n warning (recursion becomes very slow for n > 40)
 */

#include <stdio.h>

/* Recursive function to compute nth Fibonacci number */
long long fibonacci(int n) {
    /* Base cases */
    if (n == 0) return 0;
    if (n == 1) return 1;

    /* Recursive case: F(n) = F(n-1) + F(n-2) */
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("=== Recursive Fibonacci Calculator ===\n\n");
    printf("Enter the position (n) in Fibonacci series: ");
    scanf("%d", &n);

    /* Validate input */
    if (n < 0) {
        printf("Error: Position cannot be negative.\n");
        return 1;
    }

    /* Warn about slow computation for large n */
    if (n > 40) {
        printf("Warning: Computing F(%d) with pure recursion is very slow.\n", n);
        printf("This may take a long time due to exponential time complexity.\n\n");
    }

    printf("F(%d) = %lld\n", n, fibonacci(n));

    /* Print the Fibonacci series up to position n (max 25 for readability) */
    int limit = (n < 25) ? n : 25;
    printf("\nFibonacci series up to F(%d):\n", limit);
    for (int i = 0; i <= limit; i++) {
        printf("F(%d) = %lld\n", i, fibonacci(i));
    }

    return 0;
}
