/*
 * Q6: Reverse a Number
 * ---------------------
 * This program reverses the digits of a given integer.
 * Approach: Extract the last digit, build the reversed number
 *           by multiplying current reversed value by 10 and adding the digit.
 *
 * Edge cases handled:
 *   - n = 0: reversed number is 0.
 *   - Negative numbers: reverse the absolute value, then restore the sign.
 */

#include <stdio.h>

int main() {
    int n, reversed = 0;
    int original, is_negative = 0;

    printf("=== Reverse a Number ===\n");
    printf("Enter an integer: ");
    scanf("%d", &n);

    original = n;

    /* Handle negative numbers */
    if (n < 0) {
        is_negative = 1;
        n = -n;
    }

    /* Reverse the number digit by digit */
    while (n != 0) {
        int digit = n % 10;          /* Extract last digit */
        reversed = reversed * 10 + digit;  /* Append digit to reversed */
        n /= 10;                      /* Remove last digit */
    }

    /* Restore the sign if original was negative */
    if (is_negative) {
        reversed = -reversed;
    }

    printf("Original number : %d\n", original);
    printf("Reversed number : %d\n", reversed);

    return 0;
}
