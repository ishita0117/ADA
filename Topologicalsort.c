#include <stdio.h>

#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u -> v:\n");

    for(int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        indegree[v]++;
    }

    // Add vertices with indegree 0 to queue
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Sorting: ");

    int count = 0;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for(int i = 0; i < n; i++) {
            if(graph[node][i]) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Cycle detection
    if(count != n) {
        printf("\nGraph contains a cycle. Topological sort not possible.");
    }

    return 0;
}
