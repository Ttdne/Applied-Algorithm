#include<bits/stdc++.h>
using namespace std;
int n;
int year;
int a[23];
int S;
int sum=0;
int Try(int i, int tong){
    int sum = 1;
    if(tong < year) return 0;
    if(i == n)    return 1;
    for(int j=i+1; j<=n; j++){
        if(a[j] > year) continue;
        int check = Try(j, tong - a[j]);
        sum += check;
    }
    return sum;
}
int main(){
    cin>>n;
    S = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        S += a[i];
    }
    sort(a+1, a+n+1, greater<int>());
    cin>>year;
   cout<<Try(0, S);
}
