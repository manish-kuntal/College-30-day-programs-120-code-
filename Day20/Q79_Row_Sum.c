/*
 * Q79: Find Row-wise Sum of a Matrix
 * -------------------------------------
 * Compute the sum of each row in a matrix and display the results.
 * Also identifies the row with the maximum and minimum sum.
 *
 * Time Complexity: O(rows * cols)
 * Space Complexity: O(rows) for storing row sums
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/*
 * computeRowSums - Computes the sum of each row
 * @mat: input matrix
 * @rows: number of rows
 * @cols: number of columns
 * @rowSums: output array to store sum of each row
 */
void computeRowSums(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int rowSums[]) {
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSums[i] += mat[i][j];
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

void printMatrixWithRowSums(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int rowSums[]) {
    printf("\nMatrix with row sums:\n");
    printf("  ");
    for (int j = 0; j < cols; j++) {
        printf("%6s%d", "Col", j);
    }
    printf("  |  Sum\n");

    /* Separator line */
    printf("  ");
    for (int j = 0; j < cols + 1; j++) {
        printf("-------");
    }
    printf("----\n");

    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%7d", mat[i][j]);
        }
        printf("  | %d\n", rowSums[i]);
    }
}

int main() {
    int mat[MAX_ROWS][MAX_COLS], rowSums[MAX_ROWS];
    int rows, cols;

    printf("=== Row-wise Sum of a Matrix ===\n\n");

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Error: Dimensions must be between 1 and %d.\n", MAX_ROWS);
        return 1;
    }

    readMatrix(mat, rows, cols);

    computeRowSums(mat, rows, cols, rowSums);

    printMatrixWithRowSums(mat, rows, cols, rowSums);

    /* Find max and min row sums */
    int maxRow = 0, minRow = 0;
    for (int i = 1; i < rows; i++) {
        if (rowSums[i] > rowSums[maxRow]) maxRow = i;
        if (rowSums[i] < rowSums[minRow]) minRow = i;
    }

    printf("\nRow with maximum sum: Row %d (sum = %d)\n", maxRow, rowSums[maxRow]);
    printf("Row with minimum sum: Row %d (sum = %d)\n", minRow, rowSums[minRow]);

    /* --- Demo Example --- */
    printf("\n--- Demo Example (3x4 matrix) ---\n");
    int demo[MAX_ROWS][MAX_COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int demoRowSums[MAX_ROWS];

    computeRowSums(demo, 3, 4, demoRowSums);
    printMatrixWithRowSums(demo, 3, 4, demoRowSums);

    printf("\nRow sums: ");
    for (int i = 0; i < 3; i++) {
        printf("Row %d = %d  ", i, demoRowSums[i]);
    }
    printf("\n");

    return 0;
}
