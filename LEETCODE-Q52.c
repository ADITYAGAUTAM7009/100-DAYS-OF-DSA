/*
Problem: Vertical Order Traversal
Name: Aditya Gautam

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Node* newNode(int val){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* buildTree(int arr[], int n){
    if(n==0||arr[0]==-1) return NULL;

    struct Node* root=newNode(arr[0]);
    struct Node* q[n];
    int f=0,r=0,i=1;

    q[r++]=root;

    while(i<n){
        struct Node* cur=q[f++];

        if(arr[i]!=-1){
            cur->left=newNode(arr[i]);
            q[r++]=cur->left;
        }
        i++;

        if(i<n && arr[i]!=-1){
            cur->right=newNode(arr[i]);
            q[r++]=cur->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root){
    struct QNode q[1000];
    int f=0,r=0;

    int res[1000][100], sz[1000]={0};
    int min=0,max=0;

    q[r++] = (struct QNode){root,0};

    while(f<r){
        struct QNode t=q[f++];
        int idx=t.hd+500;

        res[idx][sz[idx]++]=t.node->data;

        if(t.hd<min) min=t.hd;
        if(t.hd>max) max=t.hd;

        if(t.node->left) q[r++]=(struct QNode){t.node->left,t.hd-1};
        if(t.node->right) q[r++]=(struct QNode){t.node->right,t.hd+1};
    }

    for(int i=min;i<=max;i++){
        int idx=i+500;
        for(int j=0;j<sz[idx];j++)
            printf("%d ",res[idx][j]);
        printf("\n");
    }
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);
    verticalOrder(root);
}