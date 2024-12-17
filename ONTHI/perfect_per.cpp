#include <bits/stdc++.h>
#define MAX 19
#define ll long long
using namespace std;

ll n;
ll cnt = 0; // Đếm số hoán vị hợp lệ
ll A[MAX];  // Mảng chứa hoán vị
bool visited[MAX]; // Đánh dấu các số đã được sử dụng

// Hàm kiểm tra nếu số `j` có thể đặt vào vị trí `i`
bool check(int j, int i) {
    if (visited[j]) return false; // Số đã dùng thì bỏ qua
    if (i > 1 && abs(A[i - 1] - j) == 1) return false; // Kiểm tra không được có hai số liên tiếp
    return true;
}

// Hàm quay lui để tìm hoán vị
void Try(int i) {
    if (i > n) { // Nếu đã điền đủ n vị trí
        cnt++;
        return;
    }
    for (int j = 1; j <= n; j++) { // Thử tất cả các số từ 1 đến n
        if (check(j, i)) { // Kiểm tra xem số j có hợp lệ không
            visited[j] = true;  // Đánh dấu j đã sử dụng
            A[i] = j;           // Điền j vào vị trí i
            Try(i + 1);         // Gọi đệ quy cho vị trí tiếp theo
            visited[j] = false; // Backtrack: bỏ đánh dấu j
        }
    }
}

int main() {
    cin >> n; // Nhập giá trị n
    memset(visited, false, sizeof(visited)); // Khởi tạo mảng visited là false
    Try(1); // Bắt đầu quay lui từ vị trí 1
    cout << cnt; // Xuất kết quả
    return 0;
}
