#include <stdio.h>

int main() {
    int m, n;
    int a[100][100];
    int isSymmetric = 1;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // First check: must be square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Check symmetry: a[i][j] should be equal to a[j][i]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (isSymmetric == 0)
            break;
    }

    // Print result
    if (isSymmetric == 1) {
        printf("Symmetric Matrix");
    } else {
        printf("Not a Symmetric Matrix");
    }

    return 0;
}
