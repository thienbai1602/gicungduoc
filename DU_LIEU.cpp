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
ll a[mxN];
ii seg[mxN * 4];

ii modify(ii x, ii y)
{
    vector<ll> s;
    s.pb(x.fi), s.pb(x.se);
    s.pb(y.fi), s.pb(y.se);
    sort(rall(s));
    return mp(s[0], s[1]);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = mp(a[l], -inf);
        return;
    }

    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    seg[id] = modify(seg[id << 1], seg[id << 1 | 1]);
}

ii get(int id, int l , int r, int u, int v)
{
    if (l > v || u > r) return mp(-inf, -inf);
    if (u <= l && r <= v)
    {
        return seg[id];
    }

    int m = (l + r) >> 1;
    return modify(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    build(1, 0, n-1);
    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        ii ans = get(1, 0, n - 1, l, r);
        cout << ans.fi + ans.se << "\n";
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
