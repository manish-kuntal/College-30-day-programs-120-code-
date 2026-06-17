/*
 * Q25: Recursive Factorial
 * -------------------------
 * This program calculates the factorial of a number using recursion.
 * Factorial of n (written as n!) = n * (n-1) * (n-2) * ... * 2 * 1
 *
 * Base case: 0! = 1 and 1! = 1
 * Recursive case: n! = n * (n-1)!
 *
 * Edge cases handled:
 *   - Input of 0 (0! = 1)
 *   - Negative numbers (factorial is undefined)
 *   - Large numbers (warning about overflow for n > 20 with long long)
 */

#include <stdio.h>

/* Recursive function to compute factorial */
long long factorial(int n) {
    /* Base case: factorial of 0 or 1 is 1 */
    if (n == 0 || n == 1) {
        return 1;
    }

    /* Recursive case: n! = n * (n-1)! */
    return (long long)n * factorial(n - 1);
}

int main() {
    int num;

    printf("=== Recursive Factorial Calculator ===\n\n");
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    /* Validate input */
    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1;
    }

    /* Warn about potential overflow */
    if (num > 20) {
        printf("Warning: Factorial of %d exceeds the range of long long.\n", num);
        printf("Results may overflow and be incorrect.\n\n");
    }

    printf("%d! = %lld\n", num, factorial(num));

    /* Show the step-by-step expansion */
    if (num <= 12) {
        printf("\nStep-by-step: %d! = ", num);
        for (int i = num; i >= 1; i--) {
            printf("%d", i);
            if (i > 1) printf(" x ");
        }
        if (num == 0) printf("1");
        printf(" = %lld\n", factorial(num));
    }

    /* Demonstrate with examples */
    printf("\n--- Factorial Table ---\n");
    printf("%-5s %s\n", "n", "n!");
    printf("%-5s %s\n", "---", "---");

    for (int i = 0; i <= 15; i++) {
        printf("%-5d %lld\n", i, factorial(i));
    }

    return 0;
}
