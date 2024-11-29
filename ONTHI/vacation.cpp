#include<bits/stdc++.h>
#define MAX 100006
using namespace std;
int n;
int happiness[MAX][3];
int dp[MAX][3];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>happiness[i][1]>>happiness[i][2]>>happiness[i][3];
    }
    dp[1][1] = happiness[1][1];
    dp[1][2] = happiness[1][2];
    dp[1][3] = happiness[1][3];
    int result = 0;
    for(int i=2; i<=n; i++){
        dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + happiness[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + happiness[i][2];
        dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + happiness[i][3];
        }
        result = max(dp[n][1], result);
        result = max(dp[n][2], result);
        result = max(dp[n][3], result);
        cout<<result;
}
