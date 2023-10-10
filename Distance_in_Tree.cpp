#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxK = 566;
const int mxN = 5e4 + 66;

int n, K;
ll ans = 0, dp[mxN][mxK];
vector<int> edges[mxN];

void dfs(int u, int p)
{
    for(int i=0; i<=K; i++)
    {
        dp[u][i] = (i == 0);
    }

    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
            for(int dis=0; dis<=K && K - dis > 1; dis++)
            {
                ans += dp[v][dis] * dp[u][K - dis - 1];
            }

            for(int dis=1; dis<=K; dis++)
            {
                dp[u][dis] += dp[v][dis - 1];
            }
        }
    }
}

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(0, n + 1);

    for(int u=0; u<n; u++)
    {
        ans += dp[u][K];
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
