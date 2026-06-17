/*
 * Q88: Remove Spaces from a String
 * 
 * This program removes all space characters from a given string.
 *
 * Logic:
 *   - Use two indices: one for reading (i) and one for writing (j)
 *   - Traverse the string with the read index
 *   - If the character is not a space, copy it to the write position
 *   - Increment write index only for non-space characters
 *   - Null-terminate the result at the write position
 *
 * Edge Cases:
 *   - Empty string
 *   - String with only spaces
 *   - String with no spaces
 *   - Leading, trailing, and multiple consecutive spaces
 */

#include <stdio.h>

/* Function to remove all spaces from a string (in-place) */
void removeSpaces(char str[]) {
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';  /* Null-terminate the modified string */
}

/* Function to remove spaces and store result in a new array */
void removeSpacesCopy(const char src[], char dest[]) {
    int i, j = 0;

    for (i = 0; src[i] != '\0'; i++) {
        if (src[i] != ' ') {
            dest[j] = src[i];
            j++;
        }
    }
    dest[j] = '\0';
}

int main() {
    char str[500];
    char result[500];

    printf("=== Remove Spaces from a String ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    /* Use copy version to preserve original for display */
    removeSpacesCopy(str, result);

    printf("\nOriginal string:       \"%s\"\n", str);
    printf("After removing spaces: \"%s\"\n", result);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char test1[] = "";
    removeSpaces(test1);
    printf("\"\" -> \"%s\"\n", test1);

    char test2[] = "     ";
    printf("\"     \" -> ");
    removeSpaces(test2);
    printf("\"%s\"\n", test2);

    char test3[] = "NoSpacesHere";
    printf("\"NoSpacesHere\" -> ");
    removeSpaces(test3);
    printf("\"%s\"\n", test3);

    char test4[] = "  Hello   World  ";
    printf("\"  Hello   World  \" -> ");
    removeSpaces(test4);
    printf("\"%s\"\n", test4);

    char test5[] = "A B C D E";
    printf("\"A B C D E\" -> ");
    removeSpaces(test5);
    printf("\"%s\"\n", test5);

    return 0;
}
