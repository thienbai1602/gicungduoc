#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, p, K;
ll id[mxN], a[mxN], s[mxN][7], dp[mxN][1 << 7];

bool cmp(int x, int y)
{
    return a[x] > a[y];
}

void solve()
{
    cin >> n >> p >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        id[i] = i;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<p; j++)
        {
            cin >> s[i][j];
        }
    }

    sort(id, id + n, cmp);
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int mask=0; mask<(1 << p); mask++)
        {
            int ct = (i - __builtin_popcount(mask));
            if (ct < 0) continue;
            if (ct < K)
            {
                if (dp[i][mask] != -1)
                {
                    dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask] + a[id[i]]);
                }
            } else
            {
                if (dp[i][mask] != -1)
                {
                    dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);
                }
            }

            for(int k=0; k<p; k++)
            {
                if ((mask >> k) & 1 || dp[i][mask] == -1) continue;
                ll new_mask = mask | (1 << k);
                dp[i + 1][new_mask] = max(dp[i + 1][new_mask], dp[i][mask] + s[id[i]][k]);
            }
        }
    }
    cout << dp[n][(1 << p) - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
