#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll K, a[mxN];
ii tree[mxN * 4];

ii combine(ii x, ii y)
{
    if (a[x.fi] < a[y.fi]) return mp(y.fi, x.se + y.se);
     else return mp(x.fi, x.se + y.se);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = mp(l, 1);
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

ll find_pos(int id, int l, int r, ll K)
{
    if (l == r) return r;
    int m = (l + r) >> 1;
    if (tree[id * 2].se >= K) return find_pos(id * 2, l, m, K);
     else return find_pos(id * 2 + 1, m + 1, r, K - tree[id * 2].se);
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l || l > r || u > v) return 0;
    if (u <= l && r <= v)
    {
        return tree[id].fi;
    }

    int m = (l + r) >> 1;
    int x = get(id * 2, l, m, u, v);
    int y = get(id * 2 + 1, m + 1, r, u, v);
    return (a[x] < a[y] ? y : x);
}

ll get_sz(int id, int l, int r, int u, int v)
{
    if (u > r || v < l || u > v || l > r) return 0;
    if (u <= l && r <= v)
    {
        return tree[id].se;
    }

    int m = (l + r) >> 1;
    return get_sz(id * 2, l, m, u, v) + get_sz(id * 2 + 1, m + 1, r, u, v);
}

void upd(int id, int l, int r, int k)
{
    if (l > k || k > r) return;
    if (l == r && l == k)
    {
        tree[id] = mp(0, 0);
        return;
    }

    int m = (l + r) >> 1;
    upd(id * 2, l, m, k);
    upd(id * 2 + 1, m + 1, r, k);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    vector<ll> ret;
    vector<bool> vis(n + 1, false);
    for(int ct=1; ct<=n && K > 0; ct++)
    {
        int ps = find_pos(1, 1, n, K + 1);
        int nxt = get(1, 1, n, 1, ps);
        K -= get_sz(1, 1, n, 1, nxt - 1);
        upd(1, 1, n, nxt);
        vis[nxt] = true;
        ret.pb(a[nxt]);
    }

    for(int i=0; i<sz(ret); i++)
    {
        cout << ret[i] << " ";
    }

    for(int i=1; i<=n; i++)
    {
        if (!vis[i]) cout << a[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SWAP.INP", "r", stdin);
    freopen("SWAP.OUT", "w", stdout);
    solve();
    return 0;
}
