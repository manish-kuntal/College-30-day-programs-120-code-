/*
 * Q76: Find Diagonal Sum of a Matrix
 * -------------------------------------
 * Compute the sum of elements on the primary (main) diagonal
 * and the secondary (anti) diagonal of a square matrix.
 *
 * Primary diagonal: elements where row index == column index (i == j)
 * Secondary diagonal: elements where row + column == n - 1
 *
 * Note: For odd-sized matrices, the center element is shared by
 *       both diagonals and should only be counted once for total.
 *
 * Time Complexity: O(n) for each diagonal, O(n^2) for reading input
 * Space Complexity: O(1) extra
 */

#include <stdio.h>

#define MAX_SIZE 10

/*
 * primaryDiagonalSum - Sum of main diagonal elements (top-left to bottom-right)
 * @mat: square matrix
 * @n: dimension of the matrix (n x n)
 */
int primaryDiagonalSum(int mat[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mat[i][i]; /* Row index == Column index */
    }
    return sum;
}

/*
 * secondaryDiagonalSum - Sum of anti-diagonal elements (top-right to bottom-left)
 * @mat: square matrix
 * @n: dimension of the matrix (n x n)
 */
int secondaryDiagonalSum(int mat[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mat[i][n - 1 - i]; /* Row i, Column (n-1-i) */
    }
    return sum;
}

/*
 * totalDiagonalSum - Sum of both diagonals without double-counting center
 * @mat: square matrix
 * @n: dimension of the matrix
 */
int totalDiagonalSum(int mat[MAX_SIZE][MAX_SIZE], int n) {
    int sum = primaryDiagonalSum(mat, n) + secondaryDiagonalSum(mat, n);

    /* If n is odd, the center element was counted twice - subtract once */
    if (n % 2 == 1) {
        sum -= mat[n / 2][n / 2];
    }

    return sum;
}

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int n) {
    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("  [%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        printf("  ");
        for (int j = 0; j < n; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[MAX_SIZE][MAX_SIZE], n;

    printf("=== Diagonal Sum of a Matrix ===\n\n");

    printf("Enter the size of the square matrix (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Size must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    readMatrix(mat, n);

    printf("\nMatrix:\n");
    printMatrix(mat, n);

    int primarySum = primaryDiagonalSum(mat, n);
    int secondarySum = secondaryDiagonalSum(mat, n);
    int totalSum = totalDiagonalSum(mat, n);

    printf("\nPrimary diagonal sum:   %d\n", primarySum);
    printf("Secondary diagonal sum: %d\n", secondarySum);
    printf("Total diagonal sum (no double-counting): %d\n", totalSum);

    /* --- Demo Example --- */
    printf("\n--- Demo Example (3x3 matrix) ---\n");
    int demo[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Matrix:\n");
    printMatrix(demo, 3);

    printf("\nPrimary diagonal (1+5+9):   %d\n", primaryDiagonalSum(demo, 3));
    printf("Secondary diagonal (3+5+7): %d\n", secondaryDiagonalSum(demo, 3));
    printf("Total (1+5+9+3+7, center 5 once): %d\n", totalDiagonalSum(demo, 3));

    /* Demo with 4x4 (even-sized, no center overlap) */
    printf("\n--- Demo: 4x4 Matrix ---\n");
    int demo4[MAX_SIZE][MAX_SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8},
                                     {9, 10, 11, 12}, {13, 14, 15, 16}};
    printf("Matrix:\n");
    printMatrix(demo4, 4);
    printf("Primary diagonal sum: %d\n", primaryDiagonalSum(demo4, 4));
    printf("Secondary diagonal sum: %d\n", secondaryDiagonalSum(demo4, 4));
    printf("Total diagonal sum: %d\n", totalDiagonalSum(demo4, 4));

    return 0;
}
