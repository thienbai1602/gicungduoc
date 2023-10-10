#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 2e5 + 66;

int n;
vector<int> edges[mxN];
ll dp[mxN], sub[mxN];

ll diameter(int u, int p)
{
    dp[u] = 0, sub[u] = 1;
    for(int v : edges[u])
    {
        if (v != p)
        {
            sub[u] += diameter(v, u);
            dp[u] += dp[v] + sub[v];
        }
    }
    return sub[u];
}

void dfs(int u, int p)
{
    for(int v : edges[u])
    {
        if (v != p)
        {
            dp[v] = dp[u] - sub[v] + (n - sub[v]);
            dfs(v, u);
        }
    }
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

    diameter(0, n + 1);
    dfs(0, n + 1);

    for(int i=0; i<n; i++)
    {
        cout << dp[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
