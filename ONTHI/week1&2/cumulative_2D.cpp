#include <bits/stdc++.h>
#define MAX 1002
using namespace std;
long a[MAX][MAX];
long sum[MAX][MAX];

void calculation(int n, int m)
{
    for (int i = 0; i <= n; i++)
        sum[i][0] = 0;
    for (int j = 0; j <= m; j++)
        sum[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
}
int main()
{
    // 	ios_base::sync_with_stdio(false); // Tang t?c d? d?c/ghi
    //     cin.tie(0);
    // 	freopen("test.txt", "r", stdin);
    int n, m;
    long long Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    calculation(n, m);
    long long tong;
    cin >> Q;
    for (long i = 0; i < Q; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        tong = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
        cout << tong << endl;
    }
}
