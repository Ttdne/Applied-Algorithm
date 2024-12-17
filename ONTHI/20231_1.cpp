#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, Q;
int a[MAX];
int main(){
    cin>>n>>Q;
    for(int i=1; i<=n; i++)     cin>>a[i];
    sort(a+1, a+n+1);
    int sum=0;
    int result = 0;
    for(int i=1; i<n; i++){
        int p=i+1;
        int q = n;
        while(p<q){
            sum = (a[i] + a[p] + a[q]);
            if( sum < Q)    p++;
            else if( sum > Q)   q--;
            else{
                result++;
                p++;
                q--;
        }
    }
    }
    cout<<result;
}
/* 1 2 4 5 6 7*/
