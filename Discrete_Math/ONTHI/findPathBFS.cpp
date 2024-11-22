#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int n;
int m;
int pred[MAX];
int s, p;
bool visited[MAX] = {0};
list<int> adj_list[MAX];
void input(){
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cin>>s>>p;
}
void printSolution(){
    vector<int> path;
    int a = p;
    while ( a != -1){
        path.push_back(a);
        a = pred[a];
    }
    for(int i= path.size()-1; i>=0; i--){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void BFSfindPath(int s, int p){
    queue<int> Q;
    Q.push(s);
    pred[s] = -1;
    visited[s] = true;
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(auto i: adj_list[u]){
            if(!visited[i]){
                visited[i] = true;
                pred[i] = u;
                Q.push(i);

                if (i == p){
                    printSolution();
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main(){
    input();
    BFSfindPath(s,p);
}
