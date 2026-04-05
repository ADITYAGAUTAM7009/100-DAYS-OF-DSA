/*
Problem: Construct Binary Tree from Inorder and Postorder Traversal
Name: Aditya Gautam
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node Definition
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create Node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build Tree
struct TreeNode* build(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex, int map[]) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    int inIndex = map[rootVal + 3000];

    // Build RIGHT first
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex, map);
    root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex, map);

    return root;
}

// Wrapper Function
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    
    int map[6001];

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    int postIndex = postorderSize - 1;

    return build(inorder, postorder, 0, inorderSize - 1, &postIndex, map);
}

// Preorder Traversal (Output)
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Main Function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    printf("Preorder traversal: ");
    preorder(root);

    return 0;
}