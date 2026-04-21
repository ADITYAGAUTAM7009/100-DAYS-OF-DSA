// Problem: Number of Provinces (LeetCode 547)
// Name: Aditya Gautam

#include <stdlib.h>

// DFS function
void dfs(int** isConnected, int n, int city, int* visited) {
    visited[city] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            dfs(isConnected, n, j, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    
    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, i, visited);
            provinces++;
        }
    }

    return provinces;
}