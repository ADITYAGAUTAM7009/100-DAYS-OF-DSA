/*
Problem: Given an integer array, return the maximum subarray sum
NAME : ADITYA GAUTAM
*/

#include <stdio.h>
int maxSubArray(int* nums, int numsSize) {
    int current_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // Either start new subarray or continue old one
        if (current_sum + nums[i] > nums[i])
            current_sum = current_sum + nums[i];
        else
            current_sum = nums[i];

        // Update maximum sum
        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    return max_sum;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubArray(arr, n);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}
