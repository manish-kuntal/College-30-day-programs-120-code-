/*
 * Q49: Input and display array
 *
 * Description:
 *   Read an array of integers from the user and display them.
 *   Demonstrates basic array input/output operations.
 *
 * Logic:
 *   - Ask user for the size of the array.
 *   - Read each element using a loop.
 *   - Display the array elements with their indices.
 *
 * Edge Cases:
 *   - Empty array (size 0)
 *   - Array with a single element
 *   - Maximum array size limit
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to input array elements */
int inputArray(int arr[], int size) {
    printf("Enter %d element(s):\n", size);
    for (int i = 0; i < size; i++) {
        printf("  arr[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error: Invalid input at index %d!\n", i);
            return 0; /* Failure */
        }
    }
    return 1; /* Success */
}

/* Function to display array elements */
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: { ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf(" }\n");
}

/* Function to display array with indices */
void displayArrayWithIndices(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("\nIndex  | Value\n");
    printf("-------+------\n");
    for (int i = 0; i < size; i++) {
        printf("  [%2d] | %d\n", i, arr[i]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("=== Array Input and Display ===\n\n");

    /* Read the size of the array */
    printf("Enter the number of elements (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Validate size */
    if (n <= 0) {
        printf("\nArray size must be positive.\n");
        printf("Creating an empty array.\n");
        n = 0;
        displayArray(arr, n);
        return 0;
    }

    if (n > MAX_SIZE) {
        printf("\nArray size exceeds maximum (%d). Using %d.\n", MAX_SIZE, MAX_SIZE);
        n = MAX_SIZE;
    }

    /* Input array elements */
    printf("\n");
    if (!inputArray(arr, n)) {
        return 1;
    }

    /* Display the array */
    printf("\n--- Array Display ---\n");
    displayArray(arr, n);

    /* Display with indices */
    printf("\n--- Array with Indices ---\n");
    displayArrayWithIndices(arr, n);

    /* Display additional info */
    printf("\nArray size: %d elements\n", n);
    printf("Memory used: %lu bytes\n", (unsigned long)(n * sizeof(int)));

    return 0;
}
