#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int disc[100001], low[100001], parent[100001];
bool articulationPoint[100001];
vector<pair<int, int>> bridges;
int timeCounter = 0;

void dfs(int u) {
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int v : adj[u]) {
        if (disc[v] == -1) {  // If v is not visited
            parent[v] = u;
            children++;

            // Recur for the child vertex
            dfs(v);

            // Check if the subtree rooted at v has a connection back to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // u is an articulation point in the following cases:
            // (1) u is root of DFS tree and has two or more children.
            if (parent[u] == -1 && children > 1)
                articulationPoint[u] = true;

            // (2) u is not root and low[v] >= disc[u]
            if (parent[u] != -1 && low[v] >= disc[u])
                articulationPoint[u] = true;

            // (3) Edge (u, v) is a bridge
            if (low[v] > disc[u])
                bridges.push_back({u, v});
        } else if (v != parent[u]) {
            // Update low value of u for parent function calls.
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // Read the graph
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    // Initialize discovery time and low values for all vertices
    fill(disc, disc + N + 1, -1);
    fill(low, low + N + 1, -1);
    fill(parent, parent + N + 1, -1);

    // Run DFS from all unvisited nodes
    for (int i = 1; i <= N; i++) {
        if (disc[i] == -1) {
            dfs(i);
        }
    }

    // Count the number of articulation points
    int articulationCount = 0;
    for (int i = 1; i <= N; i++) {
        if (articulationPoint[i]) {
            articulationCount++;
        }
    }

    // Print the result
    cout << articulationCount << " " << bridges.size() << endl;

    return 0;
}
