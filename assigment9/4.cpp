#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(vector<int> &dist, vector<bool> &visited, int n) {
    int minVal = INT_MAX, minIndex = -1;

    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] <= minVal)
            minVal = dist[i], minIndex = i;

    return minIndex;
}

void dijkstra(vector<vector<int>> &graph, int src, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Dijkstra Shortest Distances from " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 1},
        {1, 2, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    dijkstra(graph, 0, 5);
}
