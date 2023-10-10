#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;
const int mxN = (1 << 18) + 7;

int n, m, K;
ll combo[20][20], dp[mxN][20], dish[20];

void solve()
{
    cin >> n >> m >> K;
    for(int i=0; i<n; i++)
    {
        cin >> dish[i];
    }

    memset(combo, 0, sizeof(combo));
    for(int i=0; i<K; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        combo[u][v] = c;
    }

    for(int i=0; i<(1 << n); i++)
    {
        fill(dp[i], dp[i] + n, -INF);
    }

    for(int i=0; i<n; i++)
    {
        dp[1 << i][i] = dish[i];
    }

    for(int mask=0; mask<(1 << n); mask++)
    {
        for(int j=0; j<n; j++)
        {
            if (mask & (1 << j))
            {
                for(int k=0; k<n; k++)
                {
                    if (!(mask & (1 << k)))
                    {
                        ll new_mask = mask | (1 << k);
                        ll val = dp[mask][j] + dish[k] + combo[j][k];
                        dp[new_mask][k] = max(dp[new_mask][k], val);
                    }
                }
            }
        }
    }

    ll ret = 0;
    for(int mask=0; mask<(1 << n); mask++)
    {
        if (__builtin_popcount(mask) == m)
        {
            for(int j=0; j<n; j++)
            {
                ret = max(ret, dp[mask][j]);
            }
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
