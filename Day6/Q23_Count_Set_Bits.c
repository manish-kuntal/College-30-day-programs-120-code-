/*
 * Q23: Count Set Bits (Hamming Weight)
 * --------------------------------------
 * This program counts the number of set bits (1s) in the binary
 * representation of a given integer. It demonstrates two methods:
 *   1. Simple method: Check each bit by right-shifting
 *   2. Brian Kernighan's method: Uses n & (n-1) trick (more efficient)
 *
 * Edge cases handled:
 *   - Input of 0 (0 set bits)
 *   - Negative numbers (uses unsigned interpretation)
 *   - Powers of 2 (exactly 1 set bit)
 */

#include <stdio.h>

/* Method 1: Simple approach - check each bit by shifting */
int countSetBitsSimple(unsigned int n) {
    int count = 0;

    while (n > 0) {
        count += (n & 1);  /* Check if the last bit is set */
        n >>= 1;           /* Right shift to check the next bit */
    }

    return count;
}

/*
 * Method 2: Brian Kernighan's Algorithm
 * Key insight: n & (n-1) clears the lowest set bit.
 * So we keep clearing the lowest set bit until n becomes 0.
 * The number of iterations equals the number of set bits.
 */
int countSetBitsKernighan(unsigned int n) {
    int count = 0;

    while (n > 0) {
        n = n & (n - 1);  /* Clear the lowest set bit */
        count++;
    }

    return count;
}

int main() {
    int num;

    printf("=== Count Set Bits (Hamming Weight) ===\n\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    unsigned int unum = (unsigned int)num;

    printf("\nNumber: %d (unsigned: %u)\n", num, unum);
    printf("Set bits (Simple method):    %d\n", countSetBitsSimple(unum));
    printf("Set bits (Kernighan method): %d\n", countSetBitsKernighan(unum));

    /* Show binary representation for clarity */
    printf("Binary: ");
    if (unum == 0) {
        printf("0");
    } else {
        /* Find the highest set bit position */
        int started = 0;
        for (int i = 31; i >= 0; i--) {
            if (unum & (1u << i)) {
                started = 1;
            }
            if (started) {
                printf("%d", (unum >> i) & 1);
            }
        }
    }
    printf("\n");

    /* Demonstrate with a few examples */
    printf("\n--- Additional Examples ---\n");
    printf("%-10s %-15s %s\n", "Number", "Binary", "Set Bits");
    printf("%-10s %-15s %s\n", "------", "------", "--------");

    unsigned int examples[] = {0, 1, 7, 8, 15, 31, 100, 255};
    int count = sizeof(examples) / sizeof(examples[0]);

    for (int i = 0; i < count; i++) {
        printf("%-10u ", examples[i]);

        /* Print binary */
        if (examples[i] == 0) {
            printf("%-15s", "0");
        } else {
            char binStr[33];
            int pos = 0;
            int started = 0;
            for (int j = 31; j >= 0; j--) {
                if (examples[i] & (1u << j)) started = 1;
                if (started) binStr[pos++] = ((examples[i] >> j) & 1) + '0';
            }
            binStr[pos] = '\0';
            printf("%-15s", binStr);
        }

        printf("%d\n", countSetBitsKernighan(examples[i]));
    }

    return 0;
}
