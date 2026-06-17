/*
 * Q20: Find the Largest Prime Factor of a Number
 * ------------------------------------------------
 * This program finds the largest prime factor of a given positive integer.
 *
 * Approach:
 *   1. Divide out all factors of 2.
 *   2. Then try odd factors from 3 to sqrt(n).
 *   3. If n is still > 1 after the loop, then n itself is the largest prime factor.
 *
 * Examples:
 *   - 12 = 2 * 2 * 3 -> Largest prime factor = 3
 *   - 315 = 3 * 3 * 5 * 7 -> Largest prime factor = 7
 *
 * Edge cases handled:
 *   - n <= 1: no prime factors.
 *   - n is prime: the number itself is the largest prime factor.
 */

#include <stdio.h>
#include <math.h>

int main() {
    long long n, largest = -1;

    printf("=== Largest Prime Factor ===\n");
    printf("Enter a positive integer (> 1): ");
    scanf("%lld", &n);

    /* Edge case: n <= 1 has no prime factors */
    if (n <= 1) {
        printf("Error: %lld has no prime factors. Enter a number > 1.\n", n);
        return 0;
    }

    long long original = n;

    printf("Prime factorization of %lld: ", original);

    /* Step 1: Divide out all factors of 2 */
    while (n % 2 == 0) {
        largest = 2;
        printf("2 ");
        n /= 2;
    }

    /* Step 2: Try odd factors from 3 to sqrt(n) */
    for (long long i = 3; i <= (long long)sqrt((double)n); i += 2) {
        while (n % i == 0) {
            largest = i;
            printf("%lld ", i);
            n /= i;
        }
    }

    /* Step 3: If n is still > 1, then it is the largest prime factor */
    if (n > 1) {
        largest = n;
        printf("%lld ", n);
    }

    printf("\nLargest prime factor of %lld = %lld\n", original, largest);

    return 0;
}
