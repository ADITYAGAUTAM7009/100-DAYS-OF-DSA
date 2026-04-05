// Sum of Left Leaves - Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

// Tree structure
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

// Helper function
int helper(struct TreeNode* root, int isLeft) {
    if (root == NULL) return 0;

    // If leaf node and it's a left child
    if (root->left == NULL && root->right == NULL && isLeft)
        return root->val;

    return helper(root->left, 1) + helper(root->right, 0);
}

// Main logic function
int sumOfLeftLeaves(struct TreeNode* root) {
    return helper(root, 0);
}

// Driver code
int main() {
    // Creating tree:
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int result = sumOfLeftLeaves(root);

    printf("Sum of Left Leaves: %d\n", result); // Expected: 24

    return 0;
}