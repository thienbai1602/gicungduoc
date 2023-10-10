#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const ll INF = 1e17;
const int mxN = 1e5 + 66;

int n, Q;
ll a[mxN];
multiset<ll> tree[mxN * 4];

multiset<ll> combine(multiset<ll> a, multiset<ll> b)
{
    if (sz(a) < sz(b)) swap(a, b);
    multiset<ll> ret = a;
    for(auto it=b.begin(); it!=b.end(); it++)
    {
        ret.insert(*it);
    }
    return ret;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id].insert(a[l]);
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

void update(int id, int l, int r, int k, ll old, ll val)
{
    if (k > r || k < l) return;
    if (l == r && r == k)
    {
        tree[id].clear();
        tree[id].insert(val);
        return;
    }

    int m = (l + r) >> 1;
    if (k <= m) update(id * 2, l, m, k, old, val);
     else update(id * 2 + 1, m + 1, r, k, old, val);
    tree[id].erase(tree[id].find(old));
    tree[id].insert(val);
}

ll get(int id, int l, int r, int u, int v, ll val)
{
    if (u > r || v < l) return INF;
    if (u <= l && r <= v)
    {
        auto pos = tree[id].lower_bound(val);
        return (pos == tree[id].end() ? INF : *pos);
    }

    int m = (l + r) >> 1;
    return min(get(id * 2, l, m, u, v, val), get(id * 2 + 1, m + 1, r, u, v, val));

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
        if (type == 1)
        {
            ll k, val;
            cin >> k >> val;
            update(1, 1, n, k, a[k], val);
            a[k] = val;
        } else
        {
            ll u, v, val;
            cin >> u >> v >> val;
            ll nxt = get(1, 1, n, u, v, val);
            cout << (nxt == INF ? -1 : nxt) << "\n";
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
