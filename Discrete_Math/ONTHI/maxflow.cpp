#include<bits/stdc++.h>
using namespace std;
int n, m;   // n: number of nodes, m: number of edges
int s, t;   // s: the index of source node, t: the index of sink node
int capG[100][100] = {0};    // Khả năng ban đầu của đồ thị
int capRG[100][100] = {0};   // Đồ thị khả năng dư
int visited[100];            // Mảng đánh dấu các đỉnh đã thăm
int pred[100];               // Mảng chứa các đỉnh trước trên đường tăng luồng
queue<int> Q;                // Hàng đợi cho BFS
void input(){
    cin>>n>>m;
    int u, v, c;
    for(int i=0; i<m; i++){
        cin>>u>>v>>c;
        capG[u][v] = c;
    }
    cin>>s>>t;
}
bool BFS(int s, int t) {
    memset(visited, 0, sizeof(visited));  // Reset mảng visited
    while (!Q.empty()) Q.pop();  // Reset lại hàng đợi Q trước mỗi lượt tìm kiếm
    Q.push(s);
    visited[s] = 1;
    pred[s] = -1;  // Đỉnh bắt đầu không có đỉnh trước

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < n; i++) {
            // Nếu chưa thăm và còn khả năng dư
            if (visited[i] == 0 && capRG[u][i] > 0) {
                pred[i] = u;
                if (i == t) {
                    return true;  // Tìm thấy đích
                }
                Q.push(i);
                visited[i] = 1;
            }
        }
    }
    return false;  // Không tìm thấy đường tăng luồng
}

// Hàm Edmonds-Karp tính luồng cực đại từ s -> t
int EK(int s, int t) {
    // Khởi tạo đồ thị khả năng dư bằng đồ thị gốc
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            capRG[u][v] = capG[u][v];
        }
    }

    int max_flow = 0;  // Luồng cực đại ban đầu là 0

    // Khi còn tìm được đường tăng luồng
    while (BFS(s, t)) {
        int capP = INT_MAX;  // Khả năng tăng thêm của đường đi

        // Tìm khả năng dư nhỏ nhất trên đường tăng luồng
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            capP = min(capP, capRG[u][v]);
        }

        // Cập nhật luồng và khả năng dư trên các cạnh của đường tăng luồng
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            capRG[u][v] -= capP;
            capRG[v][u] += capP;
        }

        // Tăng luồng cực đại
        max_flow += capP;
    }

    return max_flow;
}
int main(){
    input();
    cout<<EK(s, t);
}
