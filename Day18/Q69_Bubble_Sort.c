/*
 * Q69: Bubble Sort Implementation
 * ---------------------------------
 * Sort an array using the Bubble Sort algorithm.
 * Repeatedly steps through the list, compares adjacent elements,
 * and swaps them if they are in the wrong order.
 *
 * Optimized: Early termination if no swaps occur in a pass.
 * Time Complexity: O(n^2) worst/average, O(n) best (already sorted)
 * Space Complexity: O(1) - in-place sorting
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * bubbleSort - Sorts array in ascending order using Bubble Sort
 * @arr: array to sort
 * @size: number of elements
 *
 * Uses an optimization flag to detect early completion.
 */
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    int swapped; /* Optimization: track if any swap occurred */

    for (i = 0; i < size - 1; i++) {
        swapped = 0;

        /*
         * After each pass i, the largest i+1 elements are
         * already in their correct positions at the end.
         * So inner loop only goes up to size - 1 - i.
         */
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                /* Swap adjacent elements */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        /* If no swaps occurred, array is already sorted */
        if (!swapped) {
            printf("  (Array sorted early at pass %d)\n", i + 1);
            break;
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

    printf("=== Bubble Sort ===\n\n");

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

    bubbleSort(arr, n);

    printf("After sorting:  ");
    printArray(arr, n);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo[] = {64, 34, 25, 12, 22, 11, 90};
    int demoSize = 7;

    printf("Before: ");
    printArray(demo, demoSize);

    bubbleSort(demo, demoSize);

    printf("After:  ");
    printArray(demo, demoSize);

    /* Demo with already sorted array to show optimization */
    printf("\n--- Already Sorted Demo ---\n");
    int sorted[] = {1, 2, 3, 4, 5};
    int sortedSize = 5;

    printf("Before: ");
    printArray(sorted, sortedSize);

    bubbleSort(sorted, sortedSize);

    printf("After:  ");
    printArray(sorted, sortedSize);

    return 0;
}
