/*
   Problem: Construct Binary Tree from Preorder and Inorder
   Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// ---------- TREE NODE ----------
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ---------- BUILD FUNCTION ----------
struct TreeNode* build(int* preorder, int* preIndex,
                       int inStart, int inEnd, int* map) {
    
    if (inStart > inEnd) return NULL;

    // Create root node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*preIndex];
    root->left = root->right = NULL;

    (*preIndex)++;

    // Find index in inorder
    int inIndex = map[root->val + 10000];

    // Build left & right subtree
    root->left = build(preorder, preIndex, inStart, inIndex - 1, map);
    root->right = build(preorder, preIndex, inIndex + 1, inEnd, map);

    return root;
}

// ---------- MAIN BUILD FUNCTION ----------
struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    int* map = (int*)malloc(sizeof(int) * 20001);

    // Store inorder indices
    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 10000] = i;
    }

    int preIndex = 0;

    return build(preorder, &preIndex, 0, inorderSize - 1, map);
}

// ---------- POSTORDER PRINT ----------
void postorder(struct TreeNode* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// ---------- MAIN ----------
int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int preorder[n], inorder[n];

    // Input preorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    // Input inorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    // Build tree
    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    // Output postorder
    postorder(root);

    return 0;
}