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

int N, K;
vector<ii> gem;

bool ck(ll X)
{
    vector<ll> val;
    for(int i=0; i<N; i++)
    {
        val.pb(gem[i].se - X * gem[i].fi);
    }

    sort(rall(val));
    ll S = 0;
    for(int i=0; i<K; i++)
    {
        S += val[i];
        if (S < 0) return false;
    }
    return S >= 0;
}

void solve()
{
    cin >> N >> K;
    for(int i=0; i<N; i++)
    {
        ll x, y;
        cin >> x >> y;
        gem.pb(mp(x, y));
    }

    ll l = 1, r = 1e12, ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (ck(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

