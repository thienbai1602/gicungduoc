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

string S;
int tc, n, L = 0, R = mxN;
ll hsh[mxN], rhsh[mxN], pw[mxN];

void init()
{
    pw[0] = 1;
    for(int i=1; i<=(int)1e6; i++)
    {
        pw[i] = (pw[i - 1] * base) % MOD;
    }
}

ll get(int i, int j)
{
    return (hsh[j] - hsh[i - 1] * pw[j - i + 1] + MOD * MOD) % MOD;
}

ll getr(int i, int j)
{
    return (rhsh[j] - rhsh[i - 1] * pw[i - j + 1] + MOD * MOD) % MOD;
}

bool check(int X)
{
    for(int i=1; i<=X; i++)
    {
        ll a = get(1, i), b = get(n, n - (X - i));
    }
}

void bs(int l, int r)
{
    int ret = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            ret = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }

    if (ret > ans)
    {
        ans = ret;
        L = nxtL, R = nxtR;
    }
}

void solve()
{
    cin >> S;
    n = sz(S);
    hsh[0] = 0;
    for(int i=1; i<=n; i++)
    {
        hsh[i] = (hsh[i - 1] * base + S[i - 1]) % MOD;
    }

    rhsh[n + 1] = 0;
    for(int i=n; i>0; i--)
    {
        rhsh[i] = (rhsh[i + 1] * base + S[i - 1]) % MOD;
    }

    int ans = -1;
    for(int i=1; i<=n; i++)
    {
        if (get(1, i) == getr(i, 1))
        {
            ans = i;
            L = i;
        }
    }

    for(int i=n; i>0; i--)
    {
        if (get(i, n) == getr(n, i))
        {
            ans = (n - i + 1);
            R = i;
        }
    }
    bs(1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    init(); cin >> tc;
    while(tc--) solve();
    return 0;
}

