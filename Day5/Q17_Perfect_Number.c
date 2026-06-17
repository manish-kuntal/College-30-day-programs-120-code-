/*
 * Q17: Check Perfect Number
 * ---------------------------
 * A perfect number is a positive integer that is equal to the sum
 * of its proper divisors (all divisors excluding itself).
 *
 * Examples: 6 = 1 + 2 + 3 (Perfect)
 *           28 = 1 + 2 + 4 + 7 + 14 (Perfect)
 *           496, 8128 are also perfect numbers.
 *
 * Approach: Find all divisors from 1 to n/2 and sum them.
 *           Optimized: find divisors up to sqrt(n) and add both
 *           the divisor and its complement.
 *
 * Edge cases handled:
 *   - n <= 0: not a perfect number.
 *   - n = 1: not perfect (sum of proper divisors = 0).
 */

#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("=== Perfect Number Check ===\n");
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    /* Edge case: non-positive input or 1 */
    if (n <= 1) {
        printf("%d is NOT a perfect number.\n", n);
        return 0;
    }

    /* Find all proper divisors and sum them */
    printf("Proper divisors of %d: ", n);
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
            printf("%d ", i);
        }
    }

    printf("\nSum of proper divisors = %d\n", sum);

    if (sum == n) {
        printf("%d is a PERFECT number!\n", n);
    } else {
        printf("%d is NOT a perfect number.\n", n);
    }

    return 0;
}
