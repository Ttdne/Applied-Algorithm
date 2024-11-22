#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, m;
int visited[MAX] = {0};
list<int> adj_list[MAX];
 void input(){
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
    }
}
bool findCycle(int s){
    visited[s] = 1;
    for(int i : adj_list[s]){
        if(visited[i] == 1){
            return true;
        }
        else if (visited[i]==0) return findCycle(i);
    }
    visited[s] = 2;
    return false;
}
int main(){
    input();
    bool hasCycle = false;
    for(int i=1; i<=n; i++){
         if (visited[i] == 0) {
            if (findCycle(i)) {
                hasCycle = true;
                break; // Thoát vòng lặp nếu phát hiện chu trình
            }
        }
    }
    if (hasCycle) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
