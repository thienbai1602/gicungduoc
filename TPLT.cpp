#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, m;
bool vis[mxN];
vector<int> edges[mxN];

int dfs(int u)
{
    int ans = 1;
    vis[u] = true;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            ans += dfs(v);
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int num_scc = 0, ma_scc = 0;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            num_scc++;
            ma_scc = max(ma_scc, dfs(i));
        }
    }
    cout << num_scc << " " << ma_scc;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
