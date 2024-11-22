#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int d[MAX]; // trong so cua canh nho nhat noi v với 1 dinh da thuoc cay khung
int near[MAX]; // dau mut cua dinh thuoc cay khung chua trong so cua canh nho nhat
int adj_matrix[MAX][MAX];
bool MST[MAX] = {0};
int n, m;
int findMin(){
    int minD = INT_MAX;
    int index=-1;
    for(int v =0; v<n; v++){
        if(! MST[v] && d[v] < minD){
            minD = d[v];
            index = v;
        }
    }
    return index;
}
void Prim(){
    int sum = 0;
    MST[0] =1; d[0] = 0; near[0] = 0;
    for(int v=1; v<n; v++){
       d[v] = (adj_matrix[0][v] != 0) ? adj_matrix[0][v] : INT_MAX;
        near[v] = 0;
    }
    for(int k=1; k< n; k++){
        int v = findMin();
        if (v == -1) break; // Không tìm thấy đỉnh phù hợp

        MST[v] = true;
        sum += d[v];

        // In ra cạnh được thêm vào MST
        cout << "Cạnh " << near[v] << " - " << v << " với trọng số " << d[v] << endl;

        for(int i=0; i<n; i++){
            if (!MST[i] && adj_matrix[v][i] > 0 && d[i] > adj_matrix[v][i]){
                d[i] = adj_matrix[v][i];
                near[i] = v;
            }
    }
}
}
int main(){
    cin>>n>>m;

    // Đồ thị được biểu diễn dưới dạng danh sách kề
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj_matrix[a][b] = c;
        adj_matrix[b][a] = c;
    }
    Prim();

    return 0;
}
