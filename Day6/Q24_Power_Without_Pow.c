/*
 * Q24: Power Without pow() Function
 * ------------------------------------
 * This program computes x^n (x raised to the power n) without using
 * the pow() library function. Two methods are demonstrated:
 *   1. Iterative multiplication: O(n) time
 *   2. Binary exponentiation (fast power): O(log n) time
 *
 * Edge cases handled:
 *   - Exponent of 0 (result is always 1)
 *   - Base of 0 with positive exponent (result is 0)
 *   - Base of 0 with exponent 0 (defined as 1 by convention)
 *   - Negative exponents (returns 1.0 / x^|n|)
 *   - Negative base values
 */

#include <stdio.h>

/* Method 1: Simple iterative approach - O(n) */
double powerIterative(double base, int exponent) {
    /* Any number raised to 0 is 1 */
    if (exponent == 0) return 1.0;

    int isNegative = 0;
    int exp = exponent;

    /* Handle negative exponent: x^(-n) = 1 / x^n */
    if (exp < 0) {
        isNegative = 1;
        exp = -exp;
    }

    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base; /* Multiply base 'exp' times */
    }

    return isNegative ? (1.0 / result) : result;
}

/*
 * Method 2: Binary Exponentiation (Fast Power) - O(log n)
 * Uses the property:
 *   x^n = (x^(n/2))^2         if n is even
 *   x^n = x * (x^(n/2))^2     if n is odd
 */
double powerFast(double base, int exponent) {
    /* Any number raised to 0 is 1 */
    if (exponent == 0) return 1.0;

    int isNegative = 0;
    long long exp = exponent; /* Use long long to handle INT_MIN safely */

    if (exp < 0) {
        isNegative = 1;
        exp = -exp;
    }

    double result = 1.0;
    double current = base;

    while (exp > 0) {
        /* If the current bit of exponent is set, multiply result by current */
        if (exp % 2 == 1) {
            result *= current;
        }
        current *= current; /* Square the base */
        exp /= 2;           /* Right shift the exponent */
    }

    return isNegative ? (1.0 / result) : result;
}

int main() {
    double base;
    int exponent;

    printf("=== Power Without pow() ===\n\n");
    printf("Enter base (x): ");
    scanf("%lf", &base);
    printf("Enter exponent (n): ");
    scanf("%d", &exponent);

    double resultIter = powerIterative(base, exponent);
    double resultFast = powerFast(base, exponent);

    printf("\n%.2lf ^ %d:\n", base, exponent);
    printf("  Iterative method: %.6lf\n", resultIter);
    printf("  Fast power method: %.6lf\n", resultFast);

    /* Demonstrate with a few examples */
    printf("\n--- Additional Examples ---\n");
    printf("%-12s %-8s %-20s %-20s\n", "Base", "Exp", "Iterative", "Fast Power");
    printf("%-12s %-8s %-20s %-20s\n", "----", "---", "---------", "----------");

    double bases[] = {2, 3, 5, 2, 10, 0, 7, 2};
    int exponents[] = {0, 1, 3, 10, 4, 5, 2, -3};
    int count = 8;

    for (int i = 0; i < count; i++) {
        printf("%-12.1lf %-8d %-20.6lf %-20.6lf\n",
               bases[i], exponents[i],
               powerIterative(bases[i], exponents[i]),
               powerFast(bases[i], exponents[i]));
    }

    return 0;
}
