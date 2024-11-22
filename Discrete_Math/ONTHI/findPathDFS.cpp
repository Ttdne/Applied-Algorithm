#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int n;
int m;
int pred[MAX];
int s, p;
bool visited[MAX] = {0};
list<int> adj_list[MAX];
bool found = false;
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
void DFS_Findpath(int s, int t){
    visited[s] = true;
    if (s == t){
            found = true;
            printSolution();
            return;
        }
    for(int i: adj_list[s]){
        if(!visited[i]){
            pred[i] = s;
            DFS_Findpath(i,t);
            if(found) return;
        }
    }
}
int main(){
    input();
    pred[s] = -1;
    DFS_Findpath(s,p);
    if(!found) cout<<-1;
}
