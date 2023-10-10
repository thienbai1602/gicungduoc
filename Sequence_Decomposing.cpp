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
const int mxN = 1e5 + 66;

int n;
ll a[mxN], b[mxN], dp[mxN];

int bs(int l, int r, ll X)
{
    int ret = 0;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (X <= a[b[m]])
        {
            ret = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ret;
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    int ans = 1;
    b[1] = 1, dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        int pos = bs(1, dp[ans], a[i]);
        b[pos + 1] = i;
        dp[i] = pos + 1;
        if (dp[ans] < dp[i])
        {
            ans = i;
        }
    }
    cout << dp[ans];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
