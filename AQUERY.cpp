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

int n, Q;
ii seg[mxN * 4];

void down(int id, int l, int r)
{
    ll x = seg[id].fi;
    if (x != -1)
    {
        int m = (l + r) >> 1;
        seg[id << 1].fi = x, seg[id << 1].se = (m - l + 1) * x;
        seg[(id << 1) | 1].fi = x, seg[(id << 1) | 1].se = (r - m) * x;
        seg[id].fi = -1;
    }
}

void upd(int id, int l, int r, int u, int v, ll x)
{
    if (l > v || u > r) return;
    if (u <= l && r <= v)
    {
        seg[id].fi = x;
        seg[id].se = (r - l + 1) * x;
        return;
    }

    down(id, l, r);
    int m = (l + r) >> 1;
    upd(id << 1, l, m, u, v, x);
    upd((id << 1) | 1, m + 1, r, u, v, x);
    seg[id].se = seg[id << 1].se + seg[(id << 1) | 1].se;
}

ll query(int id, int l, int r, int u, int v)
{
    if (l > v || u > r) return 0;
    if (u <= l && r <= v)
    {
        return seg[id].se;
    }

    down(id, l, r);
    int m = (l + r) >> 1;
    return query(id << 1, l, m, u, v) + query((id << 1) | 1, m + 1, r, u, v);
}

void solve()
{
    cin >> n >> Q;
    fill(seg, seg + 4 * n, mp(-1, 0));
    for(int i=0; i<Q; i++)
    {
        ll r, p;
        cin >> r >> p;
        ll lo = 1, hi = r - 1, l = r;
        while(lo <= hi)
        {
            ll m = (lo + hi) >> 1;
            ll aMid = query(1, 1, n, m, m);
            ll nxt = p - ((r - m + 1) * aMid - query(1, 1, n, m, r));
            if (nxt >= 0)
            {
                l = m;
                hi = m - 1;
            } else
            {
                lo = m + 1;
            }
        }

        ll aL = query(1, 1, n, l, l);
        ll tp = (r - l + 1) * aL - query(1, 1, n, l, r);
        ll aVal = aL + (p - tp) / (r - l + 1);
        int m = l + (p - tp) % (r - l + 1) - 1;
        if (m >= l) upd(1, 1, n, l, m, aVal + 1);
        upd(1, 1, n, m + 1, r, aVal);
    }

    for(int i=1; i<=n; i++)
    {
        cout << query(1, 1, n, i, i) << " ";
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
