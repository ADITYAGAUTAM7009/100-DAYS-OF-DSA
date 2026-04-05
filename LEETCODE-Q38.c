/*
Problem: Sliding Window Maximum
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int n, int k, int* returnSize)
{
    int *result = (int*)malloc((n - k + 1) * sizeof(int));
    int *deque = (int*)malloc(n * sizeof(int));

    int front = 0, back = 0;
    *returnSize = n - k + 1;

    for(int i = 0; i < n; i++)
    {
        /* Remove elements out of window */
        if(front < back && deque[front] <= i - k)
            front++;

        /* Remove smaller elements from back */
        while(front < back && nums[deque[back - 1]] < nums[i])
            back--;

        deque[back++] = i;

        /* Store result when window is ready */
        if(i >= k - 1)
            result[i - k + 1] = nums[deque[front]];
    }

    return result;
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter window size k: ");
    scanf("%d", &k);

    int returnSize;
    int *ans = maxSlidingWindow(nums, n, k, &returnSize);

    printf("Sliding Window Maximums:\n");
    for(int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);

    printf("\n");

    free(nums);
    free(ans);

    return 0;
}