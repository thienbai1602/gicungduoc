#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;

int n;
bool vis[mxN];
vector<int> edges[mxN];

ll dfs(int u)
{
    vis[u] = true;
    ll cow = sz(edges[u]) + (u == 0);

    ll curCow = 1, ans = 0;
    while(curCow < cow)
    {
        curCow *= 2;
        ++ans;
    }

    for(int v : edges[u])
    {
        if (!vis[v])
        {
            ans += dfs(v) + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    memset(vis, false, sizeof(vis));
    cout << dfs(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
