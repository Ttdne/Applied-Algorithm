#include<bits/stdc++.h>
using namespace std;
int N;
struct Point{
    double x, y;
};

bool comparebyY(const Point& p1, const Point& p2){
    return p1.y < p2.y;
}

bool compareX(const Point& p1, const Point& p2){
    return p1.x < p2.x;
}
double distance(const Point& p1, const Point& p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double closestPair(vector<Point>& Px){
    if(Px.size() == 2){
        Point x1 = Px.back();
        Px.pop_back();
        Point x2 = Px.back();
        return distance(x1, x2);
    }
    if (Px.size() < 2) return numeric_limits<double>::infinity();;
    int n = Px.size();
    int mid = n / 2;
    vector<Point> Lx(Px.begin(), Px.begin() + mid);
    vector<Point> Rx(Px.begin() + mid, Px.end());

    double d_left = closestPair(Lx);
    double d_right = closestPair(Rx);
    double d = min(d_left, d_right);

    vector<Point> Px_strip;
    for(int i=0; i< Px.size(); i++){
        if(abs(Px[i].x - Px[mid].x) < d){
            Px_strip.push_back(Px[i]);
        }
    }
    sort(Px_strip.begin(), Px_strip.end(), comparebyY);
    double d_strip = d;
    for(int i=0; i<Px_strip.size(); i++){
        for(int j=i+1; j<Px_strip.size() && (Px_strip[j].y - Px_strip[i].y) < d_strip; j++){
            double dist = distance(Px_strip[i], Px_strip[j]);
            d_strip = min(d_strip, dist);
        }
    }
    return min(d_strip, d);
}
int main(){
    freopen("test.txt", "r", stdin);
    vector<Point> Px;
    cin>>N;
    for(int i=0; i<N; i++){
        Point t;
        cin>>t.x>>t.y;
        Px.push_back(t);
    }
    sort(Px.begin(), Px.end(), compareX);
cout << fixed << setprecision(6) << closestPair(Px); // Set precision for output}
}
