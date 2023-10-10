#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 5e4 + 66;

int n, s;
int dis[mxN], height[mxN];
bool vis[mxN];
vector<int> edges[mxN];

void dfs(int u)
{
    vis[u] = true;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            height[v] = height[u] + 1;
            dfs(v);
            dis[u] = max(dis[u], dis[v]);
        }
    }
    dis[u] = max(dis[u], height[u]);
}

void solve()
{
    cin >> n >> s;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ret = 0;
    memset(vis, false, sizeof(vis));
    height[--s] = 0; dfs(s);

    int tp = 0;
    for(int v : edges[s])
    {
        ret = max(ret, tp + dis[v]);
        tp = max(tp, dis[v]);
        //cout << v + 1 << " " << tp << " " << dis[v] << "\n";
    }
    cout << ret + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
