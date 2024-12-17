#include<bits/stdc++.h>
#define MAX 1000006
#define ll long long
#define MOD 1000000007
using namespace std;
int n;
int a[MAX];
map<int, int> MAPne;
int fac[MAX];
int main(){
    memset(fac, -1, sizeof fac);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        MAPne[a[i]]++;

    }
    int Q = 0;
    for(auto it = MAPne.begin(); it != MAPne.end(); it++){
        if(it->second > 1){
            int check = it->second;
            Q = (Q + check*(check-1)/2) % MOD;
        }
    }
    cout<<(Q % MOD);
}
