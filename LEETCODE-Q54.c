#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Zigzag Level Order Traversal
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;
    
    bool leftToRight = true;
    
    while (front < rear) {
        int size = rear - front;
        int* level = (int*)malloc(size * sizeof(int));
        
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;
            
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        
        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
        leftToRight = !leftToRight;
    }
    
    return result;
}