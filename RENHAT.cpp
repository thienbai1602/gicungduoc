#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 166;
const ll INF = 1e18;

struct edge
{
    ll u, v, w;

    edge(ll _u = 0, ll _v = 0, ll _w = 0)
    {
        u = _u, v = _v, w = _w;
    }

    bool operator < (edge x)
    {
        return w < x.w;
    }
};

bool sf;
int n, m;
ll T, adj[mxN][mxN];
int p[mxN], sz[mxN];
vector<edge> edges;
vector<int> tmp, par;

int findp(int u)
{
    if (u == p[u]) return u;
    return p[u] = findp(p[u]);
}

bool Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return 1;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    return 0;
}

void dfs(int u, int v)
{
    if (adj[u][v])
    {
        sf = true;
        tmp[v] = u;
        T += adj[u][v];

        return;
    }

    for(int nxt=0; nxt<n; nxt++)
    {
        if (adj[u][nxt] && tmp[nxt] == -1)
        {
            tmp[nxt] = u;
            T += adj[u][nxt];
            dfs(nxt, v);
            if (sf) return;
            T -= adj[u][nxt];
        }
    }
}

void tv(int u)
{
    vector<int> path;
    while(u != par[u])
    {
        path.pb(u);
        u = par[u];
    }
    path.pb(u);

    cout << sz(path) << "\n";
    for(int i=0; i<sz(path); i++)
    {
        cout << path[i] + 1 << " ";
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.pb(edge(u, v, w));
    }

    sort(all(edges));

    for(int i=0; i<n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }

    memset(adj, 0, sizeof(adj));

    for(int i=0; i<sz(edges); i++)
    {
        bool f = Union(edges[i].u, edges[i].v);
        if (!f)
        {
            adj[edges[i].u][edges[i].v] = edges[i].w;
            adj[edges[i].v][edges[i].u] = edges[i].w;
        }
    }

    par.resize(n);
    ll ans = INF, st_node = -1;
    for(int i=0; i<sz(edges); i++)
    {
        int u = edges[i].u, v = edges[i].v;
        if (!adj[u][v])
        {
            tmp = vector<int>(n, -1);
            T = 0; sf = false; tmp[u] = u;
            dfs(u, v);

            if (ans > T + edges[i].w)
            {
                ans = T + edges[i].w;
                par = tmp;
                st_node = v;            }
        }
    }

    if (ans == INF) cout << 0;
     else
     {
         cout << 1 << "\n" << ans << "\n";
         tv(st_node);
     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
