/*
 * Q57: Reverse an array
 *
 * Description:
 *   Reverse the elements of an array in-place. The first element
 *   becomes the last, the second becomes second-to-last, etc.
 *
 * Logic:
 *   - Use two pointers: one at the start, one at the end.
 *   - Swap elements at these positions.
 *   - Move pointers toward the center until they meet.
 *
 * Time Complexity: O(n/2) = O(n)
 * Space Complexity: O(1) - in-place reversal
 *
 * Edge Cases:
 *   - Single element array (no change)
 *   - Two element array
 *   - Already palindromic array
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to reverse an array in-place */
void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        /* Swap elements at left and right positions */
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

/* Function to reverse a portion of an array (from index start to end) */
void reverseSubArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
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

int main() {
    int arr[MAX_SIZE], original[MAX_SIZE];
    int n;

    printf("=== Reverse an Array ===\n\n");

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

    /* Save original for comparison */
    copyArray(arr, original, n);

    /* Display original array */
    printf("\nOriginal array: ");
    displayArray(arr, n);
    printf("\n");

    /* Reverse the array */
    reverseArray(arr, n);

    /* Display reversed array */
    printf("Reversed array: ");
    displayArray(arr, n);
    printf("\n");

    /* Show the swap steps */
    printf("\n--- Reversal Steps ---\n");
    copyArray(original, arr, n); /* Restore original */
    int swaps = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        printf("Step %d: Swap arr[%d]=%d with arr[%d]=%d -> ",
               swaps + 1, left, arr[left], right, arr[right]);
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        displayArray(arr, n);
        printf("\n");
        left++;
        right--;
        swaps++;
    }
    printf("Total swaps: %d\n", swaps);

    /* Check if the array was palindromic */
    int isPalindromic = 1;
    for (int i = 0; i < n / 2; i++) {
        if (original[i] != original[n - 1 - i]) {
            isPalindromic = 0;
            break;
        }
    }
    if (isPalindromic) {
        printf("\nNote: The original array was palindromic ");
        printf("(reversing gives the same array).\n");
    }

    return 0;
}
