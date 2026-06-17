/*
 * Q47: Write a function for Fibonacci series
 *
 * Description:
 *   The Fibonacci series starts with 0 and 1, and each subsequent
 *   number is the sum of the two preceding numbers.
 *   Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 *
 * Logic:
 *   - Iterative: use two variables to track previous two terms.
 *   - Recursive: fib(n) = fib(n-1) + fib(n-2) with base cases.
 *
 * Edge Cases:
 *   - n = 0 (just print 0)
 *   - n = 1 (print 0, 1)
 *   - Negative n (invalid)
 *   - Large n (overflow considerations)
 */

#include <stdio.h>

/* Function to print Fibonacci series up to n terms (iterative) */
void printFibonacci(int n) {
    if (n <= 0) {
        printf("(No terms to display)\n");
        return;
    }

    long long first = 0, second = 1, next;

    printf("Fibonacci series (%d terms):\n", n);

    for (int i = 0; i < n; i++) {
        printf("%lld", first);
        if (i < n - 1) printf(", ");

        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

/* Function to get the nth Fibonacci number (0-indexed, iterative) */
long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long prev2 = 0, prev1 = 1, current;

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

/* Recursive Fibonacci (for demonstration - less efficient) */
long long fibRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;

    printf("=== Fibonacci Series Generator ===\n\n");

    /* Read number of terms from user */
    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Edge case: negative input */
    if (n < 0) {
        printf("\nError: Number of terms cannot be negative.\n");
        return 1;
    }

    /* Edge case: zero terms */
    if (n == 0) {
        printf("\nNo terms to display.\n");
        return 0;
    }

    /* Print the Fibonacci series */
    printf("\n");
    printFibonacci(n);

    /* Show individual Fibonacci numbers */
    printf("\n--- Individual Fibonacci Numbers ---\n");
    int limit = (n < 15) ? n : 15;
    for (int i = 0; i < limit; i++) {
        printf("F(%d) = %lld\n", i, fibonacci(i));
    }

    /* Compare iterative vs recursive for small values */
    if (n <= 20) {
        printf("\n--- Iterative vs Recursive Verification ---\n");
        int check = (n < 10) ? n : 10;
        for (int i = 0; i < check; i++) {
            printf("F(%d): Iterative = %lld, Recursive = %lld %s\n",
                   i, fibonacci(i), fibRecursive(i),
                   (fibonacci(i) == fibRecursive(i)) ? "[OK]" : "[MISMATCH]");
        }
    }

    return 0;
}
