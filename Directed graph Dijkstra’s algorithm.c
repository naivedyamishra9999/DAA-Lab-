#include <stdio.h>
#define V 5
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

    char vertex[V] = {'A', 'B', 'C', 'D', 'E'};

    printf("Vertex\tDistance from Source A\n");
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
            printf("%c\tUnreachable\n", vertex[i]);
        else
            printf("%c\t%d\n", vertex[i], dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0,10,5,0,0},
        {0,0,0,1,0},
        {0,3,0,9,2},
        {0,0,0,0,0},
        {2,0,0,6,0}
    };

    dijkstra(graph, 0);
    return 0;
}