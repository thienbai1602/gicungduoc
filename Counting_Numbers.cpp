#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll a, b, dp[20][10][170];

ll recur(vector<int> num, int N, int pref, int S, bool tight)
{
    if (N == 0)
    {
        return 1;
    }

    if (dp[N][pref][S] != -1 && !tight) return dp[N][pref][S];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        if (pref == digit) continue;
        ans += recur(num, N - 1, (pref == -1 && digit == 0 ? pref : digit), S + digit, tight && (digit == limit));
    }

    if (!tight) dp[N][pref][S] = ans;
    return ans;
}

ll sol(ll X)
{
    if (X <= 0) return (X == 0);
    vector<int> num;
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(all(num));
    return recur(num, sz(num), -1, 0, 1);
}

void solve()
{
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << sol(b) - sol(a - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

