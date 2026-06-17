/*
 * Q27: Recursive Sum of Digits
 * ------------------------------
 * This program calculates the sum of digits of a given number using recursion.
 * For example: sumOfDigits(1234) = 1 + 2 + 3 + 4 = 10
 *
 * Base case: If n is a single digit (0-9), return n itself.
 * Recursive case: sumOfDigits(n) = (n % 10) + sumOfDigits(n / 10)
 *
 * Edge cases handled:
 *   - Input of 0 (sum is 0)
 *   - Negative numbers (compute sum of absolute value)
 *   - Single digit numbers
 */

#include <stdio.h>

/* Recursive function to compute sum of digits */
int sumOfDigits(int n) {
    /* Handle negative numbers by working with absolute value */
    if (n < 0) {
        n = -n;
    }

    /* Base case: single digit number */
    if (n < 10) {
        return n;
    }

    /* Recursive case: last digit + sum of remaining digits */
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;

    printf("=== Recursive Sum of Digits ===\n\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = sumOfDigits(num);

    /* Show the breakdown */
    printf("\nDigits of %d: ", num < 0 ? -num : num);
    int temp = num < 0 ? -num : num;
    if (temp == 0) {
        printf("0");
    } else {
        /* Extract digits to show them */
        int digits[10];
        int count = 0;
        int t = temp;
        while (t > 0) {
            digits[count++] = t % 10;
            t /= 10;
        }
        /* Print digits from most significant to least significant */
        for (int i = count - 1; i >= 0; i--) {
            printf("%d", digits[i]);
            if (i > 0) printf(" + ");
        }
    }
    printf(" = %d\n", result);

    /* Demonstrate with examples */
    printf("\n--- Additional Examples ---\n");
    int examples[] = {0, 5, 12, 123, 9999, 10001, -456, 123456789};
    int cnt = sizeof(examples) / sizeof(examples[0]);

    for (int i = 0; i < cnt; i++) {
        printf("Sum of digits of %10d = %d\n", examples[i], sumOfDigits(examples[i]));
    }

    return 0;
}
