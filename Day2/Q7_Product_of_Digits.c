/*
 * Q7: Product of Digits
 * ----------------------
 * This program finds the product of all digits of a given integer.
 * Approach: Extract each digit using modulo 10, multiply it into the product,
 *           then remove the last digit by dividing by 10.
 *
 * Edge cases handled:
 *   - n = 0: product is 0 (since one of the digits is 0).
 *   - Negative numbers: we take the absolute value first.
 *   - Any number containing digit 0 will result in product = 0.
 */

#include <stdio.h>

int main() {
    int n;
    long long product = 1;
    int original;

    printf("=== Product of Digits ===\n");
    printf("Enter an integer: ");
    scanf("%d", &n);

    original = n;

    /* Special case: if the number is 0 itself */
    if (n == 0) {
        printf("Product of digits of %d = 0\n", original);
        return 0;
    }

    /* Handle negative numbers */
    if (n < 0) {
        n = -n;
    }

    /* Extract digits and multiply them together */
    while (n != 0) {
        int digit = n % 10;  /* Get the last digit */
        product *= digit;
        n /= 10;             /* Remove the last digit */
    }

    printf("Product of digits of %d = %lld\n", original, product);

    return 0;
}
