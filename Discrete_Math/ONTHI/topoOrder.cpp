#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, m;
bool visited[MAX] = {0};
list<int> adj_list[MAX];
list<int> L;
int Indegree[MAX] ={0};
 void input(){
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
    }
}
void DFS(int s){
    visited[s] = true;
    for(int v: adj_list[s]){
        if(!visited[v]) DFS(v);
    }
        L.push_front(s);

}

void BFS_modification(int n){
    L.clear();
    for(int i=0; i<n; i++){
        for(auto v: adj_list[i]){
            Indegree[v]++;
        }
    }
    queue<int> Q;
    for(int i=0; i<n; i++){
        if(Indegree[i] == 0){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        L.push_back(u);
        for(int i: adj_list[u]){
            Indegree[i]--;
            if(Indegree[i] == 0)    Q.push(i);
            }
        }

    for(auto i: L){
        cout<<i<<" ";
    }
}
void TopoSort(int n){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    for(auto i: L){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    input();
    BFS_modification(n);
}
