#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool visited[N];
int degree[N];
int n, m;

// Hàm DFS để kiểm tra liên thông
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

// Hàm kiểm tra đồ thị có thể hướng mạnh liên thông hay không
bool isGraphOrientable() {
    // Bước 1: Kiểm tra liên thông
    memset(visited, false, sizeof(visited));
    dfs(1); // Bắt đầu từ đỉnh đầu tiên

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false; // Không liên thông
        }
    }

    // Bước 2: Kiểm tra bậc của tất cả các đỉnh
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            return false; // Tồn tại đỉnh có bậc lẻ
        }
    }

    // Đồ thị liên thông và tất cả các đỉnh đều có bậc chẵn
    return true;
}

int main() {
    cin >> n >> m; // Số đỉnh và số cạnh

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    if (isGraphOrientable()) {
        cout << "YES, the graph can be oriented to be strongly connected.\n";
    } else {
        cout << "NO, the graph cannot be oriented to be strongly connected.\n";
    }

    return 0;
}
