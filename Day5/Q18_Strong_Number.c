/*
 * Q18: Check Strong Number
 * --------------------------
 * A strong number (also called Krishnamurthy number) is a number
 * where the sum of the factorials of its digits equals the number itself.
 *
 * Examples: 145 = 1! + 4! + 5! = 1 + 24 + 120 = 145 (Strong)
 *           40585 = 4! + 0! + 5! + 8! + 5! = 24 + 1 + 120 + 40320 + 120 = 40585
 *
 * Edge cases handled:
 *   - n <= 0: not a strong number.
 *   - n = 1: 1! = 1, so 1 is a strong number.
 *   - n = 2: 2! = 2, so 2 is a strong number.
 */

#include <stdio.h>

/* Function to compute factorial of a single digit (0-9) */
long long factorial(int d) {
    long long result = 1;
    for (int i = 2; i <= d; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    long long sum = 0;

    printf("=== Strong Number Check ===\n");
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    /* Edge case: non-positive input */
    if (n <= 0) {
        printf("%d is NOT a strong number.\n", n);
        return 0;
    }

    int original = n;
    int temp = n;

    /* Sum of factorials of each digit */
    printf("Breakdown: ");
    int first = 1;
    while (temp != 0) {
        int digit = temp % 10;
        long long fact = factorial(digit);
        sum += fact;

        if (!first) printf(" + ");
        printf("%d! (=%lld)", digit, fact);
        first = 0;

        temp /= 10;
    }

    printf("\nSum of digit factorials = %lld\n", sum);

    if (sum == original) {
        printf("%d is a STRONG number!\n", original);
    } else {
        printf("%d is NOT a strong number.\n", original);
    }

    return 0;
}
