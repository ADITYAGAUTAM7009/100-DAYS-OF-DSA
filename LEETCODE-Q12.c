/*Problem : Toepltiz matrix
Name : Aditya Gautam
*/
#include <stdio.h>
#include <stdbool.h>

bool isToeplitzMatrix(int matrix[20][20], int m, int n) {
    // Start from row 1 and column 1
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != matrix[i-1][j-1]) {
                return false;  // Not Toeplitz
            }
        }
    }
    return true; // All diagonals matched
}

int main() {
    int m, n;
    int matrix[20][20];

    // Input m and n
    scanf("%d %d", &m, &n);

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check Toeplitz
    if (isToeplitzMatrix(matrix, m, n)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}
