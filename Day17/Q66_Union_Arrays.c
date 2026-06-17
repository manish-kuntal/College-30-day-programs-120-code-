/*
 * Q66: Union of Two Arrays
 * --------------------------
 * Find the union of two arrays - a set containing all distinct
 * elements that appear in either or both arrays.
 *
 * Approach: Add all elements from first array to result, then
 *           add elements from second array only if not already present.
 * Time Complexity: O(n * m) for duplicate checking
 * Space Complexity: O(n + m) for result array
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * isPresent - Checks if an element exists in the array
 * @arr: array to search
 * @size: size of array
 * @key: element to find
 *
 * Returns 1 if found, 0 otherwise.
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
 * findUnion - Computes the union of two arrays
 * @arr1: first array
 * @size1: size of first array
 * @arr2: second array
 * @size2: size of second array
 * @result: output array for union
 *
 * Returns the size of the union array.
 */
int findUnion(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int resultSize = 0;

    /* Add all unique elements from first array */
    for (int i = 0; i < size1; i++) {
        if (!isPresent(result, resultSize, arr1[i])) {
            result[resultSize++] = arr1[i];
        }
    }

    /* Add elements from second array only if not already in result */
    for (int i = 0; i < size2; i++) {
        if (!isPresent(result, resultSize, arr2[i])) {
            result[resultSize++] = arr2[i];
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
    int arr1[MAX_SIZE], arr2[MAX_SIZE], result[MAX_SIZE * 2];
    int n1, n2, i;

    printf("=== Union of Two Arrays ===\n\n");

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

    int unionSize = findUnion(arr1, n1, arr2, n2, result);

    printf("\nArray 1: ");
    printArray(arr1, n1);
    printf("Array 2: ");
    printArray(arr2, n2);
    printf("Union:   ");
    printArray(result, unionSize);
    printf("Union size: %d\n", unionSize);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo1[] = {1, 2, 3, 4, 5};
    int demo2[] = {3, 4, 5, 6, 7};
    int demoResult[10];

    printf("Array 1: ");
    printArray(demo1, 5);
    printf("Array 2: ");
    printArray(demo2, 5);

    int demoUnionSize = findUnion(demo1, 5, demo2, 5, demoResult);
    printf("Union:   ");
    printArray(demoResult, demoUnionSize);

    return 0;
}
