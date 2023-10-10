#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 566;
const ll INF = 1e18;

int n, m, Q;
ll dp[mxN][mxN];

void solve()
{
    cin >> n >> m >> Q;

    for(int i=0; i<n; i++)
    {
        fill(dp[i], dp[i] + n, INF);
    }

    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }

    for(int i=0; i<n; i++)
    {
        dp[i][i] = 0;
    }

    for(int k=0; k<n; k++)
    {
        for(int u=0; u<n; u++)
        {
            for(int v=0; v<n; v++)
            {
                if (dp[u][v] > dp[u][k] + dp[k][v])
                {
                    dp[u][v] = dp[u][k] + dp[k][v];
                }
            }
        }
    }

    while(Q--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << (dp[u][v] == INF ? -1 : dp[u][v]) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
