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
const int mxN = 1e3 + 66;

int tc = 2;
ii dp[mxN][mxN];
ll a, b, x, y, n;

ii newSt(ii f, ll a, ll value)
{
    f.se += a;
    if (f.se >= value)
    {
        ++f.fi;
        f.se = 0;
    }
    return f;
}

bool check(ll X)
{
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            dp[i][j] = mp(0, 0);
        }
    }

    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            if (dp[i][j].fi == n) return true;
            if (i < x)
            {
                dp[i + 1][j] = max(dp[i + 1][j], newSt(dp[i][j], a, X));
            }

            if (j < y)
            {
                dp[i][j + 1] = max(dp[i][j + 1], newSt(dp[i][j], b, X));
            }
        }
    }
    return false;
}

ll bs(ll l, ll r)
{
    ll ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> x >> a >> y >> b >> n;
    ll l = 1, r = (a * x + b * y) / n;
    cout << bs(l, r) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    while(tc--) solve();
    return 0;
}
