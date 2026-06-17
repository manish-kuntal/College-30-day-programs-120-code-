/*
 * Q8: Check Whether a Number is a Palindrome
 * --------------------------------------------
 * A palindrome number reads the same forwards and backwards.
 * Example: 121, 1331, 12321 are palindromes; 123, 100 are not.
 *
 * Approach: Reverse the number and compare with the original.
 *
 * Edge cases handled:
 *   - n = 0: 0 is a palindrome.
 *   - Negative numbers: considered not palindromes (e.g., -121 != 121-).
 */

#include <stdio.h>

int main() {
    int n, reversed = 0, original;

    printf("=== Palindrome Number Check ===\n");
    printf("Enter an integer: ");
    scanf("%d", &n);

    original = n;

    /* Negative numbers are not palindromes */
    if (n < 0) {
        printf("%d is NOT a palindrome (negative numbers cannot be palindromes).\n", n);
        return 0;
    }

    /* Reverse the number */
    int temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    /* Compare original with reversed */
    if (original == reversed) {
        printf("%d is a PALINDROME.\n", original);
    } else {
        printf("%d is NOT a palindrome.\n", original);
        printf("  (Reversed: %d)\n", reversed);
    }

    return 0;
}
