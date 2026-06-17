/*
 * Q90: Find First Repeating Character in a String
 * 
 * This program finds the first character in a string that
 * appears more than once.
 *
 * Logic:
 *   - Use a boolean/visited array of size 256 (for ASCII)
 *   - Traverse the string character by character
 *   - If a character was already visited, it's the first repeating one
 *   - If not visited, mark it as visited
 *
 * Edge Cases:
 *   - Empty string
 *   - No repeating characters (all unique)
 *   - All characters are the same
 *   - Single character string
 */

#include <stdio.h>

/* Function to find first repeating character */
/* Returns the character if found, '\0' if not found */
char firstRepeating(const char str[]) {
    int visited[256] = {0};  /* Track which characters have been seen */

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (visited[ch]) {
            return str[i];  /* This character was seen before */
        }
        visited[ch] = 1;  /* Mark as seen */
    }

    return '\0';  /* No repeating character found */
}

/* Function to find index of first repeating character */
int firstRepeatingIndex(const char str[]) {
    int visited[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (visited[ch]) {
            return i;
        }
        visited[ch] = 1;
    }

    return -1;
}

int main() {
    char str[500];

    printf("=== Find First Repeating Character ===\n\n");

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

    char result = firstRepeating(str);
    int index = firstRepeatingIndex(str);

    if (result != '\0') {
        printf("First repeating character: '%c' (at index %d)\n", result, index);
    } else {
        printf("No repeating character found.\n");
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char *tests[] = {"", "abcdef", "aaaa", "abcabc", "a", "abcdb", "hello"};
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        char ch = firstRepeating(tests[i]);
        if (ch != '\0') {
            printf("\"%s\" -> First repeating: '%c'\n", tests[i], ch);
        } else {
            printf("\"%s\" -> No repeating character\n", tests[i]);
        }
    }

    return 0;
}
