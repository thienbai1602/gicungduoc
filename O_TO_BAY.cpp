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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 466;

int n, K;
ll h[mxN], pref[mxN], dp[mxN][mxN];

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> h[i];
    }

    set0(pref);
    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1] + h[i];
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=K; j++)
        {
            dp[i][j] = INF;
        }
    }

    ll mx = h[1];
    for(int i=1; i<=n; i++)
    {
        mx = max(mx, h[i]);
        dp[i][0] = mx * i - pref[i];
    }

    dp[0][0] = 0;
    for(int i=2; i<=n; i++)
    {
        for(int k=1; k<=K; k++)
        {
            ll mx = h[i];
            for(int j=i; j>0; j--)
            {
                mx = max(mx, h[j]);
                // khong chuyen
                dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + (i - j + 1) * mx - (pref[i] - pref[j - 1]));
            }
        }
    }

    ll ans = INF;
    for(int k=0; k<=K; k++)
    {
        ans = min(ans, dp[n][k]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
