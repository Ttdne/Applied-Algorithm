#include<bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;
ll n, X;
ll d[10];
ll Min[MAX];
int main(){
    cin>>n>>X;
    for(ll i=0; i<n; i++) cin>>d[i];
    for(ll i=0; i<MAX; i++) Min[i] = INT_MAX;
    Min[0] = 0;
    for(ll i=1; i<= X; i++){
        for(ll j=0; j<n; j++){
            if(d[j] <= i && ((Min[i-d[j]] +1) < Min[i])){
                Min[i] = Min[i-d[j]] + 1;
            }
        }
    }
    if(Min[X] == INT_MAX) cout<<-1;
    else cout<<Min[X];
}
