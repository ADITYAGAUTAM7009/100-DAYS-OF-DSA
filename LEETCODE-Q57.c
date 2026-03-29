/* ==========================================
   Problem: Flatten Binary Tree to Linked List
   Name: Aditya Gautam
   ========================================== */

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

// -------- FLATTEN FUNCTION --------
void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            struct TreeNode* temp = curr->left;

            // find rightmost node
            while (temp->right)
                temp = temp->right;

            // connect
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// -------- PRINT LINKED LIST --------
void printList(struct TreeNode* root) {
    while (root) {
        printf("%d ", root->val);
        root = root->right;
    }
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

    flatten(root);

    printList(root);

    return 0;
}