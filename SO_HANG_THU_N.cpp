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

ll N, last;

ll tcs(ll X)
{
    ll ans = 0;
    while(X > 0)
    {
        ans += X % 10;
        X /= 10;
    }
    return ans;
}

ll S(int x)
{
    ll ret = 10, a = 10;
    for(int i=2; i<=x; i++)
    {
        a = (tcs(a) + i) % 100;
        ret += a;
        last = a;
    }
    return ret;
}

void solve()
{
    cin >> N;
    ll ans = N / 100 * S(100);
    ll K = N - N / 100 * 100;
    if (K > 0) ans += S(K);
    cout << last << "\n" << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
