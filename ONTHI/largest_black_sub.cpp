#include<bits/stdc++.h>
#define MAX 1003
using namespace std;
int n, m;
int A[MAX][MAX];
int findArea(int h[MAX]){
    int maxArea = 0;
    stack<int> check;
    int j=1;
    h[m+1] = 0;
    for (j = 1; j <= m + 1; j++) {
         while (!check.empty() && h[check.top()] > h[j]) {
            int l = h[check.top()];
            check.pop();
            int width = check.empty() ? j - 1 : j - check.top() - 1; // Chiều rộng
            maxArea = max(maxArea, l * width);
    }
        check.push(j);
        }
    return maxArea;
}
int maxArea(){
    int maxA = 0;
    int h[MAX];
    memset(h, 0, sizeof h);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i][j] == 1) h[j]++;
            if(A[i][j] == 0)    h[j] = 0;
        }
        int area = findArea(h);
        maxA = max(maxA, area);
    }
    return maxA;
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>A[i][j];
        }
    }
    cout<<maxArea();
}
