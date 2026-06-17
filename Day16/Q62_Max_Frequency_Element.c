/*
 * Q62: Find Maximum Frequency Element in Array
 * ----------------------------------------------
 * Given an array of integers, find the element that appears
 * the most number of times (highest frequency).
 *
 * Approach: Use a nested loop to count frequency of each element.
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * findMaxFrequencyElement - Finds element with highest frequency
 * @arr: input array
 * @size: number of elements
 * @maxFreq: pointer to store the maximum frequency found
 *
 * Returns the element with highest frequency.
 * If multiple elements have the same max frequency, returns the first one found.
 */
int findMaxFrequencyElement(int arr[], int size, int *maxFreq) {
    int maxFreqElement = arr[0];
    *maxFreq = 0;

    for (int i = 0; i < size; i++) {
        int count = 0;

        /* Count occurrences of arr[i] */
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        /* Update if this element has higher frequency */
        if (count > *maxFreq) {
            *maxFreq = count;
            maxFreqElement = arr[i];
        }
    }

    return maxFreqElement;
}

int main() {
    int arr[MAX_SIZE], n, i;

    printf("=== Find Maximum Frequency Element ===\n\n");

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    /* Edge case: validate size */
    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Number of elements must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxFreq;
    int result = findMaxFrequencyElement(arr, n, &maxFreq);

    printf("\nArray: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nElement with maximum frequency: %d (appears %d times)\n", result, maxFreq);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo[] = {1, 3, 2, 3, 4, 3, 2, 2, 2};
    int demoSize = 9;
    printf("Array: ");
    for (i = 0; i < demoSize; i++) {
        printf("%d ", demo[i]);
    }
    int demoFreq;
    int demoResult = findMaxFrequencyElement(demo, demoSize, &demoFreq);
    printf("\nMax frequency element: %d (appears %d times)\n", demoResult, demoFreq);

    return 0;
}
