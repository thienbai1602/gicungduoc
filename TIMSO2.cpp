#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

ll N, dp[20][125][2][2];

ll recur(vector<int> num, int N, int s, bool leading, bool tight)
{
    if (N == 0)
    {
        return (s & 1);
    }

    if (dp[N][s][leading][tight] != -1) return dp[N][s][leading][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, s + digit, leading && (digit == 0), tight && (digit == limit));
    }
    return dp[N][s][leading][tight] = ans;
}

ll sol(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return recur(num, sz(num), 0, 1, 1);
}

ll bs(ll l, ll r)
{
    ll ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (sol(m) >= N)
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> N;
    cout << bs(1, 1e13);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
