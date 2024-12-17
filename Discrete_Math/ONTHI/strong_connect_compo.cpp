#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;  // Maximum number of nodes

vector<int> graph[MAX_N];         // Adjacency list of the graph
vector<int> reverse_graph[MAX_N]; // Adjacency list of the reversed graph
bool visited[MAX_N];              // Visited array
stack<int> finished;              // Stack to store the finishing order

// First DFS to find finishing order
void dfs1(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor);
        }
    }
    finished.push(node);  // Push node to stack after visiting all reachable nodes
}

// Second DFS on the reversed graph
void dfs2(int node) {
    visited[node] = true;
    for (int neighbor : reverse_graph[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor);
        }
    }
}

// Main function to count SCCs
int count_scc(int n) {
    // Step 1: Run DFS on original graph to fill the stack with finishing times
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Step 2: Reverse the graph
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            reverse_graph[v].push_back(u);  // Reverse edge direction
        }
    }

    // Step 3: Run DFS on the reversed graph in the order defined by the stack
    fill(visited, visited + n, false);  // Reset visited array
    int scc_count = 0;

    while (!finished.empty()) {
        int node = finished.top();
        finished.pop();
        if (!visited[node]) {
            dfs2(node);  // Each DFS call finds one SCC
            scc_count++;
        }
    }

    return scc_count;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  // Convert to zero-based indexing for convenience
        graph[u].push_back(v);
    }

    // Output the number of SCCs
    cout << count_scc(n);

    return 0;
}
