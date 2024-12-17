#include<bits/stdc++.h>
#define MAX 100003
using namespace std;
int n;
int p;
int m[MAX];
int main(){
    cin>>n;
    vector<int> a(n+1);
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>p;
    for(int i=1; i<=p; i++) cin>>m[i];
    sort(a.begin(), a.end());
    for(int i=1; i<=p; i++){
        auto ub = upper_bound(a.begin(), a.end(), m[i]);
        cout<<(ub - a.begin()-1)<<" ";
    }
}
