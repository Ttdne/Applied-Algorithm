#include <bits/stdc++.h>
using namespace std;

// Số đỉnh trong đồ thị
#define MAX_V 10  // Tăng giá trị MAX_V nếu bạn muốn hỗ trợ đồ thị có nhiều đỉnh hơn.
    int V, E;

void printSolution(int path[]);

/* Hàm kiểm tra xem đỉnh v có thể được thêm vào
ở vị trí 'pos' trong đường đi Hamilton đã được xây dựng (lưu trong 'path[]') */
bool isSafe(int v, bool graph[MAX_V][MAX_V], int path[], int pos) {
    // Kiểm tra xem đỉnh v có phải là đỉnh kề của đỉnh trước đó không
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Kiểm tra xem đỉnh v đã được thêm vào đường đi chưa
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

/* Hàm đệ quy để giải quyết bài toán đường đi Hamilton */
bool hamPathUtil(bool graph[MAX_V][MAX_V], int path[], int pos, int V) {
    // Nếu tất cả các đỉnh đã được thăm
    if (pos == V)
        return true;

    // Thử các đỉnh khác làm ứng cử viên tiếp theo trong đường đi
    for (int v = 1; v < V; v++) {
        // Kiểm tra xem đỉnh v có thể thêm vào đường đi
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Đệ quy để xây dựng phần còn lại của đường đi
            if (hamPathUtil(graph, path, pos + 1, V) == true)
                return true;

            // Nếu thêm đỉnh v không dẫn đến giải pháp, xóa nó
            path[pos] = -1;
        }
    }

    // Nếu không thể thêm đỉnh nào vào đường đi, trả về false
    return false;
}

/* Hàm chính để giải quyết bài toán đường đi Hamilton
Sử dụng hàm hamPathUtil() để giải quyết vấn đề.
Trả về false nếu không có đường đi Hamilton, nếu có, trả về true và in đường đi. */
bool hamPath(bool graph[MAX_V][MAX_V], int V) {
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Bắt đầu từ đỉnh 0
    path[0] = 0;
    if (hamPathUtil(graph, path, 1, V) == false) {
        cout << "\nSolution does not exist";
        return false;
    }

    printSolution(path);
    return true;
}

/* Hàm in ra kết quả */
void printSolution(int path[]) {
    cout << "Solution Exists: Following is one Hamiltonian Path \n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << endl;
}

// Code chính
int main() {
    cout << "Enter number of vertices (V): ";
    cin >> V;
    cout << "Enter number of edges (E): ";
    cin >> E;

    // Khởi tạo ma trận kề
    bool graph[MAX_V][MAX_V] = {0};

    // Nhập các cạnh
    cout << "Enter the edges (u, v) with u, v being vertices: \n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Vì đồ thị vô hướng
    }

    // In ra kết quả
    hamPath(graph, V);

    return 0;
}
