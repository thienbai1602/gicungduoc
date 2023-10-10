#include    <bits/stdc++.h>
#define ll unsigned long long
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

ll dp[mxN][mxN], frac[mxN], n, m, a[mxN];

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    set0(dp); dp[0][0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int s=m; s>=0; s--)
        {
            for(int j=1; j<=i+1; j++)
            {
                if (s >= a[i] && dp[j - 1][s - a[i]])
                {
                    dp[j][s] = (dp[j][s] + dp[j - 1][s - a[i]]) % MOD;
                }
            }
        }
    }

    frac[0] = 1;
    for(ll i=1; i<=n; i++)
    {
        frac[i] = (frac[i - 1] * i) % MOD;
    }

    /*for(int j=1; j<=n; j++)
    {
        for(int s=m; s>=0; s--)
        {
            if (dp[j][s] > 0) cout << s << " " << j << " " << dp[j][s] << "\n";
        }
    }*/

    ll ans = 0;
    for(int j=1; j<=n; j++)
    {
        for(int s=m; s>0; s--)
        {
            if (dp[j][s] > 0)
            {
                ans = (ans + dp[j][s] * frac[j]) % MOD;
            }
        }
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
