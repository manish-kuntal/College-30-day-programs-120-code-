/*
 * Q12: Find LCM (Least Common Multiple) of Two Numbers
 * ------------------------------------------------------
 * The LCM of two integers is the smallest positive integer that
 * is divisible by both numbers.
 *
 * Approach: LCM(a, b) = |a * b| / GCD(a, b)
 *           We first compute GCD using the Euclidean Algorithm.
 *
 * Edge cases handled:
 *   - Either number is 0: LCM is 0 (since 0 is divisible by everything).
 *   - Negative numbers: we use absolute values.
 */

#include <stdio.h>

/* Function to compute GCD using Euclidean Algorithm */
int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int a, b;

    printf("=== LCM of Two Numbers ===\n");
    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    /* Work with absolute values */
    int abs_a = (a < 0) ? -a : a;
    int abs_b = (b < 0) ? -b : b;

    /* Edge case: if either number is 0, LCM is 0 */
    if (abs_a == 0 || abs_b == 0) {
        printf("LCM(%d, %d) = 0\n", a, b);
        printf("(LCM involving zero is 0)\n");
        return 0;
    }

    /* Calculate LCM using the formula: LCM = |a*b| / GCD(a,b) */
    int g = gcd(abs_a, abs_b);
    long long lcm = (long long)abs_a / g * abs_b;  /* Divide first to avoid overflow */

    printf("GCD(%d, %d) = %d\n", a, b, g);
    printf("LCM(%d, %d) = %lld\n", a, b, lcm);

    return 0;
}
