// Problem: Redundant Connection (LeetCode 684)
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

// Find function with path compression
int find(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

// Union function
int unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py) {
        return 0; // cycle detected
    }

    parent[px] = py;
    return 1;
}

// Main function required by LeetCode
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));

    // Initialize parent
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If union fails → cycle edge found
        if (!unionSet(parent, u, v)) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = u;
            result[1] = v;
            *returnSize = 2;
            return result;
        }
    }

    *returnSize = 0;
    return NULL;
}