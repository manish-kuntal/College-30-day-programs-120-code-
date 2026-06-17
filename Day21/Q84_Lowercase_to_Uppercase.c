/*
 * Q84: Convert Lowercase to Uppercase
 * 
 * This program converts all lowercase letters in a string
 * to uppercase without using toupper().
 *
 * Logic:
 *   - ASCII value of 'a' is 97, 'A' is 65 (difference = 32)
 *   - For each lowercase character ('a' to 'z'), subtract 32
 *     to get the corresponding uppercase character
 *   - Non-lowercase characters remain unchanged
 *
 * Edge Cases:
 *   - Already uppercase string
 *   - String with digits and special characters
 *   - Mixed case string
 *   - Empty string
 */

#include <stdio.h>

/* Function to convert lowercase to uppercase without toupper() */
void toLowerToUpper(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        /* Check if character is lowercase (ASCII 97-122) */
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  /* Convert to uppercase */
        }
        /* All other characters remain unchanged */
    }
}

int main() {
    char str[500];

    printf("=== Convert Lowercase to Uppercase ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    printf("Original string:  \"%s\"\n", str);

    toLowerToUpper(str);

    printf("Uppercase string: \"%s\"\n", str);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char test1[] = "ALREADY UPPER";
    printf("Original: \"%s\" -> ", test1);
    toLowerToUpper(test1);
    printf("Result: \"%s\"\n", test1);

    char test2[] = "hello world";
    printf("Original: \"%s\" -> ", test2);
    toLowerToUpper(test2);
    printf("Result: \"%s\"\n", test2);

    char test3[] = "Hello World 123!";
    printf("Original: \"%s\" -> ", test3);
    toLowerToUpper(test3);
    printf("Result: \"%s\"\n", test3);

    char test4[] = "";
    printf("Original: \"%s\" -> ", test4);
    toLowerToUpper(test4);
    printf("Result: \"%s\"\n", test4);

    char test5[] = "a1b2c3!@#";
    printf("Original: \"%s\" -> ", test5);
    toLowerToUpper(test5);
    printf("Result: \"%s\"\n", test5);

    return 0;
}
