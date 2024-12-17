#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int L = 0;
    int S = 0;
    int maxLength = 0;

    for (int R = 0; R < n; R++)
    {
        S += a[R];

        while (S > Q && L <= R)
        {
            S -= a[L];
            L++;
        }

        maxLength = max(maxLength, R - L + 1);
    }

    if (maxLength == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << maxLength << endl;
    }

    return 0;
}
