/*
 * Q45: Write a function for palindrome check
 *
 * Description:
 *   A palindrome number reads the same forwards and backwards.
 *   Example: 121, 1331, 12321 are palindromes.
 *
 * Logic:
 *   - Reverse the number by extracting digits one by one.
 *   - Compare the reversed number with the original.
 *   - If equal, it's a palindrome.
 *
 * Edge Cases:
 *   - Single digit numbers (always palindromes)
 *   - Negative numbers (not palindromes by convention)
 *   - Numbers ending in 0 (e.g., 10, 100 - not palindromes except 0)
 */

#include <stdio.h>

/* Function to reverse a number */
int reverseNumber(int n) {
    int reversed = 0;

    /* Work with absolute value for reversal */
    int num = (n < 0) ? -n : n;

    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }

    return reversed;
}

/* Function to check if a number is a palindrome */
/* Returns 1 if palindrome, 0 otherwise */
int isPalindrome(int n) {
    /* Negative numbers are not palindromes */
    if (n < 0) {
        return 0;
    }

    /* Single digit numbers are always palindromes */
    if (n < 10) {
        return 1;
    }

    /* Numbers ending in 0 are not palindromes (except 0 itself) */
    if (n % 10 == 0) {
        return 0;
    }

    /* Compare number with its reverse */
    return (n == reverseNumber(n));
}

int main() {
    int num;

    printf("=== Palindrome Number Checker ===\n\n");

    /* Read a number from the user */
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Check and display result */
    if (isPalindrome(num)) {
        printf("\n%d is a PALINDROME.\n", num);
        printf("Reading forwards: %d\n", num);
        printf("Reading backwards: %d\n", reverseNumber(num));
    } else {
        printf("\n%d is NOT a palindrome.\n", num);
        if (num >= 0) {
            printf("Reversed: %d (different from %d)\n",
                   reverseNumber(num), num);
        } else {
            printf("(Negative numbers are not palindromes)\n");
        }
    }

    /* Display palindromes in a range */
    printf("\n--- Palindromes from 1 to 200 ---\n");
    int count = 0;
    for (int i = 1; i <= 200; i++) {
        if (isPalindrome(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal palindromes found: %d\n", count);

    return 0;
}
