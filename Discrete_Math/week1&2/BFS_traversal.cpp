#include <bits/stdc++.h>
using namespace std;
int V, E;
int adj_matrix[10][10];
list<int> adj_list[10];
bool visited[10];
queue<int> Q;
void input(){
    int a,b;
    cin>>V>>E;
    for(int i=0; i<E; i++){
        cin>>a>>b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
}

void input2(){
    int a,b;
    cin>>V>>E;
    for(int i=0; i<E; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}
void traversal_matrix(int v){
    cout<<v<<"->";
    Q.push(v);
    visited[v] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=1; i<=V; i++){
            if(adj_matrix[u][i] == 1 && !visited[i]){
                Q.push(i);
                visited[i] = true;
                cout<<i<<"->";
            }
        }
    }
}

void traversal_matrix2(int v){
     cout<<v<<"->";
    Q.push(v);
    visited[v] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for( int i:adj_list[u]){
            if(!visited[i]){
                Q.push(i);
                cout<<i<<"->";
                visited[i] = true;
            }
        }
    }
}
int main(){
    freopen("test.txt", "r", stdin);
    for(int i=0; i<10; i++) visited[i] = false;
    input();
    int sum=0;
    for(int i=1; i<=V; i++){
        if(!visited[i]){
            traversal_matrix(i);
            sum++;
        }
    }
    cout<<endl<<sum;
}
