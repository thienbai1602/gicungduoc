#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e4 + 66;

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

int n, m;
int p[mxN], sz[mxN];
vector<edge> edges;

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

    ll ans = 0;
    vector<ii> adj;
    for(int i=0; i<m; i++)
    {
        int f = Union(edges[i].u, edges[i].v);
        if (!f)
        {
            ans += edges[i].w;
            adj.pb(mp(edges[i].u, edges[i].v));
        }

        if (sz(adj) == n - 1) break;
    }

    cout << ans << "\n";
    for(auto [u, v] : adj)
    {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
