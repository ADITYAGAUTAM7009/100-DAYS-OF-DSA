/*
Problem: Transpose of a Matrix
Name: Aditya Gautam
*/

#include <stdio.h>

int main() {
    int m, n;

    // Ask for rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int transpose[n][m];

    // Input matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Compute transpose
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print transpose matrix
    printf("Transpose of the matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", transpose[i][j]);
            if (j < m - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
