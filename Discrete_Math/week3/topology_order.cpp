#include <bits/stdc++.h>
using namespace std;

int V, E;
int adj_matrix[100][100] = {0}; // Initialize the adjacency matrix to zero
int inDegree[100] = {0}; // Initialize the inDegree array to zero
queue<int> Q;
vector<int> topoOrder; // Vector to store the topological order
void input() {
    int a, b;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        adj_matrix[a][b] = 1;
    }
}
/* Cac buoc duyet qua tung phan tu theo thu tu topo
1. Dem ban bac vao cua tung dinh
2. Add vao Q cac dinh co ban bac vao bang 0
3. them node vao topologic order
4. Tru so dinh cua ban bac vao cua cac dinh ke, neu bang 0 lai day vao Q
5. Tiep tuc thuc hien chu trinh*/
void topologyTraversal(){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(adj_matrix[i][j] == 1) inDegree[j]++;
        }
    }
    for(int i=0; i<V; i++){
        if(inDegree[i] == 0) Q.push(i);
    }
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        topoOrder.push_back(u);
        for(int i=0; i<V; i++){
             if(adj_matrix[u][i] == 1) {
                inDegree[i]--;
            if(inDegree[i] == 0) Q.push(i);
        }
    }
}
}

int main() {
    freopen("test.txt", "r", stdin);
    input();
    topologyTraversal();
    for (int i = 0; i < topoOrder.size(); i++) {
        cout << topoOrder[i] << " ";
    }
    cout << endl;
    return 0;
}
