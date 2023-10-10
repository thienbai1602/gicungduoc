#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e5 + 66;
const ll MOD = 1e9 + 7;

ll D;
ll dp[mxN][105][2][2];
string num;

ll sol(string& num, int N, int S, bool leading, bool tight)
{
    if (N == 0)
    {
        return (!leading && S == 0);
    }

    if (dp[N][S][leading][tight] != -1) return dp[N][S][leading][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] - '0' : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += sol(num, N - 1, (S + digit) % D, leading && (digit == 0) , tight && (limit == digit));
        ans %= MOD;
    }
    return dp[N][S][leading][tight] = ans % MOD;
}

void solve()
{
    cin >> num >> D;
    memset(dp, -1, sizeof(dp));
    cout << sol(num, sz(num), 0, 1, 1) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
