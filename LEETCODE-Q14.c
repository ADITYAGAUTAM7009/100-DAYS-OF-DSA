/*
Problem: Rotate Image
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// Function to rotate the matrix 90 degrees clockwise (in-place)
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    // Allocate memory for matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int matrixColSize = n;  // Since it's n x n

    // Rotate the matrix
    rotate(matrix, n, &matrixColSize);

    // Print rotated matrix
    printf("Rotated matrix (90 degrees clockwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

