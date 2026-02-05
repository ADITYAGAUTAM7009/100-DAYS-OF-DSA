#include <stdio.h>

// Merge function (same logic as problem)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;        // last valid element in nums1
    int j = n - 1;        // last element in nums2
    int k = m + n - 1;    // last position in nums1

    // Merge from the back
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}

int main() {
    int m, n;

    printf("Enter m: ");
    scanf("%d", &m);

    printf("Enter n: ");
    scanf("%d", &n);

    int nums1Size = m + n;
    int nums2Size = n;

    int nums1[205], nums2[205];

    printf("Enter %d elements of nums1 (last %d should be 0):\n", nums1Size, n);
    for (int i = 0; i < nums1Size; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter %d elements of nums2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Call merge function
    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    // Print result
    printf("Merged array:\n");
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
