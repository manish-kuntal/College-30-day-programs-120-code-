/*
 * Q87: Find Character Frequency in a String
 * 
 * This program finds and displays the frequency (count) of each
 * character in a given string.
 *
 * Logic:
 *   - Use an array of size 256 (all ASCII characters) as a frequency table
 *   - Traverse the string and increment the count for each character
 *   - Display characters that have frequency > 0
 *
 * Edge Cases:
 *   - Empty string
 *   - String with all same characters
 *   - String with special characters and digits
 *   - Case-sensitive counting
 */

#include <stdio.h>

/* Function to calculate and display character frequency */
void characterFrequency(const char str[]) {
    int freq[256] = {0};  /* Frequency array for all ASCII characters */

    /* Count frequency of each character */
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    /* Display characters with non-zero frequency */
    printf("Character frequencies:\n");
    printf("%-12s %s\n", "Character", "Frequency");
    printf("%-12s %s\n", "---------", "---------");

    int found = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            found = 1;
            if (i == ' ') {
                printf("%-12s %d\n", "(space)", freq[i]);
            } else if (i == '\t') {
                printf("%-12s %d\n", "(tab)", freq[i]);
            } else {
                printf("'%c'          %d\n", (char)i, freq[i]);
            }
        }
    }

    if (!found) {
        printf("(empty string - no characters)\n");
    }
}

int main() {
    char str[500];

    printf("=== Character Frequency in a String ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    printf("\nString: \"%s\"\n\n", str);
    characterFrequency(str);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n\n");

    printf("Test: Empty string \"\"\n");
    characterFrequency("");

    printf("\nTest: \"aaaa\"\n");
    characterFrequency("aaaa");

    printf("\nTest: \"aAbBcC\"\n");
    characterFrequency("aAbBcC");

    return 0;
}
