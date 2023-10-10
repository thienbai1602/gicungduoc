#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 55;

int n, m;
bool vis[N], used[N], flat;
vector<int> edges[N], ret;

void dfs(int u)
{
    vis[u] = true;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            dfs(v);
        } else
        {
            flat = true;
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
        edges[u].push_back(v);
    }

    memset(used, true, sizeof(used));

    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            used[i] = false;
        }
    }

    memset(vis, false, sizeof(vis));
    for(int i=n-1; i>=0; i--)
    {
        if (!used[i] && !vis[i])
        {
            dfs(i);
            ret.push_back(i);
        }
    }
    cout << (int)ret.size() << "\n";
    for(int i=(int)ret.size()-1; i>=0; i--)
    {
        cout << ret[i] + 1 << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
