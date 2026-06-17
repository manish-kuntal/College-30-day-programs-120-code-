/*
 * Q19: Print Factors of a Number
 * --------------------------------
 * This program prints all factors (divisors) of a given positive integer.
 * A factor of n is any number that divides n without a remainder.
 *
 * Approach: Iterate from 1 to n and check if i divides n.
 *           Optimized: iterate from 1 to sqrt(n), print both i and n/i.
 *
 * Edge cases handled:
 *   - n <= 0: inform user that factors are for positive integers.
 *   - n = 1: only factor is 1.
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n, count = 0;

    printf("=== Factors of a Number ===\n");
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    /* Edge case: non-positive input */
    if (n <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 0;
    }

    printf("Factors of %d: ", n);

    /* Simple approach: check all numbers from 1 to n */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d", i);
            count++;
            if (i != n) printf(", ");
        }
    }

    printf("\nTotal number of factors: %d\n", count);

    /* Classify the number */
    if (count == 2) {
        printf("%d is a PRIME number (exactly 2 factors).\n", n);
    } else if (count > 2) {
        printf("%d is a COMPOSITE number.\n", n);
    }

    return 0;
}
