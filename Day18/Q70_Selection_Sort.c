/*
 * Q70: Selection Sort Implementation
 * ------------------------------------
 * Sort an array using the Selection Sort algorithm.
 * Repeatedly finds the minimum element from the unsorted portion
 * and puts it at the beginning.
 *
 * Time Complexity: O(n^2) for all cases
 * Space Complexity: O(1) - in-place sorting
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * selectionSort - Sorts array in ascending order using Selection Sort
 * @arr: array to sort
 * @size: number of elements
 *
 * In each iteration i, finds the minimum in arr[i..size-1]
 * and swaps it with arr[i].
 */
void selectionSort(int arr[], int size) {
    int i, j, minIdx, temp;

    for (i = 0; i < size - 1; i++) {
        /* Assume the current position has the minimum */
        minIdx = i;

        /* Find the index of the minimum element in unsorted portion */
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        /* Swap only if minimum is not already at position i */
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
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

    printf("=== Selection Sort ===\n\n");

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

    printf("\nBefore sorting: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("After sorting:  ");
    printArray(arr, n);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo[] = {29, 10, 14, 37, 13};
    int demoSize = 5;

    printf("Before: ");
    printArray(demo, demoSize);

    selectionSort(demo, demoSize);

    printf("After:  ");
    printArray(demo, demoSize);

    /* Demo with single element */
    printf("\n--- Single Element Demo ---\n");
    int single[] = {42};
    printf("Before: ");
    printArray(single, 1);
    selectionSort(single, 1);
    printf("After:  ");
    printArray(single, 1);

    return 0;
}
