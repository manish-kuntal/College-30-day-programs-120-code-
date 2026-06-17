/*
 * Q64: Remove Duplicates from Array
 * -----------------------------------
 * Given an array of integers, remove all duplicate elements
 * and keep only unique elements.
 *
 * Approach: For each element, check if it already exists in the
 *           result portion of the array. If not, keep it.
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) - in-place modification
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * removeDuplicates - Removes duplicate elements from array in-place
 * @arr: input array (modified in place)
 * @size: pointer to the size (updated after removal)
 *
 * After this function, *size contains the new size with unique elements.
 */
void removeDuplicates(int arr[], int *size) {
    int n = *size;

    if (n <= 1) {
        return; /* No duplicates possible with 0 or 1 elements */
    }

    int newSize = 0; /* Tracks the position for unique elements */

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;

        /* Check if arr[i] already exists in arr[0..newSize-1] */
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        /* If not a duplicate, add to the result portion */
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    *size = newSize;
}

/*
 * printArray - Helper to print array elements
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, i;

    printf("=== Remove Duplicates from Array ===\n\n");

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Number of elements must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    printArray(arr, n);

    int originalSize = n;
    removeDuplicates(arr, &n);

    printf("After removing duplicates: ");
    printArray(arr, n);

    printf("Removed %d duplicate(s). New size: %d\n", originalSize - n, n);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo[] = {4, 2, 3, 2, 4, 5, 3, 1, 5, 6};
    int demoSize = 10;

    printf("Original: ");
    printArray(demo, demoSize);

    removeDuplicates(demo, &demoSize);

    printf("After removal: ");
    printArray(demo, demoSize);
    printf("New size: %d\n", demoSize);

    return 0;
}
