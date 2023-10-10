#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 11;
const ll INF = 1e18;
const int u[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int v[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int n, m;
ll a[mxN][mxN], mi;
bool vis[mxN][mxN];

bool sf(int x, int y)
{
    return (x > 0 && x <= n && y > 0 && y <= m);
}

void dfs(int x, int y, ll k, ll val)
{
    if (k == n * m)
    {
        mi = min(mi, val);
        return;
    }

    for(int i=0; i<8; i++)
    {
        int ux = u[i] + x, vx = v[i] + y;
        if (sf(ux, vx) && !vis[ux][vx])
        {
            vis[ux][vx] = true;
            dfs(ux, vx, k + 1, val + k * a[ux][vx]);
            vis[ux][vx] = false;
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> a[i][j];
        }
    }

    mi = INF;
    memset(vis, false, sizeof(vis));
    vis[1][1] = true;
    dfs(1, 1, 1, 0);
    cout << (mi == INF ? -1 : mi);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
