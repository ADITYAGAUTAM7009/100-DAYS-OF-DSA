/*
Problem: Binary Tree Preorder Traversal
Name: Aditya Gautam
*/

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* r,int* a,int* s){
    if(!r) return;
    a[(*s)++]=r->val;
    dfs(r->left,a,s);
    dfs(r->right,a,s);
}

int* preorderTraversal(struct TreeNode* root,int* returnSize){
    int *res=malloc(100*sizeof(int));
    *returnSize=0;
    dfs(root,res,returnSize);
    return res;
}