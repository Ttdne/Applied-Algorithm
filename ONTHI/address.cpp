#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[103];
int f=0;
int fopt = INT_MAX;
//int x[103];
bool visited[103];
/* Try(int i){
    if(i == 4 ){
        for(auto i: adj[x[3]]){
            if(i == 1){
                f += a[x[3]];
                fopt = min(fopt, f);
                return;
            }
        }
        fopt = -1;
        return;
    }
    for(auto j: adj[x[i-1]]){
        if(!visited[j]){
            x[i] = j;
            visited[j] = true;
            f += a[x[i-1]];
            Try(i+1);
            visited[j] = false;
            f-= a[x[i-1]];
        }
    }
}*/
int main(){
    cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    //memset(visited, false, sizeof visited);
    for(int i=1; i<=n; i++)  cin>>a[i];
    int c, b;
    for(int i=0; i<m; i++){
        cin>>c>>b;
        adj[c].push_back(b);
        adj[b].push_back(c);
    }
    for(int u=1; u<=n; u++){
        for(int v: adj[u]){
            if(v > u){
            for(int w: adj[v]){
                if(w > v && find(adj[u].begin(), adj[u].end(), w) != adj[u].end()){
                    int cost = a[u] + a[v] + a[w];
                    fopt = min(cost, fopt);
                }
            }
            }
        }
    }
    if(fopt == INT_MAX) cout<<-1;
    else cout<<fopt;
}
