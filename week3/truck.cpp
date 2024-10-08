#include<bits/stdc++.h>
#define MAX 50
using namespace std;
int n, K, Q;
int load[MAX]={0};
int cmin = INT_MAX;
int y[MAX], x[MAX], segments=0, nbR=0, c[MAX][MAX], f=0, fopt = INT_MAX, visited[MAX]={0}, d[MAX];
bool check_X(int v, int k) {
    if (v > 0 && visited[v]) return false;  // Quay lại depot
    if ((load[k] + d[v]) > Q) return false;  // Số lượng hàng vượt quá sức chứa
    return true;  // Điều kiện thỏa mãn
}

bool check_Y(int v, int k){
    if(v == 0) return true;
    if ((load[k] + d[v]) >Q) return false;
    if(visited[v] == true) return false;
    return true;
}

void TryX(int s, int k){
    if(s == 0){
        if(k < K)
            TryX(y[k+1], k+1);
        return;
    }
        for(int v=0; v<=n; v++){
            if(check_X(v, k)){   // can go to customer v
                x[s] = v;
                visited[v] = true; f+= c[s][v]; load[k] += d[v]; segments++;
                if(v > 0){
                    int lowerB = f + (n+nbR - segments)*cmin;
                    if(lowerB < fopt) TryX(v, k);
                }
                else{ //v = 0 -> truck k back to the warehouse
                    if(k == K){
                        if(segments == n + nbR){
                            if(f < fopt) fopt = f;
                        }
                    }
                        else {
                            int lowerB = f + (n+nbR - segments)*cmin;
                            if(lowerB < fopt) TryX(y[k+1], k+1);
                        }
                    }
                visited[v] = false;
                f = f - c[s][v];
                load[k] = load[k] - d[v];
                segments--;
        }
        }
}


void TryY(int k){   // determine the first cus of trip of truck k (Value of y[k]=?
    int s = 0;
    if(y[k-1] > 0) s = y[k-1] +1;
    for(int v=s; v<=n; v++){
        if(check_Y(v,k)){
            y[k] =v;
            if(v > 0){
                segments++;
            }
            visited[v] = true;
            f+= c[0][v];
            load[k] += d[v];
            if(k < K){
                TryY(k+1);
            }
            else{
                nbR = segments;
                TryX(y[1], 1);}
            visited[v]=false; f -= c[0][v]; load[k] -= d[v];
            if(v > 0){
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
