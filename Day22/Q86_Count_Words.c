/*
 * Q86: Count Words in a Sentence
 * 
 * This program counts the number of words in a given sentence.
 * Words are separated by spaces (one or more).
 *
 * Logic:
 *   - Track whether we are inside a word or in a space
 *   - When transitioning from space to a non-space character,
 *     a new word is found
 *   - This handles multiple consecutive spaces correctly
 *
 * Edge Cases:
 *   - Empty string (0 words)
 *   - String with only spaces (0 words)
 *   - Leading/trailing spaces
 *   - Multiple spaces between words
 *   - Single word
 */

#include <stdio.h>

/* Function to count words in a string */
int countWords(const char str[]) {
    int count = 0;
    int inWord = 0;  /* Flag: 1 if currently inside a word, 0 otherwise */

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            /* Currently in whitespace */
            inWord = 0;
        } else {
            /* Currently in a non-space character */
            if (!inWord) {
                count++;    /* Start of a new word */
                inWord = 1;
            }
        }
    }

    return count;
}

int main() {
    char str[1000];

    printf("=== Count Words in a Sentence ===\n\n");

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    int words = countWords(str);

    printf("\nSentence: \"%s\"\n", str);
    printf("Number of words: %d\n", words);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char test1[] = "";
    printf("\"%s\" -> %d words\n", test1, countWords(test1));

    char test2[] = "     ";
    printf("\"     \" -> %d words\n", countWords(test2));

    char test3[] = "Hello";
    printf("\"%s\" -> %d words\n", test3, countWords(test3));

    char test4[] = "  Hello   World  ";
    printf("\"%s\" -> %d words\n", test4, countWords(test4));

    char test5[] = "The quick brown fox jumps over the lazy dog";
    printf("\"%s\" -> %d words\n", test5, countWords(test5));

    char test6[] = "One  Two   Three    Four";
    printf("\"%s\" -> %d words\n", test6, countWords(test6));

    return 0;
}
