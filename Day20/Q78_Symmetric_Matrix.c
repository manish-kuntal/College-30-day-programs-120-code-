/*
 * Q78: Check if Matrix is Symmetric
 * ------------------------------------
 * A square matrix is symmetric if it equals its own transpose,
 * i.e., A[i][j] == A[j][i] for all i, j.
 *
 * Prerequisite: Matrix must be square (rows == cols).
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) extra
 */

#include <stdio.h>

#define MAX_SIZE 10

/*
 * isSymmetric - Checks if a square matrix is symmetric
 * @mat: input square matrix
 * @n: dimension (n x n)
 *
 * Returns 1 if symmetric, 0 otherwise.
 * Only needs to check upper triangle against lower triangle.
 */
int isSymmetric(int mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { /* Only check above diagonal */
            if (mat[i][j] != mat[j][i]) {
                return 0; /* Not symmetric */
            }
        }
    }
    return 1; /* All elements match their transpose */
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

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int n, const char *name) {
    printf("%s (%d x %d):\n", name, n, n);
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

    printf("=== Check if Matrix is Symmetric ===\n\n");

    printf("Enter the size of the square matrix (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Size must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    readMatrix(mat, n);

    printf("\n");
    printMatrix(mat, n, "Matrix");

    if (isSymmetric(mat, n)) {
        printf("\nResult: The matrix IS symmetric (A[i][j] == A[j][i] for all i, j).\n");
    } else {
        printf("\nResult: The matrix is NOT symmetric.\n");

        /* Show where symmetry breaks */
        printf("Asymmetric elements:\n");
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] != mat[j][i]) {
                    printf("  A[%d][%d]=%d != A[%d][%d]=%d\n",
                           i, j, mat[i][j], j, i, mat[j][i]);
                }
            }
        }
    }

    /* --- Demo Examples --- */
    printf("\n--- Demo: Symmetric Matrix ---\n");
    int sym[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {2, 5, 6}, {3, 6, 9}};
    printMatrix(sym, 3, "Symmetric");
    printf("Is symmetric? %s\n", isSymmetric(sym, 3) ? "YES" : "NO");

    printf("\n--- Demo: Non-Symmetric Matrix ---\n");
    int nonsym[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(nonsym, 3, "Non-Symmetric");
    printf("Is symmetric? %s\n", isSymmetric(nonsym, 3) ? "YES" : "NO");

    /* 1x1 matrix is always symmetric */
    printf("\n--- Demo: 1x1 Matrix ---\n");
    int single[MAX_SIZE][MAX_SIZE] = {{42}};
    printMatrix(single, 1, "1x1 Matrix");
    printf("Is symmetric? %s\n", isSymmetric(single, 1) ? "YES" : "NO");

    return 0;
}
