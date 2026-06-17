/*
 * Q63: Find Pair with Given Sum in Array
 * ----------------------------------------
 * Given an array and a target sum, find a pair of elements
 * whose sum equals the target.
 *
 * Approach: Brute force - check all pairs using nested loops.
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

#include <stdio.h>

#define MAX_SIZE 100

/*
 * findPairWithSum - Finds a pair of elements with the given sum
 * @arr: input array
 * @size: number of elements
 * @targetSum: the desired sum
 * @idx1: pointer to store index of first element of pair
 * @idx2: pointer to store index of second element of pair
 *
 * Returns 1 if a pair is found, 0 otherwise.
 */
int findPairWithSum(int arr[], int size, int targetSum, int *idx1, int *idx2) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                *idx1 = i;
                *idx2 = j;
                return 1; /* Pair found */
            }
        }
    }
    return 0; /* No pair found */
}

/*
 * findAllPairs - Prints all pairs with the given sum
 * @arr: input array
 * @size: number of elements
 * @targetSum: the desired sum
 */
void findAllPairs(int arr[], int size, int targetSum) {
    int found = 0;

    printf("All pairs with sum %d:\n", targetSum);
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("  (%d, %d) at indices [%d, %d]\n", arr[i], arr[j], i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("  No pairs found.\n");
    }
}

int main() {
    int arr[MAX_SIZE], n, targetSum, i;

    printf("=== Find Pair with Given Sum ===\n\n");

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 2 || n > MAX_SIZE) {
        printf("Error: Need at least 2 elements (max %d).\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    /* Find first pair */
    int idx1, idx2;
    if (findPairWithSum(arr, n, targetSum, &idx1, &idx2)) {
        printf("\nFirst pair found: (%d, %d) at indices [%d, %d]\n",
               arr[idx1], arr[idx2], idx1, idx2);
    } else {
        printf("\nNo pair found with sum %d.\n", targetSum);
    }

    /* Find all pairs */
    printf("\n");
    findAllPairs(arr, n, targetSum);

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demo[] = {2, 4, 3, 5, 7, 8, 1};
    int demoSize = 7;
    int demoTarget = 9;

    printf("Array: ");
    for (i = 0; i < demoSize; i++) {
        printf("%d ", demo[i]);
    }
    printf("\nTarget sum: %d\n", demoTarget);
    findAllPairs(demo, demoSize, demoTarget);

    return 0;
}
