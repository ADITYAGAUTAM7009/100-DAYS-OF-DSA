/*
Problem: Binary Tree Inorder Traversal
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
    dfs(r->left,a,s);
    a[(*s)++]=r->val;
    dfs(r->right,a,s);
}

int* inorderTraversal(struct TreeNode* root,int* returnSize){
    int *res=malloc(100*sizeof(int));
    *returnSize=0;
    dfs(root,res,returnSize);
    return res;
}