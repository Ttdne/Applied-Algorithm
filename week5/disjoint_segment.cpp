#include <bits/stdc++.h>
using namespace std;

int n;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (y == other.y)
            return x > other.x;
        return y > other.y;
    }
};

vector<Point> point;
vector<Point> choosePoint;

int Greedy() {
    int sum = 0;
    Point checkpoint = point.back(); // Start with the last point
    point.pop_back(); // Remove the last point from the list
    choosePoint.push_back(checkpoint); // Add to chosen points
    sum++;

    while (!point.empty()) {
        Point compare = choosePoint.back();
        Point compareTo = point.back(); // Look at the last point in the vector
        point.pop_back(); // Remove it after processing

        if (compareTo.x > compare.y) {
            choosePoint.push_back(compareTo);
            sum++;
        }
    }

    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        Point X;
        cin >> X.x >> X.y;
        point.push_back(X);
    }

    sort(point.begin(), point.end()); // Sort points by y (then x)
    cout << Greedy(); // Output the result
}
