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
const int mxN = 1e6 + 66;

ll n, K, a[mxN], dp[mxN];

ll sub1()
{
    ll ans = 0;
    for(ll mask=0; mask<(1LL << n); mask++)
    {
        bool flat = true;
        ll S = 0, cnt = 0;
        for(int k=0; k<n; k++)
        {
            if ((mask >> k) & 1)
            {
                S += a[k];
                if (++cnt > K)
                {
                    flat = false;
                    break;
                }
            } else cnt = 0;
        }
        if (flat) ans = max(ans, S);
    }
    return ans;
}

ll sub2()
{
    set0(dp);
    dp[1] = a[0], dp[2] = a[0] + a[1];
    for(ll i=3; i<=n; i++)
    {
        dp[i] = max(dp[i - 1], max(a[i - 1] + dp[i - 2], a[i - 1] + a[i - 2] + dp[i - 3]));
    }
    return dp[n];
}

ll sub3()
{
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += a[i];
    }
    return ans;
}

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    if (n <= 20) cout << sub1();
     else if (K == 2) cout << sub2();
      else cout << sub3();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SMGIFT.INP", "r", stdin);
    freopen("SMGIFT.OUT", "w", stdout);
    solve();
    return 0;
}
