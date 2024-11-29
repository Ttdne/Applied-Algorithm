#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
/*Sắp xếp các cạnh: Sắp xếp tất cả các cạnh của đồ thị theo trọng số.
Khởi tạo các tập hợp: Sử dụng Disjoint Set để khởi tạo mỗi đỉnh trong đồ thị thành một tập hợp riêng biệt.
Chọn các cạnh: Duyệt qua danh sách các cạnh đã sắp xếp, và cho mỗi cạnh, sử dụng hàm findSet để kiểm tra xem hai đỉnh của cạnh đó có thuộc cùng một tập hợp không. Nếu không, thêm cạnh vào cây bao trùm và hợp nhất hai tập hợp bằng hàm link.
*/
int parent[MAX];
int r[MAX];
int n, m;
int Ax[753];
int By[753];
struct Edge {
    int src, dest, weight;
};
vector<Edge> edges;
list<Edge> dungroi;

void makeSet(int x){ // tao 1 tap con chua duy nhat phan tu x
    parent[x] = x;  // dat cha cua x la chinh no, nghia la x la goc cua tap hop
    r[x] = 0;   //dat rank của
}

int findset(int x){ //tra ve dinh danh cua tap chua x
    while( x != parent[x]) x = parent[x];
    return x;
}

void link(int x, int y){    // hop nhat 2 tap dinh danh x y
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
    int weight = 0;
    for(int x = 1; x <abs(n); x++) makeSet(x);
    sort(edges.begin(), edges.end(), compare);
    for(auto edge: edges){
        int u = edge.src;
        int v = edge.dest;
        if(findset(u) != findset(v)){
            weight += edge.weight;
            link(findset(u),findset(v));
        }
    }
    for(auto e: dungroi){
        weight -= e.weight;
    }
        cout  << weight;
}

int main() {
    cin>>n;
    int a,b,c,d;
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        Ax[i] = a;
        By[i] = b;
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>c>>d;
        Edge e;
        e.src = c;
        e.dest = d;
        int tinh = (Ax[c] - Ax[d])*(Ax[c] - Ax[d]) + (By[c] - By[d])*(By[c] - By[d]);
        e.weight = tinh;
        dungroi.push_back(e);
    }
    for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
        Edge e;
        e.src = i;
        e.dest = j;
        int tinh = (Ax[i] - Ax[j])*(Ax[i] - Ax[j]) + (By[i] - By[j])*(By[i] - By[j]);
        e.weight = tinh;
        edges.push_back(e);
            }
    }
    for(auto e: edges){
        for(auto edge: dungroi){
            if((e.src == edge.src && e.dest == edge.dest) || (e.src == edge.dest && e.dest == edge.src)){
                e.weight = INT_MAX;

            }
        }
    }
    Kruskal();

    return 0;
}
