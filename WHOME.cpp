#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;
const ll INF = 1e18;

int n, M;
ll P, C, a[mxN], S[mxN], dp[mxN][1 << 6];

ll sq(ll x)
{
    return x * x;
}

void solve()
{
    cin >> n >> M >> P >> C;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<M; i++)
    {
        cin >> S[i];
    }

    sort(a + 1, a + n + 1);
    for(int i=0; i<=n; i++)
    {
        fill(dp[i], dp[i] + (1 << M), -INF);
    }

    dp[0][0] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int mask=0; mask<(1 << M); mask++)
        {
            dp[i][mask] = max(dp[i - 1][mask], dp[i][mask]);
            for(int k=0; k<M; k++)
            {
                if (i + S[k] > n + 1 || dp[i][mask] == -INF) continue;
                ll diff = a[i + S[k] - 1] - a[i];
                if ((mask >> k) & 1)
                {
                    dp[i + S[k] - 1][mask] = max(dp[i - 1][mask] + P - sq(diff) * C, dp[i + S[k] - 1][mask]);
                } else
                {
                    ll new_mask = mask | (1 << k);
                    dp[i + S[k] - 1][new_mask] = max(dp[i - 1][mask] + P - sq(diff) * C, dp[i + S[k] - 1][new_mask]);
                }
            }
        }
    }
    cout << dp[n][(1 << M) - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("WHOME.INP", "r", stdin);
    freopen("WHOME.OUT", "w", stdout);
    solve();
    return 0;
}
