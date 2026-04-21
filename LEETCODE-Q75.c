// Problem: Is Graph Bipartite (LeetCode 785)
// Name: Aditya Gautam

#include <stdbool.h>
#include <stdlib.h>

// DFS function
bool dfs(int** graph, int graphSize, int* graphColSize, int* color, int node, int currColor) {
    
    color[node] = currColor;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];

        // If not colored
        if (color[neighbor] == -1) {
            if (!dfs(graph, graphSize, graphColSize, color, neighbor, 1 - currColor)) {
                return false;
            }
        }
        // If same color → conflict
        else if (color[neighbor] == currColor) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    
    int* color = (int*)malloc(graphSize * sizeof(int));

    // Initialize all nodes as uncolored
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    // Handle disconnected graph
    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            if (!dfs(graph, graphSize, graphColSize, color, i, 0)) {
                return false;
            }
        }
    }

    return true;
}