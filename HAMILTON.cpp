#include    <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;

const int mxN = 22;

bool flat = false;
int n, m, p[mxN];
vector<int> path, edges[mxN];

void tv(int u)
{
    int st = u;
    path.pb(st);
    u = p[u];
    while(st != u)
    {
        path.pb(u);
        u = p[u];
    }
    path.pb(u);
}

void dfs(int u, int st, int deep)
{
    if (flat) return;
    if (u == st && deep == n)
    {
        tv(u);
        flat = true;
        return;
    }

    for(int v : edges[u])
    {
        if (p[v] == -1)
        {
            p[v] = u;
            dfs(v, st, deep + 1);
            p[v] = -1;
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    fill(p, p + n, -1);
    dfs(0, 0, 0);
    if (!flat)
    {
        cout << -1;
    } else
    {
        reverse(all(path));
        for(int &x : path)
        {
            cout << x + 1 << " ";
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
