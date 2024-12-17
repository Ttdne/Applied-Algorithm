#include<bits/stdc++.h>
#define ll long long
#define MAX 1003
using namespace std;
int n;
ll a[MAX];
ll dp[MAX];
ll Try(int i){
    if(i == 1)  return a[i];
    if(dp[i] != -1) return dp[i];
    //ll result=0;
    dp[i] = 0;
    for(int j=1; j<=i; j++){
        dp[i] = max(dp[i], Try(i-j) + a[j]);
    }
    //dp[i] = result;
    return dp[i];
}
int main(){
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<Try(n);
}
