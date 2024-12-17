#include<bits/stdc++.h>
#define MAX 1004
#define ll long long
#define pii pair<int, int>
using namespace std;
ll n;
ll x[MAX], y[MAX], c[MAX][MAX];
ll f[MAX][MAX];
int main(){
    priority_queue<pii> hd;
    memset(c, 0, sizeof c);
    cin>>n;
    int d;
    for(ll i=1; i<=n; i++){
        cin>>x[i]>>y[i]>>d;
        c[x[i]][y[i]] += d;
    }
    f[0][0] = 0;
    for(ll i=0; i<MAX; i++){
        for(ll j=0; j<MAX; j++){
            if(i ==0 || j== 0){
                    f[i][j] = c[i][j];
            }
        }
    }
    for(ll i=1; i<MAX; i++){
        for(ll j=1; j<MAX; j++){
            f[i][j] = max(f[i][j-1], f[i-1][j]);
            f[i][j] += c[i][j];
        }
    }
    cout<<f[MAX-1][MAX-1];
}
