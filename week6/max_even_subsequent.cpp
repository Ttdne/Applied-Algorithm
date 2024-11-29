#include<bits/stdc++.h>
#define MAX 100005
#define ll long long
using namespace std;
ll n;
ll a[MAX];
ll f[2];
ll S[MAX];
ll res;
void Max(){
    int tmp;
    ll sum = 0;
    f[1] = 1e18;
    for(int i=1; i<=n; i++){
       tmp = abs(S[i]) % 2;
       if(f[tmp] != 1e18)    res = max(res, S[i] - f[tmp]);
       f[tmp] = min(f[tmp], S[i]);
    }
    cout<<res;
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    S[1] = a[1];
    for(int i=2; i<=n; i++){
        S[i] = S[i-1] + a[i];
    }
    Max();
}
