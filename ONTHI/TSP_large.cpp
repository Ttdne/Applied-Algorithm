#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Giá trị vô hạn hợp lý
int n, m;
int c[21][21];
int f[21][1 << 21];

int TSP_Large(int i, int mask) {
    if (mask == (1 << n) - 1) {
        return c[i][0] != INF ? c[i][0] : INF; // Kiểm tra cạnh quay về
    }
    if (f[i][mask] != -1) return f[i][mask];

    int res = INF;
    for (int j = 0; j < n; j++) {
        if (!(mask & (1 << j)) && c[i][j] != INF) { // Chỉ xử lý cạnh hợp lệ
            res = min(res, TSP_Large(j, mask | (1 << j)) + c[i][j]);
        }
    }
    return f[i][mask] = res;
}

int main() {
    cin >> n >> m;

    // Khởi tạo ma trận chi phí
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = INF; // Giá trị vô hạn
        }
    }

    // Nhập các cạnh
    int a, b, d;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        c[a - 1][b - 1] = d; // Chỉ số 0-based
    }

    // Khởi tạo mảng nhớ
    memset(f, -1, sizeof(f));

    // Gọi hàm TSP từ đỉnh 0 với trạng thái ban đầu (mask = 1)
    int result = TSP_Large(0, 1);

    // Xuất kết quả
    if (result == INF) cout << -1;
    else cout << result;

    return 0;
}
