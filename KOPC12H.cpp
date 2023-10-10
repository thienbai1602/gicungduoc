#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

int tc;
ll a, b, dp[10][80][90][2][2];

ll recur(vector<int> num, int N, int S_even, int S_odd, bool leading, bool tight)
{
    if (N == 0)
    {
        return (!leading && S_even > S_odd);
    }

    if (dp[N][S_even][S_odd][leading][tight] != -1) return dp[N][S_even][S_odd][leading][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        int newS_even = S_even, newS_odd = S_odd;
        if (digit & 1) newS_odd += digit;
         else newS_even += digit;
        ans += recur(num, N - 1, newS_even, newS_odd, leading && (digit == 0), tight && (digit == limit));
    }
    return dp[N][S_even][S_odd][leading][tight] = ans;
}

ll sol(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(all(num));
    memset(dp, -1, sizeof(dp));
    return recur(num, sz(num), 0, 0, 1, 1);
}

void solve()
{
    cin >> a >> b;
    cout << sol(b) - sol(a - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
