/*
Problem: Arrange Arrival Logs
Name: Aditya Gautam 
*/
#include <stdio.h>

int main() {
    int p, q;

    printf("Enter number of elements in first array: ");
    scanf("%d", &p);

    int A[p];
    printf("Enter %d elements (sorted):\n", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &q);

    int B[q];
    printf("Enter %d elements (sorted):\n", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0;

    printf("Merged array:\n");

    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", A[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}
