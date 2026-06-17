/*
 * Q11: Find GCD (Greatest Common Divisor) of Two Numbers
 * --------------------------------------------------------
 * The GCD of two integers is the largest positive integer that
 * divides both numbers without leaving a remainder.
 *
 * Approach: Euclidean Algorithm
 *   gcd(a, b) = gcd(b, a % b) until b becomes 0.
 *
 * Edge cases handled:
 *   - One or both numbers are 0: gcd(0, n) = n.
 *   - Negative numbers: GCD uses absolute values.
 */

#include <stdio.h>

int main() {
    int a, b, temp_a, temp_b;

    printf("=== GCD of Two Numbers ===\n");
    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    /* Work with absolute values */
    temp_a = (a < 0) ? -a : a;
    temp_b = (b < 0) ? -b : b;

    /* Edge case: both are zero */
    if (temp_a == 0 && temp_b == 0) {
        printf("GCD(0, 0) is undefined.\n");
        return 0;
    }

    /* Euclidean Algorithm */
    int x = temp_a, y = temp_b;
    while (y != 0) {
        int remainder = x % y;
        x = y;
        y = remainder;
    }

    printf("GCD(%d, %d) = %d\n", a, b, x);

    return 0;
}
