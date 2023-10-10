#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define pb push_back
using namespace std;

const ll INF = 1e17;
const int mxN = 106;

int n, a[mxN], mx = 0;
ll msk[66], dp[mxN][1 << 17], tv[mxN][1 << 17];
vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    fill(msk, msk + 61, 0);
    for(int i=0; i<=n; i++)
    {
        fill(tv[i], tv[i] + (1 << 17), 0);
        fill(dp[i], dp[i] + (1 << 17), INF);
    }

    for(int i=1; i<2*mx; i++)
    {
        for(int j=0; j<sz(p); j++)
        {
            if (i % p[j] == 0)
            {
                msk[i] |= (1 << j);
            }
        }
    }

    dp[0][0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int mask=0; mask<(1 << 17); mask++)
        {
            for(int k=1; k<2*mx; k++)
            {
                if ((mask & msk[k]) || dp[i][mask] == INF) continue;
                int new_mask = mask | msk[k];
                if (dp[i + 1][new_mask] > dp[i][mask] + abs(a[i] - k))
                {
                    dp[i + 1][new_mask] = dp[i][mask] + abs(a[i] - k);
                    tv[i + 1][new_mask] = k;
                }
            }
        }
    }

    ll ret = INF, cur_mask = -1;;
    for(int mask=0; mask<(1 << 17); mask++)
    {
        if (ret > dp[n][mask])
        {
            ret = dp[n][mask];
            cur_mask = mask;
        }
    }

    int cur = n;
    vector<int> ans;
    while(cur > 0)
    {
        ll nxt = tv[cur][cur_mask];
        ans.pb(nxt);
        cur_mask ^= msk[nxt];
        cur--;
    }
    //cout << ret << "\n";
    for(int i=sz(ans)-1; i>=0; i--)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
