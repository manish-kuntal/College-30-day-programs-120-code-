/*
 * Q80: Find Column-wise Sum of a Matrix
 * ----------------------------------------
 * Compute the sum of each column in a matrix and display the results.
 * Also identifies the column with the maximum and minimum sum.
 *
 * Time Complexity: O(rows * cols)
 * Space Complexity: O(cols) for storing column sums
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/*
 * computeColumnSums - Computes the sum of each column
 * @mat: input matrix
 * @rows: number of rows
 * @cols: number of columns
 * @colSums: output array to store sum of each column
 */
void computeColumnSums(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int colSums[]) {
    for (int j = 0; j < cols; j++) {
        colSums[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSums[j] += mat[i][j];
        }
    }
}

void readMatrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter elements of %d x %d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("  [%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrixWithColumnSums(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int colSums[]) {
    printf("\nMatrix with column sums:\n");

    /* Print matrix rows */
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%7d", mat[i][j]);
        }
        printf("\n");
    }

    /* Separator line */
    printf("  ");
    for (int j = 0; j < cols; j++) {
        printf("-------");
    }
    printf("\n");

    /* Print column sums */
    printf("  ");
    for (int j = 0; j < cols; j++) {
        printf("%7d", colSums[j]);
    }
    printf("  <-- Column sums\n");
}

int main() {
    int mat[MAX_ROWS][MAX_COLS], colSums[MAX_COLS];
    int rows, cols;

    printf("=== Column-wise Sum of a Matrix ===\n\n");

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Error: Dimensions must be between 1 and %d.\n", MAX_ROWS);
        return 1;
    }

    readMatrix(mat, rows, cols);

    computeColumnSums(mat, rows, cols, colSums);

    printMatrixWithColumnSums(mat, rows, cols, colSums);

    /* Find max and min column sums */
    int maxCol = 0, minCol = 0;
    for (int j = 1; j < cols; j++) {
        if (colSums[j] > colSums[maxCol]) maxCol = j;
        if (colSums[j] < colSums[minCol]) minCol = j;
    }

    printf("\nColumn with maximum sum: Col %d (sum = %d)\n", maxCol, colSums[maxCol]);
    printf("Column with minimum sum: Col %d (sum = %d)\n", minCol, colSums[minCol]);

    /* Total sum of all elements */
    int totalSum = 0;
    for (int j = 0; j < cols; j++) {
        totalSum += colSums[j];
    }
    printf("Total sum of all elements: %d\n", totalSum);

    /* --- Demo Example --- */
    printf("\n--- Demo Example (3x4 matrix) ---\n");
    int demo[MAX_ROWS][MAX_COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int demoColSums[MAX_COLS];

    computeColumnSums(demo, 3, 4, demoColSums);
    printMatrixWithColumnSums(demo, 3, 4, demoColSums);

    printf("\nColumn sums: ");
    for (int j = 0; j < 4; j++) {
        printf("Col %d = %d  ", j, demoColSums[j]);
    }
    printf("\n");

    return 0;
}
