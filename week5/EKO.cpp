#include<bits/stdc++.h>
#define N 1000
using namespace std;
int n;
int a[N];
int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        int max_value = 0;
        for(int j=1; j<=i; j++){
            max_value = max(max_value, a[j-1] + dp[i-j]);
        }
    dp[i] = max_value;
    }
    cout<<dp[n];
}
