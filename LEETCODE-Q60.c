// Problem: 968. Binary Tree Cameras
// Name: Aditya Gautam

// Global camera counter
int cameras;
int dfs(struct TreeNode* root) {
    if (root == NULL) {
        return 2; // NULL nodes are covered
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is NOT covered → place camera here
    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    // If any child HAS camera → current node is covered
    if (left == 1 || right == 1) {
        return 2;
    }

    // Otherwise → current node is not covered
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0; // IMPORTANT: reset for multiple testcases

    // If root is not covered → place one camera
    if (dfs(root) == 0) {
        cameras++;
    }

    return cameras;
}