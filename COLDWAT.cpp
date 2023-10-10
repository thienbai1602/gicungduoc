#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, m;
int dis[mxN];
bool vis[mxN];
vector<int> edges[mxN];

void dfs(int u)
{
    vis[u] = true;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v, --c;
        edges[u].push_back(v);
        edges[u].push_back(c);
    }

    memset(vis, false, sizeof(vis));
    dis[0] = 1;
    dfs(0);

    for(int i=0; i<n; i++)
    {
        cout << dis[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
