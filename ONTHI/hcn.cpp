#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[1003][1003];
int f[1003][1003];
int main(){
    memset(f, 0, sizeof f);
    int res = 0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }

    f[1][1] = (a[1][1] == 1)? 1 :0;
    for(int i=2; i<=m; i++) f[1][i] = (a[1][i] == 1) ? (f[1][i-1] + 1)  : 0;
    for(int i=2; i<=n; i++) f[i][1] = (a[i][1] == 1)? (f[i-1][1] + 1) : 0;
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            if( a[i][j] == 1 && f[i-1][j] > 0 && f[i][j-1] > 0 && f[i-1][j-1] > 0){
                //cout<<f[i-1][j]<< "+" <<f[i][j-1] <<"-" << f[i-1][j-1]<<"=";
                f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + 1;
            //cout<<f[i][j]<<endl;
            }
            else f[i][j] = 0;
            res = max(res, f[i][j]);
        }

    }
    cout<<res;
}
