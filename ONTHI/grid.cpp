#include<bits/stdc++.h>
using namespace std;
int H, W;
int a[1005][1005];
int dp[1005][1005];
const int MOD =  1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>H>>W;
    char c;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin>>c;
            if(c == '.')    a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    dp[1][1] = a[1][1];
    for(int i=2; i<=W; i++){
        if(a[1][i] == 1)
            dp[1][i] = dp[1][i-1] % MOD;
        else dp[1][i] = 0;
    }
    for(int i=2; i<=H; i++){
        if(a[i][1] == 1)
            dp[i][1] = dp[i-1][1] % MOD;
        else dp[i][1] = 0;
    }
    for(int i=2; i<=H; i++){
        for(int j=2; j<=W; j++){
            if( a[i][j] == 1){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout<<dp[H][W];
}
