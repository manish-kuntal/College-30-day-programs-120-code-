/*
 * Q85: Check Palindrome String
 * 
 * A palindrome reads the same forwards and backwards.
 * This program checks whether a given string is a palindrome.
 *
 * Logic:
 *   - Compare the first character with the last, second with second-last, etc.
 *   - If all corresponding characters match, it's a palindrome
 *   - Stop when the two pointers meet or cross
 *
 * Edge Cases:
 *   - Empty string (considered palindrome)
 *   - Single character (always palindrome)
 *   - Case-sensitive comparison
 *   - Even and odd length strings
 */

#include <stdio.h>
#include <ctype.h>

/* Function to find string length */
int stringLength(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/* Function to check if a string is a palindrome (case-insensitive) */
int isPalindrome(const char str[]) {
    int len = stringLength(str);
    int start = 0;
    int end = len - 1;

    /* Empty or single character strings are palindromes */
    if (len <= 1) {
        return 1;
    }

    while (start < end) {
        /* Case-insensitive comparison */
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;  /* Not a palindrome */
        }
        start++;
        end--;
    }

    return 1;  /* Is a palindrome */
}

int main() {
    char str[500];

    printf("=== Check Palindrome String ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    printf("\nString: \"%s\"\n", str);

    if (isPalindrome(str)) {
        printf("Result: It IS a palindrome!\n");
    } else {
        printf("Result: It is NOT a palindrome.\n");
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char *tests[] = {"madam", "racecar", "hello", "", "A", "AbBa", "12321", "abcba", "abcda"};
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        printf("\"%s\" -> %s\n", tests[i],
               isPalindrome(tests[i]) ? "Palindrome" : "Not Palindrome");
    }

    return 0;
}
