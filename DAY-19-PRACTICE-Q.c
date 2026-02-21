/*
Name: Aditya Gautam
Problem: Find two elements whose sum is closest to zero
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    // If less than 2 elements, no pair possible
    if (n < 2) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), cmp);

    int left = 0;
    int right = n - 1;

    int minSum = abs(arr[left] + arr[right]);
    int x = arr[left];
    int y = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < minSum) {
            minSum = abs(sum);
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0) {
            left++;   // need bigger sum
        } else {
            right--;  // need smaller sum
        }
    }

    // Print the pair
    printf("%d %d", x, y);

    return 0;
}