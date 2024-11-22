#include<bits/stdc++.h>
#define MAX 1004
using namespace std;
int n;
struct Point{
    int x;
    int y;

    bool operator<(const Point& other) const{
        if( x == other.x)
            return y < other.y;
        return x < other.x;
    }
};
map<Point, int> coord;
vector<Point> dp={0};
int DP(){
    int sum=0;
    Point check_point;
    for(auto &p: coord){
            Point t = p.first;
            Point search1, search2;
            search1.x = t.x -1;
            search1.y = t.y;
            search2.x = t.x;
            search2.y = t.y - 1;
            dp[t] = max(dp[search1], dp[search2]) + coord[t];
            check_point = t;
        }
    }
    return dp[check_point];
}
int main(){
   cin>>n;
    for(int i=0; i<n; i++){
        Point point;
        int c;
        cin>>point.x>>point.y;
        cin>>c;
        coord[point] = c;
    }
    cout<<DP();
}




