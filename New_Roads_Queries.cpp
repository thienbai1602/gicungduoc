#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5 + 66;

int n, m, Q;
ll x[mxN], y[mxN], p[mxN], sz[mxN];

int findp(int u)
{
    if (u == p[u]) return u;
    return p[u] = findp(p[u]);
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}

bool check(int a, int b, int cnt)
{
    for(int i=0; i<n; i++)
    {
        p[i] =  i;
        sz[i] = 1;
    }

    for(int i=0; i<cnt; i++)
    {
        Union(x[i], y[i]);
    }
    return findp(a) == findp(b);
}

int bs(int a, int b, int l, int r)
{
    int ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (check(a, b, m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m >> Q;
    for(int i=0; i<m; i++)
    {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
    }

    while(Q--)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << bs(a, b, 1, m) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
