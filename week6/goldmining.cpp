#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 1e6+2;
int n, l1, l2, a[N], f[N], res;
vector<ii> b;

void inp(){
    cin>>n>>l1>>l2;
    for(int i=1; i<=n; i++) cin>>a[i];
}
void proc(){
    for(int i=1; i<= n; i++){
        f[i] = a[i];
        while(! b.empty()){
            if(b.back().second < i - l2)    b.pop_back();
            else break;
        }
        if( i -l1 > 0){
            if( b.empty())  b.push_back(ii(f[i-l1], i-l1));
            else if(b.back().first < f[i-l1])   b.push_back(ii(f[i-l1], i-l1));
        }
        if(! b.empty()) f[i] += b.back().first;
        res = max(res, f[i]);
    }
    cout<<res<<"\n";
}
int main(){
    inp();
    proc();
}

