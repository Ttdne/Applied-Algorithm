#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000002;
const int LOG = 20; // log2(100002) ~ 16.6 -> làm tròn lên 17
long long n;
long long a[MAXN];
long long m;
long long I[MAXN], J[MAXN];
long long M[LOG][MAXN];
void preprocessing()
{
    // Precompute the minimums for intervals with different lengths
    for (int j = 0; j < n; j++)
    {
        M[0][j] = j; // Initialize M for the intervals of length 1
    }

    for (int i = 1; (1 << i) <= n; i++)
    { // Use bit shifting instead of pow(2, i)
        for (int j = 0; (j + (1 << i) - 1) < n; j++)
        {
            if (a[M[i - 1][j]] < a[M[i - 1][j + (1 << (i - 1))]])
            {
                M[i][j] = M[i - 1][j];
            }
            else
            {
                M[i][j] = M[i - 1][j + (1 << (i - 1))];
            }
        }
    }
}
long long query(int L, int R)
{
    int length = R - L + 1;
    int i = log2(length);
    if (a[M[i][L]] < a[M[i][R - (1 << i) + 1]])
    {
        return a[M[i][L]];
    }
    else
    {
        return a[M[i][R - (1 << i) + 1]];
    }
}
int main()
{
    // 	freopen("test.txt", "r", stdin);
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    preprocessing();
    for (int i = 0; i < m; i++)
    {
        cin >> I[i] >> J[i];
    }
    for (int i = 0; i < m; i++)
    {
        sum += query(I[i], J[i]);
    }
    cout << sum;
}
