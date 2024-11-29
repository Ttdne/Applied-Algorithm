#include <iostream>
#include <list>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// Khai báo toàn cục
int V;                    // Số đỉnh
list<int>* adj;           // Mảng động danh sách kề

// Thêm cạnh vào đồ thị
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Hàm DFS kiểm tra liên thông
void DFS(int v, bool visited[]) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            DFS(u, visited);
        }
    }
}

// Kiểm tra đồ thị có liên thông không
bool isConnected() {
    bool visited[V + 1];
    memset(visited, false, sizeof(visited));

    // Tìm một đỉnh có bậc khác 0 để bắt đầu DFS
    int start = -1;
    for (int i = 1; i <= V; i++) {
        if (!adj[i].empty()) {
            start = i;
            break;
        }
    }

    // Nếu không có cạnh nào, đồ thị là liên thông
    if (start == -1) return true;

    // Thực hiện DFS từ đỉnh tìm được
    DFS(start, visited);

    // Kiểm tra tất cả các đỉnh có bậc > 0 đều được thăm
    for (int i = 1; i <= V; i++) {
        if (!visited[i] && !adj[i].empty()) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra Euler Cycle
bool hasEulerCycle() {
    if (!isConnected()) return false;

    // Kiểm tra mọi đỉnh có bậc chẵn
    for (int i = 1; i <= V; i++) {
        if (distance(adj[i].begin(), adj[i].end()) % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra Euler Path
bool hasEulerPath() {
    if (!isConnected()) return false;

    // Đếm số đỉnh có bậc lẻ
    int odd = 0;
    for (int i = 1; i <= V; i++) {
        if (distance(adj[i].begin(), adj[i].end()) % 2 != 0) {
            odd++;
        }
    }

    // Đồ thị có Euler Path nếu và chỉ nếu có 0 hoặc 2 đỉnh bậc lẻ
    return (odd == 0 || odd == 2);
}

// Hàm xóa cạnh (u, v) khỏi đồ thị
void rmvEdge(int u, int v) {
    auto it = find(adj[u].begin(), adj[u].end(), v);
    if (it != adj[u].end()) adj[u].erase(it);

    it = find(adj[v].begin(), adj[v].end(), u);
    if (it != adj[v].end()) adj[v].erase(it);
}

// Đếm số đỉnh có thể tiếp cận từ đỉnh v
int DFSCount(int v, bool visited[]) {
    visited[v] = true;
    int count1 = 1;
    for (auto i : adj[v]) {
        if (!visited[i]) {
            count1 += DFSCount(i, visited);
        }
    }
    return count1;
}

// Kiểm tra cạnh có hợp lệ để đi tiếp không
bool isValidNextEdge(int u, int v) {
    int count = distance(adj[u].begin(), adj[u].end());
    if (count == 1) return true;

    bool visited[V + 1];
    memset(visited, false, sizeof(visited));
    int count1 = DFSCount(u, visited);

    rmvEdge(u, v);
    memset(visited, false, sizeof(visited));
    int count2 = DFSCount(u, visited);

    addEdge(u, v);

    return (count1 <= count2);
}

// In đường Euler
void printEulerUtil(int u) {
    for (auto v : adj[u]) {
        if (v != -1 && isValidNextEdge(u, v)) {
            cout << u << "-" << v << " ";
            rmvEdge(u, v);
            printEulerUtil(v);
        }
    }
}

// In Euler Path hoặc Cycle
void printEulerTour() {
    if (!isConnected()) {
        cout << "Graph is not connected. No Euler Path or Cycle.\n";
        return;
    }

    if (hasEulerCycle()) {
        cout << "Graph has an Euler Cycle:\n";
        printEulerUtil(1);
    } else if (hasEulerPath()) {
        cout << "Graph has an Euler Path:\n";
        int start = 1;
        for (int i = 1; i <= V; i++) {
            if (distance(adj[i].begin(), adj[i].end()) % 2 != 0) {
                start = i;
                break;
            }
        }
        printEulerUtil(start);
    } else {
        cout << "Graph has neither Euler Path nor Euler Cycle.\n";
    }
    cout << endl;
}

int main() {
    cout << "Nhập số lượng đỉnh và cạnh: ";
    cin >> V;

    adj = new list<int>[V + 1];

    int E;
    cout << "Nhập số lượng cạnh: ";
    cin >> E;

    cout << "Nhập các cạnh (u, v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    printEulerTour();
    delete[] adj;

    return 0;
}
