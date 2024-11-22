#include<bits/stdc++.h>
#define MAX 25
using namespace std;

bool visited[MAX] = {0};    // keep track of the visited node
int load = 0;               //current bus load (number of the passengers on the bus)
int n, k;           // n = number of passengers, k = bus capacity
int c[MAX][MAX];    //Distance matrix
int c_min = INT_MAX;    // Minimum travel distance between any two points
int fopt = INT_MAX;     //Optimal (minimal) route length_error
int x[MAX];         //To store the current path
int f=0;            // Current cost
bool check(int i){
    if( i<=n){
        return (!visited[i] && load < k);
    }
    else{
        return (!visited[i] && visited[i-n] && load >0);
    }
}

void Try(int i){
    for(int j=1; j<= 2 *n; j++){
        if(check(j)){
            if( j<= n){
                load ++;
                visited[j] = true;
                f += c[x[i-1]][j];
                x[i] = j;
            }
            else{
                load --;
                visited[j] = true;
                f += c[x[i-1]][j];
                x[i] = j;
            }

            if (i == 2*n){
                int ftemp = f + c[x[i]][0];
                if (ftemp < fopt) fopt = ftemp;
            }
            else{
                    int g = f + (2*n - i +1)*c_min;
                    if( g < fopt) Try(i+1);
                }
            visited[j] = false;
            f -= c[x[i-1]][j];
            if(j <= n) load--;
            else load++;
        }
    }
}
int main(){
    freopen("test.txt", "r", stdin);
    cin>>n>>k;
    for(int i=0; i<= 2*n; i++){
        for(int j=0; j<= 2*n; j++){
            cin>>c[i][j];
            if (i != j && c_min > c[i][j]) c_min = c[i][j];
        }
    }
    x[0] = 0;
    Try(1);
    cout<<fopt;
}
