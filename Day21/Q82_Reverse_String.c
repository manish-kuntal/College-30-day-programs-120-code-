/*
 * Q82: Reverse a String
 * 
 * This program reverses a given string in-place using the
 * two-pointer (swap) technique.
 *
 * Logic:
 *   - Place one pointer at the start and another at the end
 *   - Swap the characters at both pointers
 *   - Move pointers towards the center until they meet
 *
 * Edge Cases:
 *   - Empty string
 *   - Single character string (already reversed)
 *   - Palindrome string (same after reversal)
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

/* Function to reverse a string in-place */
void reverseString(char str[]) {
    int len = stringLength(str);
    int start = 0;
    int end = len - 1;
    char temp;

    /* Swap characters from both ends moving towards center */
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[500];

    printf("=== Reverse a String ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    printf("Original string: \"%s\"\n", str);

    reverseString(str);

    printf("Reversed string: \"%s\"\n", str);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char empty[] = "";
    printf("Original: \"%s\" -> ", empty);
    reverseString(empty);
    printf("Reversed: \"%s\"\n", empty);

    char single[] = "A";
    printf("Original: \"%s\" -> ", single);
    reverseString(single);
    printf("Reversed: \"%s\"\n", single);

    char palindrome[] = "madam";
    printf("Original: \"%s\" -> ", palindrome);
    reverseString(palindrome);
    printf("Reversed: \"%s\" (palindrome)\n", palindrome);

    char numbers[] = "12345";
    printf("Original: \"%s\" -> ", numbers);
    reverseString(numbers);
    printf("Reversed: \"%s\"\n", numbers);

    return 0;
}
