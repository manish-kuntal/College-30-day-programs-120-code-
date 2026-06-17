/*
 * Q96: Remove Duplicate Characters from a String
 * 
 * This program removes duplicate characters from a string,
 * keeping only the first occurrence of each character.
 * Example: "programming" -> "progamin"
 *
 * Logic:
 *   - Use a boolean/seen array of size 256 (for ASCII)
 *   - Traverse the string with two indices: read and write
 *   - If a character hasn't been seen, write it and mark as seen
 *   - Skip characters that have already been seen
 *   - Null-terminate the result
 *
 * Edge Cases:
 *   - Empty string
 *   - All unique characters
 *   - All same characters
 *   - Single character
 *   - String with spaces
 */

#include <stdio.h>

/* Function to remove duplicate characters (in-place) */
void removeDuplicates(char str[]) {
    int seen[256] = {0};  /* Track seen characters */
    int writeIdx = 0;

    for (int readIdx = 0; str[readIdx] != '\0'; readIdx++) {
        unsigned char ch = (unsigned char)str[readIdx];

        if (!seen[ch]) {
            /* First occurrence - keep it */
            seen[ch] = 1;
            str[writeIdx] = str[readIdx];
            writeIdx++;
        }
        /* Duplicate - skip it */
    }

    str[writeIdx] = '\0';  /* Null-terminate */
}

/* Function to remove duplicates and store result in a new array */
void removeDuplicatesCopy(const char src[], char dest[]) {
    int seen[256] = {0};
    int writeIdx = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)src[i];

        if (!seen[ch]) {
            seen[ch] = 1;
            dest[writeIdx] = src[i];
            writeIdx++;
        }
    }

    dest[writeIdx] = '\0';
}

int main() {
    char str[500];
    char result[500];

    printf("=== Remove Duplicate Characters from String ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    /* Use copy version to preserve original */
    removeDuplicatesCopy(str, result);

    printf("\nOriginal string:            \"%s\"\n", str);
    printf("After removing duplicates:  \"%s\"\n", result);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char t1[] = "";
    removeDuplicates(t1);
    printf("\"\" -> \"%s\"\n", t1);

    char t2[] = "abcdef";
    printf("\"abcdef\" -> ");
    removeDuplicates(t2);
    printf("\"%s\" (all unique)\n", t2);

    char t3[] = "aaaa";
    printf("\"aaaa\" -> ");
    removeDuplicates(t3);
    printf("\"%s\"\n", t3);

    char t4[] = "a";
    printf("\"a\" -> ");
    removeDuplicates(t4);
    printf("\"%s\"\n", t4);

    char t5[] = "programming";
    printf("\"programming\" -> ");
    removeDuplicates(t5);
    printf("\"%s\"\n", t5);

    char t6[] = "hello world";
    printf("\"hello world\" -> ");
    removeDuplicates(t6);
    printf("\"%s\"\n", t6);

    char t7[] = "aabbccdd";
    printf("\"aabbccdd\" -> ");
    removeDuplicates(t7);
    printf("\"%s\"\n", t7);

    return 0;
}
