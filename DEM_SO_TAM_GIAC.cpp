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
const ll MOD = 998244353;
const int mxN = 3e2 + 66;

ll S = 0;
int n, a[mxN];

void solve()
{
    cin >> n;
    ll  u = 1, v = 1;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        S += a[i];
        (u *= 3) %= MOD;
        (v *= 2) %= MOD;
    }

    vector<ll> g(S / 2 + 1, 0), f(S / 2 + 1, 0);
    f[0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int x=S/2; x>=0; x--)
        {
            if (x - a[i] >= 0)
            {
                if (i > 1) (g[x] += 2 * (g[x - a[i]] + (x - a[i] > 0 ? f[x - a[i]] : 0))) %= MOD;
                (f[x] += f[x - a[i]]) %= MOD;
            }
        }
    }

    /*for(int x=0; x<=S/2; x++)
    {
        cout << x << " " << g[x] << "\n";
    }*/

    ll ans = (u - 3 * v + 3 + MOD) % MOD;
    for(int x=S/2; x>=2; x--)
    {
        if (2 * x <= S) ans = (ans - 3 * g[x] + MOD) % MOD;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
