#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 2e5 + 66;

int n, Q, timer = 0;
vector<int> edges[mxN];
ll v[mxN], st[mxN], ed[mxN], fen[mxN * 2];

void upd(int id, ll val)
{
    for(; id<=n; id+=(id & -id))
    {
        fen[id] += val;
    }
}

ll get(int id)
{
    ll ans = 0;
    for(; id>0; id-=(id & -id))
    {
        ans += fen[id];
    }
    return ans;
}

void dfs(int u, int p)
{
    st[u] = timer++;
    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    ed[u] = timer - 1;
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(0, n + 1);
    for(int i=0; i<n; i++)
    {
        upd(st[i] + 1, v[i]);
    }

    for(int i=0; i<Q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll s, x;
            cin >> s >> x;
            --s;
            upd(st[s] + 1, x - v[s]);
            v[s] = x;
        } else
        {
            ll s;
            cin >> s;
            --s;
            cout << get(ed[s] + 1) - get(st[s]) << "\n";
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
