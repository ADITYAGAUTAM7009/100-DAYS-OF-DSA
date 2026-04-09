// Problem: Undirected Graph Cycle Detection using DFS
// Author: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int V;

// DFS function
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1) {
            // If not visited → go deeper
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            }
            // If visited and not parent → cycle
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to detect cycle
int hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int E;
    scanf("%d", &V);
    scanf("%d", &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
