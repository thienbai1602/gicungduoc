#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 2e5 + 66;

int n, M, Q;
ll a[mxN], tree[mxN * 4], lz[mxN * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = (tree[id * 2] + tree[id * 2 + 1]) % M;
}

void up(int id, int l, int r)
{
    if (lz[id])
    {
        int m = (l + r) >> 1;
        tree[id * 2] = (tree[id * 2] + lz[id] * (m - l + 1)) % M;
        tree[id * 2 + 1] = (tree[id * 2 + 1] + lz[id] * (r - m)) % M;
        lz[id * 2] = (lz[id * 2] + lz[id]) % M;
        lz[id * 2 + 1] = (lz[id * 2 + 1] + lz[id]) % M;
        lz[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, ll val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        tree[id] = (tree[id] + (r - l + 1) * val) % M;
        lz[id] = (lz[id] + val) % M;
        return;
    }

    up(id, l, r);
    int m = (l + r) >> 1;
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);
    tree[id] = (tree[id * 2] + tree[id * 2 + 1]) % M;
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v)
    {
        return tree[id];
    }

    up(id, l, r);
    int m = (l + r) >> 1;
    return (get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v)) % M;
}

void solve()
{
    cin >> M >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    fill(tree, tree + 4 * n, 0);
    build(1, 1, n);
    for(int i=0; i<Q; i++)
    {
        int tc;
        cin >> tc;
        if (tc == 1)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v);
        } else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
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
