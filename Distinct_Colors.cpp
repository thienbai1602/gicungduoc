#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 2e5 + 66;

int n;
vector<int> euler, seg[mxN], edges[mxN];
ll c[mxN], st[mxN], ed[mxN], fen[mxN], timer = 0;

void dfs(int u, int p)
{
    st[u] = timer++;
    euler.pb(u);
    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    ed[u] = timer - 1;
}

void upd(int id, int x)
{
    for(; id<=n; id+=(id & -id))
    {
        fen[id] += x;
    }
}

ll get(int id)
{
    ll ret = 0;
    for(; id>0; id-=(id & -id))
    {
        ret += fen[id];
    }
    return ret;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> c[i];
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
        seg[ed[i]].pb(i);
    }

    map<ll, ll> cnt;
    vector<ll> ans(n);
    memset(fen, 0, sizeof(fen));
    for(int i=0; i<n; i++)
    {
        ll col = c[euler[i]];
        if (!cnt[col])
        {
            cnt[col] = i + 1;
            upd(i + 1, 1);
        } else
        {
            upd(cnt[col], -1);
            cnt[col] = i + 1;
            upd(i + 1, 1);
        }

        for(int node : seg[i])
        {
            ans[node] = get(ed[node] + 1) - get(st[node]);
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
