/*
 * Q46: Write a function for Armstrong number check
 *
 * Description:
 *   An Armstrong (narcissistic) number is a number that equals the sum
 *   of its own digits each raised to the power of the number of digits.
 *   Example: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
 *   Example: 9474 = 9^4 + 4^4 + 7^4 + 4^4 = 9474
 *
 * Logic:
 *   - Count the number of digits in the number.
 *   - Extract each digit and raise it to the power of digit count.
 *   - Sum all these powered values.
 *   - If the sum equals the original number, it's an Armstrong number.
 *
 * Edge Cases:
 *   - Single digit numbers (0-9 are all Armstrong numbers)
 *   - Negative numbers (not considered Armstrong)
 */

#include <stdio.h>
#include <math.h>

/* Function to count the number of digits in a number */
int countDigits(int n) {
    int count = 0;
    int num = (n < 0) ? -n : n;

    if (num == 0) return 1;

    while (num > 0) {
        count++;
        num /= 10;
    }

    return count;
}

/* Function to compute base^exp for integers */
long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

/* Function to check if a number is an Armstrong number */
/* Returns 1 if Armstrong, 0 otherwise */
int isArmstrong(int n) {
    /* Negative numbers are not Armstrong numbers */
    if (n < 0) {
        return 0;
    }

    int digits = countDigits(n);
    long long sum = 0;
    int temp = n;

    /* Extract each digit, raise to power, and add */
    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, digits);
        temp /= 10;
    }

    return (sum == (long long)n);
}

int main() {
    int num;

    printf("=== Armstrong Number Checker ===\n\n");

    /* Read a number from the user */
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Check and display result */
    int digits = countDigits(num);

    if (num < 0) {
        printf("\n%d is NOT an Armstrong number.\n", num);
        printf("(Negative numbers are not Armstrong numbers)\n");
    } else if (isArmstrong(num)) {
        printf("\n%d is an ARMSTRONG number.\n", num);
        /* Show the breakdown */
        printf("Verification: ");
        int temp = num;
        long long sum = 0;
        int first = 1;
        while (temp > 0) {
            int digit = temp % 10;
            if (!first) printf(" + ");
            printf("%d^%d", digit, digits);
            sum += power(digit, digits);
            temp /= 10;
            first = 0;
        }
        printf(" = %lld\n", sum);
    } else {
        printf("\n%d is NOT an Armstrong number.\n", num);
        /* Show what the sum actually equals */
        int temp = num;
        long long sum = 0;
        while (temp > 0) {
            int digit = temp % 10;
            sum += power(digit, digits);
            temp /= 10;
        }
        printf("Sum of digits^%d = %lld (expected %d)\n", digits, sum, num);
    }

    /* Display all Armstrong numbers up to 10000 */
    printf("\n--- Armstrong numbers from 0 to 9999 ---\n");
    int count = 0;
    for (int i = 0; i <= 9999; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal Armstrong numbers found: %d\n", count);

    return 0;
}
