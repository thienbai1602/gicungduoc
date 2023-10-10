#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll MOD = 1e9 + 7;
const int mxN = 25;

int n, m;
int can[mxN][mxN];
ll dp[20][1 << 20];

void solve()
{
    cin >> n >> m;
    memset(can, 0, sizeof(can));
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++can[u][v];
    }

    memset(dp, 0, sizeof(dp));

    dp[0][1 << 0] = 1;
    for(int mask=0; mask<(1 << n); mask++)
    {
        if (mask % 2 == 0) continue;
        for(int j=0; j<n; j++)
        {
            if (dp[j][mask])
            {
                for(int k=0; k<n; k++)
                {
                    if (can[j][k] && !((mask >> k) & 1))
                    {
                        dp[k][mask | (1 << k)] = (dp[k][mask | (1 << k)] + dp[j][mask] * can[j][k]) % MOD;
                    }
                }
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
