#include <stdio.h>
#include <limits.h>

#define V 100

// Find vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra function
void dijkstra(int graph[V][V], int n, int src) {
    int dist[V];      // Shortest distances
    int visited[V];   // Visited set

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t%d\n", i, dist[i]);
    }
}

// Driver code
int main() {
    int n = 5;

    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 4},
        {5, 2, 9, 0, 2},
        {0, 0, 4, 2, 0}
    };

    int source = 0;

    dijkstra(graph, n, source);

    return 0;
}
