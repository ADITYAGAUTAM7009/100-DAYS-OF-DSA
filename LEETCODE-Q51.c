/*
  Problem: Lowest Common Ancestor in BST
  Name   : Aditya Gautam
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA (Iterative - Best)
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    struct TreeNode* root = NULL;
    struct TreeNode *pNode = NULL, *qNode = NULL;
    int n, x, p, q;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    // Create temporary nodes for search reference
    pNode = newNode(p);
    qNode = newNode(q);

    struct TreeNode* lca = lowestCommonAncestor(root, pNode, qNode);

    if (lca != NULL)
        printf("LCA: %d", lca->val);
    else
        printf("LCA not found");

    return 0;
}