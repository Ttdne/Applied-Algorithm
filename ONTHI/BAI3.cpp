#include<iostream>
#include<cstring>
#include<vector>
#include<list>
using namespace std;
int m, n;
bool pairr[12][32];
int erd[32];
int lower[12];
int k;
bool disjoint[32][32];
int allocated[32];
list<int> teach[12];
int volume[12];
int maxVolume = INT_MAX;
bool found = false;
bool check(int lop, int GV) {
    if (!pairr[GV][lop]) return false;
    for (auto i : teach[GV]) {
        if (disjoint[i][lop]) return false; }
    return true;
}
bool validateLowerBounds() {
    for (int i = 1; i <= m; i++) {
        if (teach[i].size() < lower[i]) return false;}
    return true;}
void Try(int i) {
    if (i > n) {
        if (validateLowerBounds()) {
            found = true;
            int ma=INT_MIN;

            for(int i=1;i<=m;i++)
            {ma=max(ma,volume[i]);}
            maxVolume=min(maxVolume, ma);}}
    for (int j = 1; j <= m; j++) {
        if (check(i, j)) {
            volume[j] += erd[i];
            allocated[i] = j;
            teach[j].push_back(i);
            Try(i + 1);
            volume[j] -= erd[i];
            teach[j].pop_back();    }}}
int main() {
    memset(pairr, false, sizeof(pairr));
    memset(disjoint, false, sizeof(disjoint));
    memset(volume, 0, sizeof(volume));
    memset(allocated, -1, sizeof(allocated));
    cin >> m >> n;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        for (int j = 1; j <= a; j++) {
            cin >> b;
            pairr[i][b] = true;}}
    for (int i = 1; i <= n; i++) cin >> erd[i];
    for (int i = 1; i <= m; i++) cin >> lower[i];
    cin >> k;
    int p, q;
    for (int i = 1; i <= k; i++) {
        cin >> p >> q;
        disjoint[p][q] = true;
        disjoint[q][p] = true;}
    Try(1);
    if (found) {
        cout << maxVolume;
    } else {
        cout << -1;}
    return 0;}
