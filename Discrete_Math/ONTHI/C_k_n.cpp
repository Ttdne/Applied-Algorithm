#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int k, n;
int a[1000][1000]={0}; // a[i][j] là tổ hợp chập j của i
int DP(int k, int n){
    if(k == 0 || k==n){
        a[n][k] = 1;
        return a[n][k] % MOD;
    }
    if(a[n][k] != 0) return a[n][k] % MOD;
    a[n][k] = DP(k-1, n-1) + DP(k, n-1);
    return a[n][k] % MOD;
}
int main(){
    cin>>k>>n;
    cout<<DP(k,n);
}
