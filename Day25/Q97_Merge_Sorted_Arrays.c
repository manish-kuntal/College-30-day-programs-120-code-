/*
 * Q97: Merge Two Sorted Arrays
 * 
 * This program merges two sorted arrays into a single sorted array.
 *
 * Logic:
 *   - Use two pointers, one for each array
 *   - Compare elements at both pointers
 *   - Place the smaller element into the result array and advance that pointer
 *   - When one array is exhausted, copy remaining elements from the other
 *   - Time complexity: O(n + m) where n and m are array sizes
 *
 * Edge Cases:
 *   - One or both arrays are empty
 *   - Arrays of different sizes
 *   - Arrays with duplicate elements
 *   - One array's elements are all smaller than the other's
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to merge two sorted arrays */
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[], int *mergedSize) {
    int i = 0, j = 0, k = 0;

    /* Compare elements from both arrays and pick the smaller one */
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    /* Copy remaining elements from arr1 (if any) */
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    /* Copy remaining elements from arr2 (if any) */
    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    *mergedSize = k;
}

/* Function to print an array */
void printArray(int arr[], int size) {
    if (size == 0) {
        printf("{ } (empty)");
        return;
    }
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf(" }");
}

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[2 * MAX_SIZE];
    int n1, n2, mergedSize;

    printf("=== Merge Two Sorted Arrays ===\n\n");

    /* Input first sorted array */
    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);

    if (n1 < 0 || n1 > MAX_SIZE) {
        printf("Invalid size! Must be between 0 and %d.\n", MAX_SIZE);
        return 1;
    }

    if (n1 > 0) {
        printf("Enter %d elements (sorted in ascending order):\n", n1);
        for (int i = 0; i < n1; i++) {
            printf("  arr1[%d] = ", i);
            scanf("%d", &arr1[i]);
        }
    }

    /* Input second sorted array */
    printf("\nEnter size of second sorted array: ");
    scanf("%d", &n2);

    if (n2 < 0 || n2 > MAX_SIZE) {
        printf("Invalid size! Must be between 0 and %d.\n", MAX_SIZE);
        return 1;
    }

    if (n2 > 0) {
        printf("Enter %d elements (sorted in ascending order):\n", n2);
        for (int i = 0; i < n2; i++) {
            printf("  arr2[%d] = ", i);
            scanf("%d", &arr2[i]);
        }
    }

    /* Merge the arrays */
    mergeSortedArrays(arr1, n1, arr2, n2, merged, &mergedSize);

    /* Display results */
    printf("\nArray 1: ");
    printArray(arr1, n1);
    printf("\nArray 2: ");
    printArray(arr2, n2);
    printf("\nMerged:  ");
    printArray(merged, mergedSize);
    printf("\n");

    /* Edge case demonstrations */
    printf("\n--- Edge Case Tests ---\n");

    int e1[] = {1, 3, 5, 7};
    int e2[] = {2, 4, 6, 8};
    int result[20];
    int rSize;

    mergeSortedArrays(e1, 4, e2, 4, result, &rSize);
    printf("Merge {1,3,5,7} + {2,4,6,8} = ");
    printArray(result, rSize);
    printf("\n");

    int e3[] = {1, 2, 3};
    mergeSortedArrays(e3, 3, e2, 0, result, &rSize);
    printf("Merge {1,2,3} + {} = ");
    printArray(result, rSize);
    printf("\n");

    mergeSortedArrays(e1, 0, e2, 0, result, &rSize);
    printf("Merge {} + {} = ");
    printArray(result, rSize);
    printf("\n");

    int e4[] = {1, 1, 2};
    int e5[] = {1, 3, 3};
    mergeSortedArrays(e4, 3, e5, 3, result, &rSize);
    printf("Merge {1,1,2} + {1,3,3} = ");
    printArray(result, rSize);
    printf("\n");

    int e6[] = {1, 2};
    int e7[] = {10, 20, 30, 40};
    mergeSortedArrays(e6, 2, e7, 4, result, &rSize);
    printf("Merge {1,2} + {10,20,30,40} = ");
    printArray(result, rSize);
    printf("\n");

    return 0;
}
