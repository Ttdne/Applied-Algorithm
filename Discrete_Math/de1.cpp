#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, m;
list<int> adj_list[MAX];
bool visited[MAX] = {0};
void input(){
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}
int calculateV(int i){
    int sum=0;
    for(auto j: adj_list[i]){
        sum++;
    }
    return sum;
}
int main(){
    input();
    for(int i=1; i<=n; i++){
            if(i % 2 != 0){
        cout<<calculateV(i)<<" ";
            }
    }
}
