/*
 * Q44: Write a function to find factorial
 *
 * Description:
 *   Creates a function to compute the factorial of a number.
 *   n! = n * (n-1) * (n-2) * ... * 2 * 1
 *   By definition, 0! = 1
 *
 * Logic:
 *   - Iterative approach: multiply from 1 to n.
 *   - Recursive approach: n! = n * (n-1)!
 *   - Both methods are demonstrated.
 *
 * Edge Cases:
 *   - 0! = 1 (by definition)
 *   - Negative numbers (factorial is undefined)
 *   - Large numbers (overflow beyond 12! for int, 20! for long long)
 */

#include <stdio.h>

/* Iterative factorial function */
long long factorialIterative(int n) {
    long long result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

/* Recursive factorial function */
long long factorialRecursive(int n) {
    /* Base case */
    if (n <= 1) {
        return 1;
    }
    /* Recursive case */
    return (long long)n * factorialRecursive(n - 1);
}

int main() {
    int num;

    printf("=== Factorial Calculator ===\n\n");

    /* Read a number from the user */
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Edge case: negative number */
    if (num < 0) {
        printf("\nError: Factorial is not defined for negative numbers.\n");
        return 1;
    }

    /* Edge case: overflow warning */
    if (num > 20) {
        printf("\nWarning: Factorial of %d exceeds the range of long long.\n", num);
        printf("Results may overflow. Maximum safe input is 20.\n");
    }

    /* Calculate factorial using both methods */
    long long iterResult = factorialIterative(num);
    long long recurResult = factorialRecursive(num);

    printf("\n%d! (iterative)  = %lld\n", num, iterResult);
    printf("%d! (recursive)  = %lld\n", num, recurResult);

    /* Show step-by-step multiplication */
    if (num <= 15) {
        printf("\nStep-by-step: %d! = ", num);
        if (num == 0) {
            printf("1 (by definition)");
        } else {
            for (int i = num; i >= 1; i--) {
                printf("%d", i);
                if (i > 1) printf(" x ");
            }
            printf(" = %lld", iterResult);
        }
        printf("\n");
    }

    /* Display a table of factorials */
    printf("\n--- Factorial Table (0 to 12) ---\n");
    printf("%-5s %-15s\n", "n", "n!");
    printf("%-5s %-15s\n", "---", "----------");
    for (int i = 0; i <= 12; i++) {
        printf("%-5d %-15lld\n", i, factorialIterative(i));
    }

    return 0;
}
