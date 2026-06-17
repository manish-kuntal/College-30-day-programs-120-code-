/*
 * Q77: Multiply Two Matrices
 * ----------------------------
 * Given matrix A (r1 x c1) and matrix B (r2 x c2), compute A * B.
 * The result matrix C has dimensions r1 x c2.
 *
 * Prerequisite: Number of columns of A must equal number of rows of B (c1 == r2).
 * C[i][j] = sum of A[i][k] * B[k][j] for k = 0 to c1-1
 *
 * Time Complexity: O(r1 * c2 * c1)
 * Space Complexity: O(r1 * c2) for result
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/*
 * multiplyMatrices - Multiplies matrix A (r1 x c1) by matrix B (r2 x c2)
 * @a: first matrix
 * @b: second matrix
 * @result: output matrix (r1 x c2)
 * @r1: rows of A
 * @c1: columns of A (must equal r2)
 * @c2: columns of B
 */
void multiplyMatrices(int a[MAX_ROWS][MAX_COLS], int b[MAX_ROWS][MAX_COLS],
                      int result[MAX_ROWS][MAX_COLS], int r1, int c1, int c2) {
    /* Initialize result matrix to 0 */
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    /* Perform multiplication */
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void readMatrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, const char *name) {
    printf("Enter elements of matrix %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("  %s[%d][%d] = ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, const char *name) {
    printf("%s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%6d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX_ROWS][MAX_COLS], b[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int r1, c1, r2, c2;

    printf("=== Multiply Two Matrices ===\n\n");

    /* Read dimensions of matrix A */
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);

    /* Read dimensions of matrix B */
    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);

    /* Validate dimensions */
    if (r1 <= 0 || r1 > MAX_ROWS || c1 <= 0 || c1 > MAX_COLS ||
        r2 <= 0 || r2 > MAX_ROWS || c2 <= 0 || c2 > MAX_COLS) {
        printf("Error: Dimensions must be between 1 and %d.\n", MAX_ROWS);
        return 1;
    }

    /* Check multiplication compatibility */
    if (c1 != r2) {
        printf("Error: Cannot multiply! Columns of A (%d) must equal rows of B (%d).\n",
               c1, r2);
        return 1;
    }

    readMatrix(a, r1, c1, "A");
    printf("\n");
    readMatrix(b, r2, c2, "B");

    multiplyMatrices(a, b, result, r1, c1, c2);

    printf("\n");
    printMatrix(a, r1, c1, "Matrix A");
    printf("\n");
    printMatrix(b, r2, c2, "Matrix B");
    printf("\n");
    printMatrix(result, r1, c2, "A x B (Product)");

    /* --- Demo Example --- */
    printf("\n--- Demo Example ---\n");
    int demoA[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}};       /* 2x3 */
    int demoB[MAX_ROWS][MAX_COLS] = {{7, 8}, {9, 10}, {11, 12}};  /* 3x2 */
    int demoResult[MAX_ROWS][MAX_COLS];

    multiplyMatrices(demoA, demoB, demoResult, 2, 3, 2);

    printMatrix(demoA, 2, 3, "A");
    printf("x\n");
    printMatrix(demoB, 3, 2, "B");
    printf("=\n");
    printMatrix(demoResult, 2, 2, "A x B");

    return 0;
}
