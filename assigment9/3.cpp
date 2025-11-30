#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// A
class Edge {
public:
    int u, v, w;
};

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) parent[rx] = ry;
            else if (rank[rx] > rank[ry]) parent[ry] = rx;
            else { parent[ry] = rx; rank[rx]++; }
        }
    }
};

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    DSU dsu(n);
    int mst_weight = 0;

    cout << "Kruskal MST edges:\n";

    for (auto e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            cout << e.u << " - " << e.v << " : " << e.w << "\n";
            mst_weight += e.w;
        }
    }

    cout << "Total Weight = " << mst_weight;
}


//B
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST edges:\n";
    int total = 0;

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
        total += graph[i][parent[i]];
    }

    cout << "Total Weight = " << total;
}
