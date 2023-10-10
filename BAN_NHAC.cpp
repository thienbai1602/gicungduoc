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
const int mxN = 5e3 + 66;

int n;
vector<ll> a, diff;

void solve()
{
    cin >> n;
    a.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    --n;
    diff.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        diff[i] = a[i] - a[i + 1];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = -1;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if (diff[i - 1] == diff[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = 0;

            if (i + dp[i][j] <= j) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
