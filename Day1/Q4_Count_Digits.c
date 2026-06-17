/*
 * Q4: Count Digits in a Number
 * -----------------------------
 * This program counts the number of digits in a given integer.
 * Approach: Repeatedly divide the number by 10 until it becomes 0.
 *
 * Edge cases handled:
 *   - n = 0: has exactly 1 digit.
 *   - Negative numbers: we take the absolute value first.
 */

#include <stdio.h>

int main() {
    int n, count = 0;
    int original;

    printf("=== Count Digits in a Number ===\n");
    printf("Enter an integer: ");
    scanf("%d", &n);

    original = n;

    /* Edge case: if the number is 0, it has exactly 1 digit */
    if (n == 0) {
        count = 1;
    } else {
        /* Handle negative numbers by making them positive */
        if (n < 0) {
            n = -n;
        }

        /* Count digits by repeatedly dividing by 10 */
        while (n != 0) {
            n /= 10;
            count++;
        }
    }

    printf("Number of digits in %d: %d\n", original, count);

    return 0;
}
