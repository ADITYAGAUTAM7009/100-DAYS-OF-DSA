// Problem: 994. Rotting Oranges
// Name: Aditya Gautam

#include <stdio.h>

#define SIZE 10   // changed from MAX → no conflict

// Queue structure using array
typedef struct {
    int x, y;
} Pair;

Pair queue[SIZE * SIZE];
int front = 0, rear = 0;

// Enqueue
void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

// Dequeue
Pair dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front == rear;
}

// Function to solve problem
int orangesRotting(int grid[SIZE][SIZE], int m, int n) {
    
    int fresh = 0;
    int minutes = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // Reset queue pointers
    front = rear = 0;

    // Step 1: Push all rotten + count fresh
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // BFS
    while (!isEmpty() && fresh > 0) {
        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {
            Pair p = dequeue();

            for (int d = 0; d < 4; d++) {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                }
            }
        }
    }

    if (fresh == 0) return minutes;
    return -1;
}

// Driver code
int main() {
    int m, n;
    int grid[SIZE][SIZE];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter grid (0,1,2):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, m, n);

    printf("Minimum minutes: %d\n", result);

    return 0;
}