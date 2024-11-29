#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void topologicalSort(int node, vector<bool>& visited, stack<int>& topoStack, vector<vector<pair<int, int>>>& adj) {
    visited[node] = true;
    for (auto& neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            topologicalSort(neighbor.first, visited, topoStack, adj);
        }
    }
    topoStack.push(node);
}

void shortestPathDAG(int n, int source, vector<vector<pair<int, int>>>& adj) {
    // Step 1: Perform Topological Sort
    stack<int> topoStack;
    vector<bool> visited(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topologicalSort(i, visited, topoStack, adj);
        }
    }

    // Step 2: Initialize distances
    vector<int> dist(n+1, INF);
    dist[source] = 0;

    // Step 3: Process nodes in topological order
    while (!topoStack.empty()) {
        int u = topoStack.top();
        topoStack.pop();

        // Relax edges from node u
        if (dist[u] != INF) { // Only proceed if u is reachable
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Step 4: Output distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges
    vector<vector<pair<int, int>>> adj(n+1);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Directed edge u -> v with weight w
    }

    int source;
    cin >> source;

    shortestPathDAG(n, source, adj);

    return 0;
}
