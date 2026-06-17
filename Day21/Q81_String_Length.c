/*
 * Q81: Find String Length Without strlen()
 * 
 * This program calculates the length of a string without using the
 * built-in strlen() function. It iterates through each character
 * until the null terminator '\0' is found.
 *
 * Logic:
 *   - Start a counter at 0
 *   - Traverse each character of the string
 *   - Increment counter until '\0' is encountered
 *   - The counter value is the string length
 *
 * Edge Cases:
 *   - Empty string (length = 0)
 *   - String with only spaces
 *   - Very long strings
 */

#include <stdio.h>

/* Function to find string length without strlen() */
int findStringLength(const char str[]) {
    int length = 0;

    /* Traverse until null terminator is found */
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[500];
    int length;

    printf("=== Find String Length Without strlen() ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline added by fgets */
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    length = findStringLength(str);

    printf("\nThe string: \"%s\"\n", str);
    printf("Length of the string: %d\n", length);

    /* Edge case demonstration */
    printf("\n--- Edge Case Tests ---\n");

    char empty[] = "";
    printf("Empty string \"\" -> Length: %d\n", findStringLength(empty));

    char spaces[] = "   ";
    printf("Spaces \"   \" -> Length: %d\n", findStringLength(spaces));

    char single[] = "A";
    printf("Single char \"A\" -> Length: %d\n", findStringLength(single));

    char sentence[] = "Hello World!";
    printf("\"Hello World!\" -> Length: %d\n", findStringLength(sentence));

    return 0;
}
