#include<bits/stdc++.h>
#define MAX 1000006
using namespace std;
int n;
int a[MAX];
int dp[MAX];
int DP(int i){
    if(i == 1)  return 1;
    if(dp[i] != -1) return dp[i];
    if(a[i-1] < 0){
        if(a[i] <= 0)    dp[i] = DP(i-1);
        else dp[i] = DP(i-1)+ 1;
    }
    else if(a[i-1] > 0){
        if(a[i] >=0)  dp[i] = DP(i-1);
        else dp[i] = DP(i-1) + 1;
    }
    else dp[i] = dp[i-1];
    return dp[i];
}
int main(){
    cin>>n;
    memset(dp, -1, sizeof dp);
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<DP(n);
}
