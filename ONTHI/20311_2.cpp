#include<bits/stdc++.h>
using namespace std;
struct block{
    int x, y, z;
    int volume;
};
int T;
block chinh;
int N;
block khoi[53];
int dp[103][103][1013];
int Try(int i, int j, int k, int index){
    if (i <= 0 || j <= 0 || k <= 0)  return 0;
    if(dp[i][j][k] != -1)  return dp[i][j][k];
    if(index > N){
            return i*j*k;
    }
    int pi = khoi[index].x;
    int wi = khoi[index].y;
    int hi = khoi[index].z;
    int minWaste = i *j *k;
    vector<tuple<int, int, int>> rotations = {
        {pi, wi, hi}, {pi, hi, wi}, {wi, pi, hi},
        {wi, hi, pi}, {hi, pi, wi}, {hi, wi, pi}
    };
    int waste;
    for(auto[x, y, z]: rotations){
        if (i >= x && j >= y && k >= z) {
            waste= Try(i-x, j, k, index) + Try(x, j-y, k, index) + Try(x, y, k-z, index);
        minWaste = min(minWaste, waste);
        }
    }
    minWaste = min(minWaste, Try(i, j, k, index+1));
    return dp[i][j][k] = minWaste;
}
int main(){
    cin>>T;
    memset(dp, -1, sizeof dp);
    int a, b, c;
    while(T--){
        cin>>a>>b>>c;
        chinh.x = a;
        chinh.y = b;
        chinh.z = c;
        chinh.volume = chinh.x * chinh.y * chinh.z;
        cin>>N;
        for(int i=1; i<=N; i++){
            cin>>a>>b>>c;
            khoi[i].x = a;
            khoi[i].y = b;
            khoi[i].z = c;
            khoi[i].volume = khoi[i].x * khoi[i].y * khoi[i].z;
        }
        cout<<Try(chinh.x, chinh.y, chinh.z, 1)<<"\n";
    }
}
