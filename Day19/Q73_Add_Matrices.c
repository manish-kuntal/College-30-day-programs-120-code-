/*
 * Q73: Add Two Matrices
 * -----------------------
 * Given two matrices of the same dimensions, compute their sum.
 * C[i][j] = A[i][j] + B[i][j]
 *
 * Prerequisite: Both matrices must have the same number of rows and columns.
 * Time Complexity: O(rows * cols)
 * Space Complexity: O(rows * cols) for result matrix
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/*
 * addMatrices - Adds two matrices and stores result
 * @a: first matrix
 * @b: second matrix
 * @result: output matrix (a + b)
 * @rows: number of rows
 * @cols: number of columns
 */
void addMatrices(int a[MAX_ROWS][MAX_COLS], int b[MAX_ROWS][MAX_COLS],
                 int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
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

    printf("=== Add Two Matrices ===\n\n");

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    /* Validate dimensions */
    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Error: Dimensions must be between 1 and %d (rows) / %d (cols).\n",
               MAX_ROWS, MAX_COLS);
        return 1;
    }

    readMatrix(a, rows, cols, "A");
    printf("\n");
    readMatrix(b, rows, cols, "B");

    addMatrices(a, b, result, rows, cols);

    printf("\n");
    printMatrix(a, rows, cols, "Matrix A");
    printf("\n");
    printMatrix(b, rows, cols, "Matrix B");
    printf("\n");
    printMatrix(result, rows, cols, "A + B (Sum)");

    /* --- Demo Example --- */
    printf("\n--- Demo Example (2x3 matrices) ---\n");
    int demoA[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}};
    int demoB[MAX_ROWS][MAX_COLS] = {{7, 8, 9}, {10, 11, 12}};
    int demoResult[MAX_ROWS][MAX_COLS];

    addMatrices(demoA, demoB, demoResult, 2, 3);

    printMatrix(demoA, 2, 3, "Matrix A");
    printf("+\n");
    printMatrix(demoB, 2, 3, "Matrix B");
    printf("=\n");
    printMatrix(demoResult, 2, 3, "Sum");

    return 0;
}
