#include<bits/stdc++.h>
#define MAX 10000
#define pii pair<int, int>
using namespace std;
int d[MAX]; // length of the shortest path from s to v
int p[MAX]; // the pred of v in this shortest path from s to v
vector<int> V;
vector<int> S;
list<int> adj_list[MAX];
int V_num;
int E;
int w[MAX][MAX];
void input2(){
    int a,b;
    cin>>V_num>>E;
    for (int i = 1; i <= V_num; i++) {
        V.push_back(i); // Thêm các đỉnh vào vector V
    }
    for(int i=0; i<E; i++){
        cin>>a>>b>>w[a][b];
        adj_list[a].push_back(b);
    }
}
void Dijkstra(int s){
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
}

int main(){
    for(int i=0; i<MAX;i++){
            d[i] = INT_MAX;
            p[i] = -1;
    }
    input2();
    int s;
    cin >> s;
    Dijkstra(s);
    for (int i = 0; i < S.size(); i++) {
        cout << S[i] << " ";
    }

}
