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

int tc, n, lg[mxN];
ll g[LOG][mxN];

ll get(int l, int r)
{
    int k = lg[r - l + 1];
    return __gcd(g[k][l], g[k][r - (1 << k) + 1]);
}

bool check(int K)
{
    for(int i=0; i<n-K+1; i++)
    {
        int j = i + K - 1;
        ll nxt = get(i, j - 1);
        if (nxt == 0 || nxt > 1) return true;
    }
    return false;
}

int bs(int l, int r)
{
    int ans = 1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<ll> diff(n);
    for(int i=0; i<n-1; i++)
    {
        diff[i] = abs(a[i] - a[i + 1]);
        g[0][i] = diff[i];
    }

    for(int k=1; k<LOG; k++)
    {
        for(int i=0; i<n-(1 << k); i++)
        {
            g[k][i] = __gcd(g[k - 1][i], g[k - 1][i + (1 << (k - 1))]);
        }
    }
    cout << bs(2, n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    lg[1] = 0;
    for(int i=2; i<=(int)2e5; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    while(tc--) solve();
    return 0;
}

