/* 
   Problem: Symmetric Binary Tree
   Name: Aditya Gautam
    */

#include <stdio.h>
#include <stdlib.h>

//  TREE NODE 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//  CREATE NODE 
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//  BUILD TREE (LEVEL ORDER) 
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

//  MIRROR CHECK 
int isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (!left && !right) return 1;
    if (!left || !right) return 0;
    if (left->val != right->val) return 0;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

//  SYMMETRIC CHECK 
int isSymmetric(struct TreeNode* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

//  MAIN 
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}