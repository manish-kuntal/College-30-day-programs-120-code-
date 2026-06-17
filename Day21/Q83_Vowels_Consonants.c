/*
 * Q83: Count Vowels and Consonants in a String
 * 
 * This program counts the number of vowels and consonants
 * in a given string. Non-alphabetic characters are ignored.
 *
 * Logic:
 *   - Traverse each character of the string
 *   - Check if it is an alphabet character
 *   - If yes, check if it is a vowel (a, e, i, o, u) or consonant
 *   - Increment the respective counter
 *
 * Edge Cases:
 *   - Empty string
 *   - String with only digits/special characters
 *   - Mixed case (both upper and lower)
 *   - String with only vowels or only consonants
 */

#include <stdio.h>
#include <ctype.h>  /* For tolower() and isalpha() */

/* Function to check if a character is a vowel */
int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

/* Function to count vowels and consonants */
void countVowelsConsonants(const char str[], int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isVowel(str[i])) {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
        /* Non-alphabetic characters are skipped */
    }
}

int main() {
    char str[500];
    int vowels, consonants;

    printf("=== Count Vowels and Consonants ===\n\n");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    countVowelsConsonants(str, &vowels, &consonants);

    printf("\nString: \"%s\"\n", str);
    printf("Vowels:     %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    char test1[] = "";
    countVowelsConsonants(test1, &vowels, &consonants);
    printf("\"\" -> Vowels: %d, Consonants: %d\n", vowels, consonants);

    char test2[] = "12345!@#";
    countVowelsConsonants(test2, &vowels, &consonants);
    printf("\"12345!@#\" -> Vowels: %d, Consonants: %d\n", vowels, consonants);

    char test3[] = "aeiouAEIOU";
    countVowelsConsonants(test3, &vowels, &consonants);
    printf("\"aeiouAEIOU\" -> Vowels: %d, Consonants: %d\n", vowels, consonants);

    char test4[] = "bcdfg";
    countVowelsConsonants(test4, &vowels, &consonants);
    printf("\"bcdfg\" -> Vowels: %d, Consonants: %d\n", vowels, consonants);

    char test5[] = "Hello World 123";
    countVowelsConsonants(test5, &vowels, &consonants);
    printf("\"Hello World 123\" -> Vowels: %d, Consonants: %d\n", vowels, consonants);

    return 0;
}
