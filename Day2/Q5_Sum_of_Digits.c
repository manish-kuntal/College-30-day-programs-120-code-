/*
 * Q5: Sum of Digits of a Number
 * ------------------------------
 * This program finds the sum of all digits of a given integer.
 * Approach: Extract each digit using modulo 10, add it to sum,
 *           then remove the last digit by dividing by 10.
 *
 * Edge cases handled:
 *   - n = 0: sum of digits is 0.
 *   - Negative numbers: we take the absolute value first.
 */

#include <stdio.h>

int main() {
    int n, sum = 0;
    int original;

    printf("=== Sum of Digits ===\n");
    printf("Enter an integer: ");
    scanf("%d", &n);

    original = n;

    /* Handle negative numbers */
    if (n < 0) {
        n = -n;
    }

    /* Extract digits and accumulate their sum */
    while (n != 0) {
        int digit = n % 10;  /* Get the last digit */
        sum += digit;
        n /= 10;             /* Remove the last digit */
    }

    printf("Sum of digits of %d = %d\n", original, sum);

    return 0;
}
