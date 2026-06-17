/*
 * Q71: Binary Search Implementation
 * ------------------------------------
 * Search for an element in a SORTED array using Binary Search.
 * Repeatedly divides the search interval in half.
 *
 * Prerequisite: The array MUST be sorted in ascending order.
 * Time Complexity: O(log n)
 * Space Complexity: O(1) iterative, O(log n) recursive
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * binarySearchIterative - Iterative binary search
 * @arr: sorted array (ascending)
 * @size: number of elements
 * @key: element to search for
 *
 * Returns the index of key if found, -1 otherwise.
 */
int binarySearchIterative(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; /* Avoids overflow vs (low+high)/2 */

        if (arr[mid] == key) {
            return mid;        /* Element found at mid */
        } else if (arr[mid] < key) {
            low = mid + 1;     /* Search in right half */
        } else {
            high = mid - 1;    /* Search in left half */
        }
    }

    return -1; /* Element not found */
}

/*
 * binarySearchRecursive - Recursive binary search
 * @arr: sorted array (ascending)
 * @low: left boundary index
 * @high: right boundary index
 * @key: element to search for
 *
 * Returns the index of key if found, -1 otherwise.
 */
int binarySearchRecursive(int arr[], int low, int high, int key) {
    /* Base case: search space exhausted */
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] < key) {
        return binarySearchRecursive(arr, mid + 1, high, key);
    } else {
        return binarySearchRecursive(arr, low, mid - 1, key);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, key, i;

    printf("=== Binary Search ===\n\n");

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Number of elements must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements in SORTED (ascending) order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Validate that array is sorted */
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("Warning: Array is not sorted! Binary search may give incorrect results.\n");
            break;
        }
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    /* Iterative search */
    int iterResult = binarySearchIterative(arr, n, key);
    if (iterResult != -1) {
        printf("\n[Iterative] Element %d found at index %d.\n", key, iterResult);
    } else {
        printf("\n[Iterative] Element %d not found in the array.\n", key);
    }

    /* Recursive search */
    int recResult = binarySearchRecursive(arr, 0, n - 1, key);
    if (recResult != -1) {
        printf("[Recursive] Element %d found at index %d.\n", key, recResult);
    } else {
        printf("[Recursive] Element %d not found in the array.\n", key);
    }

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int demoSize = 10;

    printf("Array: ");
    printArray(demo, demoSize);

    int targets[] = {23, 50, 2, 91};
    int numTargets = 4;

    for (i = 0; i < numTargets; i++) {
        int idx = binarySearchIterative(demo, demoSize, targets[i]);
        if (idx != -1) {
            printf("Search %d -> Found at index %d\n", targets[i], idx);
        } else {
            printf("Search %d -> Not found\n", targets[i]);
        }
    }

    return 0;
}
