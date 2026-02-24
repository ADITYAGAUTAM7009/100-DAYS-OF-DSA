/*
PROBLEM : MAXIMUM SUM CIRCULAR SUBARRAY
NAME : ADITYA GAUTAM
*/

#include <stdio.h>

// Helper functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int n) {
    int total = nums[0];

    int maxSum = nums[0], curMax = nums[0];
    int minSum = nums[0], curMin = nums[0];

    for (int i = 1; i < n; i++) {
        int x = nums[i];

        // Kadane for maximum subarray sum
        curMax = max(x, curMax + x);
        maxSum = max(maxSum, curMax);

        // Kadane for minimum subarray sum
        curMin = min(x, curMin + x);
        minSum = min(minSum, curMin);

        total += x;
    }

    // If all numbers are negative, return the maximum (normal Kadane result)
    if (maxSum < 0)
        return maxSum;

    // Otherwise, return max of normal and circular
    return max(maxSum, total - minSum);
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);
    printf("%d", result);

    return 0;
}