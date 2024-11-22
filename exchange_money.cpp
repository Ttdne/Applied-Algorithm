#include<bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;
ll n, X;
ll d[10];
ll mem[10][10001];
ll opt2(ll i, ll X){
    if(X == 0) return 0;
    if( i< 0 || X < 0) return INT_MAX;
    if(mem[i][X] == -1){
        ll res = min(opt2(i-1, X), 1 + opt2(i, X-d[i]));
        mem[i][X] = res;
    }
    return mem[i][X];
}

void trace(int i, int X){
    if(X == 0) return;
    if(i<0 || X < 0) return;
    if(mem[i][X] == 1 + mem[i][X-d[i]){
        cout<<d[i]<<endl;
        trace(i, X-d[i]);
    }
    else{
        trace(i-1, X);
    }
}
int main(){
    cin>>n>>X;
    for(ll i=0; i<n; i++) cin>>d[i];
    memset(mem, -1, sizeof(mem));
    int res = opt2(n-1, X);
    if(res == INT_MAX) cout<<-1;
    else {cout<<res;
    cout<<"They are: ";
    trace(n-1, X);
}
