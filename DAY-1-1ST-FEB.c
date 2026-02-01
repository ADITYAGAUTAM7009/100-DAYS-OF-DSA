#include <stdio.h>

int main() {
    int nums[100];
    int n, target;
    int i, j;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input target value
    printf("Enter target: ");
    scanf("%d", &target);

    // Two Sum logic (brute force)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Indices: [%d, %d]\n", i, j);
                return 0;
            }
        }
    }

    // If no pair found
    printf("No pair found\n");
    return 0;
}
