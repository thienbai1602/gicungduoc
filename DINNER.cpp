#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;
const ll MOD = 1e9 + 7;

int n;
ll dp[mxN];

void solve()
{
    cin >> n;
    dp[1] = dp[2] = 1;
    for(int i=3; i<=n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * (i - 2)) % MOD;
    }
    cout << dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("DINNER.INP", "r", stdin);
    freopen("DINNER.OUT", "w", stdout);
    solve();
    return 0;
}
