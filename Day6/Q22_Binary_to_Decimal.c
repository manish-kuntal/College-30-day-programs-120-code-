/*
 * Q22: Binary to Decimal Conversion
 * -----------------------------------
 * This program converts a binary number (entered as a sequence of 0s and 1s)
 * to its decimal (base-10) equivalent. Each binary digit is multiplied by
 * the corresponding power of 2 and summed up.
 *
 * Edge cases handled:
 *   - Input of 0 (decimal is 0)
 *   - Validation that input contains only 0s and 1s
 *   - Large binary numbers
 */

#include <stdio.h>

/* Function to check if input is a valid binary number (only 0s and 1s) */
int isValidBinary(long long n) {
    if (n < 0) return 0; /* Negative not valid */

    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && digit != 1) {
            return 0; /* Found a digit other than 0 or 1 */
        }
        n /= 10;
    }
    return 1; /* All digits are 0 or 1 */
}

/* Function to convert binary (as long long) to decimal */
int binaryToDecimal(long long binary) {
    int decimal = 0;
    int base = 1; /* Represents 2^0, 2^1, 2^2, ... */

    while (binary > 0) {
        int lastDigit = binary % 10;   /* Extract the last binary digit */
        decimal += lastDigit * base;   /* Multiply by current power of 2 */
        base *= 2;                     /* Move to the next power of 2 */
        binary /= 10;                 /* Remove the last digit */
    }

    return decimal;
}

int main() {
    long long binary;

    printf("=== Binary to Decimal Converter ===\n\n");
    printf("Enter a binary number (e.g., 1010): ");
    scanf("%lld", &binary);

    /* Validate that the input is a proper binary number */
    if (binary < 0) {
        printf("Error: Negative numbers are not supported.\n");
        return 1;
    }

    if (binary != 0 && !isValidBinary(binary)) {
        printf("Error: '%lld' is not a valid binary number.\n", binary);
        printf("A binary number should contain only 0s and 1s.\n");
        return 1;
    }

    int decimal = binaryToDecimal(binary);
    printf("Decimal equivalent: %d\n", decimal);

    /* Demonstrate with a few examples */
    printf("\n--- Additional Examples ---\n");
    long long examples[] = {0, 1, 10, 101, 1010, 1111, 11001, 11111111};
    int count = sizeof(examples) / sizeof(examples[0]);

    for (int i = 0; i < count; i++) {
        printf("Binary %8lld = Decimal %d\n", examples[i], binaryToDecimal(examples[i]));
    }

    return 0;
}
