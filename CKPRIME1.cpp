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

ll N;
vector<ll> v = {2, 3, 5, 7, 11, 13, 17, 19, 23};

ll mul(ll a, ll b, ll mod)
{
    ll ans = 0;
    while(b)
    {
        if (b & 1) ans = ((ans % mod) + (a % mod)) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll pw(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b)
    {
        if (b & 1) ans = mul(ans, a, N) % mod;
        a = mul(a, a, N) % mod;
        b >>= 1;
    }
    return ans;
}

ll check_composite(ll a, ll d, ll N, ll s)
{
    ll x = pw(a, d, N);
    if (x == 1 || x == N - 1) return false;
    for(int r=0; r<s; r++)
    {
        x = mul(x, x, N);
        if (x == N - 1) return false;
    }
    return true;
}

bool miller_rabin(ll N)
{
    if (N <= 4) return (N == 2 || N == 3);
    ll d = N - 1, s = 0;
    while(!(d & 1))
    {
        d >>= 1;
        ++s;
    }

    for(ll &a : v)
    {
        if (a == N) return true;
        if (check_composite(a, d, N, s)) return false;
    }
    return true;
}

void solve()
{
    cin >> N;
    cout << (miller_rabin(N) ? "YES" : "NO");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
