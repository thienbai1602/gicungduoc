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
const int mxN = 1e6 + 66;

struct actor
{
    int f, s, cost;

    bool operator < (const actor& c)
    {
        return (f < c.f || (f == c.f && s < c.s));
    }
};

int n, m;

void solve()
{
    cin >> n >> m;
    vector<actor> c(m);
    for(int i=0; i<m; i++)
    {
        cin >> c[i].f >> c[i].s >> c[i].cost;
    }

    sort(all(c));

    vector<ll> dp(m + 1, inf);
    ll ans = inf;
    for(int i=0; i<m; i++)
    {
        if (c[i].f == 0) dp[i] = c[i].cost;
         else
         {
             for(int j=0; j<i; j++)
             {
                 if (c[j].s >= c[i].f)
                 {
                     dp[i] = min(dp[i], dp[j] + c[i].cost);
                 }
             }
         }
         if (c[i].s == n) ans = min(ans, dp[i]);
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
