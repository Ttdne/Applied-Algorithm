#include<bits/stdc++.h>
using namespace std;
int m;
/*Sắp xếp các cạnh: Sắp xếp tất cả các cạnh của đồ thị theo trọng số.
Khởi tạo các tập hợp: Sử dụng Disjoint Set để khởi tạo mỗi đỉnh trong đồ thị thành một tập hợp riêng biệt.
Chọn các cạnh: Duyệt qua danh sách các cạnh đã sắp xếp, và cho mỗi cạnh, sử dụng hàm findSet để kiểm tra xem hai đỉnh của cạnh đó có thuộc cùng một tập hợp không. Nếu không, thêm cạnh vào cây bao trùm và hợp nhất hai tập hợp bằng hàm link.
*/
int parent[100];
int r[100];
int V;
struct Edge {
    int src, dest, weight;
};
vector<Edge> 20;

void makeSet(int x){ // tao 1 tap con chua duy nhat phan tu x
    parent[x] = x;  // dat cha cua x la chinh no, nghia la x la goc cua tap hop
    r[x] = 0;   //dat rank của
}

int findset(int x){ //tra ve dinh danh cua tap chua x
    while( x != parent[x]) x = parent[x];
    return x;
}

void link(int x, int y){    // hop nhat 2 tap dinh danh x y
    vector<Edge> result;
    if(r[x] > r[y]) parent[y] = x;
    else{
        parent[x] = y;
        if(r[x] == r[y]) r[y] ++;
    }

}
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}
void Kruskal(){
    vector<Edge> result;
    int weight = 0;
    for(int x = 1; x <abs(V); x++) makeSet(x);
    sort(edges.begin(), edges.end(), compare);
    for(auto edge: edges){
        int u = edge.src;
        int v = edge.dest;
        if(findset(u) != findset(v)){
            result.push_back(edge);
            weight += edge.weight;
            link(findset(u),findset(v));
        }
    }
     cout << "Edges in Minimum Spanning Tree:\n";
    for (Edge e : result) {
        cout << e.src << " -- " << e.dest << " == " << e.weight << "\n";
    }
    cout << "Total weight: " << weight << "\n";
}

int main() {
    V = 5; // Số đỉnh
    edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Kruskal();

    return 0;
}
