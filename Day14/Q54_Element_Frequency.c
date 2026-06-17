/*
 * Q54: Frequency of an element in array
 *
 * Description:
 *   Count how many times a specific element appears in the array.
 *   Also demonstrates finding the frequency of all elements.
 *
 * Logic:
 *   - For a specific element: traverse and count matches.
 *   - For all elements: use a visited flag to avoid re-counting.
 *
 * Edge Cases:
 *   - Element not present (frequency = 0)
 *   - All elements are the same
 *   - Single element array
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to count frequency of a specific element */
int frequency(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

/* Function to display frequency of all elements */
void allFrequencies(int arr[], int size) {
    int visited[MAX_SIZE] = {0}; /* Track already counted elements */

    printf("\nElement  | Frequency\n");
    printf("---------+----------\n");

    for (int i = 0; i < size; i++) {
        /* Skip if already counted */
        if (visited[i]) {
            continue;
        }

        /* Count frequency of arr[i] */
        int count = 0;
        for (int j = i; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
                visited[j] = 1; /* Mark as visited */
            }
        }

        printf("%7d  | %d\n", arr[i], count);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, target;

    printf("=== Element Frequency in Array ===\n\n");

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

    /* Read the target element */
    printf("\nEnter the element to find frequency of: ");
    if (scanf("%d", &target) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Find and display frequency of target */
    int freq = frequency(arr, n, target);

    printf("\n--- Result ---\n");
    if (freq > 0) {
        printf("Element %d appears %d time(s) in the array.\n", target, freq);
        printf("Percentage: %.1f%%\n", (double)freq / n * 100);

        /* Show positions */
        printf("Found at index(es): ");
        int first = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                if (!first) printf(", ");
                printf("%d", i);
                first = 0;
            }
        }
        printf("\n");
    } else {
        printf("Element %d is NOT present in the array.\n", target);
    }

    /* Display frequency of all elements */
    printf("\n--- Frequency of All Elements ---\n");
    allFrequencies(arr, n);

    return 0;
}
