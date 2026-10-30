
#include <stdio.h>
#define INF 99999

struct Edge {
    int u, v, w;
};

int main() {
    int V, E, i, j;
    int dist[20];
    struct Edge edge[100];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (source destination weight):\n");

    for(i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);
    }

    for(i = 0; i < V; i++)
        dist[i] = INF;

    dist[0] = 0;

    for(i = 1; i <= V-1; i++) {
        for(j = 0; j < E; j++) {

            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            if(dist[u] != INF &&
               dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative weight cycle
    for(j = 0; j < E; j++) {
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;

        if(dist[u] != INF &&
           dist[u] + w < dist[v]) {

            printf("Negative weight cycle detected!\n");
            return 0;
        }
    }

    printf("\nShortest distances from source 0:\n");

    for(i = 0; i < V; i++) {
        if(dist[i] == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}
