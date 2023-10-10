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

int n, Q;

void solve()
{
    cin >> n >> Q;
    vector<ll> goods(n);
    for(int i=0; i<n; i++)
    {
        cin >> goods[i];
    }

    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        goods[i] = x - goods[i];
    }

    sort(rall(goods));
    vector<ii> seg(Q);
    for(int i=0; i<Q; i++)
    {
        ll k;
        cin >> k;
        seg[i] = mp(k, i);
    }

    vector<ll> pref(n, 0);
    for(int i=0; i<n; i++)
    {
        pref[i] = (i == 0 ? goods[0] : goods[i] + pref[i - 1]);
    }

    sort(all(seg));
    vector<ll> ans(Q);
    for(int i=0, l=0; i<Q; i++)
    {
        ll cur = seg[i].fi;
        while(l < n && cur + pref[l] >= 0) ++l;
        ans[seg[i].se] = min(l, n);
    }

    for(int i=0; i<Q; i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
