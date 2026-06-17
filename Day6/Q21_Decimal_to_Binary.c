/*
 * Q21: Decimal to Binary Conversion
 * ----------------------------------
 * This program converts a decimal (base-10) number to its binary (base-2)
 * representation. It works by repeatedly dividing the number by 2 and
 * storing the remainders, which form the binary digits in reverse order.
 *
 * Edge cases handled:
 *   - Input of 0 (binary is "0")
 *   - Negative numbers (converted as magnitude with a '-' prefix)
 *   - Large numbers up to the int range
 */

#include <stdio.h>

/* Function to convert a non-negative decimal to binary and print it */
void decimalToBinary(int n) {
    int binary[32]; /* Array to store binary digits (max 32 bits for int) */
    int index = 0;

    /* Special case: zero */
    if (n == 0) {
        printf("0");
        return;
    }

    /* Extract binary digits by repeated division */
    while (n > 0) {
        binary[index] = n % 2;  /* Remainder is the current binary digit */
        n = n / 2;              /* Integer division moves to the next bit */
        index++;
    }

    /* Print binary digits in reverse order (MSB first) */
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int decimal;

    printf("=== Decimal to Binary Converter ===\n\n");
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary representation: ");

    /* Handle negative numbers */
    if (decimal < 0) {
        printf("-");
        decimalToBinary(-decimal); /* Convert the absolute value */
    } else {
        decimalToBinary(decimal);
    }

    printf("\n");

    /* Demonstrate with a few examples */
    printf("\n--- Additional Examples ---\n");
    int examples[] = {0, 1, 5, 10, 25, 100, 255};
    int count = sizeof(examples) / sizeof(examples[0]);

    for (int i = 0; i < count; i++) {
        printf("Decimal %3d = Binary ", examples[i]);
        decimalToBinary(examples[i]);
        printf("\n");
    }

    return 0;
}
