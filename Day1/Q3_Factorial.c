/*
 * Q3: Factorial of a Number
 * --------------------------
 * This program finds the factorial of a given non-negative integer.
 * Factorial(n) = n! = 1 * 2 * 3 * ... * n
 * By definition, 0! = 1.
 *
 * Edge cases handled:
 *   - n = 0: factorial is 1.
 *   - n < 0: factorial is not defined for negative numbers.
 *   - Large n: uses long long to handle bigger results (up to ~20!).
 */

#include <stdio.h>

int main() {
    int n;
    long long factorial = 1;

    printf("=== Factorial of a Number ===\n");
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    /* Edge case: negative input */
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 0;
    }

    /* Edge case: warn for very large inputs */
    if (n > 20) {
        printf("Warning: Result may overflow for n > 20 with long long.\n");
    }

    /* Calculate factorial iteratively */
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("%d! = %lld\n", n, factorial);

    return 0;
}
