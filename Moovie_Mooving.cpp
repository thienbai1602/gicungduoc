#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const ll INF = 1e18;
const int mxN = 20;
const int N = 1066;

ll n, L, D[mxN], sz[mxN], C[mxN][N];
ii dp[1 << mxN];

void solve()
{
    cin >> n >> L;
    for(int i=0; i<n; i++)
    {
        cin >> D[i] >> sz[i];
        for(int j=0; j<sz[i]; j++)
        {
            cin >> C[i][j];
        }
        sort(C[i], C[i] + sz[i]);
    }

    fill(dp, dp + (1 << n), mp(-1, 0));

    dp[0] = mp(0, 0);
    for(int mask=0; mask<(1 << n); mask++)
    {
        for(int k=0; k<n; k++)
        {
            if ((mask >> k) & 1 || dp[mask].fi == -1) continue;
            int new_mask = mask | (1 << k);
            int pos = upper_bound(C[k], C[k] + sz[k], dp[mask].se) - C[k] - 1;
            if (dp[new_mask].fi == -1)
            {
                dp[new_mask] = mp(dp[mask].fi + 1, C[k][pos] + D[k]);
            } else
            {
                if (dp[new_mask].fi == dp[mask].fi + 1)
                {
                    if (dp[new_mask].se < C[k][pos] + D[k])
                    {
                        dp[new_mask].se = C[k][pos] + D[k];
                    }
                } else if (dp[new_mask].fi > dp[mask].fi + 1)
                {
                    dp[new_mask] = mp(dp[mask].fi + 1, C[k][pos] + D[k]);
                }
            }
        }
    }

    ll ans = INF;
    for(int mask=0; mask<(1 << n); mask++)
    {
        if (dp[mask].fi != -1 && dp[mask].se >= L)
        {
            ans = min(ans, dp[mask].fi);
        }
    }
    cout << (ans == INF ? -1 : ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    solve();
    return 0;
}
