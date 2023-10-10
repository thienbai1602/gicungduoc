#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 20;

int n;
string S;
ll dp[1 << mxN], cnt[mxN];

void solve()
{
    cin >> S;
    n = sz(S);
    for(int i=0; i<n; i++)
    {
        int mask = 0;
        fill(cnt, cnt + 20, 0);
        for(int j=i; j<n; j++)
        {
            int nxt = S[j] - 'a';
            if (!cnt[nxt]) cnt[nxt]++;
             else break;
            mask |= (1 << nxt);
            dp[mask] = __builtin_popcount(mask);
        }
    }

    for(int mask=0; mask<(1 << 20); mask++)
    {
        for(int k=0; k<20; k++)
        {
            if ((mask >> k) & 1)
            {
                dp[mask] = max(dp[mask], dp[mask ^ (1 << k)]);
            }
        }
    }

    ll ans = 0;
    for(int mask=0; mask<(1 << 20); mask++)
    {
        if (dp[mask] == __builtin_popcount(mask))
        {
            int re_mask = ((1 << 20) - 1) ^ mask;
            ans = max(ans, dp[mask] + dp[re_mask]);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
