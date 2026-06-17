/*
 * Q68: Find Common Elements Between Two Arrays
 * -----------------------------------------------
 * Given two arrays, find and display all common elements
 * along with their positions in both arrays.
 *
 * This differs from intersection by showing WHERE common elements
 * appear in each array and preserving frequency information.
 *
 * Approach: Nested loop comparison tracking indices.
 * Time Complexity: O(n * m)
 * Space Complexity: O(1) for output
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * findCommonElements - Finds and prints common elements with details
 * @arr1: first array
 * @size1: size of first array
 * @arr2: second array
 * @size2: size of second array
 *
 * Returns the count of common element pairs found.
 */
int findCommonElements(int arr1[], int size1, int arr2[], int size2) {
    int count = 0;

    printf("Common elements (with positions):\n");
    printf("%-10s %-15s %-15s\n", "Value", "Index in Arr1", "Index in Arr2");
    printf("------------------------------------------\n");

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%-10d %-15d %-15d\n", arr1[i], i, j);
                count++;
            }
        }
    }

    return count;
}

/*
 * findUniqueCommonElements - Finds distinct common elements (no repeats)
 * @arr1: first array
 * @size1: size of first array
 * @arr2: second array
 * @size2: size of second array
 * @result: output array for common elements
 *
 * Returns the count of unique common elements.
 */
int findUniqueCommonElements(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int resultSize = 0;

    for (int i = 0; i < size1; i++) {
        /* Check if arr1[i] exists in arr2 */
        int foundInArr2 = 0;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                foundInArr2 = 1;
                break;
            }
        }

        /* Check if already in result (avoid duplicates) */
        if (foundInArr2) {
            int alreadyInResult = 0;
            for (int k = 0; k < resultSize; k++) {
                if (result[k] == arr1[i]) {
                    alreadyInResult = 1;
                    break;
                }
            }
            if (!alreadyInResult) {
                result[resultSize++] = arr1[i];
            }
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
    int arr1[MAX_SIZE], arr2[MAX_SIZE], common[MAX_SIZE];
    int n1, n2, i;

    printf("=== Find Common Elements Between Two Arrays ===\n\n");

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

    printf("\nArray 1: ");
    printArray(arr1, n1);
    printf("Array 2: ");
    printArray(arr2, n2);
    printf("\n");

    /* Show detailed common elements */
    int pairCount = findCommonElements(arr1, n1, arr2, n2);
    if (pairCount == 0) {
        printf("No common elements found.\n");
    } else {
        printf("\nTotal common pairs: %d\n", pairCount);
    }

    /* Show unique common elements */
    int uniqueCount = findUniqueCommonElements(arr1, n1, arr2, n2, common);
    printf("\nUnique common elements: ");
    printArray(common, uniqueCount);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo1[] = {1, 2, 3, 2, 5};
    int demo2[] = {2, 4, 2, 5, 6};
    int demoCommon[MAX_SIZE];

    printf("Array 1: ");
    printArray(demo1, 5);
    printf("Array 2: ");
    printArray(demo2, 5);
    printf("\n");

    findCommonElements(demo1, 5, demo2, 5);
    int demoUniqueCount = findUniqueCommonElements(demo1, 5, demo2, 5, demoCommon);
    printf("\nUnique common elements: ");
    printArray(demoCommon, demoUniqueCount);

    return 0;
}
