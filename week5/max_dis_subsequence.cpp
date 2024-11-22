#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int t;
int n, c, a[MAX];
// 1 2 4 8 9
bool check(int distance){
    int i=0;
    int j=1;
    int sl=1;
    while( i<n){
        while((a[j] - a[i]) < distance && j<n) ++j;
        if(j< n) sl++;
        if(sl >= c) return true;
        i = j;
        j++;
    }
    return false;
}
int MaxDistance(){
    int l = 0;
    int r = a[n-1] - a[0];
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)) l = mid +1;
        else r = mid -1;
    }
    return r;
}
int main(){
    cin>>t;
    while(t--){

        cin>>n>>c;
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a, a+n);
        cout<<MaxDistance()<<endl;
    }
}
