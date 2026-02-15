/*
Problem: Matrix Diagonal Sum
NAME : ADITYA GAUTAM
*/

#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int sum = 0;
    int x;

    printf("Enter matrix elements:\n");

    // Read elements and add only primary diagonal ones
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (i == j) {
                sum += x;
            }
        }
    }

    printf("Sum of primary diagonal elements = %d\n", sum);

    return 0;
}
