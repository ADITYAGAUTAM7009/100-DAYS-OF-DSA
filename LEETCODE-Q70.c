// Problem: 787. Cheapest Flights Within K Stops
// Name: Aditya Gautam

#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize,
                      int src, int dst, int k) {
    
    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Bellman-Ford for k+1 edges
    for (int i = 0; i <= k; i++) {
        int temp[n];

        // Copy previous distances
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        // Relax all edges
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] == INF) continue;

            if (dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        // Update dist
        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    return (dist[dst] == INF) ? -1 : dist[dst];
}