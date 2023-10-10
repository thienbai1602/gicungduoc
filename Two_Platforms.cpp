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
const int mxN = 2e5 + 66;

ll K;
int tc, n;

void solve()
{
    cin >> n >> K;
    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> y[i];
    }

    sort(all(x));
    ll ans = 0;
    vector<ll> dp(n + 1, 0);
    for(int i=n-1; i>=0; i--)
    {
        int idx = upper_bound(all(x), x[i] + K) - x.begin();
        ans = max(ans, (idx - i) + dp[idx]);
        dp[i] = max((ll)idx - i, dp[i + 1]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
