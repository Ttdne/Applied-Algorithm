#include<bits/stdc++.h>
#define MAX 100004
using namespace std;
int n;
int w[MAX];
list<int> adj_list[MAX];
int f[MAX][2];
void input(){
    cin>>n;
    int a,b;
    for(int i=1; i<=n; i++){
        cin>>a;
        w[i] = a;
    }
    for(int i=1; i<= n-1; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}
int DP(int t, int i, int parent){
    if(f[t][i] != -1) return f[t][i];
    int Max1 = 0;
    int Max2 = 0;
    for(auto u: adj_list[t]){
        if (u == parent) continue; // Bỏ qua đỉnh cha
        Max1 += max(DP(u,0,t), DP(u,1,t));
        Max2 += DP(u,0,t);
    }
    Max2 += w[t];
    f[t][0] = Max1;
    f[t][1] = Max2;
    return f[t][i];
}
int main(){
    memset(f,-1, sizeof(f));
    input();
    for(int i=1; i<=n; i++){
        if(adj_list[i].empty()){
            f[i][1] = w[i];
            f[i][0] = 0;
        }
    }
    cout<<max(DP(1,0,-1), DP(1,1,-1));
}
