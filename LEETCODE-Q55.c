/* 
   Problem: Binary Tree Right Side View
   Name: Aditya Gautam
    */

#include <stdio.h>
#include <stdlib.h>

// -------- TREE NODE --------
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// -------- CREATE NODE --------
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// -------- BUILD TREE (LEVEL ORDER) --------
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

// -------- RIGHT VIEW FUNCTION --------
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    int* result = (int*)malloc(sizeof(int) * 100);

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            // last node of level
            if (i == size - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }

    return result;
}

// -------- MAIN --------
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    int size = 0;
    int* result = rightSideView(root, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}