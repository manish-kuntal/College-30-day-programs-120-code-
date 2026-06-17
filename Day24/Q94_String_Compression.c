/*
 * Q94: String Compression (Run-Length Encoding)
 * 
 * Compress a string by replacing consecutive repeated characters
 * with the character followed by its count.
 * Example: "aabcccccaaa" -> "a2b1c5a3"
 *
 * Logic:
 *   - Traverse the string keeping track of the current character
 *   - Count consecutive occurrences of each character
 *   - When a different character is found, write the character and its count
 *   - If compressed string is not shorter, return original
 *
 * Edge Cases:
 *   - Empty string
 *   - All unique characters (compression may be longer)
 *   - Single character
 *   - All same characters
 *   - Count > 9 (multi-digit counts)
 */

#include <stdio.h>

/* Function to find string length */
int stringLength(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/* Helper function to convert integer to string and append to buffer */
/* Returns number of characters written */
int intToStr(char buffer[], int pos, int num) {
    char temp[20];
    int digits = 0;

    /* Handle the number -> string conversion */
    if (num == 0) {
        buffer[pos] = '0';
        return 1;
    }

    /* Extract digits in reverse */
    while (num > 0) {
        temp[digits++] = '0' + (num % 10);
        num /= 10;
    }

    /* Write digits in correct order */
    for (int i = digits - 1; i >= 0; i--) {
        buffer[pos + (digits - 1 - i)] = temp[i];
    }

    return digits;
}

/* Function to compress a string */
void compressString(const char input[], char output[]) {
    int len = stringLength(input);

    /* Handle empty string */
    if (len == 0) {
        output[0] = '\0';
        return;
    }

    int outIdx = 0;
    int i = 0;

    while (i < len) {
        char currentChar = input[i];
        int count = 0;

        /* Count consecutive occurrences */
        while (i < len && input[i] == currentChar) {
            count++;
            i++;
        }

        /* Write character */
        output[outIdx++] = currentChar;

        /* Write count */
        outIdx += intToStr(output, outIdx, count);
    }
    output[outIdx] = '\0';

    /* If compressed is not shorter, copy original */
    if (stringLength(output) >= len) {
        for (int j = 0; j <= len; j++) {
            output[j] = input[j];
        }
    }
}

int main() {
    char str[500];
    char compressed[1000];

    printf("=== String Compression (Run-Length Encoding) ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    compressString(str, compressed);

    printf("\nOriginal string:   \"%s\"\n", str);
    printf("Compressed string: \"%s\"\n", compressed);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char result[1000];

    char t1[] = "aabcccccaaa";
    compressString(t1, result);
    printf("\"%s\" -> \"%s\"\n", t1, result);

    char t2[] = "";
    compressString(t2, result);
    printf("\"\" -> \"%s\"\n", result);

    char t3[] = "abcdef";
    compressString(t3, result);
    printf("\"%s\" -> \"%s\" (not shorter, returns original)\n", t3, result);

    char t4[] = "a";
    compressString(t4, result);
    printf("\"%s\" -> \"%s\"\n", t4, result);

    char t5[] = "aaaaaaaaaaaa";
    compressString(t5, result);
    printf("\"%s\" -> \"%s\"\n", t5, result);

    char t6[] = "aaabbbccc";
    compressString(t6, result);
    printf("\"%s\" -> \"%s\"\n", t6, result);

    char t7[] = "aabb";
    compressString(t7, result);
    printf("\"%s\" -> \"%s\" (same length, returns original)\n", t7, result);

    return 0;
}
