/*
Problem: Top K Frequent Elements
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

int* topKFrequent(int* nums, int n, int k, int* returnSize) {

    int freq[RANGE] = {0};

    for(int i=0;i<n;i++)
        freq[nums[i] + OFFSET]++;

    int **bucket = calloc(n+1,sizeof(int*));
    int *bucketSize = calloc(n+1,sizeof(int));

    for(int i=0;i<RANGE;i++){
        int f = freq[i];
        if(f>0){
            bucket[f] = realloc(bucket[f], (bucketSize[f]+1) * sizeof(int));
            bucket[f][bucketSize[f]++] = i - OFFSET;
        }
    }

    int *res = malloc(k*sizeof(int));
    int idx = 0;

    for(int i=n;i>=0 && idx<k;i--){
        for(int j=0;j<bucketSize[i] && idx<k;j++)
            res[idx++] = bucket[i][j];
    }

    *returnSize = k;
    return res;
}

int main(){

    int n,k;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int *nums = malloc(n*sizeof(int));

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    printf("Enter k: ");
    scanf("%d",&k);

    int returnSize;
    int *result = topKFrequent(nums,n,k,&returnSize);

    printf("Top %d frequent elements:\n",k);
    for(int i=0;i<returnSize;i++)
        printf("%d ",result[i]);

    printf("\n");

    free(nums);
    free(result);

    return 0;
}