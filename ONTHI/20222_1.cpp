#include<bits/stdc++.h>
#define MAX 1000007
using namespace std;
int n, m;
int main(){
    cin>>n>>m;
    int a;
    int sum=0;
    for(int i=1; i<=n; i++){
        cin>>a;
        if(a == 0) sum++;
    }
    for(int i=1; i<=m; i++){
        cin>>a;
        if(a==0)    sum++;
    }
    cout<<sum;
}
