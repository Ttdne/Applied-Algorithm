#include<bits/stdc++.h>
#define ll long long
#define MAX 1000004
#define pii pair<int, int>
using namespace std;
ll n, L1, L2;
ll a[MAX];
ll f[MAX]; // tong luong vang lon nhat o vi tri j
int main(){
    ll res=0;
    priority_queue<pii> h;
    cin>>n>>L1>>L2;
    for(ll i=1; i<=n; i++) {
            cin>>a[i];
            f[i] = a[i];
    }
    for(ll i=1; i<=n; i++){
        if( i - L1 > 0) h.push({f[i-L1], i-L1});
        while( !h.empty()){
        if( h.top().second < i-L2)    h.pop();
        else break;
        }
        if(! h.empty()){
            f[i] = h.top().first + a[i];
            res = max(f[i], res);
    }
    }
        /*cin>>n>>L1>>L2;

    vector<pii> hd;
    for(ll i = 1; i<=n; i++){
        cin>>a[i];
        f[i] = a[i];
    }

    for(ll i=1; i<=n; i++){
        while( !hd.empty()){
            if(hd.front().second < i-L2)    hd.pop_back();
            else break;
        }
        if( i - L1 >0)  hd.push_back({f[i-L1], i-L1});
        if(!hd.empty()){
            f[i] = hd.front().first + a[i];
            res = max(f[i], res);
        }
    }*/
    cout<<res;
}
