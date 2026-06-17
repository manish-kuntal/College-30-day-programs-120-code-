/*
 * Q10: Print Prime Numbers in a Range
 * -------------------------------------
 * This program prints all prime numbers between two given numbers
 * (inclusive of both endpoints).
 *
 * Approach: For each number in the range, check if it is prime
 *           using trial division up to sqrt of that number.
 *
 * Edge cases handled:
 *   - start > end: swap the values.
 *   - Range contains no primes: inform the user.
 */

#include <stdio.h>
#include <math.h>

/* Function to check if a number is prime */
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    int limit = (int)sqrt((double)n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int start, end, count = 0;

    printf("=== Prime Numbers in a Range ===\n");
    printf("Enter the start of range: ");
    scanf("%d", &start);
    printf("Enter the end of range: ");
    scanf("%d", &end);

    /* Swap if start > end so we always iterate forward */
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
        printf("(Swapped range to [%d, %d])\n", start, end);
    }

    printf("\nPrime numbers between %d and %d:\n", start, end);

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("  %d", i);
            count++;
            /* Print a newline every 10 primes for readability */
            if (count % 10 == 0) printf("\n");
        }
    }

    if (count == 0) {
        printf("  No prime numbers found in this range.\n");
    } else {
        printf("\n\nTotal primes found: %d\n", count);
    }

    return 0;
}
