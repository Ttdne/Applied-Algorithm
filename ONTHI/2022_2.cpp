#include<bits/stdc++.h>
using namespace std;
int n;
int a[1004];
int dp[1004][1004];
//int check_palindrome(vector<int>& b){
//    int i = 0;
//    int j = b.size()-1;
//    while(i<=j){
//        if(b[i] == b[j])   {
//            i++;
//            j--;
//        }
//        else return 0;
//    }
//    return b.size();
//}
//int maxx = 0;
//void Try(int i, vector<int>& b){
//    if(i == n){
//        int check = check_palindrome(b);
//        maxx = max(maxx, check);
//        return;
//    }
//    for(int j=i+1; j<=n; j++){
//        b.push_back(a[j]);
//        Try(j, b);
//        b.pop_back();
//        Try(j, b);
//    }
//}
int Palindrome(int i, int j){
    if(i == j) return dp[i][j] = 1;
    if(dp[i][j] != -1)  return dp[i][j];
    if(a[i] == a[j])    dp[i][j] = Palindrome(i+1, j-1) + 2;
    else dp[i][j] = max(Palindrome(i+1, j), Palindrome(i, j-1));
    return dp[i][j];
}
int main(){
    cin>>n;
    int res = 0;
    memset(dp, -1, sizeof dp);

// for(int i=1;i<=n;i++)   dp[i][i] = 1;
    for(int i=1; i<=n; i++) cin>>a[i];
//
//    for(int j = 1; j<=n; j++)
//    {
//    for(int i=1; i+j<=n; i++){
//            int k=i+j;
//            if(a[i] == a[k])    dp[i][k] = dp[i+1][k-1] + 2;
//            else    dp[i][k] = max(dp[i+1][k], dp[i][k-1]);
//        }
//    }
    cout<<Palindrome(1, n);
}
