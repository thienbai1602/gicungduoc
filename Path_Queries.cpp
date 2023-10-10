#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 2e5 + 66;

int n, Q;
vector<ll> edges[mxN], sumPath;
ll st[mxN], ed[mxN], value[mxN], seg[mxN * 4], lz[mxN * 4], timer = 0;

void dfs(int u, int p = n + 1, ll val = value[0])
{
    st[u] = timer++;
    sumPath.pb(val);
    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u, val + value[v]);
        }
    }
    ed[u] = timer - 1;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = sumPath[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void upd(int id, int l, int r, int u, int v, ll x)
{
    if (lz[id] != 0)
    {
        seg[id] += (r - l + 1) * lz[id];
        if (l != r)
        {
            lz[id * 2] += lz[id];
            lz[id * 2 + 1] += lz[id];
        }
        lz[id] = 0;
    }

    if (l > v || u > r)
    {
        return;
    }

    if (u <= l && r <= v)
    {
        seg[id] += (r - l + 1) * x;
        if (l != r)
        {
            lz[id * 2] += x;
            lz[id * 2 + 1] += x;
        }
        return;
    }

    int m = (l + r) >> 1;
    upd(id * 2, l, m, u, v, x);
    upd(id * 2 + 1, m + 1, r, u, v, x);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

ll get(int id, int l, int r, int k)
{
    if (lz[id] != 0)
    {
        seg[id] += (r - l + 1) * lz[id];
        if (l != r)
        {
            lz[id * 2] += lz[id];
            lz[id * 2 + 1] += lz[id];
        }
        lz[id] = 0;
    }

    if (l == r && r == k)
    {
        return seg[id];
    }

    int m = (l + r) >> 1;
    return (k <= m ? get(id * 2, l, m, k) : get(id * 2 + 1, m + 1, r, k));
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> value[i];
    }

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(0);
    build(1, 0, n - 1);

    while(Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll s, x;
            cin >> s >> x;
            --s;
            upd(1, 0, n - 1, st[s], ed[s], x - value[s]);
            value[s] = x;
        } else
        {
            int s;
            cin >> s;
            --s;
            cout << get(1, 0, n - 1, st[s]) << "\n";
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
