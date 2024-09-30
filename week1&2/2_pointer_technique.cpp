#include <bits/stdc++.h>
#define ll long long
#define MAX 1000002
using namespace std;

int main()
{
    // freopen("test.txt", "r", stdin);
    ll n, M;
    ll a[MAX];
    cin >> n >> M;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll res = 0;
    ll i = 0;
    ll j = n - 1;
    while (i != j)
    {
        if ((a[i] + a[j]) == M)
        {
            res++;
            i++;
            j--;
        }
        else if ((a[i] + a[j]) < M)
        {
            i++;
        }
        else if ((a[i] + a[j]) > M)
            j--;
    }
    cout << res;
}