/* Đây là code phù hợp để giải quyết các bài toán về chi phí tối ưu trong hợp nhất đoạn*/
#include<bits/stdc++.h>
#define MAX 403
#define ll unsigned long long
using namespace std;
ll n;
ll a[MAX];
ll dp[MAX][MAX];
ll prefix[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=1; i<=n; i++) cin>>a[i];
    for(ll i=1; i<n; i++){
        for(ll j=i+1; j<=n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = ULLONG_MAX;
        }
    }
    prefix[1] = a[1];
    for(ll i=2; i<=n; i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    for (ll len = 2; len <= n; len++) { // Độ dài đoạn
        for (ll i = 1; i <= n - len + 1; i++) {
            ll j = i + len - 1;
            dp[i][j] = ULLONG_MAX; // Khởi tạo giá trị lớn
            for(ll k=i; k<j; k++){
            dp[i][j] = min(dp[i][k] + dp[k+1][j] + prefix[j] - prefix[i-1], dp[i][j]);
            }
        }
    }
    cout<<dp[1][n];
}
