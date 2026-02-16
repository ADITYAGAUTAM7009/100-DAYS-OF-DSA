/*
PROBLEM : ROTATE ARRAY
NAME : ADITYA GAUTAM
*/

#include <stdio.h>

// Function to reverse part of the array
void reverse(int* nums, int l, int r) {
    while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
    }
}

// Function to rotate array to the right by k steps
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;   // handle k > size

    // Step 1: reverse whole array
    reverse(nums, 0, numsSize - 1);

    // Step 2: reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: reverse remaining elements
    reverse(nums, k, numsSize - 1);
}

int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    // Rotate the array
    rotate(nums, n, k);

    // Print result
    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
