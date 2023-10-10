#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 506;

int n, m, Q;
ll BIT[mxN][mxN][4];

void upd(int x, int y, ll w)
{
    for(int i=x; i<=n; i+=(i & -i))
    {
        for(int j=y; j<=m; j+=(j & -j))
        {
            BIT[i][j][0] += w;
            BIT[i][j][1] += x * w;
            BIT[i][j][2] += y * w;
            BIT[i][j][3] += x * y * w;
        }
    }
}

void update(int x, int y, int u, int v, ll w)
{
    upd(x, y, w); upd(u + 1, v + 1, w);
    upd(x, v + 1, -w); upd(u + 1, y, -w);
}

ll get(int x, int y)
{
    ll ret = 0;
    for(int i=x; i>0; i-=(i & -i))
    {
        for(int j=y; j>0; j-=(j & - j))
        {
            ret += (x + 1) * (y + 1) * BIT[i][j][0] - (y + 1) * BIT[i][j][1] - (x + 1) * BIT[i][j][2] + BIT[i][j][3];
        }
    }
    return ret;
}

ll query(int x, int y, int u, int v)
{
    return get(u, v) - get(x - 1, v) - get(u, y - 1) + get(x - 1, y - 1);
}

void solve()
{
    cin >> n >> m >> Q;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            ll x;
            cin >> x;
            update(i, j, i, j, x);
        }
    }

    for(int i=0; i<Q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll x, y, u, v, w;
            cin >> x >> y >> u >> v >> w;
            update(x, y, u, v, w);
        } else
        {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            cout << query(x, y, u, v) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
