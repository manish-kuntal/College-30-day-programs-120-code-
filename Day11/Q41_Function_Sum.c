/*
 * Q41: Write a function to find sum of two numbers
 * 
 * Description:
 *   Demonstrates user-defined functions by creating a function
 *   that takes two integers and returns their sum.
 *
 * Logic:
 *   - Define a function sum(a, b) that returns a + b.
 *   - Read two integers from the user.
 *   - Call the function and display the result.
 *
 * Edge Cases:
 *   - Negative numbers
 *   - Zero values
 *   - Large numbers (potential overflow)
 */

#include <stdio.h>
#include <limits.h>

/* Function to find the sum of two integers */
int sum(int a, int b) {
    return a + b;
}

/* Safe sum function that checks for integer overflow */
int safeSum(int a, int b, int *result) {
    /* Check for overflow before performing addition */
    if ((b > 0) && (a > INT_MAX - b)) {
        return 0; /* Overflow detected */
    }
    if ((b < 0) && (a < INT_MIN - b)) {
        return 0; /* Underflow detected */
    }
    *result = a + b;
    return 1; /* Success */
}

int main() {
    int num1, num2, result;

    printf("=== Sum of Two Numbers ===\n\n");

    /* Read two integers from the user */
    printf("Enter first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Check for overflow using safe sum */
    if (safeSum(num1, num2, &result)) {
        printf("\nSum of %d and %d = %d\n", num1, num2, result);
    } else {
        printf("\nWarning: Integer overflow detected!\n");
        /* Still show the result using basic sum (may wrap around) */
        printf("Sum (with possible overflow) of %d and %d = %d\n",
               num1, num2, sum(num1, num2));
    }

    /* Demonstrate with additional examples */
    printf("\n--- Additional Examples ---\n");
    printf("sum(10, 20)   = %d\n", sum(10, 20));
    printf("sum(-5, 3)    = %d\n", sum(-5, 3));
    printf("sum(0, 0)     = %d\n", sum(0, 0));
    printf("sum(-10, -20) = %d\n", sum(-10, -20));

    return 0;
}
