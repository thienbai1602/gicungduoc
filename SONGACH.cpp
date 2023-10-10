#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2005;
const ll MOD = 998244353;

int n, m, K;
ll dp[mxN][mxN];

void solve()
{
    cin >> n >> m >> K;
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        dp[i][0] = m;
    }

    for(int i=1; i<=n; i++)
    {
        for(int special=1; special<=K; special++)
        {
            dp[i][special] = (dp[i - 1][special] + dp[i - 1][special - 1] * (m - 1)) % MOD;
        }
    }
    cout << dp[n][K];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SONGACH.INP", "r", stdin);
    freopen("SONGACH.OUT", "w", stdout);
    solve();
    return 0;
}
