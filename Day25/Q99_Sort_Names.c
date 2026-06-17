/*
 * Q99: Sort Names Alphabetically (Array of Strings)
 * 
 * This program sorts an array of names/strings in alphabetical
 * (lexicographic) order using bubble sort.
 *
 * Logic:
 *   - Store names in a 2D character array
 *   - Use bubble sort to compare adjacent names
 *   - Use strcmp() (or custom comparison) to compare strings
 *   - Swap entire strings when they are out of order
 *
 * Edge Cases:
 *   - Single name (already sorted)
 *   - Already sorted list
 *   - Reverse sorted list
 *   - Names with same prefix
 *   - Case-sensitive sorting
 */

#include <stdio.h>
#include <string.h>

#define MAX_NAMES 50
#define MAX_LEN 100

/* Custom string comparison function (case-insensitive) */
int compareStringsIgnoreCase(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        char ca = a[i], cb = b[i];

        /* Convert to lowercase for comparison */
        if (ca >= 'A' && ca <= 'Z') ca += 32;
        if (cb >= 'A' && cb <= 'Z') cb += 32;

        if (ca != cb) {
            return ca - cb;
        }
        i++;
    }
    return a[i] - b[i];
}

/* Function to swap two strings */
void swapStrings(char a[], char b[]) {
    char temp[MAX_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

/* Function to sort names alphabetically using bubble sort */
void sortNames(char names[][MAX_LEN], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (compareStringsIgnoreCase(names[j], names[j + 1]) > 0) {
                swapStrings(names[j], names[j + 1]);
                swapped = 1;
            }
        }
        /* Optimization: if no swaps occurred, array is sorted */
        if (!swapped) break;
    }
}

/* Function to print names array */
void printNames(char names[][MAX_LEN], int n) {
    for (int i = 0; i < n; i++) {
        printf("  %d. %s\n", i + 1, names[i]);
    }
}

int main() {
    char names[MAX_NAMES][MAX_LEN];
    int n;

    printf("=== Sort Names Alphabetically ===\n\n");

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();  /* Consume newline left by scanf */

    if (n <= 0 || n > MAX_NAMES) {
        printf("Invalid count! Must be between 1 and %d.\n", MAX_NAMES);
        return 1;
    }

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  Name %d: ", i + 1);
        fgets(names[i], MAX_LEN, stdin);

        /* Remove trailing newline */
        for (int j = 0; names[i][j] != '\0'; j++) {
            if (names[i][j] == '\n') {
                names[i][j] = '\0';
                break;
            }
        }
    }

    printf("\nBefore sorting:\n");
    printNames(names, n);

    sortNames(names, n);

    printf("\nAfter sorting (alphabetical order):\n");
    printNames(names, n);

    /* Edge case demonstration */
    printf("\n--- Edge Case Test ---\n");

    char demo[][MAX_LEN] = {"Zebra", "apple", "Mango", "banana", "Cherry"};
    int demoSize = 5;

    printf("\nBefore: ");
    for (int i = 0; i < demoSize; i++) printf("%s ", demo[i]);
    printf("\n");

    sortNames(demo, demoSize);

    printf("After:  ");
    for (int i = 0; i < demoSize; i++) printf("%s ", demo[i]);
    printf("\n");

    return 0;
}
