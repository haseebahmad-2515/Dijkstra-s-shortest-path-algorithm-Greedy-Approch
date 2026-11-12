#include <iostream>
#include <climits>
using namespace std;

#define N 6
#define INF INT_MAX

void dijkstra(int graph[N + 1][N + 1], int src)
{
    int dist[N + 1];
    bool visited[N + 1];

    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 1; count <= N; count++)
    {
        // find the unvisited vertex with minimum distance
        int minDist = INF;
        int u = -1;

        for (int j = 1; j <= N; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // relaxation: if d[u] + c(u,v) < d[v], then d[v] = d[u] + c(u,v)
        for (int v = 1; v <= N; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Shortest distances from source " << src << ":\n";

    for (int i = 1; i <= N; i++)
    {
        cout << src << " to " << i << " = ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main()
{
    int graph[N + 1][N + 1] = {0};

    graph[1][2] = 50;
    graph[1][3] = 45;
    graph[1][4] = 10;
    graph[2][3] = 10;
    graph[2][4] = 15;
    graph[3][5] = 30;
    graph[4][1] = 10;
    graph[4][5] = 15;
    graph[5][2] = 20;
    graph[5][3] = 35;
    graph[6][5] = 3;

    dijkstra(graph, 1);

    return 0;
}