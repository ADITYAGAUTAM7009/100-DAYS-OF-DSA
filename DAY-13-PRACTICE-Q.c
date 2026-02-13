/*PROBLEM :  Question 1: Boundary-to-Center Matrix Walk
NAME: ADITYA GAUTAM
*/
#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[100][100];

    // Input the matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    // Keep printing until borders cross
    while (top <= bottom && left <= right) {

        // 1. Print top row
        for (int j = left; j <= right; j++) {
            printf("%d ", a[top][j]);
        }
        top++;

        // 2. Print right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", a[i][right]);
        }
        right--;

        // 3. Print bottom row (if still valid)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%d ", a[bottom][j]);
            }
            bottom--;
        }

        // 4. Print left column (if still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", a[i][left]);
            }
            left++;
        }
    }

    return 0;
}
