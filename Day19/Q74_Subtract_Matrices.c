/*
 * Q74: Subtract Two Matrices
 * ----------------------------
 * Given two matrices of the same dimensions, compute their difference.
 * C[i][j] = A[i][j] - B[i][j]
 *
 * Prerequisite: Both matrices must have the same dimensions.
 * Time Complexity: O(rows * cols)
 * Space Complexity: O(rows * cols) for result matrix
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/*
 * subtractMatrices - Subtracts matrix B from matrix A
 * @a: first matrix (minuend)
 * @b: second matrix (subtrahend)
 * @result: output matrix (a - b)
 * @rows: number of rows
 * @cols: number of columns
 */
void subtractMatrices(int a[MAX_ROWS][MAX_COLS], int b[MAX_ROWS][MAX_COLS],
                      int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

/*
 * readMatrix - Reads matrix elements from user input
 */
void readMatrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, const char *name) {
    printf("Enter elements of matrix %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("  %s[%d][%d] = ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

/*
 * printMatrix - Displays matrix in formatted rows
 */
void printMatrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, const char *name) {
    printf("%s:\n", name);
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX_ROWS][MAX_COLS], b[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("=== Subtract Two Matrices ===\n\n");

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Error: Dimensions must be between 1 and %d (rows) / %d (cols).\n",
               MAX_ROWS, MAX_COLS);
        return 1;
    }

    readMatrix(a, rows, cols, "A");
    printf("\n");
    readMatrix(b, rows, cols, "B");

    subtractMatrices(a, b, result, rows, cols);

    printf("\n");
    printMatrix(a, rows, cols, "Matrix A");
    printf("\n");
    printMatrix(b, rows, cols, "Matrix B");
    printf("\n");
    printMatrix(result, rows, cols, "A - B (Difference)");

    /* --- Demo Example --- */
    printf("\n--- Demo Example (2x3 matrices) ---\n");
    int demoA[MAX_ROWS][MAX_COLS] = {{10, 20, 30}, {40, 50, 60}};
    int demoB[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}};
    int demoResult[MAX_ROWS][MAX_COLS];

    subtractMatrices(demoA, demoB, demoResult, 2, 3);

    printMatrix(demoA, 2, 3, "Matrix A");
    printf("-\n");
    printMatrix(demoB, 2, 3, "Matrix B");
    printf("=\n");
    printMatrix(demoResult, 2, 3, "Difference");

    return 0;
}
