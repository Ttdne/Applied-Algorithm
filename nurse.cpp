#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, K1, K2;
int f[1003][2];

int DP() {
    // Khởi tạo các giá trị ban đầu cho mảng f
    f[0][0] = 1;
    f[0][1] = 1;

    // Tính toán giá trị cho các ngày từ K1 + 1 đến N
    for (int i = 1; i <= N; i++) {
        // Tính toán tổng các cách làm việc với các độ dài chu kỳ từ K1 đến K2
        for (int j = K1; j <= K2; j++) {
            if (i - j >= 0) {
                f[i][1] = (f[i][1] + f[i - j][0]) % MOD;
            }
        }
        f[i][0] = f[i - 1][1] % MOD;  // Nếu hôm nay nghỉ, hôm qua phải là làm việc
    }

    // Trả về tổng các cách hợp lệ cho N ngày (có thể kết thúc bằng làm việc hoặc nghỉ)
    return (f[N][0] + f[N][1]) % MOD;
}

int main() {
    cin >> N >> K1 >> K2;
    cout << DP();
    return 0;
}
