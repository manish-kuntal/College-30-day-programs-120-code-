/*
 * Q51: Find largest and smallest element in array
 *
 * Description:
 *   Read an array of integers and find the maximum and minimum values.
 *
 * Logic:
 *   - Initialize max and min with the first element.
 *   - Traverse the array, updating max and min as needed.
 *
 * Edge Cases:
 *   - Single element array (max == min)
 *   - All elements identical
 *   - Array with negative numbers only
 *   - Already sorted array (ascending or descending)
 */

#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

/* Function to find the largest element in an array */
int findLargest(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/* Function to find the smallest element in an array */
int findSmallest(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

/* Function to find both largest and smallest with their positions */
void findMinMax(int arr[], int size, int *max, int *maxIdx,
                int *min, int *minIdx) {
    *max = arr[0];
    *min = arr[0];
    *maxIdx = 0;
    *minIdx = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
            *maxIdx = i;
        }
        if (arr[i] < *min) {
            *min = arr[i];
            *minIdx = i;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("=== Find Largest and Smallest in Array ===\n\n");

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

    /* Find and display results */
    int max, min, maxIdx, minIdx;
    findMinMax(arr, n, &max, &maxIdx, &min, &minIdx);

    printf("\n--- Results ---\n");
    printf("Largest element:  %d (at index %d)\n", max, maxIdx);
    printf("Smallest element: %d (at index %d)\n", min, minIdx);
    printf("Range:            %d (max - min = %d - %d)\n",
           max - min, max, min);

    /* Edge case info */
    if (max == min) {
        printf("\nNote: All elements are identical (%d).\n", max);
    }

    if (n == 1) {
        printf("\nNote: Array has only one element, so largest = smallest.\n");
    }

    return 0;
}
