/*
 * Q100: Sort Words by Length
 * 
 * This program takes a sentence, extracts individual words,
 * and sorts them by their length (shortest first).
 *
 * Logic:
 *   - Extract words from the sentence into a 2D array
 *   - Calculate the length of each word
 *   - Sort the words array using bubble sort, comparing lengths
 *   - Display the sorted words
 *
 * Edge Cases:
 *   - Empty string
 *   - Single word
 *   - Multiple words of same length (maintain relative order for stability)
 *   - Leading/trailing spaces
 *   - Multiple spaces between words
 */

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 100

/* Function to find string length */
int strLen(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/* Function to extract words from a sentence */
int extractWords(const char sentence[], char words[][MAX_WORD_LEN]) {
    int wordCount = 0;
    int i = 0;
    int wordIdx;

    while (sentence[i] != '\0') {
        /* Skip whitespace */
        while (sentence[i] == ' ' || sentence[i] == '\t') {
            i++;
        }

        if (sentence[i] == '\0') break;

        /* Extract word */
        wordIdx = 0;
        while (sentence[i] != '\0' && sentence[i] != ' ' && sentence[i] != '\t') {
            if (wordIdx < MAX_WORD_LEN - 1) {
                words[wordCount][wordIdx++] = sentence[i];
            }
            i++;
        }
        words[wordCount][wordIdx] = '\0';
        wordCount++;

        if (wordCount >= MAX_WORDS) break;
    }

    return wordCount;
}

/* Function to swap two strings */
void swapWords(char a[], char b[]) {
    char temp[MAX_WORD_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

/* Function to sort words by length using bubble sort */
/* Uses stable sort (only swaps when strictly greater) to maintain */
/* relative order of equal-length words */
void sortWordsByLength(char words[][MAX_WORD_LEN], int count) {
    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < count - 1 - i; j++) {
            if (strLen(words[j]) > strLen(words[j + 1])) {
                swapWords(words[j], words[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;  /* Already sorted */
    }
}

/* Function to display words with their lengths */
void displayWords(char words[][MAX_WORD_LEN], int count) {
    for (int i = 0; i < count; i++) {
        printf("  \"%s\" (length: %d)\n", words[i], strLen(words[i]));
    }
}

int main() {
    char sentence[1000];
    char words[MAX_WORDS][MAX_WORD_LEN];

    printf("=== Sort Words by Length ===\n\n");

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    /* Remove trailing newline */
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == '\n') {
            sentence[i] = '\0';
            break;
        }
    }

    printf("\nSentence: \"%s\"\n", sentence);

    /* Extract words */
    int wordCount = extractWords(sentence, words);

    if (wordCount == 0) {
        printf("No words found in the sentence.\n");
        return 0;
    }

    printf("\nWords before sorting:\n");
    displayWords(words, wordCount);

    /* Sort by length */
    sortWordsByLength(words, wordCount);

    printf("\nWords after sorting by length (shortest first):\n");
    displayWords(words, wordCount);

    /* Reconstruct sorted sentence */
    printf("\nSorted sentence: ");
    for (int i = 0; i < wordCount; i++) {
        printf("%s", words[i]);
        if (i < wordCount - 1) printf(" ");
    }
    printf("\n");

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char *tests[] = {
        "",
        "Hello",
        "I am a programmer",
        "The quick brown fox jumps",
        "  extra   spaces   here  ",
        "cat bat hat mat"
    };
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int t = 0; t < numTests; t++) {
        char testWords[MAX_WORDS][MAX_WORD_LEN];
        int count = extractWords(tests[t], testWords);

        sortWordsByLength(testWords, count);

        printf("\"%s\" -> ", tests[t]);
        if (count == 0) {
            printf("(no words)");
        } else {
            for (int i = 0; i < count; i++) {
                printf("%s(%d)", testWords[i], strLen(testWords[i]));
                if (i < count - 1) printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
