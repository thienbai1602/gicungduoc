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

int N;

void solve()
{
    cin >> N;
    vector<vector<ll>> a(N + 1, vector<ll>(N + 1, 0));
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -inf));
    dp[1][1] = a[1][1];
    for(int i=2; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
            if (j > 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
        }
    }

    ll ans = -inf;
    for(int j=1; j<=N; j++)
    {
        ans = max(ans, dp[N][j]);
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
