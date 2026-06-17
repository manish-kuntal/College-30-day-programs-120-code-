/*
 * Q93: Check if One String is a Rotation of Another
 * 
 * A string s2 is a rotation of s1 if s2 can be obtained by
 * rotating s1 by some number of positions.
 * Example: "erbottlewat" is a rotation of "waterbottle"
 *
 * Logic:
 *   - If lengths differ, they can't be rotations
 *   - Concatenate s1 with itself: s1+s1
 *   - If s2 is a substring of s1+s1, then s2 is a rotation of s1
 *   - This works because s1+s1 contains all possible rotations of s1
 *
 * Edge Cases:
 *   - Different lengths
 *   - Empty strings
 *   - Same string (rotation by 0)
 *   - Single character strings
 */

#include <stdio.h>
#include <string.h>

/* Function to find string length */
int stringLength(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/* Function to check if 'needle' is a substring of 'haystack' */
int isSubstring(const char haystack[], const char needle[]) {
    int hLen = stringLength(haystack);
    int nLen = stringLength(needle);

    if (nLen > hLen) return 0;
    if (nLen == 0) return 1;

    for (int i = 0; i <= hLen - nLen; i++) {
        int j;
        for (j = 0; j < nLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == nLen) {
            return 1;  /* Found needle in haystack */
        }
    }
    return 0;
}

/* Function to check if s2 is a rotation of s1 */
int isRotation(const char s1[], const char s2[]) {
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);

    /* Lengths must be equal and non-zero */
    if (len1 != len2 || len1 == 0) {
        /* Both empty is a special case - could be considered rotation */
        if (len1 == 0 && len2 == 0) return 1;
        return 0;
    }

    /* Concatenate s1 with itself */
    char concat[1001];  /* Max 500 + 500 + 1 */
    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        concat[i] = s1[i];
    }
    for (int j = 0; s1[j] != '\0'; j++) {
        concat[i + j] = s1[j];
    }
    concat[2 * len1] = '\0';

    /* Check if s2 is a substring of concat */
    return isSubstring(concat, s2);
}

int main() {
    char str1[500], str2[500];

    printf("=== Check String Rotation ===\n\n");

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

    if (isRotation(str1, str2)) {
        printf("Result: \"%s\" IS a rotation of \"%s\"\n", str2, str1);
    } else {
        printf("Result: \"%s\" is NOT a rotation of \"%s\"\n", str2, str1);
    }

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    printf("\"waterbottle\" & \"erbottlewat\" -> %s\n",
           isRotation("waterbottle", "erbottlewat") ? "Rotation" : "Not Rotation");
    printf("\"abcde\" & \"cdeab\" -> %s\n",
           isRotation("abcde", "cdeab") ? "Rotation" : "Not Rotation");
    printf("\"abcde\" & \"abced\" -> %s\n",
           isRotation("abcde", "abced") ? "Rotation" : "Not Rotation");
    printf("\"abc\" & \"abcd\" -> %s\n",
           isRotation("abc", "abcd") ? "Rotation" : "Not Rotation");
    printf("\"\" & \"\" -> %s\n",
           isRotation("", "") ? "Rotation" : "Not Rotation");
    printf("\"a\" & \"a\" -> %s\n",
           isRotation("a", "a") ? "Rotation" : "Not Rotation");
    printf("\"hello\" & \"hello\" -> %s\n",
           isRotation("hello", "hello") ? "Rotation" : "Not Rotation");

    return 0;
}
