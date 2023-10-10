#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const ll INF = 1e18;
const int mxN = 2e5 + 66;

int n, Q;
vector<int> euler, edges[mxN];
ll st[mxN], seg[mxN * 8];

void dfs(int u, int p)
{
    st[u] = sz(euler);
    euler.pb(u);

    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
            euler.pb(u);
        }
    }
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
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
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
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> Q;
    for(int child=1; child<n; child++)
    {
        int p;
        cin >> p;
        --p;
        edges[p].push_back(child);
    }

    dfs(0, n + 1);
    build(1, 0, 2 * n - 1);

    while(Q--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (st[u] > st[v]) swap(u, v);
        cout << get(1, 0, 2 * n - 1, st[u], st[v]) + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
