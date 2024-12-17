#include <iostream>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    // freopen("test.txt", "r", stdin);
    ll n;
    string cmd;

    cin >> n;
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    while (cin >> cmd && cmd != "#") {
        if (cmd == "min_greater_equal") {
            ll x;
            cin >> x;
            auto it = s.lower_bound(x);
            if (it == s.end()) 
                cout << "NULL" << endl;
            else 
                cout << *it << endl;
        } else if (cmd == "min_greater") {
            ll x;
            cin >> x;
            auto it = s.upper_bound(x);
            if (it == s.end()) 
                cout << "NULL" << endl;
            else 
                cout << *it << endl;
        } else if (cmd == "insert") {
            ll x;
            cin >> x;
            s.insert(x);
        } else if (cmd == "remove") {
            ll x;
            cin >> x;
            auto it = s.find(x);
            if (it != s.end()) {
                s.erase(it);
            }
        }
    }

    return 0;
}
