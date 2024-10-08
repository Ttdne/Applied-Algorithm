#include<bits/stdc++.h>
#define MAX 10007
using namespace std;
int adj_matrix[MAX][MAX];
int n,m, s, t;
int dis[MAX];
bool visited[MAX] = {0};
void input(){
    int a,b;
    cin>>n>>m>>s>>t;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
}

int find_DFS(int s, int t){
    visited[s] = true;
    if(s == t) return dis[s];
    for(int j=1; j<=n; j++){
        if(adj_matrix[s][j] == 1 && visited[j] == false){
            dis[j] = dis[s] + 1;
            int result = find_DFS(j,t);
            if(result != -1) return result;
        }
    }
    return -1;
}

int main(){
    freopen("test.txt", "r", stdin);
    memset(dis, -1, sizeof(dis)); // Khởi tạo mảng dis với -1
    for(int i=0; i<10; i++) visited[i] = false;
    dis[s] = 0; // Khoảng cách từ s đến chính nó là 0
    input();
    cout<<find_DFS(s,t);
}
