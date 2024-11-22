#include<bits/stdc++.h>
#define MAX 100004
using namespace std;
int V, E;
list<int> adj_list[MAX];
bool visited[MAX]={false};
queue<int> Q;
int sum=0;
void input(){
    int a,b;
    cin>>V>>E;
    for(int i=0; i<E; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}
void traversal_matrix(int v){
    Q.push(v);
    visited[v] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for( int i:adj_list[u]){
            if(!visited[i]){
                Q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    input();
    for(int i=1; i<=V; i++){
            if(visited[i] == false){
            traversal_matrix(i);
            sum++;
            }
    }
    cout<<sum;
}
