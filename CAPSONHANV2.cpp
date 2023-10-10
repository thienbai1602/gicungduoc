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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll x, N, M;

ll power(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b)
    {
        if (b & 1) ans = ((ans % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return ans;
}

ll pw(ll x, ll N, ll M)
{
    if (N == 0) return 1;
    if (N == 1) return (1 + x) % M;
    if (N & 1) return ((x % M) * (pw(x, N - 1, M) % M) + 1) % M;
     else return ((((pw(x, N / 2, M) - 1 + M) % M) * (1 + power(x, N / 2, M)) % M) + 1) % M;
}

void solve()
{
    cin >> x >> N >> M;
    cout << pw(x, N, M);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
