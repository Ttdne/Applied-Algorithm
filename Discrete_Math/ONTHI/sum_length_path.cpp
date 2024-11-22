#include<bits/stdc++.h>
#define MAX 100005
#define pii pair<int, int>
using namespace std;
list<pii> adj_list[MAX];
bool visited[MAX];
int n;
long long f[MAX];
int subtree_size[MAX];
void DFS(int s, int sum){
    visited[s] = true;
    subtree_size[s] = 1;
    for(auto i: adj_list[s]){
        if(visited[i.first] == false){
            int x = i.first;
            int y = i.second;
            f[x] += sum;
            DFS(x, sum);
            subtree_size[s] += subtree_size[x];
            f[1] += 1LL * subtree_size[x] * y; // Tổng khoảng cách từ gốc
        }
    }
}
void input(){
    int a, b, c;
    cin>>n;
    for(int i=1; i<n; i++){
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
}

void dfs2(int u, int parent){
    for(auto[v, w] : adj_list[u]){
        if( v!= parent){
            f[v] = f[u] + 1LL * (n - subtree_size[v]) * w - 1LL *subtree_size[v] *w;
            dfs2(v, u);
        }
    }
}
int main(){
    memset(f, 0, n);
    input();
        memset(visited, false, n+1);
        memset(f, 0, n+1);
        DFS(1, -1);
    dfs2(1, -1);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i]);
    }
    cout << res << endl;
}
