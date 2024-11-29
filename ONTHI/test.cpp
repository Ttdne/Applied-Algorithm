#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int dp[100];
int s[100];
int mi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)  cin>>a[i];
    s[0] = 0;
    for(int i=1; i<=n; i++){
        s[i] = s[i-1] + a[i];
    }
    /*dp[1] = a[1];
    for(int i=2; i<=n; i++){
        if(a[i] > dp[i-1] + a[i]){
            dp[i] = a[i];
        }
        else dp[i] = dp[i] + a[i];
    }
   cout << *max_element(dp + 1, dp + n + 1);
   cout<<dp[n];*/
   mi= 0;
    for(int i=1; i<=n; i++){
        dp[i] = s[i] - mi;
        mi = min(mi, s[i]);
    }
    cout<<*max_element(dp+1, dp+n+1);
}
