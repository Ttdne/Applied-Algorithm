#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll a[3004];
ll dp[3004][3004];
ll S[3004];

ll dequy(ll i, ll j) {
    if (i == j) return a[i]; // Nếu chỉ còn một phần tử
    if (dp[i][j] != -1) return dp[i][j]; // Nếu đã tính trước

    // Công thức quy hoạch động
    dp[i][j] = max(
        a[i] - dequy(i+1, j),
        a[j]  - dequy(i, j-1)
    );

    return dp[i][j];
}

int main() {
    cin >> N;

    // Nhập mảng
    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for(ll i=1; i<=N; i++){
        dp[i][i] = a[i];
    }
    // Khởi tạo dp

    // Tính kết quả
    for(ll len = 2; len<=N; len++){
        for(ll i=1; i + len - 1 <=N; i++){
            ll j = i+len -1;
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout<<dp[1][N];
    return 0;
}
