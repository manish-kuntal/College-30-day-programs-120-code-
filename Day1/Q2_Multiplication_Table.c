/*
 * Q2: Multiplication Table
 * -------------------------
 * This program prints the multiplication table of a given number.
 * The table is printed from 1 to 10 by default.
 *
 * Edge cases handled:
 *   - Works correctly for negative numbers and zero.
 */

#include <stdio.h>

int main() {
    int num;

    printf("=== Multiplication Table ===\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("\nMultiplication Table of %d:\n", num);
    printf("----------------------------\n");

    for (int i = 1; i <= 10; i++) {
        printf("  %d x %2d = %d\n", num, i, num * i);
    }

    return 0;
}
