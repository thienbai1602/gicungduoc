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
const int mxN = 3e5 + 66;

int n, k, X;
vector<ii> listID;
vector<ll> a, pref, it, seg;

void upd(int id)
{
    for(; id<=n; id+=(id & -id))
    {
        it[id] += 1;
    }
}

ll get(int id)
{
    ll ans = 0;
    for(; id>0; id-=(id & -id))
    {
        ans += it[id];
    }
    return ans;
}

void updS(int id, ll val)
{
    for(; id<=n; id+=(id & -id))
    {
        seg[id] += val;
    }
}

ll getS(int id)
{
    ll ans = 0;
    for(; id>0; id-=(id & -id))
    {
        ans += seg[id];
    }
    return ans;
}

ll Cnt(ll val)
{
    it.clear();
    it.assign(n + 1, 0);
    ll l = 0, ct = 0;
    for(int r=0; r<n; r++)
    {
        if (listID[r].fi >= val && listID[r].se >= X) ++ct;
        while(l < n && listID[r].fi - listID[l].fi >= val) upd(listID[l++].se);
        ct += get(listID[r].se - X);
    }
    return ct;
}

void solve()
{
    cin >> n >> k >> X;
    a.assign(n, 0);
    pref.assign(n, 0);
    ll mi = inf, mx = -inf;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        pref[i] = a[i] + (i == 0 ? 0 : pref[i - 1]);
        listID.pb(mp(pref[i], i + 1));
        mi = min(mi, pref[i]);
        mx = max(mx, pref[i]);
    }

    sort(all(listID));
    ll l = mi, r = mx - mi, ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (Cnt(m) >= k)
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }

    ll nxt = Cnt(ans), ret = 0;
    it.clear();
    seg.assign(n + 1, 0);
    it.assign(n + 1, 0);
    for(int r=0, l=0; r<n; r++)
    {
        if (listID[r].fi >= ans && listID[r].se >= X) ret += listID[r].fi;
        while(l < n && listID[r].fi - listID[l].fi >= ans)
        {
            upd(listID[l].se);
            updS(listID[l].se, listID[l].fi);
            ++l;
        }
        ret += listID[r].fi * get(listID[r].se - X) - getS(listID[r].se - X);
    }
    cout << ret - (nxt - k) * ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
