#include<bits/stdc++.h>
#define MAX 25
using namespace std;
int n, k;
int a[MAX][MAX];
int load=0;
int f=0;
int fopt = INT_MAX;
int x[MAX];
int cmin = INT_MAX;
bool visited[MAX];
bool check(int j){
    if(j <=n){
        return (!visited[j] && load <k);
    }
    else{
        return (!visited[j] && visited[j-n] && load >0);
    }
}
void Try(int i){
    for(int j=1; j<=2*n; j++){
        if(check(j)){
            if(j <=n){
                visited[j] = true;
                load++;
                f += a[x[i-1]][j];
                x[i] = j;
                if(i == 2*n){
                    int ftempt = f + a[x[i]][0];
                    if(ftempt < fopt){
                        fopt = ftempt;
                        }
                }
                else{
                    int g = f + (2*n -i +1) *cmin;
                    if( g < fopt)
                        Try(i+1);
                }
                f -=a[x[i-1]][j];
                visited[j] = false;
                load--;
            }
            else{
                visited[j] = true;
                load--;
                f += a[x[i-1]][j];
                x[i] = j;
                if(i == 2*n){
                    int ftempt = f + a[x[i]][0];
                    if(ftempt < fopt){
                        fopt = ftempt;
                        }
                }
                else{
                    int g = f + (2*n -i +1) *cmin;
                    if( g < fopt)
                        Try(i+1);
                }
                f-= a[x[i-1]][j];
                visited[j] = false;
                load++;
            }
        }
    }
}
int main(){
    memset(visited, false, sizeof visited);
    cin>>n>>k;
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin>>a[i][j];
            if(i != j && cmin > a[i][j]) cmin = a[i][j];
        }
    }
    x[0] = 0;
    Try(1);
    cout<<fopt;
}
