/*
Problem: Kth Largest Element in a Stream
Name: Aditya Gautam
*/

#include <stdlib.h>

typedef struct {
    int *h, s, k;
} KthLargest;

void sw(int *a,int *b){int t=*a;*a=*b;*b=t;}

void up(KthLargest* o,int i){
    for(int p;i && o->h[p=(i-1)/2]>o->h[i];i=p) sw(&o->h[p],&o->h[i]);
}

void down(KthLargest* o,int i){
    for(int l,r,s;;i=s){
        l=2*i+1,r=2*i+2,s=i;
        if(l<o->s && o->h[l]<o->h[s]) s=l;
        if(r<o->s && o->h[r]<o->h[s]) s=r;
        if(s==i) break;
        sw(&o->h[i],&o->h[s]);
    }
}

void push(KthLargest* o,int v){o->h[o->s]=v;up(o,o->s++);}
void pop(KthLargest* o){o->h[0]=o->h[--o->s];down(o,0);}

KthLargest* kthLargestCreate(int k,int* nums,int n){
    KthLargest* o=malloc(sizeof(KthLargest));
    o->h=malloc(sizeof(int)*(k+10000)); o->s=0; o->k=k;
    for(int i=0;i<n;i++){push(o,nums[i]); if(o->s>k) pop(o);}
    return o;
}

int kthLargestAdd(KthLargest* o,int v){
    push(o,v);
    if(o->s>o->k) pop(o);
    return o->h[0];
}

void kthLargestFree(KthLargest* o){
    free(o->h); free(o);
}