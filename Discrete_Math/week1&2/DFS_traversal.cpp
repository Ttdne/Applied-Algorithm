#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
list<int> adj_list[MAX];
int adj_matrix[MAX][MAX];
int n,m;
bool visited[MAX] = {0};
void input(){
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
}

void input2(){
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}

void DFS_traversal(int i){
    cout<<i<<"->";
    visited[i] = true;
    for(int j=1; j<=n; j++){
        if(adj_matrix[i][j] == 1 && visited[j] == false){
            DFS_traversal(j);
        }
    }
}

int main(){
    freopen("test.txt", "r", stdin);
    for(int i=0; i<10; i++) visited[i] = false;
    input();
    int sum=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            DFS_traversal(i);
            sum++;
        }
    }
    cout<<endl<<sum;
}
