/*
 * Q72: Sort Array in Descending Order
 * --------------------------------------
 * Sort an array in descending (largest to smallest) order.
 *
 * Approach: Modified Bubble Sort that compares for ascending
 *           and swaps to achieve descending order.
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) - in-place
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * sortDescending - Sorts array in descending order using modified bubble sort
 * @arr: array to sort
 * @size: number of elements
 */
void sortDescending(int arr[], int size) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0;

        for (j = 0; j < size - 1 - i; j++) {
            /* Swap if current element is SMALLER than next (descending) */
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        /* Early termination if no swaps */
        if (!swapped) {
            break;
        }
    }
}

/*
 * sortDescendingSelection - Descending sort using selection sort variant
 * @arr: array to sort
 * @size: number of elements
 *
 * Finds the MAXIMUM in unsorted portion and places it at front.
 */
void sortDescendingSelection(int arr[], int size) {
    int i, j, maxIdx, temp;

    for (i = 0; i < size - 1; i++) {
        maxIdx = i;

        /* Find the maximum element in unsorted portion */
        for (j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }

        /* Swap if needed */
        if (maxIdx != i) {
            temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, i;

    printf("=== Sort Array in Descending Order ===\n\n");

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

    sortDescending(arr, n);

    printf("Sorted (descending): ");
    printArray(arr, n);

    /* --- Demo: Both methods --- */
    printf("\n--- Demo: Bubble Sort Descending ---\n");
    int demo1[] = {12, 45, 7, 89, 23, 56, 1};
    int demoSize = 7;
    printf("Before: ");
    printArray(demo1, demoSize);
    sortDescending(demo1, demoSize);
    printf("After:  ");
    printArray(demo1, demoSize);

    printf("\n--- Demo: Selection Sort Descending ---\n");
    int demo2[] = {34, 78, 12, 56, 90, 23};
    int demoSize2 = 6;
    printf("Before: ");
    printArray(demo2, demoSize2);
    sortDescendingSelection(demo2, demoSize2);
    printf("After:  ");
    printArray(demo2, demoSize2);

    return 0;
}
