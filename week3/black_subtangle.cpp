#include<bits/stdc++.h>
#define 1002 MAX
#define ll long long
using namespace std;
ll h[MAX]={0};      //chieu cao cua cot histogram
ll L[MAX], R[MAX];      // chi so cot xa nhat ben trai va phai ma cot i co the mo rong
stack<ll> V;    // duoc su dung de luu chi so cua cac cot trong qua trinh tim khoang cach mo rong cho moi cot
ll n, m;
ll a[MAX][MAX];
ll ans;
void input(){
    cin>>n>>m;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
}

ll compute(){
    V.clear();
    for(ll i =1; i<=m; i++){
        while( !V.empty() && (h[i] < h[V.back()])){
            R[V.back()] = i;
            V.pop();
        }
        V.push(i);
    }
    while(!V.empty()){
        R[V.back()] = m+1;
        V.pop();
    }
    for(ll i=m; i>=1; i--){
        while( !V.empty() && (h[i] < h[V.back()]){
              L[V.back()] = i;
              V.pop();
              }
              V.push(i);
    }
    while( !V.empty()){
        L[V.back()] = 0;
        V.pop();
    }

    ll max_area = 0;
    for(ll i=1; i<=m ;i++){
        ll width = R[i] - L[i] - 1;
        ll area = width * h[i];
        max_area = max( area, max_area);
    }
    return max_area;
    }

void solve(){
     ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 1)    h[j]++;
            else    h[j] = 0;
        }
        ll t = compute();
        ans = max(t, ans);
    }
    cout<<ans;
}
int main(){
    input();
    solve();
    return 0;
}
