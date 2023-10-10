#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e4 + 66;

int n;
ii p[mxN];
ll dp[mxN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> p[i].fi >> p[i].se;
    }

    dp[0] = 0;
    sort(p + 1, p + 1 + n);
    for(int i=1; i<=n; i++)
    {
        int jmax = 0;
        for(int j=1; j<i; j++)
        {
            if (dp[j] > dp[jmax] && p[j].se <= p[i].fi)
            {
                jmax = j;
            }
        }
        dp[i] = dp[jmax] + (p[i].se - p[i].fi);
    }

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
