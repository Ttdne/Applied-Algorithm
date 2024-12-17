#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n;
int a[MAX];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    int sum=1;
    for(int i=2; i<=n; i++){
        if(a[i] > a[i-1])   continue;
        else sum++;
    }
    cout<<sum;
}
