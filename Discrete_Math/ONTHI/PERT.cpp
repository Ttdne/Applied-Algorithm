#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = INT_MIN;

vector<pair<int, int>> adj[N]; // Danh sách kề (đỉnh, trọng số)
vector<int> topo;             // Thứ tự topo
int dist[N];                  // dist[i]: Đường đi dài nhất đến đỉnh i
bool visited[N];
int n, m;

// Hàm DFS để sắp xếp topo
void dfs(int u) {
    visited[u] = true;
    for (auto [v, w] : adj[u]) {
        if (!visited[v]) dfs(v);
    }
    topo.push_back(u);
}

// Hàm chính để tìm Critical Path
void findCriticalPath(int source) {
    // Sắp xếp topo
    memset(visited, false, sizeof(visited));
    topo.clear();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());

    // Khởi tạo khoảng cách ban đầu
    fill(dist, dist + N+1, INF);
    dist[source] = 0;

    // Duyệt theo thứ tự topo để tìm đường đi dài nhất
    for (int u : topo) {
        for (auto [v, w] : adj[u]) {
            if (dist[u] != INF) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }

    // In kết quả
   /* for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "INF "; // Không có đường đi
        } else {
            cout << dist[i] << " ";
        }
    }*/
    cout << dist[n];
}

int main() {
    cin >> n >> m; // Nhập số đỉnh và số cạnh

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w; // Cạnh từ u đến v với trọng số w
        adj[u].emplace_back(v, w);
    }

    int source;
    cin >> source; // Đỉnh xuất phát
    findCriticalPath(source);

    return 0;
}

