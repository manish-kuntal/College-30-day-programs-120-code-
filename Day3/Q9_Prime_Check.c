/*
 * Q9: Check Whether a Number is Prime
 * -------------------------------------
 * A prime number is a natural number greater than 1 that has no
 * positive divisors other than 1 and itself.
 *
 * Approach: Check divisibility from 2 up to sqrt(n).
 *           If any number in that range divides n, it's not prime.
 *
 * Edge cases handled:
 *   - n <= 1: not prime.
 *   - n = 2: smallest prime number.
 *   - Even numbers > 2: immediately not prime.
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n, is_prime = 1;

    printf("=== Prime Number Check ===\n");
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    /* Numbers <= 1 are not prime */
    if (n <= 1) {
        is_prime = 0;
    }
    /* 2 is the only even prime */
    else if (n == 2) {
        is_prime = 1;
    }
    /* Eliminate even numbers > 2 */
    else if (n % 2 == 0) {
        is_prime = 0;
    }
    else {
        /* Check odd divisors from 3 to sqrt(n) */
        int limit = (int)sqrt((double)n);
        for (int i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    if (is_prime) {
        printf("%d is a PRIME number.\n", n);
    } else {
        printf("%d is NOT a prime number.\n", n);
    }

    return 0;
}
