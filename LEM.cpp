#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 20;
const ll INF = 1e18;

int n;
ll cost[mxN][mxN], dp[1 << 20][mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> cost[i][j];
        }
    }

    for(int i=0; i<(1 << n); i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = INF;
        }
    }

    for(int i=0; i<n; i++)
    {
        dp[1 << i][i] = 0;
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
                        ll val = dp[mask][j] + cost[j][k];
                        dp[new_mask][k] = min(dp[new_mask][k], val);
                    }
                }
            }
        }
    }

    ll ret = INF;
    for(int k=0; k<n; k++)
    {
        ret = min(ret, dp[(1 << n) - 1][k]);
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
