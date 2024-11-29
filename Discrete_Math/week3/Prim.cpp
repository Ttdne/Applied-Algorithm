#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int d[MAX]; // trọng số nhỏ nhất để kết nối đỉnh v với cây khung
int near[MAX]; // đỉnh gần nhất thuộc cây khung nối với v
int adj_matrix[MAX][MAX]; // ma trận kề lưu trọng số các cạnh
bool MST[MAX] = {0}; // đánh dấu đỉnh đã thuộc cây khung
int n, m; // số đỉnh và số cạnh

// Tìm đỉnh có trọng số nhỏ nhất chưa thuộc cây khung
int findMin() {
    int minD = INT_MAX;
    int index = -1;
    for (int v = 1; v <= n; v++) { // Duyệt từ 1 đến n
        if (!MST[v] && d[v] < minD) {
            minD = d[v];
            index = v;
        }
    }
    return index;
}

// Thuật toán Prim
void Prim() {
    int sum = 0;
    MST[1] = 1; // Đỉnh bắt đầu là đỉnh 1
    d[1] = 0;
    near[1] = 1;

    // Khởi tạo d[] và near[] cho các đỉnh còn lại
    for (int v = 2; v <= n; v++) {
        d[v] = (adj_matrix[1][v] != 0) ? adj_matrix[1][v] : INT_MAX;
        near[v] = 1;
    }

    // Lặp để thêm (n-1) cạnh vào cây khung
    for (int k = 1; k < n; k++) {
        int v = findMin();
        if (v == -1) break; // Không còn đỉnh nào phù hợp

        MST[v] = true;
        sum += d[v];

        // In ra cạnh được thêm vào MST
        cout << "Cạnh " << near[v] << " - " << v << " với trọng số " << d[v] << endl;

        // Cập nhật d[] và near[] cho các đỉnh chưa thuộc cây khung
        for (int i = 1; i <= n; i++) {
            if (!MST[i] && adj_matrix[v][i] > 0 && d[i] > adj_matrix[v][i]) {
                d[i] = adj_matrix[v][i];
                near[i] = v;
            }
        }
    }

    // In tổng trọng số của cây khung nhỏ nhất
    cout << "Tổng trọng số của cây khung nhỏ nhất: " << sum << endl;
}

int main() {
    cin >> n >> m;

    // Đọc đồ thị và xây dựng ma trận kề
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = c;
        adj_matrix[b][a] = c;
    }

    // Gọi thuật toán Prim
    Prim();

    return 0;
}
