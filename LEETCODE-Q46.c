// Problem: Maximum Depth of Binary Tree
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int x) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val = x;
    n->left = n->right = NULL;
    return n;
}

// Function to calculate max depth
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left > right ? left : right) + 1;
}

// -------- MAIN FUNCTION --------
int main() {
    // Example tree: [3,9,20,null,null,15,7]

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int depth = maxDepth(root);

    printf("Maximum Depth: %d\n", depth);

    return 0;
}