/*
 * Q91: Check if Two Strings are Anagrams
 * 
 * Two strings are anagrams if they contain the same characters
 * with the same frequencies, just in a different order.
 * Example: "listen" and "silent" are anagrams.
 *
 * Logic:
 *   - First check: if lengths differ, they can't be anagrams
 *   - Count frequency of each character in the first string (increment)
 *   - Count frequency of each character in the second string (decrement)
 *   - If all frequencies are zero, the strings are anagrams
 *
 * Edge Cases:
 *   - Different lengths
 *   - Empty strings (both empty = anagram)
 *   - Same string
 *   - Case-insensitive comparison
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

/* Function to check if two strings are anagrams (case-insensitive) */
int areAnagrams(const char str1[], const char str2[]) {
    int freq[256] = {0};

    /* Check if lengths are equal */
    if (stringLength(str1) != stringLength(str2)) {
        return 0;  /* Different lengths cannot be anagrams */
    }

    /* Increment frequency for str1, decrement for str2 */
    for (int i = 0; str1[i] != '\0'; i++) {
        freq[(unsigned char)tolower(str1[i])]++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        freq[(unsigned char)tolower(str2[i])]--;
    }

    /* Check if all frequencies are zero */
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            return 0;  /* Not an anagram */
        }
    }

    return 1;  /* Is an anagram */
}

int main() {
    char str1[500], str2[500];

    printf("=== Check if Two Strings are Anagrams ===\n\n");

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

    if (areAnagrams(str1, str2)) {
        printf("Result: The strings ARE anagrams!\n");
    } else {
        printf("Result: The strings are NOT anagrams.\n");
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    printf("\"listen\" & \"silent\" -> %s\n",
           areAnagrams("listen", "silent") ? "Anagrams" : "Not Anagrams");
    printf("\"Hello\" & \"World\" -> %s\n",
           areAnagrams("Hello", "World") ? "Anagrams" : "Not Anagrams");
    printf("\"\" & \"\" -> %s\n",
           areAnagrams("", "") ? "Anagrams" : "Not Anagrams");
    printf("\"abc\" & \"abcd\" -> %s\n",
           areAnagrams("abc", "abcd") ? "Anagrams" : "Not Anagrams");
    printf("\"Triangle\" & \"Integral\" -> %s\n",
           areAnagrams("Triangle", "Integral") ? "Anagrams" : "Not Anagrams");
    printf("\"aaa\" & \"aaa\" -> %s\n",
           areAnagrams("aaa", "aaa") ? "Anagrams" : "Not Anagrams");
    printf("\"Dormitory\" & \"Dirty Room\" -> %s\n",
           areAnagrams("Dormitory", "Dirty Room") ? "Anagrams" : "Not Anagrams");

    return 0;
}
