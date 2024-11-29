#include <bits/stdc++.h>
#define N 1004
#define ft first
#define sc second

using namespace std;

int n;
typedef pair<int,int> ii;

pair<ii, int> a[N];
int c[N];
int d[N];
ii b[N];

int main()
{
    /*freopen("in.inp","r",stdin);
    freopen("out.out","w",stdout);*/
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i].ft.ft>>a[i].ft.sc>>a[i].sc;
    }
    sort(a+1,a+n+1);

    for(int i=1; i<=n; i++)
    {
//        cout<<a[i].ft.ft<<" "<<a[i].ft.sc<<" "<<a[i].sc<<'\n';
        b[i].ft=a[i].ft.sc;
        b[i].sc=a[i].sc;
    }

    sort(c+1,c+n+1);


    d[1]=b[1].sc;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(b[j].ft>=b[i].ft) d[j]=max(d[j],d[i]+b[j].sc);
        }
//        cout<<b[i].ft<<" cho "<<b[i].sc<<" "<<d[i]<<'\n';
    }

    cout<<d[n];
    return 0;
}
