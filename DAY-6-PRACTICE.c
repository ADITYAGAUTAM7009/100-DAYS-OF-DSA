/*
Problem: Remove duplicates & print only unique elements 
Name: Aditya Gautam
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];   // simple fixed size array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print first element
    printf("%d ", arr[0]);

    // Print only when current is different from previous
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
