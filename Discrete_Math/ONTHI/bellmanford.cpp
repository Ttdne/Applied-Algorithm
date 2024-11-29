#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w; // u -> v with weight w
};

const int INF = 1e9;

void bellmanFord(int n, int m, int source, vector<Edge>& edges) {
    vector<int> dist(n + 1, INF);
    dist[source] = 0;

    // Step 1: Relax all edges (V-1) times
    for (int i = 1; i < n; i++) { // Perform (V-1) iterations
        for (const auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.v] > dist[edge.u] + edge.w) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    // Step 2: Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (const auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.v] > dist[edge.u] + edge.w) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle." << endl;
    } else {
        cout << "Shortest distances from source " << source << ":" << endl;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) {
                cout << i << ": INF" << endl;
            } else {
                cout << i << ": " << dist[i] << endl;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges
5
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w; // Edge from u to v with weight w
    }

    int source;
    cin >> source; // Source vertex

    bellmanFord(n, m, source, edges);

    return 0;
}
