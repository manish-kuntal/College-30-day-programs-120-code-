/*
 * Q75: Transpose a Matrix
 * -------------------------
 * The transpose of a matrix is obtained by interchanging its rows
 * and columns. If A is m x n, then A^T is n x m.
 * A^T[j][i] = A[i][j]
 *
 * Time Complexity: O(rows * cols)
 * Space Complexity: O(rows * cols) for transpose matrix
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/*
 * transposeMatrix - Computes the transpose of a matrix
 * @mat: input matrix (rows x cols)
 * @transpose: output matrix (cols x rows)
 * @rows: number of rows in original
 * @cols: number of columns in original
 */
void transposeMatrix(int mat[MAX_ROWS][MAX_COLS], int transpose[MAX_ROWS][MAX_COLS],
                     int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = mat[i][j];
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
    printf("%s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[MAX_ROWS][MAX_COLS], transpose[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("=== Transpose a Matrix ===\n\n");

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Error: Dimensions must be between 1 and %d (rows) / %d (cols).\n",
               MAX_ROWS, MAX_COLS);
        return 1;
    }

    readMatrix(mat, rows, cols, "A");

    transposeMatrix(mat, transpose, rows, cols);

    printf("\n");
    printMatrix(mat, rows, cols, "Original Matrix A");
    printf("\n");
    /* Note: transpose has 'cols' rows and 'rows' columns */
    printMatrix(transpose, cols, rows, "Transpose A^T");

    /* --- Demo Example --- */
    printf("\n--- Demo Example (2x3 matrix) ---\n");
    int demo[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}};
    int demoTranspose[MAX_ROWS][MAX_COLS];

    transposeMatrix(demo, demoTranspose, 2, 3);

    printMatrix(demo, 2, 3, "Original");
    printf("\n");
    printMatrix(demoTranspose, 3, 2, "Transpose");

    /* Demo with square matrix */
    printf("\n--- Demo: Square Matrix (3x3) ---\n");
    int sq[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sqT[MAX_ROWS][MAX_COLS];

    transposeMatrix(sq, sqT, 3, 3);

    printMatrix(sq, 3, 3, "Original");
    printf("\n");
    printMatrix(sqT, 3, 3, "Transpose");

    return 0;
}
