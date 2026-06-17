/*
 * Q98: Find Common Characters in Two Strings
 * 
 * This program finds and displays characters that are common
 * to both input strings.
 *
 * Logic:
 *   - Create frequency arrays for both strings
 *   - A character is common if it appears in both strings
 *     (frequency > 0 in both arrays)
 *   - The minimum frequency determines how many times
 *     the character is common
 *
 * Edge Cases:
 *   - Empty strings
 *   - No common characters
 *   - Identical strings
 *   - One string is a subset of the other
 *   - Case sensitivity
 */

#include <stdio.h>

/* Function to find and display common characters */
int findCommonChars(const char str1[], const char str2[], char common[]) {
    int freq1[256] = {0};
    int freq2[256] = {0};
    int commonIdx = 0;

    /* Count frequency of characters in both strings */
    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]]++;
    }

    /* Find common characters */
    /* A character is common if it appears in both strings */
    for (int i = 0; i < 256; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            /* Add the character min(freq1, freq2) times */
            int minFreq = (freq1[i] < freq2[i]) ? freq1[i] : freq2[i];
            for (int j = 0; j < minFreq; j++) {
                common[commonIdx++] = (char)i;
            }
        }
    }

    common[commonIdx] = '\0';
    return commonIdx;  /* Return number of common characters */
}

/* Function to find unique common characters (each listed once) */
int findUniqueCommonChars(const char str1[], const char str2[], char common[]) {
    int freq1[256] = {0};
    int freq2[256] = {0};
    int commonIdx = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            common[commonIdx++] = (char)i;
        }
    }

    common[commonIdx] = '\0';
    return commonIdx;
}

int main() {
    char str1[500], str2[500];
    char common[500];

    printf("=== Find Common Characters in Two Strings ===\n\n");

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    /* Remove trailing newlines */
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == '\n') { str1[i] = '\0'; break; }
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] == '\n') { str2[i] = '\0'; break; }
    }

    printf("\nString 1: \"%s\"\n", str1);
    printf("String 2: \"%s\"\n", str2);

    int count = findUniqueCommonChars(str1, str2, common);

    if (count > 0) {
        printf("\nCommon characters (unique): ");
        for (int i = 0; common[i] != '\0'; i++) {
            if (common[i] == ' ') {
                printf("(space) ");
            } else {
                printf("'%c' ", common[i]);
            }
        }
        printf("\nTotal unique common characters: %d\n", count);
    } else {
        printf("\nNo common characters found.\n");
    }

    /* Also show with frequency */
    char commonAll[500];
    int totalCount = findCommonChars(str1, str2, commonAll);
    if (totalCount > 0) {
        printf("Common characters (with repetition): \"%s\" (count: %d)\n", commonAll, totalCount);
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char result[500];

    findUniqueCommonChars("hello", "world", result);
    printf("\"hello\" & \"world\" -> Common: \"%s\"\n", result);

    findUniqueCommonChars("abc", "xyz", result);
    printf("\"abc\" & \"xyz\" -> Common: \"%s\"\n", result);

    findUniqueCommonChars("", "abc", result);
    printf("\"\" & \"abc\" -> Common: \"%s\"\n", result);

    findUniqueCommonChars("abcdef", "abcdef", result);
    printf("\"abcdef\" & \"abcdef\" -> Common: \"%s\"\n", result);

    findUniqueCommonChars("aab", "ab", result);
    printf("\"aab\" & \"ab\" -> Common: \"%s\"\n", result);

    return 0;
}
