/*
 * Q60: Move zeroes to end of array
 *
 * Description:
 *   Move all zeroes in an array to the end while maintaining
 *   the relative order of non-zero elements.
 *   Example: [0,1,0,3,12] -> [1,3,12,0,0]
 *
 * Logic (Two-pointer approach):
 *   - Use a write pointer (insertPos) starting at 0.
 *   - Traverse the array with a read pointer.
 *   - For each non-zero element, place it at insertPos and increment.
 *   - After traversal, fill remaining positions with zeroes.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) - in-place
 *
 * Edge Cases:
 *   - No zeroes in the array
 *   - All zeroes
 *   - Zeroes only at the beginning
 *   - Zeroes only at the end (already correct)
 *   - Single element
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to move zeroes to the end - maintains relative order */
void moveZeroes(int arr[], int size) {
    int insertPos = 0; /* Position to insert next non-zero element */

    /* Move all non-zero elements to the front */
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[insertPos] = arr[i];
            insertPos++;
        }
    }

    /* Fill the remaining positions with zeroes */
    while (insertPos < size) {
        arr[insertPos] = 0;
        insertPos++;
    }
}

/* Alternative: swap-based approach (minimizes writes) */
void moveZeroesSwap(int arr[], int size) {
    int insertPos = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            /* Swap only if positions are different */
            if (i != insertPos) {
                int temp = arr[insertPos];
                arr[insertPos] = arr[i];
                arr[i] = temp;
            }
            insertPos++;
        }
    }
}

/* Function to display an array */
void displayArray(int arr[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf(" }");
}

/* Function to copy an array */
void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

/* Function to count zeroes in array */
int countZeroes(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) count++;
    }
    return count;
}

int main() {
    int arr[MAX_SIZE], original[MAX_SIZE];
    int n;

    printf("=== Move Zeroes to End ===\n\n");

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

    /* Save original */
    copyArray(arr, original, n);

    /* Count zeroes before operation */
    int zeroCount = countZeroes(arr, n);
    int nonZeroCount = n - zeroCount;

    /* Display original */
    printf("\nOriginal array: ");
    displayArray(arr, n);
    printf("\n");
    printf("Zeroes: %d, Non-zeroes: %d\n", zeroCount, nonZeroCount);

    /* Edge case: no zeroes */
    if (zeroCount == 0) {
        printf("\nNo zeroes found. Array is unchanged.\n");
        return 0;
    }

    /* Edge case: all zeroes */
    if (zeroCount == n) {
        printf("\nAll elements are zero. Array is unchanged.\n");
        return 0;
    }

    /* Move zeroes to end */
    moveZeroes(arr, n);

    printf("\nAfter moving zeroes: ");
    displayArray(arr, n);
    printf("\n");

    /* Verify: show that relative order of non-zero elements is preserved */
    printf("\n--- Verification ---\n");
    printf("Non-zero elements (original order): ");
    for (int i = 0; i < n; i++) {
        if (original[i] != 0) {
            printf("%d ", original[i]);
        }
    }
    printf("\nNon-zero elements (after move):     ");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nRelative order preserved: ");

    /* Check order preservation */
    int j = 0;
    int orderOK = 1;
    for (int i = 0; i < n; i++) {
        if (original[i] != 0) {
            if (arr[j] != original[i]) {
                orderOK = 0;
                break;
            }
            j++;
        }
    }
    printf("%s\n", orderOK ? "Yes" : "No");

    /* Show step-by-step (using swap approach) */
    printf("\n--- Step-by-Step (Swap Approach) ---\n");
    copyArray(original, arr, n);
    int insertPos = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            if (i != insertPos) {
                printf("Swap arr[%d]=%d with arr[%d]=%d -> ",
                       insertPos, arr[insertPos], i, arr[i]);
                int temp = arr[insertPos];
                arr[insertPos] = arr[i];
                arr[i] = temp;
                displayArray(arr, n);
                printf("\n");
            }
            insertPos++;
        }
    }
    printf("Done!\n");

    return 0;
}
