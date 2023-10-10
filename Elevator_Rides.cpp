#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 20;

ll n, W, x[mxN];
ii dp[1 << mxN];

inline ll wei(ll a, ll b, ll MOD)
{
    if (a + b <= MOD) return a + b;
     else return b;
}

void solve()
{
    cin >> n >> W;
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }

    fill(dp, dp + (1 << n), mp(-1, 0));
    dp[0] = mp(0, 0);
    for(int mask=0; mask<(1 << n); mask++)
    {
        for(int k=0; k<n; k++)
        {
            if ((mask >> k) & 1 || dp[mask].fi == -1) continue;
            int new_mask = mask | (1 << k);
            if (dp[new_mask].fi == -1)
            {
                dp[new_mask] = mp(dp[mask].fi + ((dp[mask].se + x[k]) > W), wei(dp[mask].se, x[k], W));
            } else if (dp[new_mask].fi == dp[mask].fi + ((dp[mask].se + x[k]) > W))
            {
                dp[new_mask].se = min(dp[new_mask].se, wei(dp[mask].se, x[k], W));
            } else if (dp[new_mask].fi > dp[mask].fi + ((dp[mask].se, x[k]) > W))
            {
                dp[new_mask] = mp(dp[mask].fi + ((dp[mask].se + x[k]) > W), wei(dp[mask].se, x[k], W));
            }
        }
    }
    cout << dp[(1 << n) - 1].fi + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
