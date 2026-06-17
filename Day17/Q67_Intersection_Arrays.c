/*
 * Q67: Intersection of Two Arrays
 * ---------------------------------
 * Find the intersection of two arrays - elements that appear
 * in BOTH arrays. Each common element appears only once in the result.
 *
 * Approach: For each element in array 1, check if it exists in array 2
 *           and hasn't been added to result yet.
 * Time Complexity: O(n * m)
 * Space Complexity: O(min(n, m)) for result
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * isPresent - Checks if an element exists in the array
 */
int isPresent(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return 1;
        }
    }
    return 0;
}

/*
 * findIntersection - Computes intersection of two arrays
 * @arr1: first array
 * @size1: size of first array
 * @arr2: second array
 * @size2: size of second array
 * @result: output array for intersection
 *
 * Returns the size of the intersection array.
 */
int findIntersection(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int resultSize = 0;

    for (int i = 0; i < size1; i++) {
        /*
         * Include arr1[i] in result if:
         * 1. It exists in arr2
         * 2. It hasn't been added to result already (handles duplicates in arr1)
         */
        if (isPresent(arr2, size2, arr1[i]) &&
            !isPresent(result, resultSize, arr1[i])) {
            result[resultSize++] = arr1[i];
        }
    }

    return resultSize;
}

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
    int arr1[MAX_SIZE], arr2[MAX_SIZE], result[MAX_SIZE];
    int n1, n2, i;

    printf("=== Intersection of Two Arrays ===\n\n");

    /* Read first array */
    printf("Enter size of first array (max %d): ", MAX_SIZE);
    scanf("%d", &n1);
    if (n1 < 0 || n1 > MAX_SIZE) {
        printf("Error: Size must be between 0 and %d.\n", MAX_SIZE);
        return 1;
    }
    printf("Enter %d elements:\n", n1);
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
    printf("Enter %d elements:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int interSize = findIntersection(arr1, n1, arr2, n2, result);

    printf("\nArray 1:       ");
    printArray(arr1, n1);
    printf("Array 2:       ");
    printArray(arr2, n2);
    printf("Intersection:  ");
    printArray(result, interSize);
    printf("Intersection size: %d\n", interSize);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo1[] = {1, 2, 2, 3, 4, 5};
    int demo2[] = {2, 3, 5, 6, 7};
    int demoResult[MAX_SIZE];

    printf("Array 1: ");
    printArray(demo1, 6);
    printf("Array 2: ");
    printArray(demo2, 5);

    int demoInterSize = findIntersection(demo1, 6, demo2, 5, demoResult);
    printf("Intersection: ");
    printArray(demoResult, demoInterSize);

    return 0;
}
