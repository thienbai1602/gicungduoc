#include    <bits/stdc++.h>
#define ll long long
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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int tc, K;

bool gre(ii x, ii y)
{
    ll g = (x.se * y.se) / __gcd(x.se, y.se);
    ll u = g / x.se, v = g / y.se;
    return (u * x.fi <= v * y.fi);
}

void solve()
{
    vector<ll> a(K);
    for(int i=0; i<K; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    if (gre(mp(a[0], a[K-2]), mp(a[1], a[K-1]))) cout << a[0] << " " << a[K - 2] << " " << a[1] << " " << a[K - 1] << "\n";
     else cout <<  a[0] << " " << a[K - 1] << " " << a[1] << " " << a[K - 2] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc >> K;
    while(tc--) solve();
    return 0;
}
