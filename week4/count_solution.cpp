#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int n, M;
int a[MAX];
int sum_M;
int Try(int i, int sum_M){

        if (i == n+1){
            if(sum_M == M) return 1;
            else return 0;
             }
        int dem = 0;
        int f=0;
        for(int j=i+1; j<= n; j++) f += a[j];
        for(int j=1; j<= (M - sum_M - f/a[i]); j++){
            dem += Try(i+1, sum_M + a[i]*j);
        }
    return dem;
    }
int main(){
    cin>>n>>M;
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<Try(1, 0);
}
