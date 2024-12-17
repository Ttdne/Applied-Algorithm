#include<bits/stdc++.h>
using namespace std;
int n, D;
int a[1003];
int main(){
    cin>>n>>D;
    int cnt=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<n; i++){
        int sum = a[i];
        for(int j=i+1; j<=n; j++){
            sum += a[j];
            if(sum >= D) cnt++;
        }
    }
    cout<<cnt;
}
