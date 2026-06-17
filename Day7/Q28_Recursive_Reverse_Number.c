/*
 * Q28: Recursive Reverse Number
 * -------------------------------
 * This program reverses a given number using recursion.
 * For example: reverse(1234) = 4321
 *
 * Approach: Use a helper function with an accumulator.
 * Each recursive call extracts the last digit and builds the reversed number.
 *
 * Base case: If n is 0, return the accumulated reversed number.
 * Recursive case: reverseHelper(n / 10, reversed * 10 + n % 10)
 *
 * Edge cases handled:
 *   - Input of 0 (reversed is 0)
 *   - Negative numbers (reverse the magnitude, keep the sign)
 *   - Numbers ending in 0 (trailing zeros become leading zeros and are dropped)
 *   - Single digit numbers
 */

#include <stdio.h>

/*
 * Helper function with accumulator for building the reversed number.
 * 'reversed' accumulates the result as we strip digits from 'n'.
 */
int reverseHelper(int n, int reversed) {
    /* Base case: no more digits to process */
    if (n == 0) {
        return reversed;
    }

    /* Extract last digit and add it to the reversed number */
    return reverseHelper(n / 10, reversed * 10 + (n % 10));
}

/* Wrapper function to handle negative numbers */
int reverseNumber(int n) {
    if (n < 0) {
        return -reverseHelper(-n, 0); /* Reverse magnitude, keep sign */
    }
    return reverseHelper(n, 0);
}

int main() {
    int num;

    printf("=== Recursive Reverse Number ===\n\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    int reversed = reverseNumber(num);
    printf("Original number:  %d\n", num);
    printf("Reversed number:  %d\n", reversed);

    if (num > 0 && num % 10 == 0) {
        printf("Note: Trailing zeros in %d become leading zeros and are dropped.\n", num);
    }

    /* Demonstrate with examples */
    printf("\n--- Additional Examples ---\n");
    printf("%-15s %s\n", "Original", "Reversed");
    printf("%-15s %s\n", "--------", "--------");

    int examples[] = {0, 5, 12, 123, 1000, 12345, -678, 100200, 9876543};
    int count = sizeof(examples) / sizeof(examples[0]);

    for (int i = 0; i < count; i++) {
        printf("%-15d %d\n", examples[i], reverseNumber(examples[i]));
    }

    return 0;
}
