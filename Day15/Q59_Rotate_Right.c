/*
 * Q59: Rotate array right
 *
 * Description:
 *   Right rotate an array by d positions. The last d elements move
 *   to the front, and the rest shift to the right.
 *   Example: [1,2,3,4,5] rotated right by 2 -> [4,5,1,2,3]
 *
 * Logic (Reversal Algorithm - O(n) time, O(1) space):
 *   Right rotation by d = Left rotation by (n - d).
 *   Or equivalently:
 *   1. Reverse the entire array.
 *   2. Reverse the first d elements.
 *   3. Reverse the remaining n-d elements.
 *
 * Edge Cases:
 *   - d = 0 (no rotation)
 *   - d = n (full rotation, array unchanged)
 *   - d > n (d = d % n)
 *   - Single element array
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Helper: reverse array elements from index start to end */
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* Function to right rotate using reversal algorithm (in-place) */
void rotateRight(int arr[], int size, int d) {
    if (size <= 1 || d <= 0) return;

    d = d % size; /* Handle d > size */
    if (d == 0) return;

    /* Step 1: Reverse the entire array */
    reverse(arr, 0, size - 1);
    /* Step 2: Reverse the first d elements */
    reverse(arr, 0, d - 1);
    /* Step 3: Reverse the remaining n-d elements */
    reverse(arr, d, size - 1);
}

/* Alternative: right rotate by converting to left rotation */
void rotateRightAlt(int arr[], int size, int d) {
    if (size <= 1 || d <= 0) return;

    d = d % size;
    if (d == 0) return;

    /* Right rotation by d = Left rotation by (n - d) */
    int leftD = size - d;

    reverse(arr, 0, leftD - 1);
    reverse(arr, leftD, size - 1);
    reverse(arr, 0, size - 1);
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

int main() {
    int arr[MAX_SIZE], original[MAX_SIZE];
    int n, d;

    printf("=== Right Rotate Array ===\n\n");

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

    /* Read rotation count */
    printf("\nEnter number of positions to rotate right: ");
    if (scanf("%d", &d) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Save original */
    copyArray(arr, original, n);

    /* Display original */
    printf("\nOriginal array: ");
    displayArray(arr, n);
    printf("\n");

    /* Handle d > n */
    int effectiveD = (d % n + n) % n;
    if (d != effectiveD) {
        printf("Effective rotation: %d (since %d %% %d = %d)\n",
               effectiveD, d, n, effectiveD);
    }

    /* Perform right rotation */
    rotateRight(arr, n, d);

    printf("After right rotate by %d: ", effectiveD);
    displayArray(arr, n);
    printf("\n");

    /* Show the reversal algorithm steps */
    printf("\n--- Reversal Algorithm Steps ---\n");
    copyArray(original, arr, n);
    int ed = effectiveD;

    printf("Original:              ");
    displayArray(arr, n);
    printf("\n");

    reverse(arr, 0, n - 1);
    printf("After reverse [0..%d]:  ", n - 1);
    displayArray(arr, n);
    printf("\n");

    reverse(arr, 0, ed - 1);
    printf("After reverse [0..%d]:  ", ed - 1);
    displayArray(arr, n);
    printf("\n");

    reverse(arr, ed, n - 1);
    printf("After reverse [%d..%d]: ", ed, n - 1);
    displayArray(arr, n);
    printf(" (Final result)\n");

    /* Compare left and right rotation */
    printf("\n--- Comparison ---\n");
    printf("Right rotate by %d is same as left rotate by %d.\n",
           effectiveD, n - effectiveD);

    return 0;
}
