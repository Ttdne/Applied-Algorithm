#include<bits/stdc++.h>
#define MAX 100005
#define pii pair<int, int>
using namespace std;
int n;
vector<pii> adj_list[MAX];
bool visited[MAX] = {false};
int max_dist = 0;
int farthest = -1;
void DFS(int s, int dist){
    visited[s] = true;
    if(dist > max_dist){
        max_dist = dist;
        farthest = s;
    }
    for(auto neighbor: adj_list[s]){
        int next_node = neighbor.first;
        int weight = neighbor.second;
        if(!visited[next_node]){
            DFS(next_node, dist + weight);
        }
    }
}
int find_longest_path(int n){
    max_dist = 0;
    fill(visited, visited + n + 1, false); // Đặt lại mảng visited
    DFS(1,0);
    int start = farthest;
    max_dist = 0;
    fill(visited, visited + n + 1, false); // Đặt lại mảng visited
    DFS(start, 0);
    return max_dist;

}
int main(){
    cin>>n;
    int a, b, c;
    for(int i=0; i<n-1; i++){
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    cout<<find_longest_path(n);
}
