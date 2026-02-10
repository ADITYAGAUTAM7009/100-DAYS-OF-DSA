/**
Problem : Intersection of 2 arrays
NAME : ADITYA GAUTAM
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};  // because 0 <= nums[i] <= 1000

    // Count frequency of nums1
    for (int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(maxSize * sizeof(int));

    int k = 0;

    // Build intersection using nums2
    for (int i = 0; i < nums2Size; i++) {
        if (freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    *returnSize = k;
    return result;
}
