#include<bits/stdc++.h>
#define MAX 10000
#define pii pair<int, int>
using namespace std;
struct Edge{
    int weight;
    int v;
    Edge(int _v, int w){
        v = _v;
        weight = w;
    }
};
vector<Edge> adj_list[1000];
int V, E, s, d[1000], p[1000], t;
bool found[1000];
void input2(){
    int a,b,weight;
    cin>>V>>E>>s>>t;
    for(int i=0; i<E; i++){
        cin>>a>>b>>weight;
        adj_list[a].push_back(Edge(b, weight));
    }
}
/*void Dijkstra_priority_queue(int s){
    priority_queue<pii,vector<pii>, greater<pii>> T;
    for(auto v: V){
        d[v] = w[s][v];
        p[v] = s;
    }
    d[s] = 0;
    S.push_back(s);
    for(auto v: V){
        if(v != s){
            T.push({d[v], v});
    }}
   while (!T.empty()) {
        pii x = T.top();
        int u = x.second;
        T.pop();
        if (find(S.begin(), S.end(), u) == S.end()) {
            S.push_back(u); // Thêm u vào tập hợp đã xử lý
        }


        for (auto v : adj_list[u]) {
            if (d[v] > d[u] + w[u][v]) {
                d[v] = d[u] + w[u][v];
                p[v] = u;
                T.push({d[v], v});
            }
        }
    }
}*/
void Dijkstra(){
    for(int u=0; u<V; u++){
        d[u] = INT_MAX;
        found[u] = 0;
    }
    d[s] = 0;
    for(int i=1; i<= V - 1; i++){
        int mind = INT_MAX; int u;
        for(int k=0; k< V; k++){
            if(!found[k] && d[k] < mind){
                mind = d[k]; u =k;
            }
        }
        if(u == t) break;
        found[u] = 1;
        for(int j = 0; j< adj_list[u].size(); j++){
                Edge e = adj_list[u][j];
                if( !found[e.v]){
                    if(d[e.v] > d[u] + e.weight){
                        d[e.v] = d[u] + e.weight;
                        p[e.v] = u;
                    }
                }
    }
}
}


int main(){
    freopen("test.txt", "r", stdin);
    input2();
    Dijkstra();
    for (int i = 0; i < V; i++) {
        cout << d[i] << " ";
    }

}
