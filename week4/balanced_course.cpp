#include<bits/stdc++.h>
#define N 50
using namespace std;
int m, n;   // m is num of teacher, n is the num of courses
vector<int> T[N];   //T[i] is the list of teachers that can be assigned to course i
bool conflict[N][N];
int x[N];   // x[i] la giao vien duoc phan cong day mon i
int load[N]={0};    //số môn được phân công cho giáo viên t
int res = 1000000003;
bool check(int v, int t){
    for(int i=1; i < t; i++){
        if(conflict[i][t] && x[i] == v) return false;
        }
    return true;
}

void solution(){
    int maxload = 0;
    for(int i=1; i<=m; i++) maxload = max(load[i], maxload);
    res = min(maxload,res);
}
void Try(int v){
    for(int i=0; i<T[v].size(); i++){
        int t = T[v][i];
        if(check(t,v)){
            x[v] = t;
            load[t]++;
            if(v == n)  solution();
            else{
                if(load[t]< res) Try(v+1);
            }
            load[t]--;
        }
    }
}
int main(){
    freopen("test.txt", "r", stdin);
    int k;
    cin>>m>>n;
    for(int i=1; i<=m; i++){
        cin>>k;
        for(int j=1; j<=k;j++){
            int x;
            cin>>x;
            T[x].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j =1 ; j <= n; j++)
            conflict[i][j] = false;
    int check_conflict;
    cin>>check_conflict;
    for(int i=1; i<=check_conflict; i++){
        int c,d;
        cin>>c>>d;
        conflict[c][d]= true;
        conflict[d][c] = true;
    }
    Try(1);
    cout<<res;
}
