/*
 * Q56: Find duplicates in array
 *
 * Description:
 *   Find and display all duplicate elements in an array.
 *   An element is duplicate if it appears more than once.
 *
 * Logic:
 *   - For each element, check if it appears again later in the array.
 *   - Use a visited array to avoid printing the same duplicate twice.
 *
 * Time Complexity: O(n^2) - brute force approach
 *
 * Edge Cases:
 *   - No duplicates
 *   - All elements are the same
 *   - Single element array
 *   - Multiple different duplicates
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to find and count duplicates */
/* Returns the number of distinct duplicate elements */
int findDuplicates(int arr[], int size, int duplicates[], int counts[]) {
    int visited[MAX_SIZE] = {0}; /* Track already processed elements */
    int dupCount = 0;

    for (int i = 0; i < size; i++) {
        /* Skip if this element was already processed */
        if (visited[i]) {
            continue;
        }

        /* Count occurrences of arr[i] */
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
                visited[j] = 1; /* Mark as processed */
            }
        }

        /* If count > 1, it's a duplicate */
        if (count > 1) {
            duplicates[dupCount] = arr[i];
            counts[dupCount] = count;
            dupCount++;
        }
    }

    return dupCount;
}

/* Function to check if array has any duplicates */
int hasDuplicates(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 1; /* Found a duplicate */
            }
        }
    }
    return 0; /* No duplicates */
}

int main() {
    int arr[MAX_SIZE];
    int duplicates[MAX_SIZE], counts[MAX_SIZE];
    int n;

    printf("=== Find Duplicates in Array ===\n\n");

    /* Read the size of the array */
    printf("Enter the number of elements (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1;
    }

    if (n > MAX_SIZE) {
        printf("Limiting to %d elements.\n", MAX_SIZE);
        n = MAX_SIZE;
    }

    /* Read array elements */
    printf("Enter %d element(s):\n", n);
    for (int i = 0; i < n; i++) {
        printf("  arr[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error: Invalid input!\n");
            return 1;
        }
    }

    /* Display the array */
    printf("\nArray: { ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");

    /* Find duplicates */
    int dupCount = findDuplicates(arr, n, duplicates, counts);

    printf("\n--- Results ---\n");
    if (dupCount == 0) {
        printf("No duplicate elements found.\n");
        printf("All %d elements are unique.\n", n);
    } else {
        printf("Found %d duplicate element(s):\n\n", dupCount);
        printf("Element  | Count | Positions\n");
        printf("---------+-------+----------\n");

        for (int d = 0; d < dupCount; d++) {
            printf("%7d  | %5d | ", duplicates[d], counts[d]);

            /* Show positions of this duplicate */
            int first = 1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == duplicates[d]) {
                    if (!first) printf(", ");
                    printf("%d", i);
                    first = 0;
                }
            }
            printf("\n");
        }

        /* Summary */
        int totalDuplicateElements = 0;
        for (int d = 0; d < dupCount; d++) {
            totalDuplicateElements += counts[d];
        }
        int uniqueCount = n - totalDuplicateElements + dupCount;
        printf("\nSummary:\n");
        printf("  Total elements:      %d\n", n);
        printf("  Unique elements:     %d\n", uniqueCount);
        printf("  Duplicate values:    %d\n", dupCount);
        printf("  Extra copies:        %d\n", totalDuplicateElements - dupCount);
    }

    return 0;
}
