#include <bits/stdc++.h>
using namespace std;
int V, E;
int adj_matrix[10][10];
list<int> adj_list[10];
bool visited[10];
queue<int> Q;
list<int> l;
void input(){
    int a,b;
    cin>>V>>E;
    for(int i=0; i<E; i++){
        cin>>a>>b;
        adj_matrix[a][b] = 1;
    }
}

void DFS(int v){
    visited[v] = true;
        for(int i=1; i<=V; i++){
            if(adj_matrix[v][i] == 1 && !visited[i]){
                DFS(i);
        }
}
                    l.push_front(v);

}

int main(){
    freopen("test.txt", "r", stdin);
    for(int i=0; i<10; i++) visited[i] = false;
    input();
    for(int i=1; i<=V; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    for( auto it= l.begin(); it != l.end(); it++){
        cout<<*it<<" ";
    }
}

