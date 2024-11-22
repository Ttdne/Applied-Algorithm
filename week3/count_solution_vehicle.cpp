#include<bits/stdc++.h>
#define MAX 102
#define MOD 100000
using namespace std;

// dp[n][k]: số cách chia n đơn hàng cho k xe
int dp[MAX + 1][MAX + 1] = {0};

int main() {
    int N, K;
    cin >> N >> K;

    // Điều kiện cơ sở: có 1 cách chia 0 đơn hàng cho 0 xe
    for (int i = 0; i < 102; i++){
        for(int j=0; j<=i; j++){
            if(i == j || j==0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            }
        }
    }
    // Sử dụng quy hoạch động để tính số cách chia N đơn hàng cho K xe

    // Kết quả là số cách chia N đơn hàng cho K xe
    int result = dp[N-1][K-1];

    // Tính tổng số cách sắp xếp các đơn hàng (hoán vị)
    for (int i = K+1; i <= N; i++) {
        result = (result * i) % MOD;
    }

    cout << result << endl;
    return 0;
}
