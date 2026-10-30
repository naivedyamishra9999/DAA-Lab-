
#include <stdio.h>
#define INF 99999

int main() {
    int n, graph[20][20];
    int dist[20], visited[20] = {0};
    int i, j, count, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    for(i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;

    for(count = 0; count < n-1; count++) {
        min = INF;
        u = -1;

        for(i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && graph[u][j] != INF &&
               dist[u] != INF &&
               dist[u] + graph[u][j] < dist[j]) {

                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from source vertex 0:\n");

    for(i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}
