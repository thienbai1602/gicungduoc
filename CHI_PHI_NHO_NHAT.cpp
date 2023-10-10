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
const int mxN = 166;

int n;
ll a[mxN], pref[mxN], dp[mxN][mxN];

ll sol(int l, int r)
{
    if (l == r) return dp[l][r] = 0;
    if (dp[l][r] != -1) return dp[l][r];
    ll ans = inf;
    for(int k=l; k<r; k++)
    {
        ans = min(ans, sol(l, k) + sol(k + 1, r) + pref[r] - (l == 0 ? 0 : pref[l - 1]));
    }
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    pref[0] = a[0];
    for(int i=1; i<n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << sol(0, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
