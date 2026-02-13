/*
PROBLEM : SPIRAL MATRIX
NAME : ADITYA GAUTAM
*/
#include <stdio.h>
#include <stdlib.h>

// Function to return spiral order
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;          // rows
    int n = matrixColSize[0];    // columns

    int* ans = (int*)malloc(m * n * sizeof(int));
    int k = 0;

    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= bottom && left <= right) {

        // top row
        for (int j = left; j <= right; j++) {
            ans[k++] = matrix[top][j];
        }
        top++;

        // right column
        for (int i = top; i <= bottom; i++) {
            ans[k++] = matrix[i][right];
        }
        right--;

        // bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                ans[k++] = matrix[bottom][j];
            }
            bottom--;
        }

        // left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans[k++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = k;
    return ans;
}

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    // Allocate matrix
    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }

    // Input matrix
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int colSize = c;

    // Call function
    int* result = spiralOrder(matrix, r, &colSize, &returnSize);

    // Print result
    printf("Spiral Order: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    // Free memory
    free(result);
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
