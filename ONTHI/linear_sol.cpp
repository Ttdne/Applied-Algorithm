#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, M;
int a[MAX];
int cnt=0;
void Try(int i, int tong){
    if(i > n){
        if(tong == M)   cnt++;
        return;
    }
    for(int j=1; j<= (M-tong)/a[i]; j++){
        Try(i+1, tong + j*a[i]);
    }
}
int main(){
    cin>>n>>M;
    for(int i=1; i<=n; i++) cin>>a[i];
    Try(1, 0);
    cout<<cnt;
}
