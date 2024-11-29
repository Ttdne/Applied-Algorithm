#include <bits/stdc++.h>
#define MAX 10000
#define pii pair<int, int>
using namespace std;

int d[MAX];               // Độ dài đường đi ngắn nhất từ s đến mỗi đỉnh
int p[MAX];               // Đỉnh trước của v trong đường đi ngắn nhất từ s
vector<int> V;            // Danh sách các đỉnh
list<int> adj_list[MAX];  // Danh sách kề
int V_num;                // Số lượng đỉnh
int E;                    // Số lượng cạnh
int w[MAX][MAX];          // Trọng số của các cạnh

// Hàm nhập dữ liệu
void input2() {
    int a, b, weight;
    cin >> V_num >> E;

    // Khởi tạo ma trận trọng số w với giá trị vô cùng lớn
    memset(w, 0x3f, sizeof(w));

    for (int i = 1; i <= V_num; i++) {
        V.push_back(i);  // Thêm các đỉnh vào vector V
    }

    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        adj_list[a].push_back(b);
        w[a][b] = weight;  // Cập nhật trọng số
    }
}

// Thuật toán Dijkstra
void Dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> T;  // Hàng đợi ưu tiên (min-heap)
    unordered_set<int> S_set;  // Lưu các đỉnh đã xử lý

    // Khởi tạo khoảng cách và đường đi
    for (auto v : V) {
        d[v] = INT_MAX;  // Khoảng cách ban đầu là vô hạn
        p[v] = -1;       // Đỉnh trước chưa xác định
    }
    d[s] = 0;            // Khoảng cách từ s đến chính nó là 0
    T.push({0, s});      // Đẩy đỉnh s vào hàng đợi ưu tiên

    while (!T.empty()) {
        pii x = T.top();
        int u = x.second;  // Lấy đỉnh có khoảng cách ngắn nhất
        T.pop();

        // Kiểm tra xem đỉnh u đã được xử lý chưa
        if (S_set.find(u) != S_set.end()) continue;
        S_set.insert(u);  // Đánh dấu đỉnh u đã được xử lý

        // Duyệt tất cả các đỉnh kề của u
        for (auto v : adj_list[u]) {
            if (d[v] > d[u] + w[u][v]) {
                d[v] = d[u] + w[u][v];  // Cập nhật khoảng cách ngắn nhất
                p[v] = u;              // Cập nhật đỉnh trước
                T.push({d[v], v});     // Đẩy v vào hàng đợi ưu tiên
            }
        }
    }
}

int main() {
    // Khởi tạo mảng d và p
    for (int i = 0; i < MAX; i++) {
        d[i] = INT_MAX;
        p[i] = -1;
    }

    input2();  // Nhập dữ liệu

    int s;     // Đỉnh nguồn
    cin >> s;

    Dijkstra(s);  // Chạy thuật toán Dijkstra

    // In kết quả: Khoảng cách từ s đến mỗi đỉnh
    for (int i = 1; i <= V_num; i++) {
        if (d[i] == INT_MAX)
            cout << "INF ";  // Nếu không thể đi đến đỉnh i
        else
            cout << d[i] << " ";
    }

    return 0;
}
