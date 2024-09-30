#include <bits/stdc++.h>
#define MAX 100002
using namespace std;
long a[1000];
long I[MAX], J[MAX];
long sum[MAX];
void calculation(long n)
{
    for (long i = 0; i <= n; i++)
        sum[i] = 0;
    for (long i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i - 1];
    }
}
int main()
{
    //		freopen("test.txt", "r", stdin);
    long Q, n;
    cin >> n;
    for (long i = 0; i < n; i++)
        cin >> a[i];
    cin >> Q;
    long tong;
    calculation(n);
    for (long i = 0; i < Q; i++)
    {
        cin >> I[i] >> J[i];
        if (I[i] == 1)
        {
            tong = sum[J[i]];
        }
        else
        {
            tong = sum[J[i]] - sum[I[i] - 1];
        }
        cout << tong << endl;
    }
}
