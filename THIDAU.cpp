#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 3e5 + 66;

bool f;
vector<vector<int>> edges;
int n, m, x[mxN], y[mxN], color[mxN];

void dfs(int u, int col)
{
    color[u] = col;
    for(int v : edges[u])
    {
        if (color[v] == -1)
        {
            dfs(v, 1 - col);
        } else if (color[v] == color[u]) f = false;
    }
}

bool check(int cur)
{
    edges = vector<vector<int>>(n);
    for(int i=0; i<cur; i++)
    {
        edges[x[i]].pb(y[i]);
        edges[y[i]].pb(x[i]);
    }

    memset(color, -1, sizeof(color));
    for(int i=0; i<n; i++)
    {
        if (color[i] == -1)
        {
            f = true;
            dfs(i, 0);
            if (!f) return false;
        }
    }
    return true;
}

int bs(int l, int r)
{
    int ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans + 1;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
    }
    cout << bs(1, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
