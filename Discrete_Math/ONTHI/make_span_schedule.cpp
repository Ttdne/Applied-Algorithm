#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
int n, m;
bool visited[MAX] = {false};
list<int> adj_list[MAX];
list<int> L;
int weight[MAX];
int Indegree[MAX] ={0};
int sum=0;
int earliest_completion[MAX] = {0};
 void input(){
    int a,b;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a;
        weight[i] = a;
    }
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
    }
}
int BFS_modification(int n){
    for(int i=1; i<=n; i++){
         earliest_completion[i] = weight[i];
    }
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
            earliest_completion[i] = max(earliest_completion[i], earliest_completion[u] + weight[i]);
            Indegree[i]--;
            if(Indegree[i] == 0)    Q.push(i);
            }
        }

    return *max_element(earliest_completion+1, earliest_completion + n+1);
}

int main(){
    input();
    cout<<BFS_modification(n);
}
