#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
int n, m;
vector<int> T[MAX];
int match_staff[MAX];
bool visited[MAX];  // Mang visited de danh dau da duyet staff trong DFS
bool can_assign_task(int task){
    for(int staff: T[task]){
        if(!visited[staff]){
            visited[staff] = true;
            if(match_staff[staff] == -1 || can_assign_task(match_staff[staff])){
                match_staff[staff] = task;
                return true;
            }
        }
    }
    return false;
}
int maximum_tasks_assigned(int n, int m){
    memset(match_staff, -1, sizeof(match_staff));

    int max_assigned_tasks = 0;
    for(int task = 0; task <n; task++){
        memset(visited, false, sizeof(visited));
        if(can_assign_task(task)){
            max_assigned_tasks++;
        }
    }
    return max_assigned_tasks;
}
int main(){
    cin>>n>>m;
    int k;
    int a;
    for(int i=0; i<n; i++){
        cin>>k;
        T[i].resize(k);
        for(int j=0; j<k; j++){
            cin>>a;
            T[i][j] = a;
        }
    }
    cout<<maximum_tasks_assigned(n,m);
}
