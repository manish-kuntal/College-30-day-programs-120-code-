/*
 * Q53: Linear search in array
 *
 * Description:
 *   Search for a target element in an array using linear search.
 *   Linear search checks each element sequentially until a match
 *   is found or the array is exhausted.
 *
 * Logic:
 *   - Traverse the array from index 0 to n-1.
 *   - Compare each element with the target.
 *   - If found, return the index; otherwise return -1.
 *
 * Time Complexity: O(n)
 *
 * Edge Cases:
 *   - Element not found
 *   - Element at the beginning / end
 *   - Multiple occurrences (find first and all)
 *   - Empty array
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to perform linear search - returns index of first occurrence */
/* Returns -1 if element is not found */
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; /* Found at index i */
        }
    }
    return -1; /* Not found */
}

/* Function to find all occurrences of a target */
/* Returns the count of occurrences, fills positions[] with indices */
int linearSearchAll(int arr[], int size, int target,
                    int positions[], int maxPositions) {
    int count = 0;
    for (int i = 0; i < size && count < maxPositions; i++) {
        if (arr[i] == target) {
            positions[count++] = i;
        }
    }
    return count;
}

int main() {
    int arr[MAX_SIZE];
    int n, target;

    printf("=== Linear Search in Array ===\n\n");

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

    /* Read the target element */
    printf("\nEnter the element to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Display the array */
    printf("\nArray: { ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
    printf("Searching for: %d\n", target);

    /* Perform linear search (first occurrence) */
    int index = linearSearch(arr, n, target);

    printf("\n--- Search Results ---\n");
    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d NOT found in the array.\n", target);
    }

    /* Find all occurrences */
    int positions[MAX_SIZE];
    int count = linearSearchAll(arr, n, target, positions, MAX_SIZE);

    if (count > 0) {
        printf("Total occurrences: %d\n", count);
        printf("Found at indices: ");
        for (int i = 0; i < count; i++) {
            printf("%d", positions[i]);
            if (i < count - 1) printf(", ");
        }
        printf("\n");

        /* Show search trace */
        printf("\n--- Search Trace ---\n");
        for (int i = 0; i <= index; i++) {
            printf("Step %d: Compare arr[%d]=%d with %d -> %s\n",
                   i + 1, i, arr[i], target,
                   (arr[i] == target) ? "FOUND!" : "not equal, continue");
        }
        printf("Comparisons needed: %d\n", index + 1);
    }

    return 0;
}
