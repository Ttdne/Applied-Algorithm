#include <bits/stdc++.h>
using namespace std;

int n, year;
int a[23];
int sum = 0;
void check(int tong){
    if (tong >= year) sum++;

}
void Try(int i, int tong) {
    if (i == n) {
        check(tong);
        return;
    }
    Try(i + 1, tong + a[i]);
    Try(i + 1, tong);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> year;
    Try(0, 0);
    cout << sum;
    return 0;
}
