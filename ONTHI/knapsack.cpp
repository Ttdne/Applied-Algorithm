#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N, W;
ll w[105];
ll v[105];
ll dp[100005];
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>W;
    for(ll i=1; i<=N; i++){
        cin>>w[i]>>v[i];
    }
    memset(dp, 0, sizeof(dp));
    for(ll j=1; j<=N; j++){
        for(ll i=W; i>0; i--){
            if(i >= w[j])
                dp[i] = max(dp[i], dp[i-w[j]] + v[j]);
        }
    }
    cout<<dp[W];
}
