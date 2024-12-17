#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N, T, D;
ll a[1003];
ll t[1003];
ll f[1003][103];
int main(){
    cin>>N>>T>>D;
    ll res=0;
    for(ll i=1; i<=N;i++)  cin>>a[i];
    for(ll i=1; i<=N;i++)  cin>>t[i];
    for(ll k=1; k<=T; k++){
        for(ll i=1; i<= N; i++){
            if(t[i] > k)    f[i][k] = 0;
            else{
                for(ll j= max((ll)0,i-D); j<= i-1; j++){
                    f[i][k] = max(f[i][k], f[j][k-t[i]] + a[i]);
                }
            }
            res = max(res, f[i][k]);
        }
    }
    cout<<res;
}
