/*
PROBLEM : COUNT SUBARRAYS WITH SUM ZERO
NAME : ADITYA GAUTAM
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum[n + 1];
    prefixSum[0] = 0;

    // Build prefix sum array
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    int count = 0;

    // Check all pairs (i, j)
    // If prefixSum[i] == prefixSum[j], then subarray (i to j-1) has sum 0
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (prefixSum[i] == prefixSum[j]) {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}