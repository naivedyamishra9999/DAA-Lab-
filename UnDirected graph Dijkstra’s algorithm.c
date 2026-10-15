#include <stdio.h>
#define V 9
#define INF 99999

void dijkstra(int graph[V][V], int src)
{
    int dist[V], visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1, min = INF;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source 0\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = {
        {0,4,0,0,8,0,0,0,0},
        {4,0,11,8,0,0,0,0,0},
        {0,11,0,0,7,0,0,0,0},
        {0,8,0,0,0,7,0,0,2},
        {8,0,7,0,0,0,0,0,0},
        {0,0,0,7,0,0,2,6,0},
        {0,0,0,0,0,2,0,4,0},
        {0,0,0,0,0,6,4,0,2},
        {0,0,0,2,0,0,0,2,0}
    };

    dijkstra(graph, 0);
    return 0;
}
