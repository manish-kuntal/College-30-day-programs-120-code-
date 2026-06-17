/*
 * Q15: Check Armstrong Number (Narcissistic Number)
 * ---------------------------------------------------
 * An Armstrong number (also called narcissistic number) is a number
 * where the sum of its digits each raised to the power of the number
 * of digits equals the number itself.
 *
 * Example: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153 (Armstrong)
 *          9474 = 9^4 + 4^4 + 7^4 + 4^4 = 9474 (Armstrong)
 *
 * Edge cases handled:
 *   - Single-digit numbers (0-9) are all Armstrong numbers.
 *   - Negative numbers: not considered Armstrong numbers.
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n, original, num_digits = 0;
    double sum = 0.0;

    printf("=== Armstrong Number Check ===\n");
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    /* Edge case: negative numbers */
    if (n < 0) {
        printf("%d is NOT an Armstrong number (negative numbers excluded).\n", n);
        return 0;
    }

    original = n;

    /* Step 1: Count the number of digits */
    int temp = n;
    if (temp == 0) {
        num_digits = 1;
    } else {
        while (temp != 0) {
            num_digits++;
            temp /= 10;
        }
    }

    /* Step 2: Sum each digit raised to the power of num_digits */
    temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, num_digits);
        temp /= 10;
    }

    /* Step 3: Compare */
    if ((int)(sum + 0.5) == original) {  /* Adding 0.5 to handle floating point rounding */
        printf("%d is an ARMSTRONG number.\n", original);
        printf("  (%d digits: ", num_digits);
        /* Show the breakdown */
        temp = original;
        int digits[20], idx = 0;
        while (temp != 0) {
            digits[idx++] = temp % 10;
            temp /= 10;
        }
        for (int i = idx - 1; i >= 0; i--) {
            printf("%d^%d", digits[i], num_digits);
            if (i > 0) printf(" + ");
        }
        printf(" = %d)\n", original);
    } else {
        printf("%d is NOT an Armstrong number.\n", original);
    }

    return 0;
}
