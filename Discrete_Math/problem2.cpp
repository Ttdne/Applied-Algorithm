#include<bits/stdc++.h>
#define MAX 100005
#define pii pair<int, int>
#define INF INT_MAX

using namespace std;
int d[MAX]; // length of the shortest path from s to v
int p[MAX]; // the pred of v in this shortest path from s to v
vector<int> V;
vector<pii> adj_list[MAX];
int V_num;
int E;
void input2(){
    int a,b,c,d;
    cin>>V_num>>E;
    for (int i = 0; i < V_num; i++) {
        V.push_back(i); // Thêm các đỉnh vào vector V
    }
    for(int i=0; i<E; i++){
        cin>>a>>b>>c>>d;
        adj_list[a].push_back({b,c*d});
    }
}
void Dijkstra(int s){
    fill(d, d + V_num, INF); // Initialize distances to all vertices as infinity
    priority_queue<pii,vector<pii>, greater<pii>> T;
    d[s] = 0;
    T.push({0,s});
   while (!T.empty()) {
        pii x = T.top();
        int u = x.second;
        T.pop();
        if (x.first > d[u]) continue;
        for (auto edge : adj_list[u]) {
            int v = edge.first; // Neighbor node
            int weight = edge.second; // Weight of the edge

            // Relaxation: if a shorter path to v is found, update its distance
            if (d[v] > d[u] + weight) {
                d[v] = d[u] + weight;
                T.push({d[v], v});
            }
        }
    }
}

int main(){
    input2();
    int s,t;
    cin>>s>>t;
    Dijkstra(s);
    if (d[t] == INF) {
        cout << -1 << endl; // No path found from s to t
    } else {
        cout << d[t] << endl; // Shortest path weight from s to t
    }

    return 0;
}
