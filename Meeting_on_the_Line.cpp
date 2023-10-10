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
const int mxN = 1e5 + 66;

int tc, n;
vector<ii> coord;

bool check(ll T)
{
    ll mxl = -1, mxr = INF;
    for(int i=0; i<n; i++)
    {
        if (coord[i].se > T) return false;
        mxl = max(mxl, coord[i].fi - (T - coord[i].se));
        mxr = min(mxr, coord[i].fi + (T - coord[i].se));
    }
    return mxl <= mxr;
}

ll bs(ll l, ll r)
{
    ll T = -1;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
        {
            T = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }

    ll res = -1;
    for(int i=0; i<n; i++)
    {
        res = max(res, coord[i].fi - (T - coord[i].se));
    }
    return res;
}

void solve()
{
    cin >> n;
    coord = vector<ii>(n);
    for(int i=0; i<n; i++)
    {
        cin >> coord[i].fi;
        coord[i].fi *= 2;
    }

    for(int i=0; i<n; i++)
    {
        cin >> coord[i].se;
        coord[i].se *= 2;
    }
    ll ans = bs(0, INF);
    cout << ans / 2 << (ans & 1 ? ".5\n" : "\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
