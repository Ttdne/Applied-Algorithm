#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1003][1003];
int f[1003][1003];
int main(){
    memset(f, 0x3f, sizeof f);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    f[1][1] = a[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
                if (i == 1 && j == 1) continue;
            if(a[i][j] != 0){
                f[i][j] + = a[i][j];
                if (i > 1) f[i][j] = min(f[i][j], f[i-1][j] + a[i][j]);
                if (j > 1) f[i][j] = min(f[i][j], f[i][j-1] + a[i][j]);
                if(i> 1 && j > 1)   f[i][j] = min(f[i][j], f[i-1][j-1] + a[i][j]);
            }
        }
    }
    if(f[n][m] >= 0x3f3f3f) cout<<-1;
    else cout<<f[n][m];
}
