/*
 * Q95: Find the Longest Word in a Sentence
 * 
 * This program finds and displays the longest word in a given sentence.
 * Words are separated by spaces.
 *
 * Logic:
 *   - Traverse the string tracking the start and length of each word
 *   - When a space or end of string is encountered, compare current
 *     word length with the maximum found so far
 *   - Keep track of the start position and length of the longest word
 *   - Extract and display the longest word
 *
 * Edge Cases:
 *   - Empty string
 *   - Single word
 *   - Multiple words of same length (returns first one)
 *   - Leading/trailing spaces
 *   - Multiple spaces between words
 */

#include <stdio.h>

/* Function to find the longest word in a sentence */
void findLongestWord(const char str[], char longest[]) {
    int maxLen = 0;
    int maxStart = 0;
    int currentLen = 0;
    int currentStart = 0;
    int inWord = 0;

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            /* Inside a word */
            if (!inWord) {
                currentStart = i;  /* Mark start of new word */
                currentLen = 0;
                inWord = 1;
            }
            currentLen++;
        } else {
            /* End of a word or end of string */
            if (inWord) {
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    maxStart = currentStart;
                }
                inWord = 0;
            }
        }

        if (str[i] == '\0') break;
    }

    /* Copy the longest word to the output */
    for (int i = 0; i < maxLen; i++) {
        longest[i] = str[maxStart + i];
    }
    longest[maxLen] = '\0';
}

int main() {
    char str[1000];
    char longest[500];

    printf("=== Find Longest Word in a Sentence ===\n\n");

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    findLongestWord(str, longest);

    printf("\nSentence: \"%s\"\n", str);

    if (longest[0] != '\0') {
        /* Calculate length for display */
        int len = 0;
        while (longest[len] != '\0') len++;
        printf("Longest word: \"%s\" (length: %d)\n", longest, len);
    } else {
        printf("No words found in the string.\n");
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char *tests[] = {
        "",
        "Hello",
        "The quick brown fox",
        "I am a programmer",
        "  leading   spaces  ",
        "cat bat hat mat",
        "extraordinary programming achievement"
    };
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        findLongestWord(tests[i], longest);
        if (longest[0] != '\0') {
            printf("\"%s\" -> Longest: \"%s\"\n", tests[i], longest);
        } else {
            printf("\"%s\" -> No words found\n", tests[i]);
        }
    }

    return 0;
}
