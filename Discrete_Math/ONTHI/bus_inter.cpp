#include<bits/stdc++.h>
#define MAX 10004
#define DMAX 5005
#define pii pair<int, int>
using namespace std;
int n, m;
int C[MAX];
int D[DMAX];
struct Edge{
    int to, cost;
};

struct Bus{
    int city, cost, max_distance;
};
list<int> adj[MAX];
vector<Edge> graph[5010];

void bfs(int start, int cost, int distance){
    bool visited[5010] = {false};
    queue<pii> Q;
    Q.push({start, 0});
    visited[start] = true;
    while (! Q.empty()){
        auto it = Q.front();
        int x = it.first;
        int y = it.second;
        Q.pop();
        if( y >= distance) continue;
        for(int neighbor: adj[x]){
            if(! visited[neighbor]){
                visited[neighbor] = true;
                Q.push({neighbor, y+1});
                graph[start].push_back({neighbor, cost});
            }
        }
    }
}

int Dijkstra(){
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while( !pq.empty()){
        auto it = pq.top();
        int x = it.second;
        int y = it.first;
        pq.pop();
        if(y > dist[x]) continue;
        for(Edge edge: graph[x]){
            int v = edge.to;
            int weight = edge.cost;
            if(dist[v] > dist[x] + weight){
                dist[v] = dist[x] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[n];
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>C[i]>>D[i];
    }
    int k, j;
    for(int i=1; i<=m; i++){
        cin>>k>>j;
        adj[k].push_back(j);
        adj[j].push_back(k);
    }
    for(int i=1; i<=n; i++){
        bfs(i, C[i], D[i]);
    }
    int result = Dijkstra();
    cout<<result;
}
