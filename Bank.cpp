#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 20;

int n, m;
ii dp[1 << mxN];
ll people[mxN], salary[mxN];

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> people[i];
    }

    for(int i=0; i<m; i++)
    {
        cin >> salary[i];
    }

    fill(dp, dp + (1 << n), mp(-1, 0));
    dp[0] = mp(0, 0);
    for(int mask=0; mask<(1 << m); mask++)
    {
        for(int k=0; k<m; k++)
        {
            if ((mask >> k) & 1 || dp[mask].fi == -1) continue;
            int new_mask = mask | (1 << k);
            ll new_atm = dp[mask].se + salary[k];
            if (new_atm < people[dp[mask].fi]) dp[new_mask] = max(dp[new_mask], mp(dp[mask].fi, new_atm));
             else if (new_atm == people[dp[mask].fi]) dp[new_mask] = max(dp[new_mask], mp(dp[mask].fi + 1, 1LL * 0));
        }
    }

    bool res = false;
    for(int mask=0; mask<(1 << m); mask++)
    {
        if (dp[mask].fi == n) res = true;
    }
    cout << (res ? "YES" : "NO");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("bank.in", "r", stdin);
    freopen("bank.out", "w", stdout);
    solve();
    return 0;
}
