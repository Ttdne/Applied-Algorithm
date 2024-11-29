#include<bits/stdc++.h>
#define N 100
using namespace std;

int w[N][N];
int D[N][N];
int P[N][N];
int n, m;
int s, t;
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            w[i][j] = INT_MAX;
        }
    }

    for(int i=1; i<=n; i++) w[i][i] = 0;
    int a, b, c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        w[a][b] = c;
    }
    cin>>s>>t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            D[i][j] = w[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(w[i][j] != INT_MAX && i != j){
                P[i][j] = i;
            }
            else{
                P[i][j] = -1;
            }
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
     for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(P[i][j] == -1) cout<<"INF"<<" ";
            else cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> path;
int current = t;
while (current != -1) {
    path.push_back(current);
    current = P[s][current];
}
reverse(path.begin(), path.end());
for (int i = 0; i < path.size(); i++) {
    if (i > 0) cout << "->";
    cout << path[i];
}
cout << endl;
}
