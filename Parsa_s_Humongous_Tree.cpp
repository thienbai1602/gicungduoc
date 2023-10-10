#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 1e5 + 66;

int tc, n;
ll dp[mxN][2], val[mxN][2];
vector<int> edges[mxN];

void dfs(int u, int p = n + 1)
{
    for(int id=0; id<2; id++)
    {
        dp[u][id] = 0;
    }

    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }

    for(int id=0; id<2; id++)
    {
        for(int v : edges[u])
        {
            if (v != p)
            {
                ll x = max(dp[v][id] + abs(val[v][id] - val[u][id]), dp[v][!id] + abs(val[v][!id] - val[u][id]));
                dp[u][id] += x;
            }
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> val[i][0] >> val[i][1];
    }

    for(int i=0; i<n; i++)
    {
        edges[i].clear();
    }

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
