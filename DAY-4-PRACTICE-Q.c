#include <stdio.h>

int main() {
    int n, a[100];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Print original array
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    // Reverse using two pointers
    for (int l = 0, r = n - 1; l < r; l++, r--) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
    }

    // Print reversed array
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }

    return 0;
}

