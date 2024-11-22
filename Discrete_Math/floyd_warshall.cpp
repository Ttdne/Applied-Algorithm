#include<bits/stdc++.h>
using namespace std;

int w[N][N];
int D[N][N];
int P[N][N];
int main(){
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            D[i][j] = w[i][j];
        }
    }

    for(int k=1; k<n; k++){
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    D[i][j] = P[k][j];
                }
            }
        }
    }
}
