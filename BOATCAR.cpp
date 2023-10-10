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

int n, Q;
ll u[mxN], k[mxN], dp[mxN];

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> k[i] >> u[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=Q; j>=0; j--)
        {
            if (j >= k[i] && dp[j - k[i]] != -1)
            {
                dp[j] = max(dp[j], dp[j - k[i]] + u[i]);
            }
        }
    }

    ll x = 0;
    for(int j=0; j<=Q; j++)
    {
        x = max(x, dp[j]);
    }
    cout << x << "\n";

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int j=0; j<=Q; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if (j >= k[i] && dp[j - k[i]] != -1)
            {
                dp[j] = max(dp[j], dp[j - k[i]] + u[i]);
            }
        }
    }

    ll y = 0;
    for(int j=0; j<=Q; j++)
    {
        y = max(y, dp[j]);
    }
    cout << y << "\n" << 5 * (y - x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("BOATCAR.INP", "r", stdin);
    freopen("BOATCAR.OUT", "w", stdout);
    solve();
    return 0;
}
