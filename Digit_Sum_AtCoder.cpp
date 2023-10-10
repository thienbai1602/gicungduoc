#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const ll MOD = 1e9 + 7;
const int mxN = 1e4 + 66;

int D;
string K;
ll dp[mxN][106][2][2];

ll sol(string K, int N, int S, bool leading, bool tight)
{
    if (N == 0)
    {
        return (!leading && S == 0);
    }

    if (dp[N][S][leading][tight] != -1) return dp[N][S][leading][tight];

    ll ans = 0;
    int limit = tight ? K[sz(K) - N] - '0' : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += sol(K, N - 1, (S + digit) % D, leading && (digit == 0), tight && (digit == limit));
        ans %= MOD;
    }
    return dp[N][S][leading][tight] = ans % MOD;
}

void solve()
{
    cin >> K >> D;
    memset(dp, -1, sizeof(dp));
    cout << sol(K, sz(K), 0, 1, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
