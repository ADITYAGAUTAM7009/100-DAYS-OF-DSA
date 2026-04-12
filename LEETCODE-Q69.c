// Problem: Dijkstra’s Algorithm (Shortest Path)
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency List Node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (u -> v)
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap Node
typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[1000];
int size = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// Pop min
HeapNode pop() {
    HeapNode top = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return top;
}

// Dijkstra Function
void dijkstra(int V, Node* adj[], int source) {
    int dist[MAX];

    // Initialize
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    size = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode current = pop();
        int u = current.node;
        int d = current.dist;

        // Skip outdated entries
        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

// Main
int main() {
    int V = 5;
    Node* adj[MAX] = {NULL};

    // Same graph as Python
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 7);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 4, 1);

    int source = 0;

    dijkstra(V, adj, source);

    return 0;
}