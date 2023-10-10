#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const ll MOD = 1e9 + 7;

int tc;
string num;
ll dp[100005][4][2];

ll sol(string& num, int N, ll sq, bool tight)
{
    if (N == 0)
    {
        return (sq % 3 == 0);
    }

    if (dp[N][sq % 3][tight] != -1) return dp[N][sq % 3][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] - '0' : 9;
    for(ll digit=0; digit<=limit; digit++)
    {
        ans = (ans + sol(num, N - 1, sq + digit * digit, tight && (limit == digit))) % MOD;
    }
    return dp[N][sq][tight] = ans % MOD;
}

bool check(string num)
{
    ll ret = 0;
    for(int i=0; i<sz(num); i++)
    {
        int nxt = num[i] - '0';
        ret = (ret + nxt * nxt) % 3;
    }
    return (reat % 3 == 0);
}

void solve()
{
    cin >> num;
    memset(dp, -1, sizeof(dp));
    cout << sol(num, sz(num), 0, 1) - check(num) << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
