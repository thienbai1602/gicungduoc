#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 1e6 + 66;

int n, Q;
ll a[mxN];
ii tree[mxN * 4];

ii combine(ii a, ii b)
{
    if (a.fi > b.fi) return a;
    if (a.fi == b.fi) return mp(a.fi, a.se + b.se);
    if (b.fi > a.fi) return b;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = mp(a[l], 1);
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

void update(int id, int l, int r, int k, ll val)
{
    if (k < l || k > r) return;
    if (l == r && k == l)
    {
        tree[id] = mp(val, 1);
        return;
    }

    int m = (l + r) >> 1;
    if (k <= m) update(id * 2, l, m, k, val);
     else update(id * 2 + 1, m + 1, r, k, val);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

ii get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return mp(0, 0);
    if (u <= l && r <= v)
    {
        return tree[id];
    }

    int m = (l + r) >> 1;
    return combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);
    for(int i=0; i<Q; i++)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int u, v;
            cin >> u >> v;
            ii nxt = get(1, 1, n, u, v);
            cout << nxt.fi << " " << nxt.se << "\n";
        } else
        {
            ll k, val;
            cin >> k >> val;
            update(1, 1, n, k, val);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
