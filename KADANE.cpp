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
const int mxN = 3e5 + 66;

int n;
ll K, a[mxN], dp[3][mxN], mx[3][mxN];

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    set0(dp);
    ll S = 0, ans = 0;
    for(int i=1; i<=n; i++)
    {
        S += a[i];
        dp[0][i] = max(dp[0][i - 1] + a[i], 0LL);
        dp[1][i] = max(S * K + mx[1][i - 1], 0LL);
        dp[2][i] = max(S + mx[2][i - 1], 0LL);
        ans = max({ans, dp[0][i], dp[1][i], dp[2][i]});
        mx[1][i] = max(mx[1][i - 1], -S * K + dp[0][i]);
        mx[2][i] = max(mx[2][i - 1], -S + dp[1][i]);
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
