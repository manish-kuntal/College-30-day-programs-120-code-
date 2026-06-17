/*
 * Q55: Find second largest element in array
 *
 * Description:
 *   Find the second largest distinct element in an array.
 *
 * Logic:
 *   - Track the largest and second largest in a single pass.
 *   - Initialize both to INT_MIN.
 *   - For each element:
 *     - If it's greater than the largest, update second = largest, largest = current.
 *     - Else if it's greater than second and not equal to largest, update second.
 *
 * Edge Cases:
 *   - Array with all identical elements (no second largest)
 *   - Array with only one element
 *   - Array with two elements
 *   - Negative numbers
 */

#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

/* Function to find the second largest element */
/* Returns 1 if found, 0 if no distinct second largest exists */
int findSecondLargest(int arr[], int size, int *secondLargest) {
    if (size < 2) {
        return 0; /* Need at least 2 elements */
    }

    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;  /* Previous largest becomes second largest */
            first = arr[i];   /* Update the largest */
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];  /* Update second largest */
        }
    }

    /* Check if a valid second largest was found */
    if (second == INT_MIN) {
        return 0; /* All elements are the same */
    }

    *secondLargest = second;
    return 1;
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("=== Find Second Largest Element ===\n\n");

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

    /* Display the array */
    printf("\nArray: { ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");

    /* Find the largest element for reference */
    int largest = arr[0];
    int largestIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
            largestIdx = i;
        }
    }

    printf("\n--- Results ---\n");
    printf("Largest element: %d (at index %d)\n", largest, largestIdx);

    /* Find and display the second largest */
    int secondLargest;
    if (findSecondLargest(arr, n, &secondLargest)) {
        printf("Second largest:  %d\n", secondLargest);

        /* Find and display the index of second largest */
        for (int i = 0; i < n; i++) {
            if (arr[i] == secondLargest) {
                printf("  (found at index %d)\n", i);
                break;
            }
        }
    } else {
        if (n < 2) {
            printf("Second largest:  Does not exist (need at least 2 elements)\n");
        } else {
            printf("Second largest:  Does not exist (all elements are %d)\n", largest);
        }
    }

    return 0;
}
