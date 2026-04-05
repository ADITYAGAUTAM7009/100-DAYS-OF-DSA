/*
Problem: Daily Temperatures
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* t,int n,int* r){
    int *ans = calloc(n,sizeof(int));
    int *st = malloc(n*sizeof(int));
    int top = -1;

    for(int i=0;i<n;i++){
        while(top>=0 && t[i] > t[st[top]]){
            int j = st[top--];
            ans[j] = i - j;
        }
        st[++top] = i;
    }

    *r = n;
    return ans;
}

int main(){

    int n;

    printf("Enter number of days: ");
    scanf("%d",&n);

    int *temps = malloc(n*sizeof(int));

    printf("Enter temperatures:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&temps[i]);

    int returnSize;
    int *result = dailyTemperatures(temps,n,&returnSize);

    printf("Days to wait for warmer temperature:\n");
    for(int i=0;i<returnSize;i++)
        printf("%d ",result[i]);

    printf("\n");

    free(temps);
    free(result);

    return 0;
}