#include <bits/stdc++.h>
#define MAX 1001
#define ii pair<int, int>
using namespace std;
queue<ii> Q;
int a[MAX][MAX];
int d[MAX][MAX];
int n, m; // n la so hang, m la so cot
int r, c; // r la so hang xuat phat, c
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int BFS()
{
    int sum = 0;
    a[r][c] = 1;
    pair<int, int> s = {r, c};
    Q.push(s);
    while (!Q.empty())
    {
        ii u = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > n || y < 1 || y > m)
                return d[u.first][u.second] + 1;
            if (a[x][y] != 1)
            {
                d[x][y] = d[u.first][u.second] + 1;
                Q.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    // freopen("test.txt", "r", stdin);
    cin >> n >> m;
    cin >> r >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            d[i][j] = 0;
        }
    }
    cout << BFS();
    cout << endl;
}
