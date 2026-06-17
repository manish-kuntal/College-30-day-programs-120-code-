/*
 * Q42: Write a function to find maximum of two numbers
 *
 * Description:
 *   Creates a function that takes two integers and returns
 *   the larger of the two values.
 *
 * Logic:
 *   - Compare the two numbers using a conditional.
 *   - Return the greater one.
 *
 * Edge Cases:
 *   - Both numbers are equal
 *   - Negative numbers
 *   - One positive and one negative
 */

#include <stdio.h>

/* Function to find the maximum of two integers */
int maximum(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

/* Alternative: using ternary operator */
int maxTernary(int a, int b) {
    return (a >= b) ? a : b;
}

/* Bonus: Find maximum of three numbers using the max function */
int maxOfThree(int a, int b, int c) {
    return maximum(maximum(a, b), c);
}

int main() {
    int num1, num2;

    printf("=== Maximum of Two Numbers ===\n\n");

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

    /* Find and display the maximum */
    int maxVal = maximum(num1, num2);
    printf("\nMaximum of %d and %d = %d\n", num1, num2, maxVal);

    /* Edge case: both numbers equal */
    if (num1 == num2) {
        printf("(Both numbers are equal)\n");
    }

    /* Demonstrate with additional examples */
    printf("\n--- Additional Examples ---\n");
    printf("maximum(10, 20)   = %d\n", maximum(10, 20));
    printf("maximum(-5, -3)   = %d\n", maximum(-5, -3));
    printf("maximum(0, 0)     = %d\n", maximum(0, 0));
    printf("maximum(100, -50) = %d\n", maximum(100, -50));

    /* Demonstrate max of three */
    printf("\n--- Maximum of Three Numbers ---\n");
    printf("maxOfThree(10, 20, 15) = %d\n", maxOfThree(10, 20, 15));
    printf("maxOfThree(-1, -2, -3) = %d\n", maxOfThree(-1, -2, -3));

    return 0;
}
