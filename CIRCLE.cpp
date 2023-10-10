#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

ll l, r;
vector<int> num;
ll dp[20][11][11];

ll recur(vector<int> num, int N, int st, int ed, bool tight)
{
    if (N == 0)
    {
        return (st == ed && st != 0);
    }

    if (dp[N][st][ed] != -1 && !tight) return dp[N][st][ed];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, (st == 0 ? digit : st), digit, tight && (digit == limit));
    }
    if (!tight) dp[N][st][ed] = ans;
    return ans;
}

ll sol(ll X)
{
    num.clear();
    for(; X>0; X/=10)
    {
        num.pb(X % 10);
    }
    reverse(all(num));
    return recur(num, sz(num), 0, -1, 1);
}

void solve()
{
    cin >> l >> r;
    memset(dp, -1, sizeof(dp));
    cout << sol(r) - sol(l - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CIRCLE.INP", "r", stdin);
    freopen("CIRCLE.OUT", "w", stdout);
    solve();
    return 0;
}
