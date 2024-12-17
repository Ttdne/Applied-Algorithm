/*#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n;
int a[MAX];
int dp[MAX];
int save[MAX];
int DP(int i){
    if(i == 1){
        save[i] = -1;
        return dp[i] = a[i];
    }
    if(i == 2){
        if(a[i] > a[i-1]){
            save[i] = -1;
            return dp[i] = a[i];}
        else {
            save[i] = i-1;
            return dp[i] = a[i-1];
        }
    }
    if(dp[i] != -1) return dp[i];
    int first = DP(i-1);
    int sec = DP(i-2) + a[i];
    int result;
    if(first >= sec) {
        result = first;
        save[i] = i-1;
    }
    else{
        result = sec;
        save[i] = i-2;
    }
    return dp[i] = result;
}
int main(){
    memset(dp, -1, sizeof dp);
    memset(save, -1, sizeof save);
    cin>>n;
    int sum=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<DP(n)<<"\n";
    vector<int> selected;
    for(int i=n; i>0; i= save[i]){
        if(save[i] == i-2 ||  save[i] == -1) selected.push_back(i);
    }
    cout<<selected.size()<<endl;
    for(int i = selected.size() - 1; i>=0; i--)   cout<<selected[i]<<" ";
}*/
#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n;
int a[MAX];
int dp[MAX];
int last;
int pre[MAX];
vector<int> ans;

int main(){

    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    if(a[1]>0)
    {
        dp[1]=a[1];
        pre[1]=1;
    }
    else{
        dp[1] = 0;
        pre[1] = 0;
    }

    for(int i=2;i<=n;i++)
    {
        if(dp[i-2]+a[i]>dp[i-1])
        {
            last=i;
            pre[i]=i;
            dp[i]=dp[i-2]+a[i];
        }
        else
        {
            pre[i]=pre[i-1];
            dp[i]=dp[i-1];
        }
//        cout<<dp[i]<<" ";
    }
    if(dp[n] == 0){
        int max1 = INT_MIN;
        int index;
        for(int i=1; i<=n; i++){
            max1 = max(max1, a[i]);
            if(max1 == a[i]) index = i;
        }
        cout<<max1<<endl<<1<<endl<<index;
    }
    else{ cout<<dp[n]<<'\n';
        while(pre[last])
        {
            ans.push_back(last);
            if(pre[last]==last)
            {
                if(last>1) last=pre[last-2];
                else break;
            }
            else last=pre[last];
        }
        cout<<ans.size()<<'\n';

        while(ans.size())
        {
            cout<<ans.back()<<" ";
            ans.pop_back();
        }
    }
    return 0;

}
