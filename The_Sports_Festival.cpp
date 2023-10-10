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
const int mxN = 2e3 + 66;

int n;
ll s[mxN], dp[mxN][mxN];

ll opt(int l, int r)
{
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;
    return dp[l][r] = s[r] - s[l] + min(opt(l + 1, r), opt(l, r - 1));
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
    }

    sort(s, s + n);
    memset(dp, -1, sizeof(dp));
    cout << opt(0, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
