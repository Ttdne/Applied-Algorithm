#include<bits/stdc++.h>
#define MAX 100000
#define ll long long
using namespace std;
ll n;
ll d[MAX];
ll gio[MAX]={0};
ll end_time = 0;
int main(){

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>d[i];
    }
    for(int i=1; i<n; i++)   gio[i] = gio[i-1] + 1;
    sort(d, d+n, greater<int>());
    for(int i=0; i<n; i++){
        int end_time_temp = d[i] + gio[i];
        if(end_time_temp > end_time) end_time = end_time_temp;
    }
    cout<<end_time;
}
