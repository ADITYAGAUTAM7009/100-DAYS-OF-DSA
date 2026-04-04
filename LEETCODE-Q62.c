// Problem: 841. Keys and Rooms
// Name: Aditya Gautam

#include <stdio.h>
#include <stdbool.h>

// DFS function
void dfs(int room, int** rooms, int* roomsColSize, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];

        if (!visited[key]) {
            dfs(key, rooms, roomsColSize, visited);
        }
    }
}

// Main function
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];

    // Initialize visited array
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    // Start DFS from room 0
    dfs(0, rooms, roomsColSize, visited);

    // Check if all rooms visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}