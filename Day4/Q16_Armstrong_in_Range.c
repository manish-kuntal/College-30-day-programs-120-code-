/*
 * Q16: Print Armstrong Numbers in a Range
 * -----------------------------------------
 * This program finds and prints all Armstrong numbers within a
 * user-specified range [start, end].
 *
 * An Armstrong number is a number where the sum of its digits each
 * raised to the power of the total number of digits equals the number itself.
 *
 * Edge cases handled:
 *   - start > end: swap the values.
 *   - No Armstrong numbers in the range: inform the user.
 */

#include <stdio.h>
#include <math.h>

/* Function to check if a number is an Armstrong number */
int is_armstrong(int n) {
    if (n < 0) return 0;

    int original = n;
    int num_digits = 0;
    double sum = 0.0;

    /* Count digits */
    int temp = n;
    if (temp == 0) {
        num_digits = 1;
    } else {
        while (temp != 0) {
            num_digits++;
            temp /= 10;
        }
    }

    /* Calculate sum of digits^num_digits */
    temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, num_digits);
        temp /= 10;
    }

    return ((int)(sum + 0.5) == original);
}

int main() {
    int start, end, count = 0;

    printf("=== Armstrong Numbers in a Range ===\n");
    printf("Enter the start of range: ");
    scanf("%d", &start);
    printf("Enter the end of range  : ");
    scanf("%d", &end);

    /* Swap if start > end */
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
        printf("(Swapped range to [%d, %d])\n", start, end);
    }

    /* Ensure we start from at least 0 */
    if (start < 0) start = 0;

    printf("\nArmstrong numbers between %d and %d:\n", start, end);

    for (int i = start; i <= end; i++) {
        if (is_armstrong(i)) {
            printf("  %d\n", i);
            count++;
        }
    }

    if (count == 0) {
        printf("  No Armstrong numbers found in this range.\n");
    } else {
        printf("\nTotal Armstrong numbers found: %d\n", count);
    }

    return 0;
}
