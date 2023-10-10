#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const ll INF = 1e18;
const int mxN = 2e5 + 66;

int n, Q;
ll st[mxN], seg[mxN * 8], deep[mxN];
vector<int> edges[mxN], euler;

void dfs(int u, int hei, int p)
{
    st[u] = sz(euler);
    euler.pb(u);
    deep[u] = hei;

    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, hei + 1, u);
            euler.pb(u);
        }
    }
}

ll combine(ll x, ll y)
{
    if (x == INF) return y;
    if (y == INF) return x;
    return (deep[x] < deep[y] ? x : y);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = euler[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = combine(seg[id * 2], seg[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (l > v || u > r)
    {
        return INF;
    }

    if (u <= l && r <= v)
    {
        return seg[id];
    }

    int m = (l + r) >> 1;
    return combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int lca(int u, int v)
{
    if (st[u] > st[v]) swap(u, v);
    return get(1, 0,  2 * n - 1, st[u], st[v]);
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(0, 1, n + 1);
    build(1, 0, 2 * n - 1);

    while(Q--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int hei = deep[lca(u, v)];
        cout << deep[u] + deep[v] - 2 * hei << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
