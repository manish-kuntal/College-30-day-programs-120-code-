/*
 * Q50: Find sum and average of array elements
 *
 * Description:
 *   Read an array of integers, compute the sum and average.
 *
 * Logic:
 *   - Traverse the array and accumulate the sum.
 *   - Average = sum / number_of_elements (using float for precision).
 *
 * Edge Cases:
 *   - Empty array (division by zero for average)
 *   - Array with all identical elements
 *   - Array with negative numbers
 *   - Large sums (potential integer overflow)
 */

#include <stdio.h>

#define MAX_SIZE 100

/* Function to calculate the sum of array elements */
long long arraySum(int arr[], int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

/* Function to calculate the average of array elements */
double arrayAverage(int arr[], int size) {
    if (size == 0) {
        return 0.0; /* Avoid division by zero */
    }
    return (double)arraySum(arr, size) / size;
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("=== Array Sum and Average ===\n\n");

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
            printf("Error: Invalid input at index %d!\n", i);
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

    /* Calculate and display sum and average */
    long long sum = arraySum(arr, n);
    double avg = arrayAverage(arr, n);

    printf("\n--- Results ---\n");
    printf("Number of elements: %d\n", n);
    printf("Sum of elements:    %lld\n", sum);
    printf("Average:            %.2f\n", avg);

    /* Show step-by-step sum calculation */
    if (n <= 20) {
        printf("\nStep-by-step sum: ");
        for (int i = 0; i < n; i++) {
            printf("%d", arr[i]);
            if (i < n - 1) printf(" + ");
        }
        printf(" = %lld\n", sum);
    }

    /* Additional statistics */
    printf("\nAverage formula: %lld / %d = %.2f\n", sum, n, avg);

    return 0;
}
