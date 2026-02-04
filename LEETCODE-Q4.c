/*
Q: Given an integer array nums and an integer val, remove all occurrences of val in nums in-place
   and return the number of elements not equal to val.

Name: Aditya Gautam
*/

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;  // index for valid elements

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];  // move valid element to front
        }
    }
    return k;  // number of elements not equal to val
}
