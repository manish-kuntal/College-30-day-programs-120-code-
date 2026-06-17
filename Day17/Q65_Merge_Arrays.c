/*
 * Q65: Merge Two Arrays
 * -----------------------
 * Given two arrays, merge them into a single array containing
 * all elements from both arrays (concatenation).
 *
 * Approach: Copy all elements of first array, then append all
 *           elements of second array.
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m) for the merged array
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * mergeArrays - Merges two arrays into a result array
 * @arr1: first array
 * @size1: size of first array
 * @arr2: second array
 * @size2: size of second array
 * @result: output array (must have space for size1 + size2 elements)
 *
 * Returns the total size of the merged array.
 */
int mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i, idx = 0;

    /* Copy all elements from first array */
    for (i = 0; i < size1; i++) {
        result[idx++] = arr1[i];
    }

    /* Append all elements from second array */
    for (i = 0; i < size2; i++) {
        result[idx++] = arr2[i];
    }

    return idx; /* Total merged size */
}

/*
 * printArray - Helper to print array elements
 */
void printArray(int arr[], int size) {
    if (size == 0) {
        printf("(empty)");
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];
    int n1, n2, i;

    printf("=== Merge Two Arrays ===\n\n");

    /* Read first array */
    printf("Enter size of first array (max %d): ", MAX_SIZE);
    scanf("%d", &n1);
    if (n1 < 0 || n1 > MAX_SIZE) {
        printf("Error: Size must be between 0 and %d.\n", MAX_SIZE);
        return 1;
    }
    printf("Enter %d elements for first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    /* Read second array */
    printf("Enter size of second array (max %d): ", MAX_SIZE);
    scanf("%d", &n2);
    if (n2 < 0 || n2 > MAX_SIZE) {
        printf("Error: Size must be between 0 and %d.\n", MAX_SIZE);
        return 1;
    }
    printf("Enter %d elements for second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    /* Merge arrays */
    int mergedSize = mergeArrays(arr1, n1, arr2, n2, merged);

    /* Display results */
    printf("\nArray 1: ");
    printArray(arr1, n1);
    printf("Array 2: ");
    printArray(arr2, n2);
    printf("Merged:  ");
    printArray(merged, mergedSize);
    printf("Merged size: %d\n", mergedSize);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo1[] = {1, 3, 5, 7};
    int demo2[] = {2, 4, 6, 8, 10};
    int demoMerged[9];

    printf("Array 1: ");
    printArray(demo1, 4);
    printf("Array 2: ");
    printArray(demo2, 5);

    int demoMergedSize = mergeArrays(demo1, 4, demo2, 5, demoMerged);
    printf("Merged:  ");
    printArray(demoMerged, demoMergedSize);

    return 0;
}
