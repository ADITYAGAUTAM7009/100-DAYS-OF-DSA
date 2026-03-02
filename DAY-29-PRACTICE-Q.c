/*
Problem: Rotate Linked List Right by k Places
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int main() {
    int n,k,x,i,len=1;
    scanf("%d",&n);

    struct Node *h=NULL,*t=NULL,*p;

    for(i=0;i<n;i++){
        scanf("%d",&x);
        p=malloc(sizeof(struct Node));
        p->data=x; p->next=NULL;
        if(!h) h=t=p;
        else t=t->next=p;
    }

    scanf("%d",&k);
    if(!h||!h->next){ while(h) printf("%d ",h->data),h=h->next; return 0; }

    p=h; while(p->next) p=p->next,len++;
    k%=len; 
    if(k){
        p->next=h;
        for(i=0;i<len-k;i++) p=p->next;
        h=p->next; p->next=NULL;
    }

    for(p=h;p;p=p->next) printf("%d ",p->data);
}