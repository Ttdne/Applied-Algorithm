#include<bits/stdc++.h>
#define MAX 1000003
using namespace std;
int n;
int c[23][23];
bool visited[23] = {false};
int f[23][1<<23];
int TSP_Large(int i, int mask){
    if(mask == (1<<n) - 1)  return c[i][0];
    if(f[i][mask] != -1)    return f[i][mask];
    int res = INT_MAX;
    for(int j=0; j<n; j++){
        if(!(mask &(1<<j))){
            res = min(res, TSP_Large(j, mask | (1<<j)) + c[i][j]);
        }
    }
    return f[i][mask] = res;
}
int main(){
    cin>>n;
    memset(f, -1, sizeof f);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>c[i][j];
    }
    int mask = 1;
    cout<<TSP_Large(0, mask);
}
