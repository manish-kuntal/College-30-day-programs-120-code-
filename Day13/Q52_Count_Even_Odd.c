/*
 * Q52: Count even and odd elements in array
 *
 * Description:
 *   Read an array of integers and count how many elements are even
 *   and how many are odd.
 *
 * Logic:
 *   - A number is even if n % 2 == 0, odd otherwise.
 *   - Traverse the array and count each type.
 *
 * Edge Cases:
 *   - Array with all even numbers
 *   - Array with all odd numbers
 *   - Zero (zero is even)
 *   - Negative numbers (even/odd still applies)
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to count even elements */
int countEven(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

/* Function to count odd elements */
int countOdd(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

/* Function to count and store even and odd elements separately */
void separateEvenOdd(int arr[], int size,
                     int even[], int *evenCount,
                     int odd[], int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[(*evenCount)++] = arr[i];
        } else {
            odd[(*oddCount)++] = arr[i];
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int even[MAX_SIZE], odd[MAX_SIZE];
    int n, evenCount, oddCount;

    printf("=== Count Even and Odd Elements ===\n\n");

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

    /* Separate and count even and odd elements */
    separateEvenOdd(arr, n, even, &evenCount, odd, &oddCount);

    /* Display results */
    printf("\n--- Results ---\n");
    printf("Total elements: %d\n", n);
    printf("Even count:     %d\n", evenCount);
    printf("Odd count:      %d\n", oddCount);

    /* Display even elements */
    printf("\nEven elements: ");
    if (evenCount == 0) {
        printf("(none)");
    } else {
        printf("{ ");
        for (int i = 0; i < evenCount; i++) {
            printf("%d", even[i]);
            if (i < evenCount - 1) printf(", ");
        }
        printf(" }");
    }
    printf("\n");

    /* Display odd elements */
    printf("Odd elements:  ");
    if (oddCount == 0) {
        printf("(none)");
    } else {
        printf("{ ");
        for (int i = 0; i < oddCount; i++) {
            printf("%d", odd[i]);
            if (i < oddCount - 1) printf(", ");
        }
        printf(" }");
    }
    printf("\n");

    /* Percentage breakdown */
    printf("\nPercentage: %.1f%% even, %.1f%% odd\n",
           (double)evenCount / n * 100,
           (double)oddCount / n * 100);

    return 0;
}
