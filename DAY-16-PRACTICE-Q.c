/*
PROBLEM : Frequency Counter in Array
NAME : ADITYA GAUTAM 
*/

#include <stdio.h>

int main() {
    int n, i, j, c;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        if(a[i] == -1) continue;

        c = 1;
        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                c++;
                a[j] = -1;   // mark duplicate
            }
        }
        printf("%d:%d ", a[i], c);
    }

    return 0;
}
