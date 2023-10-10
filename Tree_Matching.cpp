#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 2e5 + 66;

int n;
ll dp[mxN][2];
vector<int> edges[mxN];

void dfs(int u, int p = n + 1)
{
    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
    }

    for(int v : edges[u])
    {
        if (v != p)
        {
            dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
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
    dfs(0);
    cout << max(dp[0][0], dp[0][1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
