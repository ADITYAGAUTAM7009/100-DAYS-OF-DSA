// Problem: Binary Tree Level Order Traversal
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = x;
    n->left = n->right = NULL;
    return n;
}

// Simple queue
struct Node* q[100];
int f = 0, r = 0;

void levelOrder(struct Node* root) {
    if (!root) return;

    q[r++] = root;

    while (f < r) {
        struct Node* t = q[f++];
        printf("%d ", t->val);

        if (t->left)  q[r++] = t->left;
        if (t->right) q[r++] = t->right;
    }
}

int main() {
    // Example tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    levelOrder(root);
    return 0;
}