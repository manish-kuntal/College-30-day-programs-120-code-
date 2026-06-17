/*
 * Q92: Find Maximum Occurring Character in a String
 * 
 * This program finds the character that occurs most frequently
 * in a given string.
 *
 * Logic:
 *   - Use a frequency array of size 256 for all ASCII characters
 *   - Count occurrences of each character
 *   - Find the character with the highest count
 *   - In case of a tie, return the first one encountered in the string
 *
 * Edge Cases:
 *   - Empty string
 *   - All characters appear once
 *   - Multiple characters with same max frequency
 *   - String with spaces (spaces counted too)
 */

#include <stdio.h>

/* Function to find the maximum occurring character */
/* Returns '\0' if string is empty */
char maxOccurringChar(const char str[]) {
    int freq[256] = {0};

    /* Handle empty string */
    if (str[0] == '\0') {
        return '\0';
    }

    /* Count frequency of each character */
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    /* Find the character with maximum frequency */
    /* Traverse the original string to get the first one in case of tie */
    char maxChar = str[0];
    int maxFreq = freq[(unsigned char)str[0]];

    for (int i = 1; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] > maxFreq) {
            maxFreq = freq[(unsigned char)str[i]];
            maxChar = str[i];
        }
    }

    return maxChar;
}

/* Function to get the frequency of a character in string */
int getFrequency(const char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[500];

    printf("=== Find Maximum Occurring Character ===\n\n");

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

    char result = maxOccurringChar(str);

    if (result != '\0') {
        int freq = getFrequency(str, result);
        if (result == ' ') {
            printf("Maximum occurring character: (space), Frequency: %d\n", freq);
        } else {
            printf("Maximum occurring character: '%c', Frequency: %d\n", result, freq);
        }
    } else {
        printf("String is empty. No maximum occurring character.\n");
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char *tests[] = {"", "abcde", "aabbcc", "aabbbcc", "zzzzz", "hello world"};
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        char ch = maxOccurringChar(tests[i]);
        if (ch != '\0') {
            int freq = getFrequency(tests[i], ch);
            if (ch == ' ') {
                printf("\"%s\" -> Max char: (space), Freq: %d\n", tests[i], freq);
            } else {
                printf("\"%s\" -> Max char: '%c', Freq: %d\n", tests[i], ch, freq);
            }
        } else {
            printf("\"%s\" -> Empty string\n", tests[i]);
        }
    }

    return 0;
}
