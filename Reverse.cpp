#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int n;
string S;
bool cnt[20];
ll dp[1 << 20];

void solve()
{
    cin >> S;
    n = sz(S);
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++)
    {
        memset(cnt, false, sizeof(cnt));
        int mask = 0;
        for(int j=i; j<n; j++)
        {
            if (!cnt[S[j] - 'a'])
            {
                cnt[S[j] - 'a'] = 1;
            } else
            {
                break;
            }
            mask |= (1 << (S[j] - 'a'));
            dp[mask] = __builtin_popcount(mask);
        }
    }

    for(int mask=0; mask<(1 << 20); mask++)
    {
        for(int k=0; k<20; k++)
        {
            if ((mask >> k) & 1) continue;
            int new_mask = mask | (1 << k);
            dp[new_mask] = max(dp[new_mask], dp[mask]);
        }
    }

    ll ret = 0;
    for(int mask=0; mask<(1 << 20); mask++)
    {
        if (__builtin_popcount(mask) == dp[mask])
        {
            int re_mask = ((1 << 20) - 1) ^ mask;
            ret = max(ret, dp[mask] + dp[re_mask]);
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
