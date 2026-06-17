/*
 * Q89: Find First Non-Repeating Character in a String
 * 
 * This program finds the first character in a string that
 * does not repeat anywhere else in the string.
 *
 * Logic:
 *   - First pass: Count frequency of each character using a frequency array
 *   - Second pass: Traverse string again, return the first character
 *     with frequency == 1
 *
 * Edge Cases:
 *   - Empty string (no non-repeating character)
 *   - All characters repeat
 *   - All characters are unique
 *   - Single character string
 */

#include <stdio.h>

/* Function to find the first non-repeating character */
/* Returns the character if found, '\0' if not found */
char firstNonRepeating(const char str[]) {
    int freq[256] = {0};

    /* First pass: count frequency of each character */
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    /* Second pass: find first character with frequency 1 */
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }

    return '\0';  /* No non-repeating character found */
}

/* Function to find the index of first non-repeating character */
/* Returns -1 if not found */
int firstNonRepeatingIndex(const char str[]) {
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    char str[500];

    printf("=== Find First Non-Repeating Character ===\n\n");

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

    char result = firstNonRepeating(str);
    int index = firstNonRepeatingIndex(str);

    if (result != '\0') {
        printf("First non-repeating character: '%c' (at index %d)\n", result, index);
    } else {
        printf("No non-repeating character found.\n");
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char *tests[] = {"", "aabbcc", "abcdef", "aabcbd", "a", "aabb", "swiss"};
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        char ch = firstNonRepeating(tests[i]);
        if (ch != '\0') {
            printf("\"%s\" -> First non-repeating: '%c'\n", tests[i], ch);
        } else {
            printf("\"%s\" -> No non-repeating character\n", tests[i]);
        }
    }

    return 0;
}
