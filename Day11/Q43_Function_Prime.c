/*
 * Q43: Write a function to check prime number
 *
 * Description:
 *   Creates a function that checks whether a given number is prime.
 *   A prime number is a natural number greater than 1 that has no
 *   positive divisors other than 1 and itself.
 *
 * Logic:
 *   - Numbers <= 1 are not prime.
 *   - 2 and 3 are prime.
 *   - Eliminate even numbers and multiples of 3.
 *   - Check divisibility from 5 to sqrt(n), stepping by 6.
 *     (All primes > 3 are of the form 6k +/- 1)
 *
 * Edge Cases:
 *   - Negative numbers (not prime)
 *   - 0 and 1 (not prime)
 *   - 2 (smallest prime, and the only even prime)
 */

#include <stdio.h>
#include <math.h>

/* Function to check if a number is prime */
/* Returns 1 if prime, 0 otherwise */
int isPrime(int n) {
    /* Numbers less than or equal to 1 are not prime */
    if (n <= 1) {
        return 0;
    }

    /* 2 and 3 are prime */
    if (n <= 3) {
        return 1;
    }

    /* Eliminate multiples of 2 and 3 */
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    /* Check for factors from 5 to sqrt(n) */
    /* All primes > 3 are of the form 6k +/- 1 */
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int num;

    printf("=== Prime Number Checker ===\n\n");

    /* Read a number from the user */
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    /* Check and display result */
    if (isPrime(num)) {
        printf("\n%d is a PRIME number.\n", num);
    } else {
        printf("\n%d is NOT a prime number.\n", num);
        /* If not prime and > 1, show a factor */
        if (num > 1) {
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    printf("(It is divisible by %d: %d = %d x %d)\n",
                           i, num, i, num / i);
                    break;
                }
            }
        }
    }

    /* Display primes in a range */
    printf("\n--- Prime numbers from 1 to 50 ---\n");
    int count = 0;
    for (int i = 1; i <= 50; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal primes found: %d\n", count);

    return 0;
}
