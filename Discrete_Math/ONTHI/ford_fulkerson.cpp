#include <bits/stdc++.h>
using namespace std;

// Hàm DFS đệ quy để tìm đường tăng
bool dfsRecursive(vector<vector<int>>& residualGraph, vector<int>& parent, vector<bool>& visited, int u, int sink) {
    // Nếu đạt đến đỉnh đích, kết thúc tìm kiếm
    if (u == sink) return true;

    visited[u] = true;

    // Duyệt qua các đỉnh kề
    for (int v = 1; v < residualGraph.size(); v++) {
        // Nếu chưa thăm và còn khả năng chảy từ u -> v
        if (!visited[v] && residualGraph[u][v] > 0) {
            parent[v] = u; // Lưu lại đường đi
            // Đệ quy để tiếp tục tìm kiếm
            if (dfsRecursive(residualGraph, parent, visited, v, sink)) {
                return true;
            }
        }
    }
    return false;
}

// Hàm Ford-Fulkerson
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int V = graph.size() - 1; // Số đỉnh (đỉnh bắt đầu từ 1 đến V)
    vector<vector<int>> residualGraph = graph; // Đồ thị dư ban đầu
    vector<int> parent(V + 1); // Mảng lưu đường đi

    int maxFlow = 0; // Luồng cực đại ban đầu bằng 0

    // Lặp tìm đường tăng cho đến khi không còn đường tăng
    while (true) {
        vector<bool> visited(V + 1, false);
        // Tìm đường tăng sử dụng DFS đệ quy
        if (!dfsRecursive(residualGraph, parent, visited, source, sink)) break;

        // Tìm luồng tăng nhỏ nhất trên đường tăng
        int pathFlow = INT_MAX;
        vector<int> path;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path.push_back(v);
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        path.push_back(source);
        reverse(path.begin(), path.end());
        cout << "Augmenting path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\nPath capacity: " << pathFlow << endl;

        // Cập nhật đồ thị dư
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        // Cộng luồng tăng vào luồng cực đại
        maxFlow += pathFlow;
    }

    return maxFlow;
}

// Hàm chính
int main() {
    // Nhập số đỉnh và số cạnh
    int V, E;
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> V >> E;

    // Kích thước `V+1` để lưu đỉnh từ 1 đến V
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));

    cout << "Nhập các cạnh (u, v, capacity):\n";
    for (int i = 0; i < E; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] += capacity; // Cộng giá trị nếu cạnh trùng
    }

    int source, sink;
    cout << "Nhập đỉnh nguồn và đỉnh đích: ";
    cin >> source >> sink;

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Luồng cực đại là: " << maxFlow << endl;

    return 0;
}
