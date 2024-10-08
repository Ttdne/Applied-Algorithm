#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
int N, M, s, t;
int dis[MAX];
queue<int> Q;
list<int> adj_list[MAX];
bool visited[MAX] = {0};
void input(){
    cin>>N>>M>>s>>t;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}

int find_path(int s, int t){
    Q.push(s);
    visited[s] = true;
    while(! Q.empty()){
        int v = Q.front();
        Q.pop();
        if (v == t){
                return dis[v];
        }
        else{
        for( int i : adj_list[v]){
            if(!visited[i]){
                visited[i] = true;
                dis[i] = dis[v] + 1;
                Q.push(i);
            }
        }
        }
    }
    return -1;
}
int main(){
    freopen("test.txt", "r", stdin);
    input();
    cout<<find_path(s,t);
}
