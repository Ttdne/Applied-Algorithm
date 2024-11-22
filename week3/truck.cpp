#include<bits/stdc++.h>
#define MAX 50
using namespace std;
int n, K, Q;        //K: Số lượng xe tải. Biến này xác định số xe tải có sẵn để phục vụ khách hàng.
int load[MAX]={0};
int cmin = INT_MAX;     //Chi phí di chuyển tối thiểu giữa các điểm (có thể là khoảng cách hoặc chi phí). Biến này được sử dụng để tính toán dự đoán chi phí (lower bound) cho các hành trình.
int y[MAX];         //gia tri diem dau tien truck i don
int x[MAX];     // Mảng để lưu trữ hành trình hiện tại của xe tải, cho biết các khách hàng mà xe tải đang đi đến.
int segments=0; //Biến đếm số lượng khách hàng đã được phục vụ trong hành trình hiện tại. Được sử dụng để xác định xem tất cả khách hàng đã được phục vụ hay chưa.
int nbR=0;      //Số lượng khách hàng đã được phục vụ trong các hành trình (số lượng segment). Biến này giúp kiểm soát số lượng khách hàng mà các xe tải đã phục vụ.
int c[MAX][MAX];
int f=0;        //Tổng chi phí hiện tại của hành trình (tổng chi phí di chuyển). Biến này sẽ được cập nhật trong quá trình tìm kiếm hành trình.
int fopt = INT_MAX;     //Tổng chi phí tối ưu hiện tại (tốt nhất tìm được). Biến này được sử dụng để lưu trữ giá trị tối ưu khi tìm được một hành trình tốt hơn.
int visited[MAX]={0}, d[MAX];

bool checkX(int v, int k){          // v: Đây là chỉ số của khách hàng mà xe tải dự định đến (hoặc đã đến); k:Đây là chỉ số của xe tải hiện tại (xe tải thứ k)
    if(v > 0 && visited[v]) return false;
    if ( d[v] + load[k] > Q ) return false;
    return true;
}

bool checkY(int v, int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    if ( d[v] + load[k] > Q ) return false;
    return true;
}

void TryX(int s, int k){
    if(s == 0){
        if(k < K){
            TryX(y[k+1], k+1);
        }
        return;
    }
    for(int v=0; v<=n; v++){
        if(checkX(v,k)){
            x[s] = v;
            visited[v] = true;
            f +=c[s][v];
            load[k] += d[v];
            segments++;
        if(v>0){
            int ftemp = f + (n+nbR-segments)*cmin;
            if(ftemp < fopt) TryX(v,k);
        }else{
            if(k<K) {
                int ftemp = f + (n+nbR-segments)*cmin;
                if(ftemp < fopt) TryX(y[k+1],k+1);
            }
            else if(k == K){
                if(segments == n + nbR){
                    if (f < fopt) fopt = f;
                }

            }
        }
         visited[v] = false;
            f -=c[s][v];
            load[k] -= d[v];
            segments--;
    }
    }
}

void TryY(int k){
    int s=0;
    if(y[k-1] > 0) s = y[k-1] +1;
    for(int i=s; i<=n; i++){
        if(checkY(i,k)){
            y[k] = i;
            visited[i] = true;
            f +=c[0][i];
            load[k] +=d[i];
             if(i > 0){
                segments++;
            }
             if(k < K){
                TryY(k+1);
            }
            else{
                nbR = segments;
                TryX(y[1], 1);
                }
            visited[i]=false; f -= c[0][i]; load[k] -= d[i];
            if(i > 0){
                 segments--;
            }
        }
    }

}

int main(){
    freopen("test.txt", "r", stdin);
    cin>>n>>K>>Q;
    for(int i=1; i<=n; i++) cin>>d[i];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin>>c[i][j];
            if (i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }
    TryY(1);
    cout<<fopt<<endl;

}
