// Problem: 1584. Min Cost to Connect All Points
// Name: Aditya Gautam

#include <limits.h>

#define TABLE_SIZE 1000

int absVal(int x) {
    return x < 0 ? -x : x;
}

int dist(int* a, int* b) {
    return absVal(a[0] - b[0]) + absVal(a[1] - b[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;

    int minDist[TABLE_SIZE];
    int visited[TABLE_SIZE];

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = 0;
    }

    minDist[0] = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int d = dist(points[u], points[v]);
                if (d < minDist[v]) {
                    minDist[v] = d;
                }
            }
        }
    }

    return result;
}