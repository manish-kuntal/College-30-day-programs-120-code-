/*
 * Q61: Find Missing Number in Array
 * ----------------------------------
 * Given an array containing n-1 distinct numbers from 1 to n,
 * find the one missing number.
 *
 * Approach: Sum of 1 to n = n*(n+1)/2. Subtract array sum to get missing number.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

/*
 * findMissingNumber - Finds the missing number in an array of 1 to n
 * @arr: input array with n-1 elements
 * @size: number of elements in the array (which is n-1)
 *
 * Returns the missing number.
 */
int findMissingNumber(int arr[], int size) {
    /* n is size + 1 because one number is missing */
    int n = size + 1;

    /* Expected sum of numbers from 1 to n */
    long long expectedSum = (long long)n * (n + 1) / 2;

    /* Calculate actual sum of array elements */
    long long actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    /* The difference is the missing number */
    return (int)(expectedSum - actualSum);
}

int main() {
    int n, i;

    printf("=== Find Missing Number in Array (1 to N) ===\n\n");

    /* Get the value of n (the range is 1 to n) */
    printf("Enter the value of N (range 1 to N): ");
    scanf("%d", &n);

    /* Edge case: n must be at least 2 for a meaningful problem */
    if (n < 2) {
        printf("Error: N must be at least 2.\n");
        return 1;
    }

    int arr[n - 1]; /* Array will have n-1 elements (one is missing) */

    printf("Enter %d numbers (from 1 to %d, with one missing):\n", n - 1, n);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    /* Validate that numbers are in range 1 to n */
    for (i = 0; i < n - 1; i++) {
        if (arr[i] < 1 || arr[i] > n) {
            printf("Error: All numbers must be between 1 and %d.\n", n);
            return 1;
        }
    }

    int missing = findMissingNumber(arr, n - 1);
    printf("\nThe missing number is: %d\n", missing);

    /* --- Demo with a hardcoded example --- */
    printf("\n--- Demo Example ---\n");
    int demo[] = {1, 2, 4, 5, 6};
    int demoSize = 5; /* n = 6, so 5 elements present */
    printf("Array: ");
    for (i = 0; i < demoSize; i++) {
        printf("%d ", demo[i]);
    }
    printf("\nN = 6\n");
    printf("Missing number: %d\n", findMissingNumber(demo, demoSize));

    return 0;
}
