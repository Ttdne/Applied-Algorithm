#include<bits/stdc++.h>
using namespace std;
int n;
int a[32];
int M;
int f[32];
int minnn= 1e9;
void solution(int tong){
    minnn = min(minnn, M - tong);
}
void Try(int i, int tong){
        if(tong > M)    return;

     if(i == n+1){
            solution(tong);
            return;
        }

    for(int j=i; j<=n; j++){
        Try(j+1, tong + a[j]);
        Try(j+1, tong);
    }
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    cin>>M;
    Try(1, 0);
    cout<<minnn;
}
