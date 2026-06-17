/*
 * Q48: Write a function for perfect number check
 *
 * Description:
 *   A perfect number is a positive integer that is equal to the sum
 *   of its proper divisors (excluding itself).
 *   Example: 6 = 1 + 2 + 3
 *   Example: 28 = 1 + 2 + 4 + 7 + 14
 *
 * Logic:
 *   - Find all divisors of n from 1 to n/2.
 *   - Sum all the proper divisors.
 *   - If the sum equals n, it is a perfect number.
 *   - Optimization: check divisors up to sqrt(n) and add pairs.
 *
 * Edge Cases:
 *   - Numbers <= 0 (not perfect)
 *   - 1 (not perfect, only proper divisor sum = 0)
 */

#include <stdio.h>
#include <math.h>

/* Function to find sum of proper divisors */
int sumOfDivisors(int n) {
    if (n <= 1) return 0;

    int sum = 1; /* 1 is always a proper divisor for n > 1 */

    /* Check divisors up to sqrt(n) for efficiency */
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            /* Add the paired divisor if it's different */
            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    return sum;
}

/* Function to check if a number is perfect */
/* Returns 1 if perfect, 0 otherwise */
int isPerfect(int n) {
    if (n <= 1) {
        return 0;
    }

    return (sumOfDivisors(n) == n);
}

/* Function to display the proper divisors of a number */
void displayDivisors(int n) {
    if (n <= 1) {
        printf("(none)");
        return;
    }

    int first = 1;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            if (!first) printf(" + ");
            printf("%d", i);
            first = 0;
        }
    }
}

int main() {
    int num;

    printf("=== Perfect Number Checker ===\n\n");

    /* Read a number from the user */
    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Edge case: non-positive numbers */
    if (num <= 0) {
        printf("\nError: Please enter a positive integer.\n");
        printf("Perfect numbers are defined only for positive integers.\n");
        return 1;
    }

    /* Check and display result */
    int divisorSum = sumOfDivisors(num);

    if (isPerfect(num)) {
        printf("\n%d is a PERFECT number!\n", num);
        printf("Proper divisors: ");
        displayDivisors(num);
        printf(" = %d\n", divisorSum);
    } else {
        printf("\n%d is NOT a perfect number.\n", num);
        printf("Sum of proper divisors: ");
        displayDivisors(num);
        printf(" = %d", divisorSum);
        if (divisorSum < num) {
            printf(" (deficient - sum < %d)\n", num);
        } else {
            printf(" (abundant - sum > %d)\n", num);
        }
    }

    /* Display perfect numbers in a range */
    printf("\n--- Perfect numbers from 1 to 10000 ---\n");
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        if (isPerfect(i)) {
            printf("%d = ", i);
            displayDivisors(i);
            printf("\n");
            count++;
        }
    }
    printf("Total perfect numbers found: %d\n", count);

    return 0;
}
