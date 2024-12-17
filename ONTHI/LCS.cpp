#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[3004][3004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string xau = "";
    cin>>s1;
    cin>>s2;
    int n = s1.size();
    int m = s2.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                    dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i=n, j=m;
    while( i > 0 && j> 0){
        if(s1[i-1] == s2[j-1]){
            xau = s1[i-1] + xau;
            i--;
            j--;
        }else if(dp[i-1][j] >= dp[i][j-1])  i--;
        else    j--;
    }
    cout<<xau;
}
