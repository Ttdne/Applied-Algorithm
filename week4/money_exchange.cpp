#include<bits/stdc++.h>
#define MAX 100000
#define ll long long
using namespace std;
int n, X;
int d[10];
int dem=0;
void cashier(int X){
    int quos=0;
    while(X > 0){
        for(int i=0; i<n; i++){
            if( X > d[i]){
                quos = X / d[i];
                X = X - quos * d[i];
                dem+= quos;
            }
            if( i == n-1 && X > 0){
                cout<<-1;
                return;
            }
        }
    }
        cout<<dem;
}
int main(){
    cin>>n>>X;
    for(int i=0; i<n; i++) cin>>d[i];
    sort(d, d+n, greater<int>());
    cashier(X);
}
